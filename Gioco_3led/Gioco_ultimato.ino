////// ARDUINO ///////////
int pin_led[3] = {8,9,10}; // porte dei led: 8 giallo 9 verde 10 rosso 
int seq_acc[3];
char colori_A[3];
////// GIOCATORE ///////////
int pin_bot[3] = {11, 12, 13} ; // porte dei bottoni: 11 giallo 12 verde 13 rosso
int n_t = 3; // nummero di tentativi 
int p = 0 ; // posizine del colore del bottone nella seguenza digitata
int buttonState[3] ; // dice lo stato dei bottoni  LOW non premuto HIGH PREMUTO
char color[3]={ 'N', 'N', 'N' }; // seguenza colori di defolt
int t ; // nummero del tentativo 
int y=0;
///// VERIFICA ///
int v = 0 ; //  0 non coretta 1 coretta
////// PIEZO ////
int pin_piezo = 7 ;
///// RGB /////// 
int pin_RGB[3] = { 3, 6 , 5}; // pin dei led RGB
int seq_rosso[3] = {255 , 0 , 0 }; // seguenza dei led RGB
int seq_verde[3] = {0 , 255, 0 }; // seguenza dei led RGB
int seq_spento[3] = {0 , 0 ,0}; // seguenza dei led RGB
int start = 0 ; // variabile per iniziare il gioco 

void setup() {
  
  // rinizio del gioco  dopo aver vinto o perso 
  inizio : 

  ////// ARDUINO ///////////
  
  // inizializzo i pin dei led
  for (int i=0; i<3; i++)
  {
    pinMode(pin_led[i],OUTPUT);
    }

    // izializzo i pin dei bottoni come input
    for ( int i = 0 ; i < sizeof(pin_bot)/sizeof(int) ; i++ ){
    pinMode(pin_bot[i], INPUT);
    }

    // inizializzo la porta seriale  
    Serial.begin(9600); 
    Serial.println("Il gioco inizierà tenedo premuto un qualsiasi bottone");

    // seguenza di attesa di arduino 
    while (start <= 0){
      
      for ( int i = 0; i < sizeof(pin_led)/sizeof(int); i++){
        
        digitalWrite(pin_led[i],HIGH);
        delay(200);
        digitalWrite(pin_led[i],LOW);
        delay(200);
        
       } // chiude il for bel il blink a scala 
       
      if (digitalRead(11) == HIGH || digitalRead(12) == HIGH || digitalRead(13) == HIGH ) {
        
        start ++ ;
        
      } // chiude il for per incrementare start se premuto il bottone 
      
    } // chiude il while per l'inizio

    Serial.println("Il gioco INIZIA");
    delay(500);

    // inizializzo i numeri casuali
  randomSeed(analogRead(0));

  // genero la seguenza casuale di accenzione led
  for (int i=0; i<sizeof(seq_acc)/sizeof(int); i++)
  {
    seq_acc[i] = random(8,11);
    delay(500);
    }
    
  // accenzione led secondo la seguenza seq_acc
  for (int i=0; i<sizeof(seq_acc)/sizeof(int); i++)
  {
    digitalWrite(seq_acc[i],HIGH);
    delay(300);
    digitalWrite(seq_acc[i],LOW);
    delay(300);
    }
    
  // spegnimento dei led
 for (int i=0; i<3; i++)
 {
   digitalWrite(pin_led[i],LOW);
  }
    
///// GENERICA //////

// sequenza da attivare se si vuole vedere la regenza di pin eseguita da arduino

// stapo la sequenza eseguita da arduino
  Serial.println("Sequenza eseguita da Arduino IN TERMINI DI PIN:");
   for (int  i=0; i<sizeof(seq_acc)/sizeof(int); i++)
   {
   Serial.print(seq_acc[i]);
     if(i<sizeof(seq_acc)/sizeof(int)-1){
   Serial.print("_");
     } else{
      Serial.println(".");
      }
   }
// seguenza da attivare se si vuole stampata la seguenza in termini di colori dei led

// conversione in lettere della seguenza di pin 
for (int  i=0; i<sizeof(seq_acc)/sizeof(int); i++){
  if(seq_acc[i]==8){
    colori_A[i]='G';
    }
    if(seq_acc[i]==9){
    colori_A[i]='V';
    }
    if(seq_acc[i]==10){
    colori_A[i]='R';
    }
  
  }
// stapo la sequenza eseguita da arduino
  Serial.println("Sequenza eseguita da Arduino IN TERMINI DI COLORI:");
   for (int  i=0; i<sizeof(colori_A)/sizeof(char); i++) 
   {
   Serial.print(colori_A[i]);
     if(i<sizeof(colori_A)/sizeof(char)-1){
   Serial.print("_");
     }else{
      Serial.println(".");
      }
   }
  


/// GIOCATORE ///

// segnalo inizio del gioco 
Serial.println("Digitare la seguenza di colori premendo i bottoni ! ");
Serial.print("ricordati che hai  ");
Serial.print(n_t);
Serial.println(" tentativi");

// inizio della digitazione delle serie 
for (int i = 0 ; i < n_t ; i++ ){
  
  // segnalo il nummero del tentativo 
  Serial.print("Sei al tentativo numero: ") ;
  t = i + 1 ;
  Serial.println( t );

  // prima posizione della seguenza 
   while ( p <= 0 ){ 
    
    for ( int i = 0 ; i < sizeof(pin_bot)/sizeof(int) ; i++){
      
      buttonState[i] = digitalRead(pin_bot[i]);
      
      // colore giallo 
      if (buttonState[i] == HIGH && i == 0 ) {
        color[p] = 'G' ;
        delay(200);
        p++ ;
      } // chiude il if sul giallo 
      // colore verde 
      if (buttonState[i] == HIGH && i == 1 ) {
        color[p] = 'V' ;
        delay(200);
        p++ ;
      } // chiude il if sul verde 
      // colore Rosso
      if (buttonState[i] == HIGH && i == 2 ) {
        color[p] = 'R' ;
        delay(200);
        p++ ;
      } // chiude il if sul rosso 
      
      } // chiude il for sui bottoni
     
    } // chiude il while sulla prima posizione della seguenza posizione 0 


//seconda posizione della seguenza 

delay(200);

while ( p <= 1 ){ 
    
    for ( int i = 0 ; i < sizeof(pin_bot)/sizeof(int) ; i++){
      
      buttonState[i] = digitalRead(pin_bot[i]);
      
      // colore giallo 
      if (buttonState[i] == HIGH && i == 0 ) {
        color[p] = 'G' ;
        delay(200);
        p++ ;
      } // chiude il if sul giallo 
      // colore verde 
      if (buttonState[i] == HIGH && i == 1 ) {
        color[p] = 'V' ;
        delay(200);
        p++ ;
      } // chiude il if sul verde 
      // colore Rosso
      if (buttonState[i] == HIGH && i == 2 ) {
        color[p] = 'R' ;
        delay(200);
        p++ ;
      } // chiude il if sul rosso 
      
      } // chiude il for sui bottoni
     
    } // chiude il while sulla seconda posizione della seguenza posizione 1

    delay(200);
    // terza della seguenza 

while ( p <= 2 ){ 
    
    for ( int i = 0 ; i < sizeof(pin_bot)/sizeof(int) ; i++){
      
      buttonState[i] = digitalRead(pin_bot[i]);
      
      // colore giallo 
      if (buttonState[i] == HIGH && i == 0 ) {
        color[p] = 'G' ;
        delay(200);
        p++ ;
      } // chiude il if sul giallo 
      // colore verde 
      if (buttonState[i] == HIGH && i == 1 ) {
        color[p] = 'V' ;
        delay(200);
        p++ ;
      } // chiude il if sul verde 
      // colore Rosso
      if (buttonState[i] == HIGH && i == 2 ) {
        color[p] = 'R' ;
        delay(200);
        p++ ;
      } // chiude il if sul rosso 
      
      } // chiude il for sui bottoni
     
    } // chiude il while sulla terza posizione della seguenza posizione 2

    // finita la genesi della sequenza verifico che coincide con arduino 
    if (color[0] == colori_A[0] && color[1] == colori_A[1] && color[2] == colori_A[2]){
      v = 1 ;
      } else {
        v = 0 ;
        }
        // consegenze della vittoria e della sconfitta 
        
        // VITTORIA
        if (v == 1 ){
      
      Serial.println("HAI VINTO") ;
      // led RGB
      for ( int i = 0 ; i < sizeof(pin_RGB)/sizeof(int) ; i++){
        analogWrite(pin_RGB[i], seq_verde[i]);
        }
        delay(700);
        for ( int i = 0 ; i < sizeof(pin_RGB)/sizeof(int) ; i++){
        analogWrite(pin_RGB[i], seq_spento[i]);
        }
        
      
      // musica vittoria
      tone(pin_piezo,1000,100);
      delay(200);
      tone(pin_piezo,1000,100);
      delay(200);
      tone(pin_piezo,1000,100);
      delay(200);
      
      // rimposto la seguenza si defolt 
        for ( int i = 0 ; i < sizeof(color)/sizeof(char) ; i++ ){
          color[i] = 'N' ;
          
          }// chiude il for sul restore della seguenza

          // rimetto p a zero 
          p = 0 ;

          // rimetto stato a zero 
          start = 0;
          
          // rimetto LOW bottonState
          for ( int i = 0 ; i < sizeof(buttonState[3])/sizeof(int) ; i++ ){
          buttonState[i] = LOW ;
          // restor variabile sulla vittoria 
          v = 0 ;

          
          }// chiude il for sul restore dello stato dei bottoni 

          
      // rimando al inizio 
      goto fine;

      
      }

      else {
        Serial.println("HAI PERSO");

        // led RGB
      for ( int i = 0 ; i < sizeof(pin_RGB)/sizeof(int) ; i++){
        analogWrite(pin_RGB[i], seq_rosso[i]);
        }
        delay(700);
        for ( int i = 0 ; i < sizeof(pin_RGB)/sizeof(int) ; i++){
        analogWrite(pin_RGB[i], seq_spento[i]);
        }
        

        // musica sconfitta 
        tone(pin_piezo,100,100);
        delay(200);
        tone(pin_piezo,100,100);
        delay(200);
        tone(pin_piezo,100,100);
        delay(200);

        // rimposto la seguenza si defolt 
        for ( int i = 0 ; i < sizeof(color)/sizeof(char) ; i++ ){
          color[i] = 'N' ;
          
          }// chiude il for sul restore della seguenza

          // rimetto p a zero 
          p = 0 ;
          // rimetto stato a zero 
          start = 0;
          // rimetto LOW bottonState
          for ( int i = 0 ; i < sizeof(buttonState[3])/sizeof(int) ; i++ ){
          buttonState[i] = LOW ;
          
          }// chiude il for sul restore dello stato dei bottoni 

          
        } // chiude else della sconfitta 



  } // chiude il for dei tentativi 
  fine :
  goto inizio  ;


  
} // chiude setup



void loop() {
  // put your main code here, to run repeatedly:

}
