
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.net.MalformedURLException;
import java.rmi.NotBoundException;
import java.util.Vector;
import java.io.*;

public class PrimeClient {

  public static void main(String[] args) {
    
    int n = Integer.parseInt(args[0]);
    Number obj = new Number(n);
    System.out.println("Input: " + obj);

    try {

      Prime p = (Prime)Naming.lookup("PrimeService");
              
      obj = p.prime(obj);

      System.out.println("Result: " + obj);
    
    } catch (Exception e) {
      System.out.println(e);   
    }
  }
}
