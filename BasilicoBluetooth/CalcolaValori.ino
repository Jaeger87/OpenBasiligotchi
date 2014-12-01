//Write the Arduino Serial to comunicate data via bluetooth

void scriviSeriale()
{
  aggiornaValori();
  //  Serial.print("ut:");
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
  // *  umidità terreno ; temperatura ; luce; umore ; umidità ambiente \n
}

//this function read the sensors

void aggiornaValori()
{
  DHT.read11(DHT11_PIN);
  ambientSensorValue=DHT.humidity;
  terreinSensorValue = terreinSensorValue = int(map(analogRead(terreinSensorPin),0,1023,0,100));
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








