public class Pianta
{
  private int ambientHumidity=0; //Pressione
  private int terrainHumidity=0; //Umidità
  private int temperature=0;
  private int light=0;
  private String name;
  private int mood=0;
  private int idPianta;
  private boolean bluetooth;
  private boolean robaDaInviare=false;
  private int saluto=0;
  public Pianta(String name, int idPianta,boolean bluetooth)
  {
    this.name=name;
    this.idPianta=idPianta;
    this.bluetooth=bluetooth;
  }
  public boolean hasBlueTooth()
  {
    return bluetooth;
    }
  public boolean getRobaDaInviare()
  {
    return robaDaInviare;
    }
  public void attivaInvio()
  {
    robaDaInviare=true;
    }
  public int getTerrainHumidity()
  {
    return terrainHumidity;
  }
  
    public int getAmbientHumidity()
  {
    return ambientHumidity;
  }
  
  public int getTemperature()
  {
    return temperature;
  }
  public int getIdPianta()
  {
    return idPianta;
    }
  public int getLight()
  {
    return light;
  }
  public String getName()
  {
    return name;
  }
  public int getMood()
  {
    return mood;
  }
  
  public void setTemperature(int temperature)
  {
    this.temperature=temperature;
  }
  public void setLight(int light)
  {
    this.light=light;
  }
  public void setMood(int mood)
  {
    this.mood=mood;
  }
    public void setTerrainHumidity(int terrainHumidity)
  {
    this.terrainHumidity=terrainHumidity;
  }
      public void setAmbientHumidity(int ambientHumidity)
  {
    this.ambientHumidity=ambientHumidity;
  }

  public void setsalutato(int salutato)
  {
      this.saluto=salutato;
  }
  
  
  public String createSenderLink()
  {
    robaDaInviare=false;
    return "http://yourUrl.com/insert.aspx?l="+light+"&idp="+idPianta+"&ut="+terrainHumidity+"&t="+temperature+"&u="+mood+"&ua="+ambientHumidity+"&salutato="+saluto;
  }
    public String createReceiveLink()
  {
    return "http://yourUrl.com/Stats.aspx?type=last_results&idp="+idPianta+"&top=1";
  }
  
  public int getFace()
  {
    if (mood<17)
      return 0;
    if (mood<33)
      return 1;
    if (mood<48)
      return 2;
    if (mood<65)
      return 3;
    if (mood<82)
      return 4;
    return 5;
  }
}
