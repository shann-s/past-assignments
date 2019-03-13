
public class Palindromes {


    public boolean ptest(String str) {

        boolean result = false;

        if (str.length() <= 1)
            result = true;
        else if (str.charAt(0) == str.charAt(str.length() - 1))
            result = ptest(str.substring(1, str.length() - 1));

        return result;

    }


    public static void main(String[] args) {
        Palindromes tester = new Palindromes();

        System.out.println("radar  --> "
                + tester.ptest("radar"));

        System.out.println("able was I ere I saw elba  -->"
                + tester.ptest("able was I ere I saw elba"));

        System.out.println("hello  -->"
                + tester.ptest("hello"));

        System.out.println("madam  -->"
                + tester.ptest("madam"));
    }
}