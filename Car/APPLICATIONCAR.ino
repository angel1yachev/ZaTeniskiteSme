#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

const char* ssid = "alexpc";
const char* password = "12345678";

String  data =""; 

#define motor1 D3
#define motor2 D4
#define LED2 D2
#define LED3 D5

void setup()
{
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT); 
  pinMode(LED2, OUTPUT);  
  pinMode(LED3, OUTPUT);
  
  server.begin();
}

void loop()
{
    
  client = server.available();
  if (!client) return; 
      data = checkClient ();
    
   


    if (data == "forward") MotorForward();
      else 
        if (data == "backward") MotorBackward();
          else
            if (data == "stop") MotorStop();
              
            
} 


void MotorForward(void)   
{
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,HIGH );
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
}


void MotorBackward(void)   
{
      digitalWrite(motor1,HIGH);
      digitalWrite(motor2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED3,HIGH);
}



void MotorStop(void)   
{
      digitalWrite(motor1,LOW );
      digitalWrite(motor2,LOW);
}




String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
