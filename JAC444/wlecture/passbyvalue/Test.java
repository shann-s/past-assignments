public class Test {

    public static void main(String[] args) {
        Integer[] intArray = new Integer[2];
        int sum = 0;
        for (Integer i : intArray)
            sum += i;

        System.out.println(sum / intArray.length);
    }
}
