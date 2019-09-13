#ifndef Laser
#define Laser

#include <Arduino.h> // per usare le funzioni di lettura e scrittura di arduino

////////////////////////////////////////////////////////////////////////////////////
// DICHIARAZIONE DI FUNZIONI
////////////////////////////////////////////////////////////////////////////////////
int Sutup_ambiente() ;
int Setup_laser() ;
int Controllo() ;



////////////////////////////////////////////////////////////////////////////////////
// FUNZIONE PER ESEGUIRE IL SETUP DELLA LUCE AMBIENTE 
////////////////////////////////////////////////////////////////////////////////////
int Sutup_ambiente () {
  
   int lum_ambiente_setup_f[10] ;
   int lum_ambiente_f ;
   int lum_ambiente_setup_somma = 0 ;
  
  // Blink del laser e imposto OF
    digitalWrite(PIN_LASER,HIGH);
    delay(300);
    digitalWrite(PIN_LASER,LOW);
    delay(300);
    digitalWrite(PIN_LASER,HIGH);
    delay(300);
    digitalWrite(PIN_LASER,LOW);
    delay(300);

    // prendo le misurazioni 
    for (int i = 0; i<10 ; i++){
      lum_ambiente_setup_f[i]= analogRead(PIN_RES) ; 
     // Serial.println(lum_ambiente_setup_f[i]);
      delay(500);     
      }

    for (int i = 0; i<10 ; i++){
      lum_ambiente_setup_somma = lum_ambiente_setup_somma + lum_ambiente_setup_f[i];
      }  

      lum_ambiente_f = lum_ambiente_setup_somma /10 ;
      //Serial.println(lum_ambiente_f);
      delay(500);

      return lum_ambiente_f ;
  }
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// FUNZIONE PER ESEGUIRE IL SETUP DEL LASER
////////////////////////////////////////////////////////////////////////////////////
int Setup_laser() {

  int lum_laser_setup_f[10] ;
  int lum_laser_f ;
  int lum_laser_setup_somma = 0 ;

  // Blink del laser e imposto su ON
    digitalWrite(PIN_LASER,HIGH);
    delay(300);
    digitalWrite(PIN_LASER,LOW);
    delay(300);
    digitalWrite(PIN_LASER,HIGH);
    delay(300);
    digitalWrite(PIN_LASER,LOW);
    delay(300);
    digitalWrite(PIN_LASER,HIGH);
    delay(300);

    // prendo le misurazioni 
    for (int i = 0; i<10 ; i++){
      lum_laser_setup_f[i]= analogRead(PIN_RES) ; 
      Serial.println(lum_laser_setup_f[i]);
      delay(500);     
      }

    
    for (int i = 0; i<10 ; i++){
      lum_laser_setup_somma = lum_laser_setup_somma + lum_laser_setup_f[i];
      }  
  

      lum_laser_f = lum_laser_setup_somma/10 ;
      Serial.println(lum_laser_f);
      delay(500);  

      return lum_laser_f ;
  }
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// FUNZIONE PER IL CONTROLLO
////////////////////////////////////////////////////////////////////////////////////
int Controllo(  int lum_laser_f, const int soglia_f) {
  
  int lum_varco_f = analogRead(PIN_RES) ;
  int varco_f ;
  
  if (lum_varco_f < lum_laser_f - soglia_f ){
    varco_f = 1 ;
    } else {
      varco_f = 0 ;
      }
return varco_f ;
  
  }
////////////////////////////////////////////////////////////////////////////////////














#endif
