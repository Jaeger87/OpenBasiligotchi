//this read the button for print the senosor values in the matrix


void leggiTasto()
{
// read the state of the switch into a local variable:
  int reading = analogRead(buttonPin);
  
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:  
/*  // If the switch changed, due to noise or pressing:
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
*/
      // only toggle the LED if the new button state is HIGH
      if (reading > 800)
      {
        statoDisegno=0;
        char appoggio[46];
        sprintf(appoggio,"L=%i T=%i TH=%i AH=%i M=%i",lightSensorValue,temperature,terreinSensorValue,ambientSensorValue,umore);
        
        for (int x=4; x>=-194; x--) {
          matrix.clear();
          matrix.setCursor(x,0);
          matrix.print(appoggio);

          matrix.writeDisplay();
          delay(90);
          
      }
      
    }
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  //lastButtonState = reading;

/*
}

}
*/
