import java.util.Scanner;

public class InteractRunner {
    public static void main(String[] args) {
	Scanner reader = new Scanner(System.in);
	try {
	    calculate calc = new calculate();
	    String exit = "no";
	    while (!exit.equals("yes")) {
		System.out.println("Enter first args:");
		String first = reader.next();
		System.out.println("Enter second args:");
		String second = reader.next();
		calc.add(Integer.valueOf(first), Integer.valueOf(second));
		System.out.println("Result:" + calc.getResult());
		calc.cleanResult();
		System.out.println("Exit: yes/no");
		exit = reader.next();
	    }
	} finally  {
	    reader.close();
	}
    }
    
}
