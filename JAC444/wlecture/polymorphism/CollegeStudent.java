class Student {
    int id = 123;
    private String name = "John";

    public String getName() {
        return name;
    }
}

public class CollegeStudent extends Student {

    int id = 987;
    private String name = "Mike";

    public String getName() {
        return name;
    }

    public String toString() {
        return name + " id is " + id;
    }

    public static void main(String[] args) {
        Student s = new CollegeStudent();

        System.out.println("s.id = " + s.id);
        System.out.println("s.getName = " + s.getName());
        System.out.println(s);
    }
}
