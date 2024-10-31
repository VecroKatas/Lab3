// This is a simple test file for the lexical analyzer
public class InputTest {

    public static void main(String[] args) {
        // Variables declaration
        int a = 5;
        double b = 10.75;
        String message = "Hello, world!";

        // A condition with a comparison operator
        if (a < b) {
            System.out.println(message);
        }
        /* multiline comment with single line */
        int result = a + 0x73A + 0x12Z;

        /* Multiline comment
           with a couple of text lines */
        char symbol = 'A';

        for (int i = 0; i < 10; i++) {
            System.out.println(i);
        }
    }
}