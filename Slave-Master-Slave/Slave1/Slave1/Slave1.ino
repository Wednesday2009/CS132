#include <Wire.h>                                                                                                 // Include the required Wire library for I2C<br>                                                                                            
int LED = 13;                                                                                                     // definition where LED is equal to 13
int start;                                                                                                        // initialization start
int a;                                                                                                            // initializing a

void setup() {
 Wire.begin(1);                                                                                                   // join i2c bus with address 1
 Wire.onReceive(receiveEvent);                                                                                    // register recieve event
 Wire.onRequest(requestEvent);                                                                                    // register request event
 Serial.begin(9600);                                                                                              // start serial comm.
 Serial.println("I am Slave Uno-chan");                                                                           // prints "I am Slave Uno-chan" in Serial monitor
}

void loop() {

}

void receiveEvent(){
  a = Wire.read();                                                                                              // catches the thrown value of a
}

char requestEvent() {                                                                                           // function that executes whenever data is requested from master
  
  if(a == 1){
    Wire.write(" SPECIAL   ");                                                                                  // condition that writes "SPECIAL" if a == 1
  }
  else if(a == 2){
    Wire.write(" PRIME     ");                                                                                  // condition that writes "PRIME" if a == 2
  }
  else if(a == 3){
    Wire.write(" PRIME     ");                                                                                  // condition that writes "PRIME" if a == 3
  }
  else if(a == 5){
    Wire.write(" PRIME     ");                                                                                  // condition that writes "PRIME" if a == 5
  }
  else if(a == 7){
    Wire.write(" PRIME     ");                                                                                  // condition that writes "PRIME" if a == 7
  }
  else if(a % 2 == 0){
    Wire.write(" not prime ");                                                                                  // condition that checks if a is divisible by 2
  }
  else if(a % 3 == 0){
    Wire.write(" not prime ");                                                                                  // condition that checks if a is divisible by 3
  }
  else if(a % 5 == 0){
    Wire.write(" not prime ");                                                                                  // condition that checks if a is divisible by 5
    Wire.write(a);
  }
  else if(a % 7 == 0){
    Wire.write(" not prime ");                                                                                  // condition that checks if a is divisible by 7
  }
  else if(a % 9 == 0){
    Wire.write(" not prime ");                                                                                  // condition that checks if a is divisible by 9
  }
  else{
    int b = 0;
    for(int i = 2; i <= (a / 2); ++i){                                                                          // condition that checks if a is divisible by other numbers other than the checkers above
      if(a % i == 0){
        b  = 1;
        break;
      }
    }
   if(b == 0){
    Wire.write(" PRIME     "); 
   }
   else Wire.write(" not prime ");
   
  }
}
