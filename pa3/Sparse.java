/*
 * Annie Shen (ashen7@ucsc.edu)
 * ID#1562848
 * CMPS 101 pa3
 * Sparse.java
 */

import java.util.Scanner;
import java.io.*;

public class Sparse {

	public static void main(String[] args) throws IOException{
		Scanner in = null;
		PrintWriter out = null;
		int n, a, b, lineNum = 1;
		Matrix A = null;
		Matrix B = null;
		
		if(args.length != 2){ //Check for in and out files
            System.out.println("Usage: Sparse <input file> <output file>");
            System.exit(1);
		}
		
		//Take in input and output files
		in = new Scanner(new File(args[0]));
		out = new PrintWriter(new FileWriter(args[1]));
		
		//Check first line of in file and store n, a, and b
		n = Integer.parseInt(in.next()); //n x n matrix
		a = Integer.parseInt(in.next()); //Number of entries in Matrix A
		b = Integer.parseInt(in.next()); //Number of entries in Matrix B
		
		A = new Matrix(n); //Create Matrix A
		B = new Matrix(n); //Create Matrix B
		
		//Skip the empty second line
		in.hasNextLine();
		
		while(in.hasNextLine()) {
			//Will run until there's no more lines in the input file,
			//after finish reading through A's lines and B's lines
			if(lineNum <= a){ //Storing Matrix A row, column, and data
				A.changeEntry(Integer.parseInt(in.next()), Integer.parseInt(in.next()), Double.parseDouble(in.next()));
				lineNum++;
				
			} else if(lineNum == a+1){
				in.nextLine(); //Skip the middle empty line
				// if(lineNum-a <= b)
			} else{ //Storing Matrix B row, column, and data
				B.changeEntry(Integer.parseInt(in.next()), Integer.parseInt(in.next()), Double.parseDouble(in.next()));
				lineNum++;
			}
		} //End while
		
		//Printing out matrix functions
		out.println("A has " + A.getNNZ() + " non-zero entries:");
		out.println(A);
		
		out.println("B has " + B.getNNZ() + " non-zero entries:");
		out.println(B);
		
		out.println("(1.5)*A =");
		out.println(A.scalarMult(1.5));
		
		out.println("A+B =");
		out.println(A.add(B));
		
		out.println("A+A =");
		out.println(A.add(A));
		
		out.println("B-A =");
		out.println(B.sub(A));
		
		out.println("A-A =");
		out.print(A.sub(A));
		
		out.println("Transpose(A) =");
		out.print(A.transpose());
		
		out.println("A*B =");
		out.print(A.mult(B));
		
		out.println("B*B =");
		out.print(B.mult(B));
		
		//Close input and output files
		in.close();
		out.close();
	}
}
