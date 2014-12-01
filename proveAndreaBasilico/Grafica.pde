void disegnaGrafica(Pianta p)
{
  image(bg, 0, 0, width*2, height*2);
  imageMode(CENTER);
  image(img, width/2, height*0.16, width*0.66, height*0.33);
  textSize(width*0.05);
  textAlign(CENTER, CENTER);
  fill(98, 107, 249);
  text(p.getName(), width*0.50, height*0.35);

  fill(98, 107, 249);
  //textSize(50);
  //text(p.getName(), width/2-140, 150);
  textSize(width*0.07);
  fill(255, 255, 255);

  textAlign(LEFT, CENTER);
  image(humidityTerrain, width*0.48, height*0.45, width*0.9, height*0.07);
  image(temp, width*0.48, height*0.53, width*0.9, height*0.07);
  image(luminosita, width*0.48, height*0.61, width*0.9, height*0.07);
  image(humidityAmbient, width*0.48, height*0.69, width*0.9, height*0.07);
  //image(plant, width*0.15, height*0.89, height*0.094, height*0.094);
  //image(stat, width*0.48, height*0.89, height*0.094, height*0.094);
  //image(plant, width*0.85, height*0.89, height*0.094, height*0.094);
  text(""+p.getTerrainHumidity()+"%", width*0.68, height*0.45);
  text(""+p.getTemperature()+"°", width*0.68, height*0.53);
  text(""+p.getLight()+"%", width*0.68, height*0.61);
  text(""+p.getAmbientHumidity()+"%", width*0.68, height*0.69);
  text(p.getMood(), width*0.68, height*0.77);

  
  textSize(width*0.07);


  text("Terrain:", width*0.05, height*0.45);  

  text("Temperature:", width*0.05, height*0.53 );

  text("Light:", width*0.05, height*0.61 );


  text("Ambient Humidity:", width*0.05, height*0.69 );

  text("Mood:", width*0.05, height*0.77 );

  textSize(width*0.04);
  textAlign(CENTER, CENTER);
  text(piante.get(0).getName(), width*0.15, height*0.95 );
  text("Stats", width*0.48, height*0.95 );
  text(piante.get(1).getName(), width*0.85, height*0.95 );
  for(Button b:bottoni)
      b.display();
}

