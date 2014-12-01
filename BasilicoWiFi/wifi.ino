void connessioneTCPAndrea()
{
  Adafruit_CC3000_Client client;
  if ( !cc3000.checkConnected()) {
    cc3000.deleteProfiles();
    //  we don't have something the code needs, so go get it
    cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY);
    //  etc
  }
  client = cc3000.connectTCP(cc3000.IP2U32(217, 194, 13, 202), 80);
  if(client.connected())
  {
    char buffer[65];
    sprintf(buffer,"/insert.aspx?l=%i&idp=2&ut=%i&t=%i&u=%i&ua=%i&salutato=%s",lightSensorValue,terreinSensorValue,temperature,umore,ambientSensorValue,(twitter)?"1":"0");   //this construct the url for the data insert
    twitter=false; 
    client.fastrprint(F("GET "));

    client.fastrprint(buffer);

    client.fastrprint(F(" HTTP/1.1\r\n"));
    client.fastrprint(F("Host: ")); 
    client.fastrprint(sito); 
    client.fastrprint(F("\r\n"));
    client.fastrprint(F("\r\n"));
    unsigned long lastRead = millis();
    while (client.connected() && (millis() - lastRead < IDLE_TIMEOUT_MS)) {
      while (client.available()) {
        char c = client.read();
        //Serial.print(c);
        lastRead = millis();
      }

    }
  }
  client.close();

}

void wifisetup()
{

  // Serial.print("aaa");
  cc3000.begin();
  cc3000.deleteProfiles();
  cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY);
 // Serial.print("connesso");
  // cc3000.getHostByName(sito, &ip);
  // Serial.print(ip);
  //Serial.print("connesso");
}



