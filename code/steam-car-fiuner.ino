#include <Ultrasonic.h>

Ultrasonic ultrasonido (12, 13); //Pin Trigger y echo

int var1 = 3;       //Pin del Modulo L298N Input1
int var2 = 4;       //Pin del Modulo L298N Input2
int var3 = 7;       //Pin del Modulo L298N Input3
int var4 = 8;       //Pin del Modulo L298N Input4
int ena = 5;        //Variable de velocidad
int enb = 6;        //Veriable de velocidad



void adelante();      //Funcion para activar var2 y var3
void atras();         //Funcion para activar var1 y var4
void derecha();       //Funcion para activar var1
void izquierda();     //Funcion para activar var4
void distancia();     //Funcion para poder controlar el ultrasonido

void velocidad ();    //Funcion para controlar ena y enb

void setup() {

  pinMode (var1, OUTPUT);   //Declaracion del pin var1
  pinMode (var2, OUTPUT);   //Declaracion del pin var2
  pinMode (var3, OUTPUT);   //Declaracion del pin var3
  pinMode (var4, OUTPUT);   //Declaracion del pin var4
  pinMode (ena, OUTPUT);    //Declaracion para el motor derecho
  pinMode (enb, OUTPUT);    //Declaracion para el motor izquierdo

}


void loop() {
  distancia();
}

void distancia() {

  velocidad ();
  adelante();

  if (ultrasonido.Ranging(CM) < 10) {
    atras();
    delay(700);
    izquierda();
    delay(700);
  }
}





void derecha() {

  digitalWrite(var1, HIGH);   
  digitalWrite(var2, LOW);
  digitalWrite(var3, LOW);
  digitalWrite(var4, LOW);

}

void izquierda() {

  digitalWrite(var1, LOW);
  digitalWrite(var2, LOW);
  digitalWrite(var3, LOW);
  digitalWrite(var4, HIGH);

}

void adelante() {
  digitalWrite(var1, LOW);
  digitalWrite(var2, HIGH);
  digitalWrite(var3, HIGH);
  digitalWrite(var4, LOW);


}


void atras() {
  digitalWrite(var1, HIGH);
  digitalWrite(var2, LOW);
  digitalWrite(var3, LOW);
  digitalWrite(var4, HIGH);


}
void velocidad () {
  analogWrite(ena, 100); //Velocidad motor derecho
  analogWrite(enb, 90); //Velocidad motor izquierdo

}
