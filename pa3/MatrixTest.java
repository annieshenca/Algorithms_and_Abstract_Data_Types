/*
 * Annie Shen (ashen7@ucsc.edu)
 * ID#1562848
 * CMPS 101 pa3
 * MatrixTest.java
 */

public class MatrixTest {
	public static void main(String[] args){
		int n=1000;
		Matrix A = new Matrix(n);
		Matrix B = new Matrix(n);

		A.changeEntry(2,2,5); B.changeEntry(2,2,1);
		A.changeEntry(1,3,3); B.changeEntry(1,3,1);
		A.changeEntry(3,2,8); B.changeEntry(3,2,1);
		A.changeEntry(2,3,6); B.changeEntry(2,3,0);
		A.changeEntry(3,1,7); B.changeEntry(3,1,1);
		A.changeEntry(1,1,1); B.changeEntry(1,1,1);
		A.changeEntry(1,2,2); B.changeEntry(1,2,0);
		A.changeEntry(3,3,9); B.changeEntry(3,3,1);
		A.changeEntry(2,1,4); B.changeEntry(2,1,0);

		System.out.println("A:");
		System.out.println("A NNZ: " + A.getNNZ());
		System.out.println(A);
		System.out.println("B:");
		System.out.println("B NNZ: " + B.getNNZ());
		System.out.println(B);
		
		System.out.println("B trans:");
		System.out.println("B.trans NNZ: " + B.transpose().getNNZ());
		System.out.println(B.transpose());
		
		System.out.println("Printing C = A.copy():");
		Matrix C = A.copy();
		System.out.println("C NNZ: " + C.getNNZ());
		System.out.println(C);
		
		System.out.println("A == A?: " + A.equals(A));
		System.out.println("A == B?: " + A.equals(B));
		System.out.println("B == C?: " + B.equals(C));
		System.out.println("A == C?: " + A.equals(C));
		System.out.println();
		
		System.out.println("Printing D = A.scalarMult(1.5):");
		Matrix D = A.scalarMult(1.5);
		//System.out.println(A);
		System.out.println("D NNZ: " + D.getNNZ());
		System.out.println(D);
		
		System.out.println("E1 = B.mult(B):");
		Matrix E1 = B.mult(B);
		System.out.println("E1 NNZ: " + E1.getNNZ());
		System.out.println(E1);
		
		System.out.println("E2 = A.mult(B):");
		Matrix E2 = A.mult(B);
		System.out.println("E2 NNZ: " + E2.getNNZ());
		System.out.println(E2);
		
		System.out.println("F1 = A.add(A):");
		Matrix F1 = A.add(A);
		System.out.println("F1 NNZ: " + F1.getNNZ());
		System.out.println(F1);
		
		System.out.println("F2 = A.add(B):");
		Matrix F2 = A.add(B);
		System.out.println("F2 NNZ: " + F2.getNNZ());
		System.out.println(F2);
		
		System.out.println("F3 = B.add(B.trans):");
		Matrix F3 = B.add(B.transpose());
		System.out.println("F3 NNZ: " + F3.getNNZ());
		System.out.println(F3);
		
		System.out.println("F4 = E1.add(B.scalarMult(2):");
		Matrix F4 = E1.add(B.scalarMult(2));
		System.out.println("F4 NNZ: " + F4.getNNZ());
		System.out.println(F4);
		
		System.out.println("F5 = F4.add(E2):");
		Matrix F5 = F4.add(E2);
		System.out.println("F5 NNZ: " + F5.getNNZ());
		System.out.println(F5);
		
		System.out.println("F6 = A.add(an empty matrix)");
		Matrix empty = new Matrix(n);
		Matrix F6 = empty.add(A);
		System.out.println("F6 NNZ: " + F6.getNNZ());
		System.out.println(F6);
		
		System.out.println("HELLO E=A.sub(B)");
		Matrix E = B.sub(A);
		System.out.println(E.getNNZ());
		System.out.println(E);
		
		System.out.println("A.makeZero():");
		A.makeZero();
		System.out.println("NNZ: " + A.getNNZ());
		System.out.println(A);
		
		System.out.print("End of MatrixTest.java");
	}
}