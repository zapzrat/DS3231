#include <Wire.h>
#include <DS3231.h>
DS3231 clock;
RTCDateTime dt;

const int led = 13;

void setup()
{
  Serial.begin(9600);
  Serial.println("Micro Project Thailand ~^.^~ ");
  pinMode(led, OUTPUT);

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  delay(1000);


  if (dt.second > 30 ) {
    digitalWrite(led, HIGH);

  } else {
    digitalWrite(led, LOW);
  }
}
