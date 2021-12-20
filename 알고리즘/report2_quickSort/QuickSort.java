package report2_quickSort;

public class QuickSort {
	public static void main(String[] args) {
		int n[] = {1000, 5000, 10000, 20000, 50000, 100000};
		int[][] rand = new int[6][];  // 난수를 저장할 배열
		
		for (int i = 0; i < 6; i++) {
			rand[i] = new int[n[i]+10];  // 배열에 대한 사이즈
		}
		
		System.out.println("QuickSort 결과 : ");
		System.out.println(" [1000]  [5000]  [10000]  [20000]  [50000]  [100000]");
		System.out.print(" ");
		for (int i = 0; i < 10; i++) {  // 10개의 테스트 데이터
			for (int j = 0; j < 6; j++) {  
				for (int k = 0; k < n[j]; k++) {
					rand[j][k] = (int) (Math.random()*n[j]); // 난수 입력
				}
			}
			for (int l = 0; l < 6; l++) {
				QuickSortClass1 quick = new QuickSortClass1(rand[l], n[l]);
				long start = System.nanoTime();  // 퀵정렬 시작시간
				rand[l] = quick.QuickSortCall();
				long end = System.nanoTime();  // 퀵정렬 종료시간
				long execute = end-start;  // 걸린 시간
				System.out.print(execute + "  ");
			}
			System.out.println();
			System.out.print("  ");
		}
		System.out.println("  ");
	}
}

