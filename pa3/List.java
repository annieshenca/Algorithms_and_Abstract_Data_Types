
public class List 
{
	//Linked list  of type node
	private class Node
	{
		Object data;
		Node next;
		Node prev;
		
		//Default constructor
		Node()
		{
			data = 0;
			next = prev = null;
		}
		
		//This constructor allows user to set data right a way
		Node(Object data, Node next, Node prev)
		{
			this.data = data;
			this.next = next;
			this.prev = prev;
		}
		
		//overrides equals in Object superclass
		public boolean equals(Object x)	
		{
			if (x instanceof Node)
			{
				Node N = (Node)x;
				if(this.data.equals(N.data))
				{
					return true;
				}
				else
					return false;
			}
			return false;
		}
		
		public String toString()
		{
			return data.toString();
		}
	}
	
	public int length; // number of elements in this list
	public int index; //keeps track of where cursor is pointing
	public Node front; //always points to node at front of the list
	public Node back; //always points to node at back to the list
	public Node cursor; //client user controls where this cursor points to
	
	//creates a new empty list
	public List()
	{
		length = 0;
		index = -1;
		front = back = cursor = null;
	}


	
// The following methods are the access functions to access the list
	
	// return the number of elements in this list
	public int length()
	{
		return length;
	}
	
	//index stores where cursor is pointing to
	//if cursor defined, returns the index of the cursor element, otherwise return -1
	public int index()
	{
		if (cursor == null)
			return -1;
		else
		return index;
	}
	
	//returns data stored in front element. Error if list is empty
	public Object front()
	{
		if (length <= 0)
			throw new RuntimeException("Error: method front() called, but the List is empty");
		return front.data;
	}
	
	//returns data stored in back element. Error if list is empty.
	public Object back()
	{
		if (length <= 0)
			throw new RuntimeException("Error: method front() called, but the List is empty");
		return back.data;
	}
	
	//returns data store in cursor element. Error if list is empty or index is not valid.
	public Object get()
	{
		if (length <= 0)  
			throw new RuntimeException("Error: method get() called, but the list is empty");
		if (index < 0)  
			throw new RuntimeException("Error: method get() called, but the index invalid, cursor does not point to valid Node");
		return cursor.data;
	}

	//returns true if this List and L are the same integer sequence
	public boolean equals(Object x)	
	{
		if (x instanceof List)
		{
			List L = (List) x;
			if (length != L.length)
				return false;
			else
			{
				Node A = front;
				Node B = L.front;
				for (int i = 0; i < length; i++ )
				{
					if (A.data.equals(B.data))
					{
						A = A.next;
						B = B.next;
					}
					else
						return false;
				}
				return true;
			}
		}
		else
			return false;
}

	
//The following methods are the manipulating procedures
	
	//resets this List to its original empty state
	void clear()
	{
		length = 0;
		index = -1;
		front = back = cursor = null;
	}
	
	// if list is non-empty place cursor under the front element, otherwise does nothing
	void moveFront()
	{
		if (length > 0)
		{
			cursor = front;
			index = 0;
		}
	}
	
	//if list is non-empty place cursor under back element, otherwise does nothing
	void moveBack()
	{
		if (length > 0)
		{
			cursor = back;
			index = length -1;
		}
	}
	
	//moves cursor to previous element than current one, if not at front
	void movePrev()
	{
		if (cursor != null && cursor != front)
		{
			cursor = cursor.prev;
			index = index - 1;
		}
		else
		{
			cursor = null;
			index = -1;
		}
	}
	
	//moves cursor to next element after current element, if not at back
	void moveNext()
	{
		if (cursor != null && cursor != back)
		{
			cursor = cursor.next;
			index = index + 1;
		}
		else
		{
			cursor = null;
			index = -1;
		}
	}
	
	//inserts new element to front of list
	void prepend(Object data)
	{
		if (length == 0 && front == null && back == null)
		{
			front = back = new Node (data, null, null);
			length = length + 1;
		}	
	    else
	    {
			Node newNode = new Node (data, front, null);
			front.prev = newNode;
			front = newNode;
			length = length + 1;	
		}
	}
	
	//insets new element to back of list
	void append(Object data)
	{
		if (length == 0 && front == null && back == null)
		{
			front = back =new Node (data, null, null);
			length = length + 1;
		}
		else
		{
			Node newNode = new Node (data, null, back);
			back.next = newNode;
			back = newNode;
			length = length + 1;
		}
	}
	
	//insert new element before cursor. Pre: length() >0, index() >= 0
	void insertBefore(Object data)
	{
		if (length() <= 0)
			throw new RuntimeException("Error: method insertBefore() called, but the List is empty");
		if (index() < 0)
			throw new RuntimeException("Error: method insertBefore() called, but cursor doesn't point to valid location");
		if (cursor == front)
		{
			prepend(data);
			index = index +1;
		}
		else
		{
			Node newNode = new Node (data, cursor, cursor.prev);
			
			Node temp = cursor.prev;
			cursor.prev = newNode;
			temp.next = newNode;
			index = index +1;
			length = length + 1;
		}
	}
	
	//insert new element after cursor. Pre: length() >0, index() >= 0
	void insertAfter(Object data)
	{
		if (length() <= 0)
			throw new RuntimeException("Error:  insertAfter() called, but the List is empty");
		if (index() < 0)
			throw new RuntimeException("Error: method insertAfter() called, but cursor doesn't point to valid location, index is less than 0");
		if (cursor == back)
		{
			append(data);
		}
		else
		{
			Node newNode = new Node (data, cursor.next, cursor);
			Node temp = cursor.next;
			temp.prev = newNode;
			cursor.next = newNode;
			length = length +1;	
		}
	}
	
	//deletes front element. Pre: length () >0
	void deleteFront()
	{
		if (length() <= 0)
			throw new RuntimeException("Error: method deleteFront() called, but the List is empty");
		front = front.next;
		length = length - 1; 
	}
	
	//deletes back element. Pre; length() >0
	void deleteBack()
	{
		if (length <= 0)
			throw new RuntimeException("Error: method deleteBack() called, but the List is empty");
		back = back.prev;
		length = length - 1;
	}
	
	//deletes cursor element, making cursor undefined. Pre: length()>0 and index()>=0
	void delete()
	{
		if (length <= 0)
			throw new RuntimeException("Error: method delete() called, but the List is empty");
		if (index < 0)
			throw new RuntimeException("Error: method delete() called, but cursor doesn't point to valid location, index is less than 0");
		Node prevNode = cursor.prev;
		Node nextNode = cursor.next;
		prevNode.next = cursor.next;
		nextNode.prev = cursor.prev;
		cursor = null;
		index = -1;
		length = length - 1;
	}
	
	//Overrides Object's toString method. Returns a String representation of the List consisting of a space separated
	//sequence of integers, with front on left
	public String toString()
	{
		String values = new String();
		Node tempNode = front;
		for (int i = 1; i <= length; i++)
		{
			values += tempNode.data + " ";
			tempNode = tempNode.next;
		}
		return values;
	}
}