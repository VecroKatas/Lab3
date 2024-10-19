import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;

public class SquareRootCeil {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // We ask the user to enter the size of the array
        System.out.print("Enter the number of elements in the array: ");
        int size = scanner.nextInt();

        // We create an array for numbers
        double[] numbers = new double[size];

        // We fill the array with the values entered by the user
        System.out.println("Enter the numbers:");
        for (int i = 0; i < size; i++) {
            numbers[i] = scanner.nextDouble();
        }

        // We create a new array to store the results
        int[] roundedRoots = new int[size];

        // We use the method for calculating the root and rounding
        for (int i = 0; i < size; i++) {
            roundedRoots[i] = calculateSquareRootCeil(numbers[i]);
        }

        // We derive the result
        System.out.println("Rounded square roots:");
        System.out.println(Arrays.toString(roundedRoots));

        scanner.close();
    }

    // A method for calculating the square root and rounding up
    public static int calculateSquareRootCeil(double number) {
        double sqrtValue = Math.sqrt(number);
        return (int) Math.ceil(sqrtValue);
    }
}
