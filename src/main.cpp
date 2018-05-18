#include <Arduino.h>
#define OUTPIN 12
#define PULSE_DUR 50
#define LT_PULSE 100
#define MAX_T 200000
#define MIN_T 5000
uint32_t del;
float portata =0.;

void impulso();

void setup() {
pinMode(OUTPIN, OUTPUT);
digitalWrite(OUTPIN,0);
Serial.begin(9600);
Serial.println("\n************ Generatore Impulsi ***************");
Serial.println("         100 litri/impulso, 50 ms");
Serial.println("             Range: 0,5-20l/s");
Serial.println("***********************************************");
del = random(5,200)*1000;
}

void loop() {
    Serial.println("\nAumento della Portata...\n");
    while(del > MIN_T+1){
      impulso();
      del-=random(1000,5000);
      if(del<5000) del=5000;
      portata = (float) LT_PULSE/del*1000.;
      Serial.println("Portata corrente: "+String(portata)+" l/s, durata: "+String(del/1000.)+" s");
      delay(del);
    }
    Serial.println("\nDiminuzione della Portata...\n");
    while(del < MAX_T-1){
      impulso();
      del+=random(500,1000);
      if(del>200000) del=200000;
      portata = (float) LT_PULSE/del*1000.;
      Serial.println("Portata corrente: "+String(portata)+" l/s, durata: "+String(del/1000.)+" s");
      delay(del);
    }
}
void impulso(){
  digitalWrite(OUTPIN, 1);
  delay(PULSE_DUR);
  digitalWrite(OUTPIN, 0);
  return;
}
