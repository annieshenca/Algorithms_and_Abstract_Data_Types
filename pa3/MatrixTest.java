
public class MatrixTest {
	public static void main(String[] args){
		int i,j, n=9;
		Matrix A = new Matrix(n);
		Matrix B = new Matrix(n);
		
		
		A.changeEntry(2,3,6); B.changeEntry(2,3,0);
		A.changeEntry(3,1,7); B.changeEntry(3,1,1);
		A.changeEntry(3,2,8); B.changeEntry(3,2,1);
		A.changeEntry(3,3,9); B.changeEntry(3,3,1);
		A.changeEntry(1,1,1); B.changeEntry(1,1,1);
		A.changeEntry(1,2,2); B.changeEntry(1,2,0);
		A.changeEntry(1,3,3); B.changeEntry(1,3,1);
		A.changeEntry(2,1,4); B.changeEntry(2,1,0);
		A.changeEntry(2,2,5); B.changeEntry(2,2,1);
		
		
		
		System.out.println(A);
	
	}
}
