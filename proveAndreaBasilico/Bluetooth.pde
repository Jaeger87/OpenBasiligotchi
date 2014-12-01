void onKetaiListSelection(KetaiList klist) {
  String selection = klist.getSelection();
  bt.connectToDeviceByName(selection);
  arduinoDevice=selection;
  println(arduinoDevice);
  //dispose of list for now
  klist = null;
}

void onBluetoothDataEvent(String who, byte[] data) {
  if (isConfiguring)
    return;
  //received

  info += new String(data);
  //clean if string to long
  int header_location=info.indexOf("*");
  int footer_location=info.indexOf("\n");

  if (info.length() > 120)
    info = "";
  if (header_location >  -1)
  {

    if (footer_location > 0)
    {
      if (header_location < footer_location)
      {
        int count=0;
        
        String appoggio=info.substring(1, info.length()-1);
        /*for (int i=0; i<appoggio.length(); i++)
          if (appoggio.charAt(i)==';')
            count++;
        if (count==5)
        {*/
          try {  
            println(appoggio);
            String[] valori=appoggio.split(";");
            piante.get(0).setTerrainHumidity(Integer.parseInt(valori[0]));
            piante.get(0).setTemperature(Integer.parseInt(valori[1]));
            piante.get(0).setLight(Integer.parseInt(valori[2]));
            piante.get(0).setMood(Integer.parseInt(valori[3]));
            piante.get(0).setAmbientHumidity(Integer.parseInt(valori[4]));
            piante.get(0).setsalutato(Integer.parseInt(valori[5]));
            piante.get(0).attivaInvio();
          }
          catch(Exception e) {
          }
        //}
      }
    }
  }
}

void onCreate(Bundle savedInstanceState) {
  super.onCreate(savedInstanceState);
  bt = new KetaiBluetooth(this);
}

void onActivityResult(int requestCode, int resultCode, Intent data) {
  bt.onActivityResult(requestCode, resultCode, data);
}

