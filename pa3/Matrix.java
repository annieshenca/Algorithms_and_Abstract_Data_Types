import List.Node;

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
	
	private List[] matrix;
	private int size;
	private int NNZ;
	
	//Makes a new n x n zero Matrix. pre: n>=1
	Matrix(int n){
		if(n < 1){
			throw new RuntimeException("Matrix error: n is less than 1");
		}
		
		matrix = new List[n]; //Create as many array named matrix as there is n
		for(int i=0; i <= n;){
			matrix[i] = new List();
		}
		//Size of n x n matrix
		size = n;
	}
	
	//dot(List P, List Q)
	//
	private static double dot(List P, List Q){
		return 0;
	}
	
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
			Entry E = (Entry)x;
		}
		
		return true;
	}
	
	//Manipulation procedures--------------------------------
	//makeZero()
	//Sets this Matrix to the zero state
	void makeZero(){
		
	}
	
	//Matrix copy()
	//Returns a new Matrix having the same entries as this Matrix
	Matrix copy(){
		
	}
	
	//changeEntry(int i, int j, double x)
	//Changes ith row, jth column of this Matrix to x
	//Pre: 1<=i<=getSize(), 1<=j<=getSize()
	void changeEntry(int i, int j, double x){
		
	}
	
	//Matrix scalarMult(double x)
	//Returns a new Matrix that is the scalar product of this Matrix with x
	Matrix scalarMult(double x){
		
	}
	
	//Matrix add(Matrix M)
	//Returns a new Matrix that is the sum of this Matrix with M
	//Pre: getSize()==M.getSize()
	Matrix add(Matrix M){
		
	}
	
	//Matrix sub(Matrix M)
	//Returns a new Matrix that is the difference of this Matrix with M
	//Pre: getSize()==M.getSize()
	Matrix sub(Matrix M){
		
	}
	
	//Matrix transpose()
	//Returns a new Matrix that is the transpose of this Matrix
	Matrix transpose(){
		
	}
	
	//Matrix mult(Matrix M)
	//Returns a new Matrix that is the product of this Matrix with M
	//Pre: getSize()==M.getSize()
	Matrix mult(Matrix M){
		
	}
	
	//Other functions------------------------------------
	//toString()
	//Overrides Object's toString() method
	public String toString(){
		
	}

}
