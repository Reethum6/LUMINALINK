#define BLYNK_TEMPLATE_ID
"TMPL3TnM3E6Lj"
#define BLYNK_TEMPLATE_NAME
"Quickstart Template"
#define BLYNK_AUTH_TOKEN
"EBJwrQpgtQEQB_ORjjdj3-uvf7FshjVp"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
char auth[] ="EBJwrQpgtQEQB_ORjjdj3-uvf7FshjVp"; 
char ssid[] = "Iqoo Neo 6"; 
char pass[] = "Nani2005";
#define LDR_PIN1 A0
#define LDR_PIN2 A0
#define LDR_PIN3 A0
#define LDR_PIN4 A0
#define LED_PIN1 D1
#define LED_PIN2 D2
#define LED_PIN3 D3
#define LED_PIN4 D4
#define VIRTUAL_PIN 1 
// Virtualpin to send notifications
voidsetup() { 
Blynk.begin(auth, ssid, pass); pinMode(LED_PIN1, OUTPUT); pinMode(LED_PIN2, OUTPUT); pinMode(LED_PIN3, OUTPUT); pinMode(LED_PIN4, OUTPUT); digitalWrite(LED_PIN1, LOW);
 //Initially turn off all LEDs digitalWrite(LED_PIN2, LOW); digitalWrite(LED_PIN3, LOW); digitalWrite(LED_PIN4, LOW);
}
void loop() {
int ldrValue1 =analogRead(LDR_PIN1); 
int ldrValue2 =analogRead(LDR_PIN2); 
int ldrValue3 = analogRead(LDR_PIN3); int ldrValue4 = analogRead(LDR_PIN4);
// You can adjust these threshold values based on your light conditions
int threshold = 500;
// Check LDR values and control LEDs
 if(ldrValue1<threshold) digitalWrite(LED_PIN1, HIGH);
// Turn on LED1 if it's dark else
digitalWrite(LED_PIN1, LOW);
 // Turn off LED1 if it's bright
if(ldrValue2<threshold) digitalWrite(LED_PIN2, HIGH);
// Turn on LED2 if it's dark else
digitalWrite(LED_PIN2,LOW);
 // Turn off LED2 if it's bright
if(ldrValue3<threshold) digitalWrite(LED_PIN3,HIGH);
//Turn on LED3 if it’s dark else
digitalWrite(LED_PIN3,LOW);
//Turn off LED3 if it’s bright
if(ldrValue4<threshold) digitalWrite(LED_PIN4, HIGH);
// Turn on LED4 if it's dark else
digitalWrite(LED_PIN4,LOW); 
// Turn off LED4 if it's bright
// Check for street light fault 
if (ldrValue1 < threshold &&ldrValue2 < threshold && ldrValue3 < threshold && ldrValue4 < threshold) {
// All LDRs indicate darkness, which may indicate a street light fault
Blynk.virtualWrite(VIRTUAL_PIN, "Street Light Fault Detected!
Please check the lights."); 
} 
else {
Blynk.virtualWrite(VIRTUAL_PIN, "");
 // Clear the notification if not in fault condition
}
Blynk.run();
}
