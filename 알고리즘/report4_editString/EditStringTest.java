package report4_editString;
import java.util.Scanner;

public class EditStringTest {
	public static void main(String[] args) {
		String X, Y;
		int n, m;
		Scanner sc = new Scanner(System.in);
		
		System.out.print("�� ���ڿ��� ���� �Է�: ");
		n = sc.nextInt();
		m = sc.nextInt();
		System.out.print("X ���ڿ� �Է�: ");
		X = sc.next();
		System.out.print("Y ���ڿ� �Է�: ");
		Y = sc.next();
		System.out.println();
		
		EditStringClass ec = new EditStringClass(n, m, X, Y);
	}
}

