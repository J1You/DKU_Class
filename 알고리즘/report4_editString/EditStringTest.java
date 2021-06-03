package report4_editString;
import java.util.Scanner;

public class EditStringTest {
	public static void main(String[] args) {
		String X, Y;
		int n, m;
		Scanner sc = new Scanner(System.in);
		
		System.out.print("두 문자열의 길이 입력: ");
		n = sc.nextInt();
		m = sc.nextInt();
		System.out.print("X 문자열 입력: ");
		X = sc.next();
		System.out.print("Y 문자열 입력: ");
		Y = sc.next();
		System.out.println();
		
		EditStringClass ec = new EditStringClass(n, m, X, Y);
	}
}

