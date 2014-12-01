//this read the button for print the senosor values in the matrix

void leggiTasto()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        statoDisegno=0;
        char buffer[6];
        String appoggio="L="+String(lightSensorValue)+"% T="+temperature+" TH="+String(terreinSensorValue)+"% AH="+dtostrf(ambientSensorValue, 1, 2, buffer)+" M="+String(umore);

        for (int x=4; x>=-194; x--) {
          /*
           matrix.setCursor(0,0);  
           matrix.print(" ");
           matrix.write();
           */
          clearMatrix();
          matrix.setCursor(x,0);
          matrix.print(appoggio);

          matrix.write();
          delay(90);
        }

      }
    }
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}




