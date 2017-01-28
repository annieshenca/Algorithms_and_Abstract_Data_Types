/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS101 pa2
 * Due Jan 28, 2017
 * Lex.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#define MAX_LEN 300

int main(int argc, char*argv[]){
	if(argc != 3){ //Check for in and out files
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}

	FILE* in;
	FILE* out;
	char line[MAX_LEN];
	//char inputArray[MAX_LEN][MAX_LEN];
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

	//Count number of lines in the in file
	while(chara != EOF){ //EOF = "end of file"
		chara = fgetc(in); //fgetc() gets the next character from in file
		if(chara == '\n'){ //If the character is a next line, then increment lineNum
			lineNum++;
		}
	}
	//printf("Line number count: %i\n", lineNum);
	fclose(in);

	char inputArray[lineNum][MAX_LEN];
	int x=0;
	while(fgets(line, MAX_LEN, in) != NULL){
		strcpy(inputArray[x], line);
		x++;

	}

//------------------------------------------------------------------------
//Insertion Sort
	List L = newList();
	char* temp;
	int i=0;
	int z =0;
	append(L, 0); //First item counts as already sorted
	//For the rest of the elements
	for(int j=1; j < lineNum; j++){
		temp = &line[j];
		i = 0; //Start from the first index

		moveFront(L); //Move cursor to the front
		z = get(L);
		while(index(L) != -1){
			while(strcmp(&line[z], temp) <0 && i<j){
				//if str[i] is smaller than temp
				moveNext(L);
				i++;
			} //Gets out of while loop when str[get(L)] is BIGGER than temp
			if(index(L) == -1){ //If cursor fall off the array
				append(L, j);
			} else{ //if cursor is still active
				insertBefore(L, j);
			}
		}
	}

	//Printing to the out file
	moveFront(L);
	while(index(L) != -1){ //Stops when cursor is out of bound
		fprintf(out, "%s", &line[get(L)]); //Prints List into output file "out"
		moveNext(L); //Move cursor to the next
	}

	//free memories. Prevent memory leaks
	for(int y = 0; y < lineNum; y++){
		free(&line[y]);
		line[y]=NULL;
	}

	//Close the read and write files
	fclose(in);
	fclose(out);

	return(EXIT_SUCCESS);
}
