
package report3_Huffman;

public class TreeNode {
	char symbol; // ���ĺ� ����
	int weight; // �󵵼� ����
	TreeNode leftChild;  // ���� �ڽ�
	TreeNode rightChild; // ������ �ڽ�
	TreeNode() {} // ������
	TreeNode(TreeNode left, TreeNode right) {
		leftChild = left;
		rightChild = right;
	}
}

