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
		
	}//End of Entry
	
	//Constructor--------------------------------------------
	
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
	}
	
	//dot(List P, List Q)
	//
//	private static double dot(List P, List Q){
//		return 0;
//	}
	
	//Access functions---------------------------------------
	//getSize()
	//Returns n, the number of rows and columns of this Matrix
	int getSize(){
		return size;
	}
	
	//getNNZ()
	//Returns the number of non-zero entries in this Matrix
	int getNNZ(){
		return NNZ;
	}
	
	//boolean equals(Object x)
	//Overrides Object's equals() method
	public boolean equals(Object x){
		if(x instanceof Entry){
			Matrix M = (Matrix)x;
			if(this.size != M.size){
				//If the length of both arrays don't match up, then there's no point of
				//keep on going and compare.
				return false;
			} else{ //If the size match up
				for(int k = 1; k <= getSize(); k++){	
					if(!(matrix[k].equals(M.matrix[k]))){
						return false;
					}
				}
				return true;
			}
		}else 	return false; //If x is NOT an instanceof Entry
	}
	
	//Manipulation procedures--------------------------------
	//makeZero()
	//Sets this Matrix to the zero state
	void makeZero(){
		for(int l=1; l <= getSize(); l++){
			matrix[l] = null;
		}
	}
	
	//Matrix copy()
	//Returns a new Matrix having the same entries as this Matrix
//	Matrix copy(){
//		Matrix copyM = new Matrix(getSize());
//		//List[] copy = new List[getSize()];
//		for(int i = 0; i < getSize(); i++){
//			copyM[i] = matrix[i];
//		}
//		return copyM;
//	}
//	
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
			//System.out.println("bitch");
			matrix[i].moveFront();
			//*****NOTE: check if x is 0.0 or duplicate*****//
			
			if(matrix[i].length() == 0){
				matrix[i].prepend(new Entry(j,x));
			} else{
				while(matrix[i].index() > -1 && ((Entry)matrix[i].get()).column < j){
					//while the matrix cursor is not invalid(-1), and the matrix's ith is less than j
					matrix[i].moveNext();
				}
				if(matrix[i].index() == -1){
					matrix[i].append(new Entry(j,x));
				} else{
					matrix[i].insertBefore(new Entry(j,x));
				}
				NNZ++;
			}
		}
	}
//	
//	//Matrix scalarMult(double x)
//	//Returns a new Matrix that is the scalar product of this Matrix with x
//	Matrix scalarMult(double x){
//		
//	}
//	
//	//Matrix add(Matrix M)
//	//Returns a new Matrix that is the sum of this Matrix with M
//	//Pre: getSize()==M.getSize()
//	Matrix add(Matrix M){
//		
//	}
//	
//	//Matrix sub(Matrix M)
//	//Returns a new Matrix that is the difference of this Matrix with M
//	//Pre: getSize()==M.getSize()
//	Matrix sub(Matrix M){
//		
//	}
//	
//	//Matrix transpose()
//	//Returns a new Matrix that is the transpose of this Matrix
//	Matrix transpose(){
//		
//	}
//	
//	//Matrix mult(Matrix M)
//	//Returns a new Matrix that is the product of this Matrix with M
//	//Pre: getSize()==M.getSize()
//	Matrix mult(Matrix M){
//		
//	}
	
//	//Other functions------------------------------------
	//toString()
	//Overrides Object's toString() method
	public String toString(){
		String str = new String();
		for(int i = 1; i<=getSize(); i++){
			if(matrix[i].length() >0){
				str += (i + ": " + matrix[i] + "\n");
			}
		}
		return str;
	}

}
