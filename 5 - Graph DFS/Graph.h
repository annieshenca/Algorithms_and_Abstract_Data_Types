/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa5
 * Due March 13, 2017
 * Graph.h
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "List.h"

#define UNDEF -1
#define NIL 0 //represents undefined vertex label

typedef struct GraphObj* Graph;

/********************* Constructors-Destructors *********************/
//newGraph()
//returns a Graph pointing to a newly created GraphObj representing a
//graph having n vertices and no edges.
Graph newGraph(int n);

//freeGraph()
//frees all dynamic memory associated with the Graph *pG, then sets the handle *pG to NULL
void freeGraph(Graph* pG);

/********************* Access functions *********************/
//getOrder()
//returns number of vertices in G
//pre: G != NULL
int getOrder(Graph G);

//getSize()
//returns number of edges
//pre: G != NULL
int getSize(Graph G);

//getParent()
//return the parent of vertex u in the Breadth-First tree created by BFS(),
//or NIL if BFS() has not yet been called
//pre: G != NULL, 1 <= u <= getOrder(G) (number of vertices)
int getParent(Graph G, int u);

//getDiscover()
//return the appropriate field values for the given vertex.
//pre:1 <= u <= n = getOrder(G)
int getDiscover(Graph G, int u);

//getFinish()
//return the appropriate field values for the given vertex.
//pre:1 <= u <= n = getOrder(G)
int getFinish(Graph G, int u);

/********************* Manipulation procedures *********************/

//addEdge()
//inserts a new edge joining u to v
//i.e.: u is added to the adjacency List of v, and v to the adjacency List of u.
//pre: G != NULL, 1 <= u <= getOrder(G), 1 <= v <= getOrder(G)
void addEdge(Graph G, int u, int v);

//addArc()
//inserts a new directed edge from u to v
//i.e.: v is added to the adjacency List of u (but not u to the adjacency List of v).
//pre: G != NULL, 1 <= u <= getOrder(G), 1 <= v <= getOrder(G)
void addArc(Graph G, int u, int v);

//DFS()
//pre: length(S)==getOrder(G)
void DFS(Graph G, List s);

/********************* Other operations *********************/

//transpose()
Graph transpose(Graph G);

//copyGraph()
Graph copyGraph(Graph G);

//printGraph()
//prints the adjacency list representation of G to the file pointed to by out
//pre: G != NULL
void printGraph(FILE* out, Graph G);


#endif /* GRAPH_H_ */
