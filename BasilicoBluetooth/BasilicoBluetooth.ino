/*
Quest'opera è stata rilasciata con licenza Creative Commons
Attribuzione - Non commerciale -  CC BY-NC-SA
Condividi allo stesso modo 4.0 Internazionale.
Per leggere una copia della licenza visita il sito web
http://creativecommons.org/licenses/by-nc-sa/4.0/.


*/


//This code is the basiligotchi version seen at the maker faire 
#include <dht.h>
#include <math.h>
#include "types.h"
#include <avr/pgmspace.h>
dht DHT;  //termometro
#define DHT11_PIN 4 //pin


#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

//caricamento librerie


const int redPin = 3;
const int greenPin = 9;
const int bluePin = 8;
const int TRIG_PIN = 6;
const int ECHO_PIN = 7;
const int buzzer = 5;
const int buttonPin = A1;

/*
Questi valori servono per l'algoritmo di calcolo dell'umore della pianta, in pratica funziona come una gaussiana:

____/\____  dove max e min indicano i valori dove la curva inizia e finisce

These values ​​are used for the calculation algorithm mood of the plant,  in practice functions as a Gaussian

____/\____  where max and min indicate where the curve bengin and finish
*/
const int maxTerrain=140;
const int minTerrain=24;
const int maxTemperature=48;
const int minTemperature=9;
const int maxAmbient=150;
const int minAmbient=35;
// pin matrice led
const int Max7219_pinCLK=13;
const int Max7219_pinCS = 10;
const int Max7219_pinDIN =11;

//pin sensori
const int lightSensorPin = A2;
const int terreinSensorPin = A0;



//gestione scritta a scorrimento 
const long scrollDelay = 75;   // adjust scrolling speed

unsigned long bufferLong [14] = {
  0};


Max72xxPanel matrix = Max72xxPanel(Max7219_pinCS, 1, 1);
//fine gestione




boolean twitter=false;


//temp sensor and value
int lastButtonState = LOW;
int buttonState; 


long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int ambientSensorValue=0;
int lightSensorValue = 0;
int terreinSensorValue=0;
int temperature;
//int B=3975;                  //B value of the thermistor

int umore = 50;
int tempo = 0;
int tempoLoop=0;
boolean salutato = false;

int statoDisegno=0;
int millisdisegno=0;

//Smile management
#include "types.h"

enum StatiUmoreEnum {
  ENTUSIASTA,FELICE,QUASIFELICE,NORMALE,TRISTE,INCAZZATO};
  
  
StatiUmoreEnum statoUmore=QUASIFELICE;
StatiUmoreEnum vecchioStatoUmore=INCAZZATO;

//faccine
static const uint8_t PROGMEM entusiasta[2][8]={
  {
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B11111111,
    B01111110,
    B00111100              }
  ,
  //smile sorridente giu


  {
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B11111111,
    B01111110,
    B00111100,
    B00000000              }
  ,


};
static const uint8_t PROGMEM felice[3][8]={
  {
    B00000000,
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B01000010,
    B00111100                                                                                    }
  ,
  //smile sorridente giu


  {
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B01000010,
    B00111100,
    B00000000                                                                                    }
  ,
  //smile sorridente normale



  {
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B01000010,
    B00111100,
    B00000000,
    B00000000                                                                                    }
};



static const uint8_t PROGMEM quasifelice[1][8]={
  {
    B00000000,
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B01111110,
    B00000000                                    }
};
static const uint8_t PROGMEM normale[2][8]={
  {
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00100000,
    B00010000,
    B00001000,
    B00000100                                            }
  ,
  //smile obliquo dx


  {
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000100,
    B00001000,
    B00010000,
    B00100000                                            }
};



static const uint8_t PROGMEM triste[1][8]={
  {
    B00000000,
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00111100,
    B01000010,
    B00000000                                }
};
static const uint8_t PROGMEM incazzato[3][8]={ 
  {
    B00000000,
    B00000000,
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00111100,
    B01000010                                            }
  ,
  //smile triste giu

  {
    B00000000,
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00111100,
    B01000010,
    B00000000                                            }
  ,
  //smile triste normale


  {
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B00111100,
    B01000010,
    B00000000                                            }
};


int numNote = 8;
int nota[] = {
  261, 294, 330, 349, 392, 440, 495, 528};
//            do    re   mi   fa  sol  la   si   do
int testFaccine=0;


void setup()
{
  Serial.begin(9600);  

  //sensori
  pinMode(lightSensorPin, INPUT);  
  pinMode(terreinSensorPin, INPUT);

  //buzz
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  //led
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(Max7219_pinCLK,OUTPUT);
  pinMode(Max7219_pinCS,OUTPUT);
  pinMode(Max7219_pinDIN,OUTPUT);
  matrix.setIntensity(4);
  matrix.setTextSize(1);
  matrix.setTextWrap(false); 


  delay(50);

}

void loop()
{
  leggiTasto();
  controllaSaluto();

  if(tempoLoop%6==0)   //if too speed, the sensor read random values
    scriviSeriale();

  tempoLoop++;

  if(tempoLoop%2==0)    //this is for the smile animation
  {
    setStatoUmore(umore); 
    scegliFaccia();

  }

  delay(50);
}

