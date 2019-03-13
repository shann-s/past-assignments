
class Super {
   public String className = "Super";
}

class Sub extends Super  {
    public String className = "Sub";
}

public class Question  {

    public static void main(String[] args) {
        System.out.print(((Sub) new Super()).className);
    }
}
