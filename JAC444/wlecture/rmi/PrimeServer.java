
public class PrimeServer {

	public PrimeServer() {

		try {
			
			Prime p = new PrimeImpl();
			java.rmi.Naming.rebind("PrimeService", p);

		} catch (Exception e) {
			System.out.println("Trouble: " + e);
		}
	}

	public static void main(String args[]) {
		new PrimeServer();
	}
}
