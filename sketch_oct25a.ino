#include <Bounce2.h>

#define led1 2
#define led2 3
#define led3 4
#define led4 5

#define boton1 7
#define boton2 8
#define boton3 9
#define boton4 10


Bounce button1 = Bounce();
Bounce button2 = Bounce();
Bounce button3 = Bounce();
Bounce button4 = Bounce();

void setup() {

  // Setup the button with an internal pull-up :
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
  pinMode(boton4, INPUT_PULLUP);
  pinMode(led1,LOW);
  pinMode(led2,LOW);
  pinMode(led3,LOW);
  pinMode(led4,LOW);


  Serial.begin(9600);
  // After setting up the button, setup the Bounce instance :
  button1.attach(boton1);
  button1.interval(50);
  button2.attach(boton2);
  button2.interval(50);
  button3.attach(boton3);
  button3.interval(50);
  button4.attach(boton4);
  button4.interval(50);




}

int secuencia[10];

void loop() {

  // Update the Bounce instance :
  button1.update();
  button2.update();
  button3.update();
  button4.update();

  // Call code if Bounce fell (transition from HIGH to LOW) :

  for (int i; i >= 10; i++) {
    if (button1.fell()) {
      Serial.println("Boton 1 pulsado");
      secuencia[i] = 1;
      digitalWrite(led1,HIGH);
      delay(200);
      digitalWrite(led1,LOW);
      button1.update();
    }
    if (button2.fell()) {
      Serial.println("Boton 2 pulsado");
      secuencia[i] = 2;
           digitalWrite(led2,HIGH);
      delay(200);
      digitalWrite(led2,LOW);
      button2.update();
    }
    if (button3.fell()) {
      Serial.println("Boton 3 pulsado");
      secuencia[i] = 3;
      button3.update();
        digitalWrite(led3,HIGH);
      delay(200);
      digitalWrite(led3,LOW);
    }
    if (button4.fell()) {
      Serial.println("Boton 4 pulsado");
      secuencia[i] = 4;
      digitalWrite(led4,HIGH);
      delay(200);
      digitalWrite(led4,LOW);
      button4.update();
    }

  }


}
