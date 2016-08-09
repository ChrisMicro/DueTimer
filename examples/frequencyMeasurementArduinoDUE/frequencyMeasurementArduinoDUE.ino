/*
 * frequency measurement with an ARDUINO DUE
 * 
 * The frequency is measured on pin 22
 * 
 * Pin assignement for clock input pins is found here:
 * https://github.com/ivanseidel/DueTimer/blob/master/TimerCounter.md
 *
 */
#include <DueTimer.h>

volatile uint32_t Frequency;

// update the global Frequency variable
void timerCatch(){
  Timer0.stopCounter();
  Frequency=Timer0.counterValue();
  Timer0.startCounter();
}

#define FREQUENCYCORRECTIONFACTOR 3 // adjusted manually, some correction due to timerCatch function necessary

void setup(){
  Serial.begin(9600);

  Timer0.setUpCounter();
  Timer3.attachInterrupt(timerCatch);
  Timer3.start(1000000+FREQUENCYCORRECTIONFACTOR); // time gate for frequency measurement in us
}

void loop() {
  Serial.print("frequency: ");
  Serial.println(Frequency);
  delay(1000);
}
