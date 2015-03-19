#include <EasyTransfer.h>
EasyTransfer ET;

const int potpin1 = A0;
const int potpin2 = A1;


struct SEND_DATA_STRUCTURE{
int servo1val;
int servo2val;



};

SEND_DATA_STRUCTURE txdata;

void setup(){
  Serial.begin(9600);
  //  Serial.begin(115200);
  ET.begin(details(txdata), &Serial);
  // pinMode(potpin1, INPUT);
  // pinMode(potpin2, INPUT);

}

void loop(){

  int val1 = analogRead(potpin1);

   
   
  val1 = map(val1, 0, 1023, 0, 180);
  txdata.servo1val = val1;
  txdata.servo2val = 180 - val1;
  
  
  ET.sendData();
}
