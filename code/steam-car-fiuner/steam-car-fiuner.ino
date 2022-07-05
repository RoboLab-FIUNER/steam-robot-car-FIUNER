// Script de control de STEAM car FIUNER
// Este ejemplo es el codigo base del robot autonomo esquiva-obstaculo basado en sensor HC-SR04
// Ultrasonic library https://github.com/ErickSimoes/Ultrasonic (available to download from Arduino IDE library manager)
//  - -- 2022 -- -

#include "Ultrasonic.h"

// Pines sensor de ultrasonido
#define PIN_TRIGGER 12
#define PIN_ECHO 13


// Pines control motor-A
#define MOT_A_1 3 //Pin del Modulo L298N Input1
#define MOT_A_2 4 //Pin del Modulo L298N Input2

// Pines control motor B
#define MOT_B_1 7 //Pin del Modulo L298N Input3
#define MOT_B_2  8 //Pin del Modulo L298N Input4

// Pines reguladores de velocidad. Control por PWM.
#define MOT_A_en 5
#define MOT_B_en 6

// Valores de PWM (0 - 255).
#define VEL_A 150
#define VEL_B 150

//Objeto ultrasonido y variables
Ultrasonic ultrasonic (PIN_TRIGGER, PIN_ECHO);
  
const int distance_max = 10 // distancia de detección de obstaculo
const int time_maniover = 500; // tiempo de duración de maniobra de esquivo


// funciones de dirrecion del auto
void forward();      
void reverse();         
void right();     
void left();    


void distance();     //Funcion para poder controlar el ultrasonido y decidir
void set_velocity ();    //Funcion para controlar ena y enb

void setup() {
 //config pines control motores
  pinMode (MOT_A_1, OUTPUT);   
  pinMode (MOT_A_2, OUTPUT);  
  pinMode (MOT_B_1, OUTPUT);  
  pinMode (MOT_B_2, OUTPUT);   
  pinMode (MOT_A_en, OUTPUT);    
  pinMode (MOT_B_en, OUTPUT);    
  
// seteo de velocidad
  set_velocity();
  
}


void loop() {
  
  forward();
  distance();

}

void distance() {
// Funcion que detecta obtaculos y esquiva.
  if (ultrasonic.read(CM) < distance_max) {
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


void set_velocity () {
  //Controlling speed (0 = off and 255 = max speed):    
  analogWrite(MOT_A_en, VEL_A); //Velocidad motor derecho
  analogWrite(MOT_B_en, VEL_B); //Velocidad motor izquierdo

}
