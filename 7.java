// Custom Exception Class
class DivisionByZeroException extends Exception {

    public DivisionByZeroException(String message) {
        super(message);
    }

}

public class CustomDivision {

    public static int division(int a, int b) throws DivisionByZeroException {
        if (b == 0) {
            throw new DivisionByZeroException("Error: Division by Zero is not possible");
        }
        return a / b;
    }

    public static void main(String[] args) {

        int num1 = 20, num2 = 0;

        try {
            System.out.println("Trying to divide numbers...");
            int result = division(num1, num2);
            System.out.println("Result = " + result);
        }
        catch (DivisionByZeroException e) {
            System.out.println("Caught Exception: " + e.getMessage());
        }
        finally {
            System.out.println("Finally block Executed.");
        }

        System.out.println("Program continues.");
    }
}