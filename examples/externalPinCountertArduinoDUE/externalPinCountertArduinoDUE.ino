/*
 * count pulse on external pin
 *  
 * Pin assignement for clock input pins is found here:
 * https://github.com/ivanseidel/DueTimer/blob/master/TimerCounter.md
 *
 */
#include <DueTimer.h>

void setup(){
  Serial.begin(9600);

  Timer0.setUpCounter(); // Digital Pin 22
  Timer0.startCounter();

  Timer1.setUpCounter(); // Pin: Analog In 5
  Timer1.startCounter();

  Timer2.setUpCounter(); // Digital Pin 31
  Timer2.startCounter();
}

void loop() {
  Serial.print("pulse count - "); 
  Serial.print("pin 22: ");
  Serial.print(  Timer0.counterValue());

  Serial.print("  analog 5: ");
  Serial.print(  Timer1.counterValue());

  Serial.print("  pin 31: ");
  Serial.println(  Timer2.counterValue());
  
  delay(1000);
}
