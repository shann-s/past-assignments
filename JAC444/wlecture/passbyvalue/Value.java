class TwoInt {
    int a = 1;
    int b = 2;

    public String toString() {
        return "a " + a + " b " + b;
    }
}


public class Value {

    public static void swap(int i, int j) {
        int tmp = i;
        i = j;
        j = tmp;
    }

    public static void swap(TwoInt o) {
        int tmp = o.a;
        o.a = o.b;
        o.b = tmp;
        o = null;
    }

    public static void main(String[] args) {

        int x = 1, y = 2;
        System.out.println("x " + x + " y " + y);
        Value.swap(x, y);
        System.out.println("x " + x + " y " + y);

        TwoInt obj = new TwoInt();
        System.out.println(obj);
        Value.swap(obj);
        System.out.println(obj);
    }

}