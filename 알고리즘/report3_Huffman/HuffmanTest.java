
package report3_Huffman;

public class HuffmanTest {
	public static void main(String args[]) throws Exception {
		Huffman huff = new Huffman();
		String str = "";
		TreeNode root = new TreeNode();
		root = huff.HuffmanTree(); // Huffman Ʈ�� ����
		System.out.println("Huffman Code : "); // Huffman �ڵ� ���
		huff.HuffmanPrint(root, str);
	}
}


