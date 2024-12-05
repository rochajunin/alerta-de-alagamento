#define BLYNK_TEMPLATE_ID " "
#define BLYNK_TEMPLATE_NAME " "
#define BLYNK_AUTH_TOKEN " "

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = " ";
char pass[] = " ";

int jump = D7;

void setup()
{
  pinMode(jump, INPUT_PULLUP);
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
  int valor = !digitalRead(jump); 
  if(valor == HIGH){
    Serial.println("ligado"); 
    Blynk.virtualWrite(V1, "ligado");
  } else {
    Serial.println("desligado"); 
    Blynk.virtualWrite(V1, "desligado");
  }
  Blynk.virtualWrite(V0, valor);
  delay(1000); 
}