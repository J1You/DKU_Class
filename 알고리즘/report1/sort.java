package report1;
import java.util.Scanner; // 표준 입력 클래스

public class sort {
	public static void main(String[] args) {
		int n, temp;
		Scanner s = new Scanner(System.in); // 표준 입력 클래스 생성
		System.out.print("n값 입력: ");
		n = s.nextInt(); // 정수 n 입력
		int arr[] = new int[n];
		System.out.print(n+"개의 정수 입력: ");
		for (int i=0; i<n; i++) {
			arr[i] = s.nextInt(); // 배열에 정수 입력
		}
		
		for (int i=0; i<arr.length; i++) { // 작은 수 부터 채워 오름차순 정렬
			for (int j=i+1; j<arr.length; j++) {
				if(arr[i]>arr[j]) { 
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		
		System.out.print("정렬결과: ");
		for (int i=0; i<arr.length; i++) {
			System.out.print(arr[i]+" "); // 정렬 결과 출력
		}
	}
}
