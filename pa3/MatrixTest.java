public class MatrixTest {
	public static void main(String[] args){
		int i,j, n=3;
		Matrix A = new Matrix(n);
		Matrix B = new Matrix(n);
		System.out.println("a size:" +A.getSize());

		A.changeEntry(2,2,5); B.changeEntry(2,2,1);
		A.changeEntry(1,3,3); B.changeEntry(1,3,1);
		A.changeEntry(3,2,8); B.changeEntry(3,2,1);
		A.changeEntry(2,3,6); B.changeEntry(2,3,0);
		A.changeEntry(3,1,7); B.changeEntry(3,1,1);
		A.changeEntry(1,1,1); B.changeEntry(1,1,1);
		A.changeEntry(1,2,2); B.changeEntry(1,2,0);
		A.changeEntry(3,3,9); B.changeEntry(3,3,1);
		A.changeEntry(2,1,4); B.changeEntry(2,1,0);
		
//      A.changeEntry(1,1,1); B.changeEntry(1,1,1);
//      A.changeEntry(1,2,2); B.changeEntry(1,2,0);
//      A.changeEntry(1,3,3); B.changeEntry(1,3,1);
//      A.changeEntry(2,1,4); B.changeEntry(2,1,0);
//      A.changeEntry(2,2,5); B.changeEntry(2,2,1);
//      A.changeEntry(2,3,6); B.changeEntry(2,3,0);
//      A.changeEntry(3,1,7); B.changeEntry(3,1,1);
//      A.changeEntry(3,2,8); B.changeEntry(3,2,1);
//      A.changeEntry(3,3,9); B.changeEntry(3,3,1);

		System.out.println("Printing A:");
//		System.out.println("NNZ: " + A.getNNZ());
		System.out.println(A);
		System.out.println();
//		System.out.println("Printing B:");
//		System.out.println("NNZ: " + B.getNNZ());
//		System.out.println(B);
		
		System.out.println("Printing C = A.copy():");
		Matrix C = A.copy();
		System.out.println("a size:" +A.getSize());
		System.out.println("c size:" +C.getSize());
		//System.out.println("NNZ: " + C.getNNZ());
		System.out.println(C);
		//System.out.println("A == A?: " + A.equals(A));
//		System.out.println("A == B?: " + A.equals(B));
//		System.out.println("B == C?: " + B.equals(C));
		System.out.println("A == C?: " + A.equals(C));
		
//		System.out.println("Printing D = A.scalarMult(1.5):");
//		Matrix D = A.scalarMult(1.5);
//		//System.out.println(A);
//		System.out.println("NNZ: " + D.getNNZ());
//		System.out.println(D);
//		
//		System.out.println("Printing E = A.transpose():");
//		Matrix E = A.transpose();
//		System.out.println("NNZ: " + E.getNNZ());
//		System.out.println(E);
		
		
		
		
//      Matrix D = A.add(A);
//      System.out.println(D.getNNZ());
//      System.out.println(D);
//
//      Matrix E = A.sub(A);
//      System.out.println(E.getNNZ());
//      System.out.println(E);
//
//      Matrix G = B.mult(B);
//      System.out.println(G.getNNZ());
//      System.out.println(G);
		
//		System.out.println("A.makeZero():");
//      A.makeZero();
//      System.out.println("NNZ: " + A.getNNZ());
//      System.out.println(A);
		
		System.out.print("End of MatrixTest.java");
	}
}