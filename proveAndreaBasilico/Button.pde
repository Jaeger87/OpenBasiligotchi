public class Button {

  private float x;
  private float y;
  private float w;
  private PImage icon;
  private int indiceBottone;


  Button(int indicebottone, float x, float y, PImage icon, float w) {
    this.x=x;
    this.y=y;
    this.icon=icon;
    this.w=w;
    this.indiceBottone=indiceBottone;
  }

  boolean mousePressed() {
    if (mousePressed== true)
      if (mouseX<(x+(w/2)+int(w*.10))&&mouseX>(x-(w/2)-int(w*.10))&&(mouseY<(y+(w/2)+int(w*.10))&&mouseY>(y-(w/2)-int(w*.10))))       

        return true;

    return false;
  }

  void display() {
    image(icon, x, y, w, w);
  }
  void addX(int x) {
    this.x+=x;
  }
  void addY(int y) {
    this.y+=y;
  }
  float getX() {
    return x;
  }
  float getY() {
    return y;
  }
  public int getIndiceBottone()
  {
    return this.indiceBottone;
  }

  public boolean mouseOverIt()
  {

    return mouseX<(x+(w/2)+int(w*.10))&&mouseX>(x-(w/2)-int(w*.10))&&(mouseY<(y+(w/2)+int(w*.10))&&mouseY>(y-(w/2)-int(w*.10)));
  }
  public void effettoBottoni(int indexButton)
  {
    if (indexButton<2)
    {

      if (indexButton==0&&index>0)
      {
        isConfiguring=true;
        println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHSHBFBFKLFBLFK");
      }
      index=indexButton;
      return;
    }
    apriWebPage();
  }
}

