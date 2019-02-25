/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa4
 * Due March 1, 2017
 * Graph.h
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "List.h"

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
//returns number of vertices
//pre: G != NULL
int getOrder(Graph G);

//getSize()
//returns number of edges
//pre: G != NULL
int getSize(Graph G);

//getSource()
//returns the source vertex most recently used in function BFS(),
//or NIL if BFS() has not yet been called
//pre: G != NULL
int getSource(Graph G);

//getParent()
//return the parent of vertex u in the Breadth-First tree created by BFS(),
//or NIL if BFS() has not yet been called
//pre: G != NULL, 1 <= u <= getOrder(G) (number of vertices)
int getParent(Graph G, int u);

//getDist()
//returns the distance from the most recent BFS source to vertex u,
//or INF if BFS() has not yet been called
//pre: G != NULL,  1 <= u <= getOrder(G) (number of vertices)
int getDist(Graph G, int u);

//getPath()
//appends to the List L the vertices of a shortest path in G from source
//to u, or appends to L the value NIL if no such path exists
//pre: getSource(G) != NIL, 1 <= u <= getOrder(G) (number of vertices)
void getPath(List L, Graph G, int u);

/********************* Manipulation procedures *********************/
//makeNull()
//deletes all edges of G, restoring it to its original (no edge) state.
//pre: G != NULL
void makeNull(Graph G);

//addEdge()
//inserts a new edge joining u to v
//i.e.: u is added to the adjacency List of v, and v to the adjacency List of u.
//pre: G != NULL, 1 <= u <= getOrder(G), 1 <= v <= getOrder(G)
void addEdge(Graph G, int u, int v);

//addArc
//inserts a new directed edge from u to v
//i.e.: v is added to the adjacency List of u (but not u to the adjacency List of v).
//pre: G != NULL, 1 <= u <= getOrder(G), 1 <= v <= getOrder(G)
void addArc(Graph G, int u, int v);

//BFS()
//runs the BFS algorithm on the Graph G with source s, setting the color,
//distance, parent, and source fields of G accordingly
//pre: G != NULL
void BFS(Graph G, int s);

/********************* Other operations *********************/
//printGraph()
//prints the adjacency list representation of G to the file pointed to by out
//pre: G != NULL
void printGraph(FILE* out, Graph G);

#endif /* GRAPH_H_ */
