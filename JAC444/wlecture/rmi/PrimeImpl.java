
import java.io.*;

public class PrimeImpl
             extends java.rmi.server.UnicastRemoteObject
             implements Prime {

  public PrimeImpl()
         throws java.rmi.RemoteException {
    super();
  }

  public Number prime(Number obj) {

      int n = obj.getNumber();
      obj.setPrime(isPrime(n));
      return obj;
  }

  //checks whether an int is prime or not.
  boolean isPrime(int n) {

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
  } 
}
