
package report3_Huffman;

public class Element {
	TreeNode tree;
	int key;
	Element(){ // 생성자
		tree = null; // tree 초기화
		key = 0;
	}
	Element(Element e){ // 매개변수 갖는 생성자
		tree = e.tree;
		key = e.key;
	}
}

