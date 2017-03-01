//-----------------------------------------------------------------------------
//
// GraphClient.c
// 
// This is a fancy test client that calculates the Radius and Diameter of 
// the graph defined on lines 41-49, along with its Central and Peripheral 
// vertices.  The definitions of these terms at:
// 
//    http://en.wikipedia.org/wiki/Distance_(graph_theory)
// 
// Place this file in a directory with copies of your List.c, List.h, Graph.c, 
// Graph.h and an appropriate Makefile, then compile and run. The output 
// is contained in the file GraphClientOut.
// 
// This program does not exercise all functions in your Graph ADT, but it 
// does a pretty good job of testing BFS().  If your output differs from 
// the above, you have a logical problem in either your Graph or List ADT.
// 
// Remember you are required to submit a file named GraphTest.c with pa4 that
// exercises your Graph functions.  Do not submit this file.
//
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(){
	Graph g = newGraph(5);
	freeGraph(&g);
	g = newGraph(5);
	printf("vertices: %i\n",getOrder(g));
	printf("edges: %i\n",getSize(g));
	printf("distance: %i\n",getDist(g,1));
	printf("parent: %i\n",getParent(g,1));
	//printf("%i\n",getParent(g,0));
	//printf("%i\n",getDist(g,6));
	printf("get dist: %i\n",getDist(g,5));
	freeGraph(&g);
	//printf("%i\n",getDist(g,5));
	g = newGraph(5);
	addEdge(g,1,2);
	addEdge(g,1,3);
	addEdge(g,1,4);
	addEdge(g,2,3);
	//addEdge(g,6,1);
	//addEdge(g,0,1);
	//addEdge(g,5,0);
	//addEdge(g,5,6);
	printf("size: %i\n",getSize(g));
	printGraph(stdout,g);

	makeNull(g);
	printGraph(stdout,g);
	g = newGraph(6);
	addEdge(g,1,3);
	addEdge(g,1,2);
	addEdge(g,2,4);
	addEdge(g,2,5);
	addEdge(g,2,6);
	addEdge(g,3,4);
	addEdge(g,4,5);
	addEdge(g,5,6);
	printGraph(stdout,g);
//	int s = 3;
//	int d = 2;
//	BFS(g,s);
//	List l = newList();
//	printf("The distance from %i to %i is %i\n",s,d,getDist(g,d));
//	getPath(l,g,2);
//	printList(stdout,l);
//	makeNull(g);
	freeGraph(&g);
//	return 0;
}

//5
//0
//-1
//0
//get dist-1
//size: 4
//1: 2 3 4
//2: 1 3
//3: 1 2
//4: 1
//5:
//1:
//2:
//3:
//4:
//5:
//1: 2 3
//2: 1 4 5 6
//3: 1 4
//4: 2 3 5
//5: 2 4 6
//6: 2 5
//The distance from 3 to 2 is 2
//3 1 2
//Process finished with exit code 0
