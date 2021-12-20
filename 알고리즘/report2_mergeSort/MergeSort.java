package report2_mergeSort;

public class MergeSort {
	public static void main(String[] args) {
		int n[] = {1000, 5000, 10000, 20000, 50000, 100000};
		int[][] rand = new int[6][];  // ������ ������ �迭
		
		for (int i = 0; i < 6; i++) {
			rand[i] = new int[n[i]+10];  // �迭�� ���� ������
		}
		
		System.out.println("MergeSort ��� : ");
		System.out.println(" [1000]  [5000]  [10000]  [20000]  [50000]  [100000]");
		System.out.print(" ");
		for (int i = 0; i < 10; i++) {  // 10���� �׽�Ʈ ������
			for (int j = 0; j < 6; j++) {  
				for (int k = 0; k < n[j]; k++) {
					rand[j][k] = (int) (Math.random()*n[j]); // ���� �Է�
				}
			}
			for (int l = 0; l < 6; l++) {
				MergeSortClass merge = new MergeSortClass(rand[l], n[l]);
				long start = System.nanoTime();  // �պ����� ���۽ð�
				rand[l] = merge.MergeSortCall();
				long end = System.nanoTime();  // �պ����� ����ð�
				long execute = end-start;  // �ɸ� �ð�
				System.out.print(execute + "  ");
			}
			System.out.println();
			System.out.print("  ");
		}
		System.out.println("  ");
	}
}

