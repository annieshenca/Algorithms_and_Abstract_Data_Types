/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa5
 * Due March 13, 2017
 * GraphTest.c
 */

#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"Graph.h"

int main(int argc, char* argv[]){
	int i, n=8;
	List S = newList(); //Stack
	Graph G = newGraph(n);

	for(i=1; i<n+1; i++){
		append(S, i); //1 to 8 on Stack S
	}

	addArc(G, 1,2);
	addArc(G, 2,3);
	addArc(G, 2,5);
	addArc(G, 2,6);
	addArc(G, 3,4);
	addArc(G, 3,7);
	addArc(G, 4,3);
	addArc(G, 4,8);
	addArc(G, 5,1);
	addArc(G, 5,6);
	addArc(G, 6,7);
	addArc(G, 7,6);
	addArc(G, 7,8);
	addArc(G, 8,8);
	fprintf(stdout, "G order: %i\n", getOrder(G));
	fprintf(stdout, "G size: %i\n", getSize(G));
	printGraph(stdout, G);
	fprintf(stdout, "\n");

	DFS(G,S);
	fprintf(stdout, "x:  d  f  p\n"); //vertex: discover time, finish time, parent
	for(i=1; i<n+1; i++){
		fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
	}
	fprintf(stdout, "\n");
	printList(stdout, S);
	fprintf(stdout, "\n");

	Graph T = transpose(G);
	printGraph(stdout, T);
	fprintf(stdout, "\n");
	Graph C = copyGraph(G);
	printGraph(stdout, C);
	fprintf(stdout, "\n");

	fprintf(stdout, "T order: %i\n", getOrder(T));
	fprintf(stdout, "T size: %i\n", getSize(T));
	DFS(T,S);
	fprintf(stdout, "x:  d  f  p\n"); //vertex: discover time, finish time, parent
	for(i=1; i<n+1; i++){
		fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(T, i), getFinish(T, i), getParent(T, i));
	}
	fprintf(stdout, "\n");
	printList(stdout, S);
	fprintf(stdout, "\n");

	freeList(&S);
	freeGraph(&G);
	freeGraph(&T);
	freeGraph(&C);
	return 0;
}
