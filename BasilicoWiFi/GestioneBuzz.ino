
void buzz()
{

  for (int i = 0; i < numNote; i++)
  {
    tone(buzzer, nota[i]);
    matrix.clear();
    matrix.setRotation(i+1);//this works cause the notes are a multiple of 4
    switch (statoUmore)
    {
    case ENTUSIASTA:
      {
        matrix.drawBitmap(0, 0, entusiasta[statoDisegno], 8, 8, LED_GREEN);
        break;
      }
    case FELICE:
      {
        matrix.drawBitmap(0, 0, felice[statoDisegno], 8, 8, LED_GREEN);
        break;
      }
    case QUASIFELICE:
      {
        matrix.drawBitmap(0, 0, quasifelice[statoDisegno], 8, 8, LED_YELLOW);
        break;
      }
    case NORMALE:
      {
        matrix.drawBitmap(0, 0, normale[statoDisegno], 8, 8, LED_YELLOW);
        break;
      }
    case TRISTE:
      {
        matrix.drawBitmap(0, 0, triste[statoDisegno], 8, 8, LED_RED);
        break;
      }
    case INCAZZATO:
      {
        matrix.drawBitmap(0, 0, incazzato[statoDisegno], 8, 8, LED_RED); 
        break;
      }
    } 

    matrix.writeDisplay();
    
    
    delay(200);
  }
  noTone(buzzer);  

}

/*this check if the timeout for the hello is done and if something is in front of the buzzer
in case of yes the hello starts and all the values related is set
*/

void controllaSaluto()
{
  if(salutato == true)
  { 
    tempo+= 1;
    if(tempo<0)
      tempo=0;
  }
  if(tempo > 120&&salutato==true)
  {
    salutato = false;
    umore -= 10; 
  }



  if(salutato == false&&saluto()==true)
  {
    buzz();
    salutato = true;
    twitter=true;
    umore+=10;
    tempo=0;
  }


}

/*
this check if something is in front of the ultrasoundsensor
*/

boolean saluto()
{

  long duration, distanceCm, distanceIn;
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN,HIGH);

  // convert the time into a distance
  distanceCm = duration / 29.1 / 2 ;
  return distanceCm<=10&&distanceCm>0;

}


