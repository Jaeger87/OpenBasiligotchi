import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.ArrayList;
import java.lang.reflect.Method;
import java.lang.Runnable;


import android.webkit.WebView;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import ketai.net.bluetooth.*;
import ketai.ui.*;
import ketai.net.*;

KetaiList klist;
KetaiBluetooth bt;

String arduinoDevice;
boolean bReleased = true; //no permament sending when finger is tap

boolean isConfiguring = true;
String info = "";

ArrayList devicesDiscovered = new ArrayList();

String prova="*100;50;6;2;58\n";

ArrayList <Pianta> piante=new ArrayList<Pianta>();
ArrayList <Button> bottoni=new ArrayList<Button>();


ExecutorService pool;
boolean invio=true;
int stoptime=0;
PImage img;
PImage bg;
PImage luminosita;
PImage temp;
PImage humidityTerrain;
PImage humidityAmbient;
PImage stat;
PImage plant;
PFont font;
int index=0;
boolean mainMouse=false;
int indexButton=0;
boolean ricevi=true;
int stoptimeRicevi=0;


void setup() {
  imageMode(CENTER);
  orientation(PORTRAIT);
  img = loadImage("bsmussata.png");
  //font = loadFont("Minecraftia-48.vlw");
  luminosita = loadImage("luminosita.png");
  temp = loadImage("temp.png");
  bg = loadImage("bg.jpg");
  humidityTerrain = loadImage("terreno.png");
  humidityAmbient = loadImage("umidAmbient.png");
  stat = loadImage("stat.png");
  plant = loadImage("plant.png");
  bottoni.add(new Button(0, width*0.15, height*0.89, plant, height*0.094));

  bottoni.add(new Button(1, width*0.85, height*0.89, plant, height*0.094));
  bottoni.add(new Button(2, width*0.48, height*0.89, stat, height*0.094));
  //textFont(font);


  pool=Executors.newFixedThreadPool(6);
  piante.add(new Pianta("Basili", 1, true));
  piante.add(new Pianta("Plant 42", 2, false));
  for (int i=0; i<piante.size (); i++)
    pool.submit(new ThreadRiceviDati(piante.get(i)));
  bt.start();
  //at app start select device…
  isConfiguring = true;
}

void draw()
{
  if (isConfiguring)
  {
    ArrayList names;
    klist = new KetaiList(this, bt.getPairedDeviceNames());
    isConfiguring = false;
  } else
    if (piante.get(index).hasBlueTooth())
    if (invio==false&&piante.get(index).getRobaDaInviare())
    {
      invio=true;
      stoptime=millis()+10000;
      // pool.submit(new ThreadRiceviDati(p));
      pool.submit(new ThreadInvioDati(piante.get(index)));
    } else
      if (millis()>stoptime)
      invio=false;
    else
      if (ricevi==false)
    {
      ricevi=true;
      stoptimeRicevi=millis()+10000;
      pool.submit(new ThreadRiceviDati(piante.get(index)));
    } else
      if (millis()>stoptimeRicevi)
      invio=false;
  disegnaGrafica(piante.get(index));
  for (int i=0; i<bottoni.size (); i++)
    if (bottoni.get(i). mousePressed())
    {  
      mainMouse=true;
      indexButton=i;
    }
}

void mouseReleased()
{
  if (mainMouse == true)
    if (bottoni.get(indexButton).mouseOverIt())
      bottoni.get(indexButton).effettoBottoni(indexButton);
  mainMouse=false;
}







void apriWebPage() {


  final Activity activity = (Activity) this;

  activity.runOnUiThread(new Runnable() {
    public void run() {
      WebView webView = new WebView(activity);
      String customHtml = "<html><body><h1>Hello, WebView</h1></body></html>";
      //webView.loadData(customHtml, "text/html", "UTF-8");
      webView.loadUrl("http://yourUrl.com/");
      setContentView(webView);
    }
  }
  );
}

