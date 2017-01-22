/*
 * Annie Shen (ashen7@ucsc.edu)
 * CMPS 101 pa1
 * List.java
 * Linked List implementation of the List ADT
 */
import java.util.Scanner;
import java.io.*;

public class Lex{
	public static void main(String[] args) throws IOException{
		if(args.length != 2){ //Check for in and out files
			System.out.println("Usage: Lex <input file> <output file>");
			System.exit(1);
		}
		
		Scanner in = new Scanner(new File(args[0]));
		PrintWriter out = new PrintWriter(new FileWriter(args[1]));
		int n = 0;
		int lineNum = 0;
		
		while(in.hasNextLine()) {//Count how many lines there are in the "in" file
			lineNum++; 
			in.nextLine();
		}
		in.close();
		//out.println("line number: " + lineNum);
		
		in = new Scanner(new File(args[0])); //Reinitialize the in Scanner
		String[] str = new String[lineNum];
		while(in.hasNextLine()){
			str[n] = in.nextLine();
			n++;
		}
		
//		for(int x= 0; x < lineNum; x++){
//			out.println(str[x]);
//		}
		
		//------------------------------------------------------------------------
		
		List A = new List();
		
		A.append(0); //First item counts as already sorted
		//For the rest of the elements
		for(int j = 1; j < lineNum; j++){
			String temp = str[j];
			int i = 0; //Start from first index
			
			A.moveFront(); //Move cursor to the front
			int k = A.get();
			while(str[k].compareTo(temp) < 0 && i<j){ //if str[i] is smaller than temp
				A.moveNext();
				i++;
			} //Gets out of while loop when str[A.get()] is BIGGER than temp
			  // or i >= j
			if(A.index() == -1){ //If cursor fall off the array
				A.append(j);
			} else{ //if cursor is still active
				A.insertBefore(j);
			}
		}
		
		A.moveFront(); //Reset cursor to front again
		for(int x= 0; x < lineNum; x++){
			out.println(str[A.get()]); //Prints List into output file "out"
			A.moveNext();
		}
		
		in.close();
		out.close();
	}
}