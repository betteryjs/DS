package class04;

public class Code05_SmallerEqualBigger {

	public static class Node {
		public int value;
		public Node next;

		public Node(int data) {
			this.value = data;
		}
	}

	public static Node listPartition1(Node head, int pivot) {
		if (head == null) {
			return head;
		}

		Node cur = head;
		int i = 0;
		while (cur != null) {
			i++;
			cur = cur.next;
		}
		Node[] nodeArr = new Node[i];
		i = 0;
		cur = head;
		for (i = 0; i != nodeArr.length; i++) {
			nodeArr[i] = cur;
			cur = cur.next;
		}
		arrPartition(nodeArr, pivot);
		for (i = 1; i != nodeArr.length; i++) {
			nodeArr[i - 1].next = nodeArr[i];
		}
		nodeArr[i - 1].next = null;
		return nodeArr[0];
	}

	public static void arrPartition(Node[] nodeArr, int pivot) {
		int small = -1;
		int big = nodeArr.length;
		int index = 0;
		while (index != big) {
			if (nodeArr[index].value < pivot) {
				swap(nodeArr, ++small, index++);
			} else if (nodeArr[index].value == pivot) {
				index++;
			} else {
				swap(nodeArr, --big, index);
			}
		}
	}

	public static void swap(Node[] nodeArr, int a, int b) {
		Node tmp = nodeArr[a];
		nodeArr[a] = nodeArr[b];
		nodeArr[b] = tmp;
	}

	public static Node listPartition2(Node head, int pivot) {
		Node sH = null; // small head
		Node sT = null; // small tail

		Node eH = null; // equal head
		Node eT = null; // equal tail

		Node bH = null; // big head
		Node bT = null; // big tail

		Node next = null; // save next node
		// every node distributed to three lists
		while (head != null) {
			next = head.next;  // sava next of the head
			head.next = null;   // cut the head in the linklist
			if (head.value < pivot) {
				if (sH == null) {
					sH = head;
					sT = head;
				} else {
				 //  尾插法
					sT.next = head;
					sT = head;
				}
			} else if (head.value == pivot) {
				if (eH == null) {
					eH = head;
					eT = head;
				} else {
					eT.next = head;
					eT = head;
				}
			} else {
			// head.value > pivot
				if (bH == null) {
					bH = head;
					bT = head;
				} else {
					bT.next = head;
					bT = head;
				}
			}
			// next of the head
			head = next;
		}
		// small and equal reconnect
		if (sT != null) {
			sT.next = eH;
			// 链接  ST 和 EH 如果 ET 为null  那末 新合成的链表的尾部是ST
			eT = eT == null ? sT : eT;
		}
		// all reconnect
		if (eT != null) {
			eT.next = bH;
		}

		return sH != null ? sH : eH != null ? eH : bH;
	}

	public static void printLinkedList(Node node) {
		System.out.print("Linked List: ");
		while (node != null) {
			System.out.print(node.value + " ");
			node = node.next;
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Node head1 = new Node(7);
		head1.next = new Node(9);
		head1.next.next = new Node(1);
		head1.next.next.next = new Node(8);
		head1.next.next.next.next = new Node(5);
		head1.next.next.next.next.next = new Node(2);
		head1.next.next.next.next.next.next = new Node(5);
		printLinkedList(head1);
		// head1 = listPartition1(head1, 4);
		head1 = listPartition2(head1, 5);
		printLinkedList(head1);

	}

}
