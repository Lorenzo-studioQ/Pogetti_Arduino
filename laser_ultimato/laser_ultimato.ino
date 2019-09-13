// Sketch del progetto laser

// Definizione di tutti i pin delle periferiche usate 
#define PIN_LASER 13    // pin del laser 
#define PIN_RES A0      // pin della fotoresistenza
#define PIN_LED 12      // pin del led di segnalazione 
#define PIN_BOT 8       // pin del bottone 
#define PIN_PIEZO 7     // pin del piezo 

# include "Laser.h"

// Variabili 

int bot_stato = 0 ;    // variabile dello stato del bottone 
int stato = 0 ;        // varabile dello stato dello sketch 
int varco  ;           // variabile che dice :  1 varco valicato 0 varco non valicato  
int lum_laser ;
int lum_ambiente ;

const int soglia = 50 ;      // soglia di attivazione del varco 


void setup() {
  
  // inizializz la seriale 
  Serial.begin(9600);
  
  // LASER 
  pinMode(PIN_LASER, OUTPUT ); 

  // LED
  pinMode(PIN_LED, OUTPUT );

  // BOTTONE
  pinMode(PIN_BOT, INPUT) ;
  

  
}

void loop() {
  reset:
  /////////////// FASE SETUP ///////////////////////////
  
  // Lettura dello stato del bottone per iniziare il setup 
  bot_stato = digitalRead(8);
  Serial.println(bot_stato);
  
  // se il pulsante è premuto 
  if (bot_stato == HIGH){

    // ON led 
    digitalWrite(PIN_LED,HIGH); 
    
    Serial.println("AVVIO DEL SETUP");
    Serial.println("------------------------");
    delay(20);

    // setto la luminosità  ambiente 
    Serial.println("SETUP DELLA LUMINOSIA' AMBIENTE");
    Serial.println("------------------------");
    delay(20);

    lum_ambiente = Sutup_ambiente() ;

    // Blink di segnalazione
    digitalWrite(PIN_LED,LOW); 
    delay(200);
    digitalWrite(PIN_LED,HIGH); 
    delay(200);
    digitalWrite(PIN_LED,LOW); 
    delay(200);
    digitalWrite(PIN_LED,HIGH); 
    delay(200);
    
    // setto la luminosità  con laser 
    Serial.println("SETUP DELLA LUMINOSIA' con laser");
    Serial.println("------------------------");
    delay(20) ;

    lum_laser = Setup_laser() ;
    
    /*Serial.println("------------------------");
    Serial.println(lum_laser);
    Serial.println(lum_ambiente);
    Serial.println("------------------------");
    */
    
    Serial.println("------------------------");
    Serial.println("FINITO IL SETUP");
    Serial.println("------------------------");

    // finito il setup incremento la variabile stato per passare alla fase controllo 
     stato ++ ; 

     // OFF led 
     digitalWrite(PIN_LED,LOW);
    
  } // chiude if del setup dei parametri 
  

  /////////////// FASE CONTROLLO VARCO ///////////////////////////

  while( stato >=1) {

    // verifico se è stato o meno  valicato il passagio 
    int varco = Controllo(lum_laser, soglia) ;
    Serial.print("stato del varco: ");
    Serial.println(varco);

    // discrimino i compostatmenti : VALICATO 1 NON VALICAO 0
    
    if (varco == 1){
      Serial.println("------------------------");
      Serial.println("PASSAGIO");
      Serial.println("------------------------");
      // ON led
      digitalWrite(PIN_LED,HIGH);
      // ON piezo
      tone(PIN_PIEZO,200,100);
      delay(200);
      tone(PIN_PIEZO,200,100);
      delay(200);
      tone(PIN_PIEZO,200,100);
      delay(200); 
      
      } else if (varco == 0){
        Serial.println("------------------------");
        Serial.println(" NO PASSAGIO");
        Serial.println("------------------------");
        // OFF led
        digitalWrite(PIN_LED,LOW);

        }

//////// RESET MANUALE DEI DATI AMBIENTALI /////////////

     // leggo se viene ripremuto il tasto 
      bot_stato = digitalRead(8);
      
      if (bot_stato==HIGH ){
        stato = 0 ;
        goto reset;
        }
    
    } // chiude il while 
  
} // chiude il loop 






























  
  


  
  
