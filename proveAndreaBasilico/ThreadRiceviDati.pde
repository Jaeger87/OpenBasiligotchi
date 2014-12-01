public class ThreadRiceviDati implements Callable<Void> {

  Pianta p;

  public ThreadRiceviDati(Pianta p)
  {
    this.p=p;
  }

    public Void call() {
      String lines[] = loadStrings(p.createReceiveLink());
    JSONArray listaJson = JSONArray.parse(lines[0]);
    for (int i=0; i<listaJson.size(); i++)
    {
      JSONObject j=listaJson.getJSONObject(i);
      p.setTemperature(j.getInt("Temperatura"));
      p.setLight(j.getInt("Luminosita"));
      p.setMood(j.getInt("Umore"));
      p.setAmbientHumidity(j.getInt("UmiditaAmbiente"));
      p.setTerrainHumidity(j.getInt("UmiditaTerreno"));
      
    }

    return null;
  }
}
