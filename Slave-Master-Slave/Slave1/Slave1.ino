#include <Wire.h>                                                                         
int LED = 13; 
int start;
int a;

void setup() {
 Wire.begin(1);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent);
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial comm. */
 Serial.println("I am Slave Uno-chan");
}

void loop() {

}

void receiveEvent(){
  a = Wire.read();
}

// function that executes whenever data is requested from master
char requestEvent() {
  
  if(a == 1){
    Wire.write(" SPECIAL   ");
  }
  else if(a == 2){
    Wire.write(" PRIME     ");
  }
  else if(a == 3){
    Wire.write(" PRIME     ");
  }
  else if(a == 5){
    Wire.write(" PRIME     ");
  }
  else if(a == 7){
    Wire.write(" PRIME     ");
  }
  else if(a == 9){
    Wire.write(" PRIME     ");
  }
  else if(a % 2 == 0){
    Wire.write(" not prime ");
  }
  else if(a % 3 == 0){
    Wire.write(" not prime ");
  }
  else if(a % 5 == 0){
    Wire.write(" not prime ");
  }
  else if(a % 7 == 0){
    Wire.write(" not prime ");
  }
  else if(a % 9 == 0){
    Wire.write(" not prime ");
  }
  else{
    for(int i = 2; i <= a / 2; ++i){
      if(a % i == 0){
        Wire.write(" not prime ");
        break;
      }
      Wire.write(" PRIME     ");
    }
  }
}
