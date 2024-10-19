import java.io.FileWriter;
import java.io.IOException;

public class LexicalAnalyzerTest {

    public static void main(String[] args) {
        // The path to the file with the input Java code to analyze
        String inputFilePath = "testCode.java";
        // The path to the file for recording the analysis results
        String outputFilePath = "analysisOutput.txt";

        // Creating a test file with Java code
        createTestFile(inputFilePath);

        // Call the lexical analyzer and pass it the input file and the result file
        LexicalAnalyzer analyzer = new LexicalAnalyzer();
        try {
            analyzer.analyze(inputFilePath, outputFilePath);
            System.out.println("The analysis is complete. The results are recorded in" + outputFilePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // A method for creating a test Java file
    private static void createTestFile(String filePath) {
        try (FileWriter writer = new FileWriter(filePath)) {
            writer.write("// This is a test class for testing the lexical analyzer\n");
            writer.write("public class TestClass {\n");
            writer.write("    public static void main(String[] args) {\n");
            writer.write("        int a = 10;\n");
            writer.write("        double b = 3.14;\n");
            writer.write("        String str = \"Hello, world!\";\n");
            writer.write("        if (a < 20) {\n");
            writer.write("            System.out.println(str);\n");
            writer.write("        }\n");
            writer.write("    }\n");
            writer.write("}\n");
            System.out.println("Test file " + filePath + " is created.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
