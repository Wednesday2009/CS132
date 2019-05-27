#include <Wire.h>                                                                                               // Include the required Wire library for I2C<br>                                                                                                                            
int LED = 13;                                                                                                   // definition where LED is equal to 13 
int start;                                                                                                      // initialization of start with a type of int
long a;                                                                                                         // initialization of a with a type of long

void setup() {
 Wire.begin(8);                                                                                                 // join i2c bus with address 8
 Wire.onReceive(receiveEvent);
 Wire.onRequest(requestEvent);                                                                                  // register request event
 Serial.begin(9600);                                                                                            // start serial monitor
 Serial.println("I am Slave Uno-chan");                                                                         // prints "I am Slave Uno-chan: "
}

void loop() {

}

void receiveEvent(){
  a = Wire.read();                                                                                              // catches the a value thrown by the master
} 


char requestEvent() {                                                                                          // function that executes whenever data is requested from master
  
  if(a == 1){
    Wire.write(" SPECIAL   ");                                                                                 // condition that writes "SPECIAL" if a == 1
  }
  else if(a == 2){
    Wire.write(" PRIME     ");                                                                                 // condition that writes "PRIME" if a == 2
  }
  else if(a == 3){
    Wire.write(" PRIME     ");                                                                                 // condition that writes "PRIME" if a == 3
  }
  else if(a == 5){
    Wire.write(" PRIME     ");                                                                                 // condition that writes "PRIME" if a == 5
  }
  else if(a == 7){
    Wire.write(" PRIME     ");                                                                                 // condition that writes "PRIME" if a == 7
  }
  else if(a == 9){
    Wire.write(" SEMIPRIME     ");                                                                             // condition that writes "SEMIPRIME" if a == 9
  }
  else if(a % 2 == 0){
    Wire.write(" not prime ");                                                                                 // condition that checks if a is divisible by 2
  }
  else if(a % 3 == 0){
    Wire.write(" not prime ");                                                                                 // condition that checks if a is divisible by 3
  }
  else if(a % 5 == 0){
    Wire.write(" not prime ");                                                                                 // condition that checks if a is divisible by 5
  }
  else if(a % 7 == 0){
    Wire.write(" not prime ");                                                                                 // condition that checks if a is divisible by 7
  }
  else if(a % 9 == 0){
    Wire.write(" not prime ");                                                                                // condition that checks if a is divisible by 2
  }
  else{
    for(int i = 2; i <= (a / 2); ++i){                                                                        // condition that checks if a is divisible by other numbers other than the checkers above
      if((a % i) == 0){
        Wire.write(" not prime ");
        break;
      }
      else  Wire.write(" PRIME     ");
    }
  }
}
