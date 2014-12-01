public class ThreadInvioDati implements Callable<Void> {

  Pianta p;

  public ThreadInvioDati(Pianta p)
  {
    this.p=p;
  }

    public Void call() {
String [] k=loadStrings(p.createSenderLink());
println(k[0]);
    return null;
  }
}
