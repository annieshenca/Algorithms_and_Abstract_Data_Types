/*
 * Annie Shen (ashen7@ucsc.edu)
 * CMPS 101 pa1
 * List.java
 * Linked List implementation of the List ADT
 */

public class List {
	
	private class Node {
		int item;
		Node next;
		Node prev;
		
		Node(int x) {
			item = x;
			next = prev = null;
		}
	}
	
	private Node head; //The beginning of the List
	private Node tail; //The end of the List
	private Node cursor; //For user. Highlight a distinguished element in the List
	private int cIndex; //The index that the cursor is highlighting
	private int numItems; //The number of items in the List
	
	public List() {
		head = tail = cursor = null;
		cIndex = -1;
		numItems = 0;
	}
	
	//length()
	//Returns the number of elements in this List.
	public int length(){
		return numItems;
	}
	
	//index()
	//If cursor is defined, returns the index of the cursor element, otherwise returns -1.
	public int index(){
		if(cursor == null){
			return -1; //set cursor index out of range
		}
		return cIndex;
	}
	
	//front()
	//Returns front element. Pre: length()>0
	public int front(){
		if(length() <= 0){
			throw new RuntimeException("front() error: List is empty");
		}
		return head.item;
	}
	
	//back()
	//Returns back element. Pre: length()>0
	public int back(){
		if(length() <= 0){
			throw new RuntimeException("back() error: List is empty");
		}
		return tail.item;
	}
	
	//get()
	//Returns cursor element. Pre: length()>0, index()>=0
	public int get(){
		if(length() <= 0){
			throw new RuntimeException("get() error: List is empty");
		}
		if(index()< 0){
			throw new RuntimeException("get() error: invalid index");
		}
		return cursor.item;
	}
	
	//equals(List L)
	//Returns true if this List and L are the same integer sequence.
	//The cursor is ignored in both lists.
	boolean equals(List L) {
		if(length() != L.length()){
			//If length of both lists don't match up, then return false right away
			//because there's no need to continue comparing
			return false;
		}
		Node A = head;
		Node B = L.head;
		while(A != null && B != null){
			if(A.item == B.item){
				//If items match up, set next node as the new head and continue comparing
				A = A.next;
				B = B.next;
			} else  	return false; //when one item doesn't match up with the other
		}
		return true;
	}
	
	//clear()
	//Resets this List to its original empty state.
	void clear() {
		head = tail = cursor = null;
		cIndex = -1;
		numItems = 0;
	}
	
	//moveFront()
	//If List is non-empty, places the cursor under the front
	//element, otherwise does nothing.
	void moveFront(){
		if(length() > 0){ //If list had length more than zero, as in non-empty
			cursor = head;
			cIndex = 0;
			//System.out.println("in moveFront()");
		}
		//Do nothing if else
	}
	
	//moveBack()
	//If List is non-empty, places the cursor under the back element,
	//otherwise does nothing.
	void moveBack(){
		if(length() > 0){
			cursor = tail;
			cIndex = length() -1; //Cursor index would be the length of the list minus 1
		}
		//Do nothing if else
	}
	
	//movePrev()
	//If cursor is defined and not at front, moves cursor one step toward
	//front of this List, if cursor is defined and at front, cursor becomes
	//undefined, if cursor is undefined does nothing.
	void movePrev(){
		if(cursor != null){
			if(cursor == head){
				cursor = null; //movePrev on head will lead to null/out of range
				cIndex = -1;
			} else{ //when cursor is NOT at head
				cursor = cursor.prev; //reset cursor to the previous cursor
				cIndex--; //decrement the cursor index
			}
		}
		//Do nothing if cursor is null.
	}
	
	//moveNext()
	//If cursor is defined and not at back, moves cursor one step toward
	//back of this List, if cursor is defined and at back, cursor becomes
	//undefined, if cursor is undefined does nothing.
	void moveNext(){
		if(cursor != null){
			if(cursor == tail){
				cursor = null; //moveNext on tail will lead to null/out of range
				cIndex = -1;
			} else { //when cursor is NOT at tail
				cursor = cursor.next; //reset cursor to the next cursor
				cIndex++; //increment cursor index
			}
		}
		//Do nothing if cursor is null.
	}
	
	//prepend(int data)
	//Insert new element into this List. If List is non-empty,
	//insertion takes place before front element.
	void prepend(int data) {
		Node A = new Node(data);
		if(length() == 0){ //List is empty
			head = A;
			tail = A;
		}
		if(length() > 0){ //List is Not empty
			A.next = head;
			head.prev = A;
			head = A;
			if(cIndex != -1){
				cIndex++;
			}
		}
		numItems++; //increment number of items
	}
	
	//append(int data)
	//Insert new element into this List. If List is non-empty,
	//insertion takes place after back element.
	void append(int data) {
		Node A = new Node(data);
		if(length() == 0){ //List is empty
			//System.out.println("reached here 1?");
			head = A;
			tail = A;
		} else if(length() > 0){ //List is Not empty
			//System.out.println("reached here 2?");
			//System.out.println(tail);
			tail.next = A; //Insert after tail
			A.prev = tail;
			tail = A;
		}
		numItems++;
	}
	
	//insertBefore(int data)
	//Insert new element before cursor.
	//Pre: length()>0, index()>=0
	void insertBefore(int data) {
		if(length() <= 0){ //If the list is empty
			throw new RuntimeException("insertBefore() error: List is empty");
		}
		if(index() < 0){ //If cursor index is invalid
			throw new RuntimeException("insertBefore() error: invalid index");
		}
		
		Node A = new Node(data);
		if(length() == 1){ //if cursor is at head and null is in front of the cursor
			cursor.prev = A; //Set the null before the cursor to be the new node
			A.next = cursor; //Set new node's next as the cursor
		} else { // when length is more than 1, that cursor.prev is NOT a null
			Node temp = cursor.prev; //Save current cursor.prev as a new node named temp
			cursor.prev = A;
			A.next = cursor;
			temp.next = A; //The old cursor.prev now is in front of node A
			A.prev = temp;
		}
		cIndex++;
		numItems++;
	}
	
	//insertAfter(int data)
	//Inserts new element after cursor.
	//Pre: length()>0, index()>=0
	void insertAfter(int data){
		if(length() <= 0){
			throw new RuntimeException("insertAfter() error: List is empty");
		}
		if(index() < 0){
			throw new RuntimeException("insertAfter() error: invalid index");
		}
		
		Node A = new Node(data);
		if(length() == 1){ //if cursor is at head and null is after the cursor
			cursor.next = A;
			A.prev = cursor;
		} else { // when length is more than 1, that cursor.prev is NOT a null
			Node temp = cursor.next; //Save current cursor.prev as a new node named temp
			cursor.next = A;
			A.prev = cursor;
			temp.prev = A; //The old cursor.prev now is in front of node A
			A.next = temp;
		}
		numItems++;
	}
	
	//deleteFront()
	//Deletes the front element. Pre: length()>0
	void deleteFront(){
		if(length() <= 0){
			throw new RuntimeException("deleteFront() error: List is empty");
		}
		if(length() == 1){ //If the list has only one element
			head = tail = cursor = null; //Reset
			cIndex = -1;
		} else{ //The list has more than 1 element 
			head = head.next;
			head.prev = null;
			numItems--;
		}
	}
	
	//deleteBack()
	//Deletes the back element. Pre: length()>0
	void deleteBack() {
		if(length() <= 0){
			throw new RuntimeException("deleteBack() error: List is empty");
		}
		if(length() == 1){ //If the list has only one element
			head = tail = cursor = null; //Reset
			cIndex = -1;
		} else{ //The list has more than 1 element 
			tail = tail.prev;
			tail.next = null;
			numItems--;
		}
	}

	//delete()
	//Deletes cursor element, making cursor undefined.
	//Pre: length()>0, index()>=0
	void delete() {
		if(length() <= 0){
			throw new RuntimeException("delete() error: List is empty");
		}
		if(index() < 0){
			throw new RuntimeException("delete() error: invalid index");
		}
		if(cIndex == 0){ //If cursor is at head
			deleteFront(); //Call deleteFront() to do the same job
		} else if(cIndex == length() -1){ //If the cursor is at tail
			deleteBack(); //Call deleteBack() to do the same job
		} else{ //If the cursor is in the middle of the list
			Node before = cursor.prev;
			Node after = cursor.next;
			before.next = after;
			after.prev = before;
			cursor = null;
			cIndex = -1;
			numItems--;
		}
	}

	//toString()
	//Overrides Object's toString method. Returns a String
	//representation of this List consisting of a space
	//separated sequence of integers, with front on left.
	public String toString(){
		StringBuffer sb = new StringBuffer();
		
		Node N = head;
		for( ; N != null; N = N.next){
            sb.append(N.item + " ");
		}
		return sb.toString();
	}
	
	//Returns a new List representing the same integer sequence as this
	//List. The cursor in the new list is undefined, regardless of the
	//state of the cursor in this List. This List is unchanged.
	List copy(){
		List cp = new List();
		Node temp = head;
		while(temp != null){
			cp.append(temp.item);
			temp = temp.next;
		}
		return cp;
	}
	
	// Returns a new List which is the concatenation of
	// this list followed by L. The cursor in the new List
	// is undefined, regardless of the states of the cursors
	// in this List and L. The states of this List and L are
	// unchanged.
//	List concat(List L) {
//		
//	}
}