#include <Wire.h>                                                                          
int LED = 13;                                                                              
unsigned long start, finished, elapsed;
long a = 1;
char c;
                                                                                           
void setup() {
 pinMode (LED, OUTPUT);
 Serial.begin(9600); /* begin serial comm. */
 Wire.begin(); /* join i2c bus as master */
 Serial.println("I am Master");
 
  start = micros();
  Serial.println();
  
}

void loop() {
  
    // receive from slave
    Serial.print("Slave Uno-chan: ");
    Serial.print(a);

    //send to slave
     Wire.beginTransmission(8);
     Wire.write(a);
     Wire.endTransmission();
    
    Serial.print("  ");
    Wire.requestFrom(8, 11); /* request & read data of size ? from slave */
    while(Wire.available()){
        c = Wire.read();/* read data received from slave */
    Serial.print(c);
    }
 
    Serial.println();
    a++;
    
    if(a > 1000){
      // print time elapsed
      Serial.println();
      finished = micros();                                                                   
      Serial.print("Finished in ");                                                            
      elapsed = finished - start;                                                           
      Serial.print(elapsed);                                                                
      Serial.println(" microseconds!");                                              
      delay(500);
      exit(0);
    }
    
}
