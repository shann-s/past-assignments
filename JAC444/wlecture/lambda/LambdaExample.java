import java.util.*;

interface MyInterface<T> {
    public void addStuff(T t);
}

class X {
    public String toString() {
        return "This is X ";
    }
}

public class LambdaExample {

    public static void main(String[] args) {

        final int i = 1; // Outer variable to be used inside lambda scope

        MyInterface<Integer> anInstance;
        anInstance = num -> System.out.println("Result: " + num + i);
        anInstance.addStuff(33); // Call

        MyInterface<X> another;
        another = obj -> System.out.println("Result: " + obj + i);
        another.addStuff(new X());

    }
} 