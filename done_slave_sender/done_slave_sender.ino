String a;
const int str_len=20;
char arr[str_len];
#include <Wire.h>
void setup() {
  Serial.begin(9600);
  Wire.begin(8);                // join I2C bus with address #8
  Wire.onRequest(requestEvent); // register event

}
void loop() {
  while (Serial.available()>0) {
 a=Serial.readString();
 a.toCharArray(arr,str_len);
  delay(100);
   }
  }
void requestEvent() {
   Wire.write(arr,str_len); 
   delay(1000);
   for(int i=0;i<str_len;i++)
   {
      arr[i]=NULL; 
   }
}
