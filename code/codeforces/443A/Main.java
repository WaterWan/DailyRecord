import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String string = scanner.nextLine();
		string = string.substring(1, string.length() - 1);
		String[] s = string.split(",");
		Set<String> set = new HashSet<>();
		for(String t : s) {
			if(t.trim().equals("")) {
				continue;
			}
			set.add(t.trim());
		}
		System.out.println(set.size());
	}

}
