void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(RCTime(6));      // Connect to pin 2, display results
  delay(250);         // Wait 250 ms
}

long RCTime(int sensorIn){
   long duration = 0;
   pinMode(sensorIn, OUTPUT);     // Make pin OUTPUT
   digitalWrite(sensorIn, HIGH);  // Pin HIGH (discharge capacitor)
   delay(1);                      // Wait 1ms
   pinMode(sensorIn, INPUT);      // Make pin INPUT
   digitalWrite(sensorIn, LOW);   // Turn off internal pullups
   while(digitalRead(sensorIn)){  // Wait for pin to go LOW
      duration++;
   }
   return duration;
}

/* sensor on pin 4: (far right) 
 *  WHITE: ~12  
 *  BLACK: 145-153 
 *  
 *  sensor on pin 5: (center right) 
 *   WHITE: ~8 
 *   BLACK: ~94 
 *   
 *   sensor on pin 6: (center left) 
 *   
 *   WHITE: ~7 ** dirty mat: 9
 *   BLACK: ~122 ** dirty mat: 58
 *   
 *   sensor on pin 7: (far left) 
 *   WHITE: ~12 ** dirty mat: 11 
 *   BLACK: ~145 ** dirty mat: 70
 */
 
