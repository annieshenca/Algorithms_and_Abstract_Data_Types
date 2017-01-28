/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa2
 * Due Jan 27, 2016
 * Lex.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(int argc, char*argv[]){
	if(argc != 3){ //Check for in and out files
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}

	FILE* in;
	FILE* out;
	//char* string;
	int lineNum = 0;
    int chara = 0;
	//Open files for reading and writing
	in = fopen(argv[1], "r"); //"r" for reading
	out = fopen(argv[2], "w"); //"w" for writing

	if(in == NULL){
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if(out == NULL){
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}

	while(chara != EOF){ //EOF = "end of file"
		chara = fgetc(in); //fgetc() gets the next character from in file
		if(chara == '\n'){ //If the character is a next line, then increment lineNum
			lineNum++;
		}
	}
	printf("Line number count: %i\n", lineNum);
	fclose(in);

	in = fopen(argv[1], "");
//	String[] str = new String[lineNum];
//	while(in.hasNextLine()){
//		str[n] = in.nextLine();
//		n++;
//	}


//------------------------------------------------------------------------

	List A = newList();

	append(A, 0); //First item counts as already sorted
	//For the rest of the elements
	for(int j=1; j < lineNum; j++){
        int i = 0;
        
        moveFront(L);


	}

//	for(int j = 1; j < lineNum; j++){
//		String temp = str[j];
//		int i = 0; //Start from first inde
//
//		A.moveFront(); //Move cursor to the front
//		while(A.index() != -1 && str[A.get()].compareTo(temp) < 0 && i<j){ //if str[i] is smaller than temp
//			A.moveNext();
//			i++;
//		} //Gets out of while loop when str[A.get()] is BIGGER than temp
//		// or i >= j
//		if(A.index() == -1){ //If cursor fall off the array
//			A.append(j);
//		} else{ //if cursor is still active
//			A.insertBefore(j);
//		}
//	}
//
//	A.moveFront(); //Reset cursor to front again
//	while(A.index() != -1){ //Stops when cursor is out of bound
//		out.println(str[A.get()]); //Prints List into output file "out"
//		A.moveNext();
//	}


	//Close read and write files
	fclose(in);
	fclose(out);

	return(EXIT_SUCCESS);
}
