/***** ARDUIRIG *****/
/* this code converts a IRIG.B bit sequence to a NMEA string and send it oou using the serial port */
byte pin = 2;              //input pin for IRIG-B bit sequence

/* Flag for the various check */
boolean PPD_flag;
bool dataFlag = 0;
bool timeFlag = 0;
bool monthFlag;
bool yearFlag = 0;
bool serialFlag = 0;

/*** Variables to desume from the IRIG-B stream ***/
byte Seconds;
byte Minutes;
byte Hours;
int DaysOY;              //day of the year (given by IRIG-B)
int Days_old;             //day of the year at the previous interval
int Days;                   //day of the month
byte Month;
unsigned int Year;
unsigned int SBS;         // straight binary seconds (17 bits)
/*** Reiceved bits counter and array ***/
byte counter;              //reiceved bit counter[max 84+5 INDEX]
byte bitstream[89];     //array where input bitstream is stHoursd [max 84 + 5 INDEX]
/*** Program Variables ***/
unsigned long duration;
unsigned long PPDmillisec;
byte daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
/*** STRING PARAMETERS ***/
byte TMZh = 0;
byte TMZm = 0;

void setup()
{
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  duration = pulseIn(pin, HIGH, 250000);      //WARNING time value is in micro_seconds

  if (duration == 0) {
    resetFlags();
  }
  
  if (duration <= 2200){
    bitstream[counter] = 0;
    counter ++;
    PPD_flag = 0;
  } else if (duration <= 5200) {
    bitstream[counter] = 1;
    counter++;
    PPD_flag = 0;
  } else {
    if (PPD_flag)                           //if the previouse pulse was a POINTER
    {
      PPDmillisec = millis();
      if (counter == 89) dataFlag = 1;      //if all the 89 bit are reiceved
      else
        resetFlags();
      counter = 0;
    }
    PPD_flag = 1;
  }

  if (counter == 24 && dataFlag)            //conversion of hours/minutes/seconds
  {
    Seconds = bitstream[0] + bitstream[1] * 2 + bitstream[2] * 4 + bitstream[3] * 8 + bitstream[5] * 10 + bitstream[6] * 20 + bitstream[7] * 40;
    Minutes = bitstream[8] + bitstream[9] * 2 + bitstream[10] * 4 + bitstream[11] * 8 + bitstream[13] * 10 + bitstream[14] * 20 + bitstream[15] * 40;
    Hours = bitstream[17] + bitstream[18] * 2 + bitstream[19] * 4 + bitstream[20] * 8 + bitstream[22] * 10 + bitstream[23] * 20;
    timeFlag = 1;
  }
  if (counter == 37 && dataFlag)            //conversion of days of the year/year
  {
    Days_old = DaysOY;                     //store the previous day of the year
    DaysOY = bitstream[26] + bitstream[27] * 2 + bitstream[28] * 4 + bitstream[29] * 8 + bitstream[31] * 10 + bitstream[32] * 20 + bitstream[33] * 40 + bitstream[34] * 80 + bitstream[35] * 100 + bitstream[36] * 200;
    Year = 2000 + bitstream[44] + bitstream[45] * 2 + bitstream[46] * 4 + bitstream[47] * 8 + bitstream[49] * 10 + bitstream[50] * 20 + bitstream[51] * 40 + bitstream[52] * 80;
    
    //check for leap year
    if (!serialFlag)
    {
      if (Year % 4  == 0)
      {
        if (Year % 100 != 0)
          daysInMonth[1] = 29;
        else if (Year % 400 == 0)
          daysInMonth[1] = 29;
      }
    }
    yearFlag = 1;
  }
  if (counter == 38 && dataFlag)          //conversion of days/month
  {
    if (DaysOY != Days_old)              //if the day of the year is different check the month
    {
      monthFlag = 0;
    }
    if (!monthFlag)                       //calculation for the month and the day
    {
      int i = 0;
      Days = DaysOY;

      Serial.println(Days);
      while ( Days > daysInMonth[i])
      {
        Days -= daysInMonth[i];
        i++;
      }
      Month = i + 1;
      monthFlag = 1;
    }
    serialFlag = (yearFlag && timeFlag);
  }
  if (counter == 39 && serialFlag)      //sending on the serial port
  {
    char strg[32];                      //string
    unsigned int interval = millis() - PPDmillisec;
    interval = round(interval / 10.0);
    //sprintf(strg, "%02d%02d%02d.%02d,%02d,%02d,%04d,%02d,%02d", Hours, Minutes, Seconds, interval, TMZh, TMZh , Year, Month, Days);

    sprintf(strg, "%04d-%02d-%02d %02d:%02d:%02d", Year, Month, Days, Hours, Minutes, Seconds);

    Serial.println(strg);
    
   
  }
  
  if (counter > 89)
  {
    resetFlags();
  }
  
}


/* RESET FLAGS FUNCTION */
void resetFlags (void)
{
  counter = 0;
  dataFlag = 0;
  timeFlag = 0;
  yearFlag = 0;
  serialFlag = 0;
}




