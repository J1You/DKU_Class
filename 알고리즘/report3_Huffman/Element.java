
package report3_Huffman;

public class Element {
	TreeNode tree;
	int key;
	Element(){ // ������
		tree = null; // tree �ʱ�ȭ
		key = 0;
	}
	Element(Element e){ // �Ű����� ���� ������
		tree = e.tree;
		key = e.key;
	}
}

