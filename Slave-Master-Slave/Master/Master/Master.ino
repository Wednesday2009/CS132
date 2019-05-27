#include <Wire.h>                                                                          // Include the required Wire library for I2C<br>   
int LED = 13;                                                                              // definition where LED is equal to 13   
unsigned long start, finished, elapsed;                                                    // initialization of variables     
int a = 1;                                                                                 // assigning value of a == 1
char c;                                                                                    // initialization char c
                                                                                           
void setup() {
 pinMode (LED, OUTPUT);                                                                    // Define the LED pin as 
 Serial.begin(9600);                                                                       // begin serial monitor    
 Wire.begin();                                                                             // join i2c bus as master
 Serial.println("I am Master");                                                            // prints "I am Master" in Serial Monitor
 
  start = micros();                                                                        // record start time 
  Serial.println();
  
}

void loop() {
  
    // receive from slave
    Serial.print("Uno-chan: ");                                                           // prints "Slave Uno-chan: " in the Serial Monitor
    Serial.print(a);                                                                      // prints the value of a

    //send to slave
     Wire.beginTransmission(1);                                                           // transmit to device #1
                                                                                          // (it could be any number, it is just the address of the slave device)
     
     Wire.write(a);                                                                       // throws the value of a to the slave receiver
     Wire.endTransmission();                                                              // triggers to end the transmission
     a++;                                                                                 // increment value of a
     
     
    Serial.print("  ");
    Wire.requestFrom(1, 11);                                                              // request & read data of size ? from slave
    while(Wire.available()){
        c = Wire.read();                                                                  // reads data received from slave
    Serial.print(c);                                                                      // prints the slave's output
    }
    
    Serial.print(" Dos-chan: ");                                                          // prints "Slave Dos-chan: " in the Serial Monitor
    Serial.print(a);                                                                      // prints the value of a

    Wire.beginTransmission(2);                                                            // transmit to device #2
                                                                                          // (it could be any number, it is just the address of the slave device)
    
    Wire.write(a);
     Wire.endTransmission();                                                              // triggers to end the transmission
     a++;                                                                                 // increment value of a / input
    
    Serial.print("  ");
    Wire.requestFrom(2, 11);                                                              // request & read data of size ? from slave
    while(Wire.available()){
        c = Wire.read();                                                                  // reads data received from slave
    Serial.print(c);                                                                      // prints the slave's output
    }
 
    Serial.println();
    
      
    if(a > 1000){                                                                         // stops input to slave     
      // print time elapsed
      Serial.println();
      finished = micros();                                                                // record finish time    
      Serial.print("Finished in ");                                                            
      elapsed = finished - start;                                                         // get processing time                                                 
      Serial.print(elapsed);                                                              // print processing time       
      Serial.println(" microseconds!");                                              
      delay(500);                                                                         // delay before exit
      exit(0);
    }
    
}
