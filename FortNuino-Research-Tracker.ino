/*
   Author: Félix "DiglidiDudeNG" Dion-Robidoux
   Date:2017/08/16
   IDE V1.6.9
   Email:digldidude.ng@gmail.com
   Function: A Research points tracker for Fortnite, to use with a 16x2 LCD display.
*/
const int   RESEARCH_GEN_LIMIT = 3195; // Change to your current generation limit.
const short RESEARCH_PER_HOUR = 108; // Change to your current amount generated per hour.

#include <Time.h>
#include <TimeAlarms.h>
#include <Wire.h>
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String comdata = "";
int    research_points_generated = 0;
double single_research_point_progress = 0.0,
       point_progress_per_tick;

void setup()
{
  serial_setup();
  Wire.begin();
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Do setup for Research points.
  Research_setup();
  // Do setup for RTC.
  Alarm_setup();
  lcd_write_research();
}

void serial_setup() {
  Serial.begin(9600);
  // TODO: Control current amount & sync progress using input from serial monitor.
}

void Research_setup() {
  // Calculate single increase per tick.
  point_progress_per_tick = ((RESEARCH_PER_HOUR * 100) / 60) / 60;
}
void Alarm_setup() {
  // Set the first alarm every second.
  // The progression is added every second, indicated by the first parameter on the function call,
  // which you can change it to however often you want in order to save power when running on 
  // battery power for example.
  // However, remember to scale it with the value calculated for `point_progress_per_tick` in 
  // the `Research_setup` function.
  Alarm.timerRepeat(1, onAlarm);
}

void loop()
{
  // Checks every second for alarms that need to trigger.
  Alarm.delay(1000);
}

void onAlarm() {
  // For debugging...
  Serial.println(single_research_point_progress);
  Serial.println(point_progress_per_tick);
  single_research_point_progress += point_progress_per_tick;
  if (single_research_point_progress >= 100.0) {
    single_research_point_progress -= 100.0;
    research_points_generated++;
  }
  lcd_write_research();
}

void lcd_write_research() {
  lcd.setCursor(0, 0);
  lcd.write("Research pts:");
  update_research_pts_onscreen();
}

void update_research_pts_onscreen() {
  lcd.setCursor(0, 1);
  lcd.print(research_points_generated, DEC);
  lcd.write(" / ");
  lcd.print(RESEARCH_GEN_LIMIT, DEC);
}
