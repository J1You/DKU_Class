package report1;
import java.util.Scanner; // ǥ�� �Է� Ŭ����

public class sort {
	public static void main(String[] args) {
		int n, temp;
		Scanner s = new Scanner(System.in); // ǥ�� �Է� Ŭ���� ����
		System.out.print("n�� �Է�: ");
		n = s.nextInt(); // ���� n �Է�
		int arr[] = new int[n];
		System.out.print(n+"���� ���� �Է�: ");
		for (int i=0; i<n; i++) {
			arr[i] = s.nextInt(); // �迭�� ���� �Է�
		}
		
		for (int i=0; i<arr.length; i++) { // ���� �� ���� ä�� �������� ����
			for (int j=i+1; j<arr.length; j++) {
				if(arr[i]>arr[j]) { 
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		
		System.out.print("���İ��: ");
		for (int i=0; i<arr.length; i++) {
			System.out.print(arr[i]+" "); // ���� ��� ���
		}
	}
}
