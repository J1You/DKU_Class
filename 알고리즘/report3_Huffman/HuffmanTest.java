
package report3_Huffman;

public class HuffmanTest {
	public static void main(String args[]) throws Exception {
		Huffman huff = new Huffman();
		String str = "";
		TreeNode root = new TreeNode();
		root = huff.HuffmanTree(); // Huffman 飘府 积己
		System.out.println("Huffman Code : "); // Huffman 内靛 免仿
		huff.HuffmanPrint(root, str);
	}
}


