import java.util.Scanner;

public class Main208A {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String string = scanner.next();
		String[] result = string.split("WUB");
		boolean first = true;
		for(int i = 0; i < result.length; i++) {
			if("".equals(result[i])) {
				continue;
			}
			if(first) {
				System.out.print(result[i]);
				first = false;
			} else {
				System.out.print(" " + result[i]);
			}
		}
		System.out.println();
	}
}
