package report2_quickSort;

public class QuickSort {
	public static void main(String[] args) {
		int n[] = {1000, 5000, 10000, 20000, 50000, 100000};
		int[][] rand = new int[6][];  // ������ ������ �迭
		
		for (int i = 0; i < 6; i++) {
			rand[i] = new int[n[i]+10];  // �迭�� ���� ������
		}
		
		System.out.println("QuickSort ��� : ");
		System.out.println(" [1000]  [5000]  [10000]  [20000]  [50000]  [100000]");
		System.out.print(" ");
		for (int i = 0; i < 10; i++) {  // 10���� �׽�Ʈ ������
			for (int j = 0; j < 6; j++) {  
				for (int k = 0; k < n[j]; k++) {
					rand[j][k] = (int) (Math.random()*n[j]); // ���� �Է�
				}
			}
			for (int l = 0; l < 6; l++) {
				QuickSortClass1 quick = new QuickSortClass1(rand[l], n[l]);
				long start = System.nanoTime();  // ������ ���۽ð�
				rand[l] = quick.QuickSortCall();
				long end = System.nanoTime();  // ������ ����ð�
				long execute = end-start;  // �ɸ� �ð�
				System.out.print(execute + "  ");
			}
			System.out.println();
			System.out.print("  ");
		}
		System.out.println("  ");
	}
}

