/*
Quest'opera è stata rilasciata con licenza Creative Commons
Attribuzione - Non commerciale -  CC BY-NC-SA
Condividi allo stesso modo 4.0 Internazionale.
Per leggere una copia della licenza visita il sito web
http://creativecommons.org/licenses/by-nc-sa/4.0/.


*/


//This code is the basiligotchi version seen at the maker faire 


//This plant use the Adafruit's cc3000 shield for wifi comunications
//In this plant, we have a different Led matrix, the bicolor adafruit Matrix!
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();



#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>

// These are the interrupt and control pins
#define ADAFRUIT_CC3000_IRQ   3  // MUST be an interrupt pin!
// These can be any two pins
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10
// Use hardware SPI for the remaining pins
// On an UNO, SCK = 13, MISO = 12, and MOSI = 11
Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT,
SPI_CLOCK_DIVIDER); // you can change this clock speed but DI


#define WLAN_SSID       "basiliconet"        // cannot be longer than 32 characters!
#define WLAN_PASS       "password"


// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2

//#define WEBSITE "basilicotchi.3nd.biz"
#define IDLE_TIMEOUT_MS  3000   


/*
To send data to the server, we made an http request to the server, with the values to send inside the url.

*/

char sito[]="yoururl.3nd.biz";  
const unsigned long
connectTimeout  = 10L * 1000L, // Max time to wait for server connection
responseTimeout = 10L * 1000L; // Max time to wait for data from server
unsigned long ip;


#include <dht.h>
#include <types.h>
#include <avr/pgmspace.h>
dht DHT;  //termometro
#define DHT11_PIN 4 //pin
//pin leg RGB
// da invertire probabilmente R e G

const int redPin = 7;
const int greenPin = 9;
const int bluePin = 8;
const int TRIG_PIN = 6; //giallo
const int ECHO_PIN = 2;//verde
const int buzzer = 14;
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



//pin sensori
const int lightSensorPin = A2;
const int terreinSensorPin = A3;


//gestione scritta a scorrimento 


//fine gestione

boolean twitter;
//temp sensor and value
int lastButtonState = LOW;
int buttonState; 
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int ambientSensorValue=0;
int lightSensorValue = 0;
int terreinSensorValue=0;
int temperature=0;
//int B=3975;                  //B value of the thermistor
int umore = 50;
unsigned int tempo = 0;
unsigned int tempoLoop=0;
boolean salutato = false;

int statoDisegno=0;
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
    B00111100                }
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
    B00000000                }
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
    B00111100                                                                                      }
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
    B00000000                                                                                      }
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
    B00000000                                                                                      }
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
    B00000000                                      }
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
    B00000100                                              }
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
    B00100000                                              }
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
    B00000000                                  }
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
    B01000010                                              }
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
    B00000000                                              }
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
    B00000000                                              }
};


int numNote = 8;
int nota[] = {
  261, 294, 330, 349, 392, 440, 495, 528};
//            do    re   mi   fa  sol  la   si   do
int contatoreConnessione=0;
void setup()
{
  Serial.begin(9600);
  matrix.begin(0x70); 
  matrix.setTextWrap(false);   
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
  //wifisetup();
  delay(50);
}

void loop()
{
  leggiTasto();
  controllaSaluto();
  if(tempoLoop%28==0)  //if too speed, the sensor read random values
    scriviSeriale();
  tempoLoop++;
  if(tempoLoop%2==0) //this is for the smile animation
    scegliFaccia();

 // if(contatoreConnessione%550==3)
 //   connessioneTCPAndrea();
//  contatoreConnessione++;
  delay(50);
}





