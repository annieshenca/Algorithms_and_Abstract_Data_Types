/*
 * Annie Shen (ashen7@ucsc.edu)
 * ID#1562848
 * CMPS 101 pa3
 * Matrix.java
 */

public class Matrix{
	
	//Private Entry calss
	//Encapsulates the column and value information
	//corresponding to a matrix entry
	private class Entry{
		private int column;
		private double data;
		
		public Entry(int column, double data){ 
			this.column = column;
			this.data = data;
		}
		
		public boolean equals(Object x){
			//System.out.println("here?");
			if(x instanceof Entry){
				Entry E = (Entry)x;

				if(this.column == E.column && this.data == E.data){
					return true;		
				} else	return false;
			}else 	return false;
		}
		
		public String toString(){
			String str = new String("(" + column + ", " + data + ")");
			return str;
		}
		
	}//End Entry
	
	//Constructor***********************************************************
	private List[] matrix; //Array of lists
	private int size; //size of matrix
	private int NNZ; //number of non-zero entries
	
	//Makes a new n x n zero Matrix. pre: n>=1
	Matrix(int n){
		if(n < 1){
			throw new RuntimeException("Matrix Error: Matrix callign n < 1");
		}
		
		matrix = new List[n+1]; //Create as many array named matrix as there is n
		for(int i = 1; i <= n; i++){
			matrix[i] = new List();
		}
		//Size of n x n matrix
		size = n;
	} //End Matrix
	
	//Access functions***********************************************************
	//getSize()
	//Returns n, the number of rows and columns of this Matrix
	int getSize(){
		return size;
	} //End getSize()
	
	//getNNZ()
	//Returns the number of non-zero entries in this Matrix
	int getNNZ(){
		return NNZ;
	} //End getNNZ;
	
	//boolean equals(Object x)
	//Overrides Object's equals() method
	public boolean equals(Object x){
		int k;
		if(x instanceof Matrix){
			Matrix M = (Matrix)x;
			if(this.getSize() != M.getSize()){
				return false;
			} else{
				for(k = 1; k <= this.getSize(); k++){
					List a = M.matrix[k];
					List b = this.matrix[k];

					if(!(a.equals(b))){
						//System.out.println("k: " + k);
						return false;
					}
				}
			}
			return true;
		}else	return false; //If x is NOT an instanceof Entry
	} //End of equals(Object x)
	
	//Manipulation procedure*********************************
	//makeZero()
	//Sets this Matrix to the zero state
	void makeZero(){
		for(int i = 1; i <= getSize(); i++){
			matrix[i] = new List();
		}
		NNZ=0;
	} //End  makeZero
	
	//Matrix copy()
	//Returns a new Matrix having the same entries as this Matrix
	Matrix copy(){
		Matrix copy = new Matrix(getSize());
		
		for(int i = 1; i <= getSize(); i++){
			this.matrix[i].moveFront(); //Move cursor to the front

			while( matrix[i].index() != -1){ //While the cursor doesn't fall off yet
				int a = ((Entry)matrix[i].get()).column;
				double b = ((Entry)matrix[i].get()).data;
				copy.changeEntry(i, a, b); //copy the column and data
				this.matrix[i].moveNext(); //Move cursor to the next
			}	
		}
		return copy;
	} //End copy
	
	//changeEntry(int i, int j, double x)
	//Changes ith row, jth column of this Matrix to x
	//Pre: 1<=i<=getSize(), 1<=j<=getSize()
	void changeEntry(int i, int j, double x){
		if(1 > i || i > getSize()){
			throw new RuntimeException("Matrix Error: changeEntry calling 1 > i > getSize()");
		}
		if(1 > j || j > getSize()){
			throw new RuntimeException("Matrix Error: changeEntry calling 1 > j > getSize()");
		}
		
		if(x != 0.0){
			matrix[i].moveFront();
			
			if(matrix[i].length() == 0){
				matrix[i].prepend(new Entry(j,x));
			} else{
				while(matrix[i].index() > -1 && ((Entry)matrix[i].get()).column < j){
					//while the matrix cursor is not invalid(-1), and the matrix's ith is less than j
					matrix[i].moveNext();
				}
				if(matrix[i].index() == -1){ //If cursor fall off the list
					matrix[i].append(new Entry(j,x));
				} else{
					matrix[i].insertBefore(new Entry(j,x));
				}
			}
			//System.out.println("changeEntry index: "+matrix[i].index());
			//System.out.println("changeEntry length: "+ this.matrix[i].length());
			NNZ++;
		}
	} //End changeEntry
	
	//Matrix transpose()
	//Returns a new Matrix that is the transpose of this Matrix
	//Taking this.matrix's row and store into trans's columns
	Matrix transpose(){
		Matrix trans = new Matrix(this.getSize()); //Create a new matrix to store transpose into
		int i; int j; //Initialize i for this.matrix and j for trans
		double x;
		
		for(i=1; i <= getSize(); i++){
			this.matrix[i].moveFront(); //Start this.matrix's list i's cursor at front
			j = 1; //Restart j at 1;
			while(this.matrix[i].index() != -1){
				//while there's nodes to be read in this.matrix's list j
				if(j == ((Entry)this.matrix[i].get()).column){
					x = ((Entry)this.matrix[i].get()).data;
					trans.changeEntry(j, i, x); //changeEntry trans to store the data 
					this.matrix[i].moveNext(); //Move the cursor to next element
				}
				j++;
			}
		}
		return trans;
		//Failed attempt
//		copy.matrix[i].moveFront();
//		while(copy.matrix[i] != null){
//			for(int j = 1; j <= getSize(); j++){
//				trans.matrix[j].moveFront();
//				double aData = ((Entry)copy.matrix[i].get()).data;
//				double bData = ((Entry)trans.matrix[j].get()).data;
//				bData = aData;
//				((Entry)trans.matrix[j].get()).data = bData;
//				copy.matrix[i].moveNext();
//				((Entry)M.matrix[i].get()).data = a;
//				M.matrix[i].moveNext();
//			}
//		}
		} //End transpose
	
	//private double dot(List A, List B)
	//Computes the vector dot product of two matrix rows of List A and B
	private static double dot(List A, List B){
		double data = 0.0;
		A.moveFront();
		B.moveFront();
		int Ac, Bc; //List A and B 's columns
		double Ad, Bd; //List A and B 's datas
		
		while(A.index() != -1 && B.index() != -1){
			Ac = ((Entry)A.get()).column;
			Bc = ((Entry)B.get()).column;
			Ad = ((Entry)A.get()).data;
			Bd = ((Entry)B.get()).data;
			//System.out.println("Ad: " + Ad);
			if(Ac == Bc){
				data += Ad * Bd;
				A.moveNext();
				B.moveNext();
			}else if(Ac < Bc){
				A.moveNext();
			} else{ //if(Ac > Bc)
				B.moveNext();
			}
			
		}
		return data;
	} //End dot
	
	//Matrix scalarMult(double x)
	//Returns a new Matrix that is the scalar product of this Matrix with x
	Matrix scalarMult(double x){
		Matrix M = this.copy();
		
		for(int i=1; i <= getSize(); i++){
			M.matrix[i].moveFront();
			while(M.matrix[i].index() != -1){
				double a = ((Entry)M.matrix[i].get()).data;
				a = a * x;
				((Entry)M.matrix[i].get()).data = a;
				M.matrix[i].moveNext();
			}
		}
		return M;
	}
	
	//Matrix add(Matrix M)
	//Returns a new Matrix that is the sum of this Matrix with M
	//Pre: getSize()==M.getSize()
	//If two matrices are the same || If two nodes are both numbers,
	//if one node is number and the other is not ||
	Matrix add(Matrix M){
		if(this.getSize() != M.getSize()){
			throw new RuntimeException("add Error: getSize() != M.getSize()");
		}
		
		if(M == this){ //If adding the matrix M to itself
			return this.copy().scalarMult(2); //Could be treated as itself multiplied by 2
		}
		
		Matrix N = new Matrix(getSize()); //New matrix to store the sum of two matrices
		int i;
		int Tc, Mc; //List A and B 's columns
		double Td, Md; //List A and B 's data
		
		for(i = 1;i <= getSize(); i++){
			this.matrix[i].moveFront();
			M.matrix[i].moveFront();
			
			while(this.matrix[i].index() != -1 || M.matrix[i].index() != -1){
				
				if(this.matrix[i].index() != -1 && M.matrix[i].index() != -1){
					Tc = ((Entry)this.matrix[i].get()).column;
					Mc = ((Entry)M.matrix[i].get()).column;
					Td = ((Entry)this.matrix[i].get()).data;
					Md = ((Entry)M.matrix[i].get()).data;
					if(Tc < Mc){
						//If this column number is smaller than M column number,
						//meaning M entry contains a zero
						N.changeEntry(i, Tc, Td);
						this.matrix[i].moveNext();
					} else if(Tc > Mc){
						//If this column number is bigger than M column number,
						//meaning this entry contains a zero
						N.changeEntry(i, Mc, Md);
						M.matrix[i].moveNext();
					} else{ //if(Tc == Mc)
						//If this column number is the same as M column number,
						//meaning this and M both entries that are non-zeros
						N.changeEntry(i, Tc, (Td+Md));
						this.matrix[i].moveNext();
						M.matrix[i].moveNext();
					} //End if else
				
				} else if(this.matrix[i].index() != -1){
					N.changeEntry(i, ((Entry)this.matrix[i].get()).column, ((Entry)this.matrix[i].get()).data);
					this.matrix[i].moveNext();
				} else{ //M.matrix[i].index() != -1
					N.changeEntry(i, ((Entry)M.matrix[i].get()).column, ((Entry)M.matrix[i].get()).data);
					M.matrix[i].moveNext();
				}
			} //End while loop
			
		} //End for loop
		
		return N;
	} //End add
	
	//Matrix sub(Matrix M)
	//Returns a new Matrix that is the difference of this Matrix with M
	//Pre: getSize()==M.getSize()
	Matrix sub(Matrix M){
		if(this.getSize() != M.getSize()){
			throw new RuntimeException("add Error: getSize() != M.getSize()");
		}
		
		Matrix N = new Matrix(getSize()); //New matrix to store the difference of two matrices
		
		if(M == this){ //If subtracting the matrix M to itself
			return N; //Meaning returning an all zero entries matrix
		}
		
		int i;
		int Tc, Mc; //List A and B 's columns
		double Td, Md; //List A and B 's data
		
		for(i = 1;i <= getSize(); i++){
			this.matrix[i].moveFront();
			M.matrix[i].moveFront();
			
			while(this.matrix[i].index() != -1 || M.matrix[i].index() != -1){
				
				if(this.matrix[i].index() != -1 && M.matrix[i].index() != -1){
					Tc = ((Entry)this.matrix[i].get()).column;
					Mc = ((Entry)M.matrix[i].get()).column;
					Td = ((Entry)this.matrix[i].get()).data;
					Md = ((Entry)M.matrix[i].get()).data;
					if(Tc < Mc){
						//If this column number is smaller than M column number,
						//meaning M entry contains a zero
						N.changeEntry(i, Tc, Td);
						this.matrix[i].moveNext();
					} else if(Tc > Mc){
						//If this column number is bigger than M column number,
						//meaning this entry contains a zero
						N.changeEntry(i, Mc, -Md);
						M.matrix[i].moveNext();
					} else{ //if(Tc == Mc)
						//If this column number is the same as M column number,
						//meaning this and M both entries that are non-zeros
						if((Td-Md) != 0){
							N.changeEntry(i, Tc, (Td-Md));
						}
						this.matrix[i].moveNext();
						M.matrix[i].moveNext();
					} //End if else
				
				} else if(this.matrix[i].index() != -1){
					N.changeEntry(i, ((Entry)this.matrix[i].get()).column, ((Entry)this.matrix[i].get()).data);
					this.matrix[i].moveNext();
				} else{ //M.matrix[i].index() != -1
					N.changeEntry(i, ((Entry)M.matrix[i].get()).column, -((Entry)M.matrix[i].get()).data);
					M.matrix[i].moveNext();
				}
			} //End while loop
			
		} //End for loop
		
		return N;
	} //End sub
	
	//Matrix mult(Matrix M)
	//Returns a new Matrix that is the product of this Matrix with M
	//Pre: getSize()==M.getSize()
	Matrix mult(Matrix M){
		if(this.getSize() != M.getSize()){
			throw new RuntimeException("mult Error: getSize() != M.getSize()");
		}
		
		double x = 0.0;
		Matrix N = M.transpose(); //Transpose the Matrix M
		Matrix product = new Matrix(getSize()); //For storing multiplied matrices result
		//System.out.println("result size: " + result.getSize());
		for(int i = 1; i <= getSize(); i++){
			for(int j = 1; j <= getSize(); j++){
				x = dot(this.matrix[i], N.matrix[j]); //Perform dot product on two lists
				if(x != 0){ //If x(the data) is not zero
					product.changeEntry(i, j, x);
				}
			}
		}
		return product;
	} //End of mult
	
	//Other functions*******************************************************
	//toString()
	//Overrides Object's toString() method
	public String toString(){
		String str = "";
		for(int i = 1; i<=getSize(); i++){
			if(matrix[i].length() >0){
				str += (i + ": " + matrix[i] + "\n");
			}
		}
		return str;
	} //End toString

}