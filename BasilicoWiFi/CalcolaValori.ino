

void scriviSeriale()
{
  aggiornaValori();
  setStatoUmore(umore);
  Serial.print( "*" ); 
  Serial.print( terreinSensorValue ); 
  Serial.print(";");
  //Serial.print("t:");
  Serial.print( temperature );
  Serial.print(";");
  //  Serial.print("l:");
  Serial.print( lightSensorValue );
  Serial.print(";");
  //Serial.print("u:");
  Serial.print( umore );
  Serial.print(";");
  //Serial.print("a:");
  Serial.print( ambientSensorValue );
  Serial.print(";");
  Serial.print( twitter );
  Serial.print("\n");
  twitter=false;
     
  
}

//this function read the sensors

void aggiornaValori()
{
  DHT.read11(DHT11_PIN);
  ambientSensorValue=DHT.humidity;
  terreinSensorValue = terreinSensorValue = int(map(analogRead(terreinSensorPin),1023,0,0,100));
  terreinSensorValue=77;
  temperature=DHT.temperature;
  lightSensorValue = int(map(analogRead(lightSensorPin),0,1023,0,100));
  umore = calcolaUmore();
}

/*
I have to admit that this function is still buggy, the mood calculation is not good as it should, sorry :(
*/

int calcolaUmore()
{
  double us = 50; //umore standard
  //valuta l'umidità
  if(salutato)us+=10;

  if(terreinSensorValue>minTerrain&&terreinSensorValue<maxTerrain)
  {
    us+=calcolaSingoloValoreUmore(terreinSensorValue,minTerrain,maxTerrain);
  } 
  else
    us-=12;
  if(temperature>minTemperature&&temperature<maxTemperature)
  {
    us+=calcolaSingoloValoreUmore(temperature,minTemperature,maxTemperature);

  }
  else
    us-=12;

  if(ambientSensorValue>minAmbient&&ambientSensorValue<maxAmbient)
    us+=calcolaSingoloValoreUmore(ambientSensorValue,minAmbient,maxAmbient);
  else
    us-=12;
  if(lightSensorPin>80)
    us+=12;
else
  us+=map(lightSensorPin,0,80,-12,12);
//valuta la luminosità

return int(us);
}

/*  Vecchio calcolo sensore cinesata
 float calcolaTemperatura(float t)
 {
 float temp = t * 0.48828125;
 return temp;
 }
 
 */

double calcolaSingoloValoreUmore(int sensore,int minimo,int massimo)
{
  if(sensore>massimo/2)
    return map(sensore,(massimo+minimo)/2,massimo,11,-10);
  return (sensore,minimo,(massimo+minimo)/2,-10,11);
}

//this function set the mood of the plant and everything related to the mood


void setStatoUmore(int u)
{ 
  vecchioStatoUmore=statoUmore;
  
  matrix.setTextColor(LED_RED);
  if(u>=0 && u<=16) 
  {
    statoUmore=INCAZZATO;
    return impostaLed(127,0,155);
  }
  if(u>=17 && u<=32) 
  {
    statoUmore=TRISTE;
    return impostaLed(255,50,0);
  }
  matrix.setTextColor(LED_YELLOW);
  if(u>=33 && u<=47) 
  {
    statoUmore=NORMALE;
    return impostaLed(255,200,0);
  }
  if(u>=48 && u<=64) 
  {
    statoUmore=QUASIFELICE;
    return impostaLed(150,255,100);
  }
  matrix.setTextColor(LED_GREEN);
  if(u>=65 && u<=81)
  {
    statoUmore=FELICE;
    return impostaLed(0,255,0);
  }  
  if(u>=82 && u<=99)
  {
    statoUmore=ENTUSIASTA; 
    return impostaLed(0,0,255);
  }



}



