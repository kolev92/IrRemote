#include <IRremote.h>

const int RECV_PIN = 2;
int result;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  if(results.value==0xFFA25D){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if(results.value==0xFF629D){
    digitalWrite(LED_BUILTIN, LOW);
  }
}
