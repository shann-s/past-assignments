import java.io.*;

public interface Prime
      extends java.rmi.Remote {
	
  public Number prime(Number n)
    throws java.rmi.RemoteException;
}
