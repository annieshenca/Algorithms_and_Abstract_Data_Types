/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa4
 * Due March 1, 2017
 * FindPath.c
 */

#include "Graph.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 100

int main(int argc, char*argv[]){
	if(argc != 3){ //Check for in and out files
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//Open files for reading and writing
	FILE* in = fopen(argv[1], "r"); //"r" for reading
	FILE* out = fopen(argv[2], "w"); //"w" for writing
	char c [MAX_LENGTH];
	int size = 0; //
	int u = 0; //vertices
	int v = 0; //edges


	if(in == NULL){
		fprintf(out, "Unable to open file %s for reading\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if(out == NULL){
		fprintf(out, "Unable to open file %s for writing\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	fgets(c,MAX_LENGTH,in); //gets first line, which is the number of vertices
	sscanf(c, "%d", &size); //reads formatted input from a string, and store into int size
	//printf("vetices(size): %i\n",size);
	Graph G = newGraph(size);
	List L = newList();
	int flag =  0;

	while(fgets(c, MAX_LENGTH, in) != NULL && flag == 0){
		sscanf(c, "%d %d",&u,&v);
		if(u != 0 && v !=0){
			addEdge(G,u,v);
		} else{ //ends when reached end of input: u==0 || v==0
			flag = 1;
		}
	} //get out of while loop once reach 0 0 pair
	printGraph(out, G); //prints u and v to output file

	//fprintf(out, "c: %s\n",c);
	flag = 0; //reset flag back to 0

	//to read the second half of the input file. Calculating distance between u and v
	do{
		sscanf(c, "%d %d",&u,&v);
		//printf("u: %i\n",u);
		if(u != 0 && v !=0){
			BFS(G,u);
			fprintf(out, "\n");
			if(getDist(G,v) == -1){
				fprintf(out, "The distance from %d to %d is infinity\n", u, v);
				fprintf(out, "No %d-%d path exists\n", u, v);

			} else if(u == v){
				fprintf(out, "The distance from %d to %d is 0\n", u, v);
				fprintf(out, "A shortest %d-%d path is: %d", u, u, u);
				fprintf(out, "\n");

			} else{
				fprintf(out, "The distance from %d to %d is %d\n", u, v, getDist(G, v));
				fprintf(out, "A shortest %d-%d path is:", u, v);
				getPath(L,G,v); //get the path and store into list L
				printList(out, L); //print out the list of vertices
				fprintf(out, "\n");
			}
			clear(L);
		}
	}while(fgets(c,MAX_LENGTH,in) != NULL);

	freeGraph(&G);
	freeList(&L);
	fclose(in);
	fclose(out);
	return(0);
}
