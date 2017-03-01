/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa4
 * Due March 1, 2017
 * GraphTest.c
 */

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(){
	int n = 10;
	Graph G = newGraph(n);
	//List L = newList();

	addEdge(G, 1, 2);
	addEdge(G, 1, 6);
	addEdge(G, 2, 3);
	addEdge(G, 2, 4);
	addEdge(G, 5, 2);
	addEdge(G, 3, 6);
	addEdge(G, 4, 8);
	addEdge(G, 9, 2);
	addEdge(G, 1, 9);
	addEdge(G, 7, 6);
	addEdge(G, 7, 2);
	addEdge(G, 9, 10);

	printf("vertices: %i\n",getOrder(G));
	printf("edges: %i\n",getSize(G));
	printf("distance: %i\n",getDist(G,3));
	printf("parent: %i\n",getParent(G,4));
	printGraph(stdout, G);
	makeNull(G);

	printf("\n");
	printf("edges: %i\n",getSize(G));
	printf("distance: %i\n",getDist(G,1));
	printGraph(stdout, G);

	printf("\n");
	G = newGraph(6);
	addEdge(G, 1, 4);
	addEdge(G, 1, 5);
	addEdge(G, 2, 3);
	addEdge(G, 2, 4);
	addEdge(G, 2, 6);
	addEdge(G, 3, 6);
	addEdge(G, 4, 5);
	addEdge(G, 5, 6);
	printf("size: %i\n",getSize(G));
	printGraph(stdout, G);

	int source = 3;
	int destination = 5;
	BFS(G,source);
	printf("The distance from %i to %i is %i\n", source, destination, getDist(G,destination));
	printf("parent: %i\n",getParent(G,1));
	makeNull(G);

	printf("\n");
	n = 3;
	G = newGraph(n);
	addArc(G, 1, 2);
	//addArc(G, 1, 3);
	addArc(G, 2, 3);
	//addArc(G, 3, 1);
	printGraph(stdout, G);
	source = 1;
	destination = 3;
	BFS(G,source);
	printf("The distance from %i to %i is %i\n", source, destination, getDist(G,destination));

	freeGraph(&G);
}
