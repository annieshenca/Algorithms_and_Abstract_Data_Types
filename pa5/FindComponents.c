/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa5
 * Due March 13, 2017
 * FindComponents.c
 */

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#define MAX_LENGTH 100

int main(int argc, char*argv[]){

	if(argc != 3){ //Check for in and out files
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* in = fopen(argv[1], "r"); //"r" for reading
	FILE* out = fopen(argv[2], "w"); //"w" for writing
	char c [MAX_LENGTH];
	int size = 0;
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
	Graph G = newGraph(size); //create a Graph with size of size
	int flag =  0;

	while(fgets(c, MAX_LENGTH, in) != NULL && flag == 0){
		sscanf(c, "%d %d",&u,&v);
		if(u != 0 && v !=0){
			addArc(G,u,v);
		} else{ //ends when reached end of input: u==0 || v==0
			flag = 1;
		}
	} //get out of while loop once reach 0 0 pair

	List S = newList();
	for(int i = 1; i < getOrder(G)+1;i++){
		append(S,i);
	}

	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(out, G); //prints u and v to output file

	DFS(G, S);
	Graph T = transpose(G);
	DFS(T, S);

	//printList(out, S);

	int numSCC = 0; //number of strongly connected components
	moveFront(S);
	for(int i = 1; i < getOrder(T)+1; i++){
		if(getParent(T, get(S)) == NIL){
			numSCC++; //once reach a vertex that has NIl as parent, then that's a set of scc. increment numSCC
		}
		moveNext(S);
	}
	//fprintf(out, "%i", numSCC);
	fprintf(out, "\n");
	fprintf(out, "G contains %i strongly connected components:\n", numSCC);
	List comp[numSCC + 1];

	moveBack(S); //start from the back of the Stack list
	for(int i = 1; i < numSCC+1; i++){
		comp[i] = newList(); //create component lists
		while(getParent(T, get(S)) != NIL){
			prepend(comp[i], get(S));
			movePrev(S);
		}
		//when reach the vertex that the parent is NIL
		prepend(comp[i], get(S));
		movePrev(S);
	}


	for(int i = 1; i < numSCC+1; i++){
		fprintf(out, "Component %i: ", i);
		printList(out, comp[i]);
		fprintf(out, "\n");
		freeList(&comp[i]);
	}

	freeGraph(&G);
	freeGraph(&T);
	freeList(&S);
	fclose(in);
	fclose(out);
	return 0;
}
