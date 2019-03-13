import java.io.*;

public class Number implements Serializable {

    private int number;
    private boolean prime;
    private boolean set;

    public Number(int n) {
        number = n;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }


    public void setPrime(boolean prime) {
        this.prime = prime;
        set = true;        
    }

    public String toString() {
        if (set == false)
            return " " + number + " is prime? Unknown "; 
        else 
            return " " + number + " is prime? " + prime;
    }
}