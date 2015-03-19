#include <Servo.h>
#include <EasyTransfer.h>
EasyTransfer ET;

Servo myservo1;
Servo myservo2;


Servo ST1, ST2; 

struct RECEIVE_DATA_STRUCTURE{
  int servo1val;
  int servo2val

};

RECEIVE_DATA_STRUCTURE txdata;

void setup(){
  Serial.begin(9600);
  // Serial.begin(115200);

  ET.begin(details(txdata), &Serial);
  // Servo
  ST1.attach(5, 1000, 2000);
  ST2.attach(6, 1000, 2000);


}

void loop(){
  if(ET.receiveData()){
    ST1.write(txdata.servo1val);
    ST2.write(txdata.servo2val);
    //ST1.write(map(txdata.servo1val, 0, 1023, 0, 180));
    //ST2.write(map(txdata.servo2val, 0, 1023, 0, 180));
  }
}
