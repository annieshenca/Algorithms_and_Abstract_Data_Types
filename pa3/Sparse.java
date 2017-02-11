import java.util.Scanner;

/*
 * Annie Shen (ashen7@ucsc.edu)
 * ID#1562848
 * CMPS 101 pa3
 * Sparse.java
 */

import java.util.Scanner;
import java.io.*;
import java.lang.Object;
import java.util.StringTokenizer;

public class Sparse {

	public static void main(String[] args) throws IOException{
		if(args.length != 2){ //Check for in and out files
            System.out.println("Usage: Sparse <input file> <output file>");
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
		
		//  for(int x= 0; x < lineNum; x++){
		//          out.println(str[x]);
		//  }
		
	//------------------------------------------------------------------------
		Object Obj = new Object();

	}

}
