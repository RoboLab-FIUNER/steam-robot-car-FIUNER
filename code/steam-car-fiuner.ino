// Script de control de STEAM car FIUNER
// Este ejemplo es el codigo base del robot autonomo esquiva-obstaculo basado en sensor HC-SR04
// 2022

#include <Ultrasonic.h>

// Pines sensor de ultrasonido
#define PIN_TRIGGER 12
#define PIN_ECHO 13


// Pines control motor-A
#define MOT_A_1 3
#define MOT_A_2 4

// Pines control motor B
#define MOT_B_1 7
#define MOT_B_2  8

// Pines reguladores de velocidad. Control por PWM.
#define MOT_A_en 5
#define MOT_B_en 6


Ultrasonic ultrasonido (PIN_TRIGGER, PIN_ECHO); 

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


void distance();     //Funcion para poder controlar el ultrasonido y decidir
void velocity ();    //Funcion para controlar ena y enb

void setup() {

  pinMode (MOT_A_1, OUTPUT);   //Declaracion del pin var1
  pinMode (MOT_A_2, OUTPUT);   //Declaracion del pin var2
  pinMode (MOT_B_1, OUTPUT);   //Declaracion del pin var3
  pinMode (MOT_B_2, OUTPUT);   //Declaracion del pin var4
  pinMode (MOT_A_en, OUTPUT);    //Declaracion para el motor derecho
  pinMode (MOT_B_en, OUTPUT);    //Declaracion para el motor izquierdo
  
  int Vel_a = 100 ;
  int Vel_b = 80 ;
  set_velocity();
  
  const int distance_max = 10;
  const int time_maniover = 500;

}


void loop() {
  forward();
  distance();
}

void distance() {

  if (ultrasonido.Ranging(CM) < distance_max) {
    stop();
    reverse();
    delay(time_maniover);
    left();
    delay(time_maniover);
  }
  
}


void right() {

  digitalWrite(MOT_A_1, HIGH);   
  digitalWrite(MOT_A_2, LOW);
  digitalWrite(MOT_B_1, LOW);
  digitalWrite(MOT_B_2, LOW);

}

void left() {

  digitalWrite(MOT_A_1, LOW);
  digitalWrite(MOT_A_2, LOW);
  digitalWrite(MOT_B_1, LOW);
  digitalWrite(MOT_B_2, HIGH);

}

void forward() {
  digitalWrite(MOT_A_1, LOW);
  digitalWrite(MOT_A_2, HIGH);
  digitalWrite(MOT_B_1, HIGH);
  digitalWrite(MOT_B_2, LOW);


}


void reverse() {
  
  digitalWrite(MOT_A_1, HIGH);
  digitalWrite(MOT_A_2, LOW);
  digitalWrite(MOT_B_1, LOW);
  digitalWrite(MOT_B_2, HIGH);
  
}

void stop() {

  digitalWrite(MOT_A_1, LOW);
  digitalWrite(MOT_A_2, LOW);
  digitalWrite(MOT_B_1, LOW);
  digitalWrite(MOT_B_2, LOW);
  
}


void set_velocity (Vel_a, Vel_b) {
  //Controlling speed (0 = off and 255 = max speed):    
  analogWrite(MOT_A_en, Vel_a); //Velocidad motor derecho
  analogWrite(MOT_B_en, Vel_b); //Velocidad motor izquierdo

}
