/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa4
 * Due March 1, 2017
 * Graph.c
 */

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INF -1 //represent infinity, because there's no such thing as negative distance
#define NIL 0 //represents undefined vertex label

//Private GraphObj type
typedef struct GraphObj{
	List* list;
	int* color;		//white=0, grey=1, black=2
	int* dist;		//distance between vertices
	int* parent;	//parent vertex
	int numVertex;	//number of vertices
	int numEdge; 	//number of edges
	int source; 	//the source vertex
}GraphObj;

/********************* Constructors-Destructors *********************/
//newGraph()
//returns a Graph pointing to a newly created GraphObj representing a
//graph having n vertices and no edges.
Graph newGraph(int n){
	Graph graph = malloc(sizeof(GraphObj));
	graph->list = malloc(sizeof(List)*(n+1));
	graph->color = malloc(sizeof(int)*(n+1));
	graph->dist = malloc(sizeof(int)*(n+1));
	graph->parent = malloc(sizeof(int)*(n+1));
	graph->numVertex = n; //given n = number of vertices the new Graph has
	graph->numEdge = 0;
	graph->source = NIL; //undefined vertex
	for(int i = 1; i < n+1; i++){
		graph->list[i] = newList();
		graph->color[i] = WHITE; 	//color = 0(white)
		graph->dist[i] = INF; 	//distance = infinity
		graph->parent[i] = NIL; //parent = 0
	}
	return graph;
}

//freeGraph()
//frees all dynamic memory associated with the Graph *pG, then sets the handle *pG to NULL
void freeGraph(Graph* pG){
	if(pG != NULL && *pG != NULL){ //check if there's anything in pG to be freed.
		//free array of lists
		for(int i = 1; i < getOrder(*pG); i++){
			freeList(&((*pG)->list[i]));
		}
		//free arrays
		free((*pG)->list);
		free((*pG)->color);
		free((*pG)->dist);
		free((*pG)->parent);
		free(*pG);
		*pG = NULL;
	}
}

/********************* Access functions *********************/
//getOrder()
//returns number of vertices
//pre: G != NULL
int getOrder(Graph G){
	if(G == NULL){
		printf("getOrder error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	return G->numVertex;
}

//getSize()
//returns number of edges
//pre: G != NULL
int getSize(Graph G){
	if(G == NULL){
		printf("getSize error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	return G->numEdge;
}

//getSource()
//returns the source vertex most recently used in function BFS(),
//or NIL if BFS() has not yet been called
//pre: G != NULL
int getSource(Graph G){
	if(G == NULL){
		printf("getSource error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	return G->source;
}

//getParent()
//return the parent of vertex u in the Breadth-First tree created by BFS(),
//or NIL if BFS() has not yet been called
//pre: G != NULL, 1 <= u <= getOrder(G) (number of vertices)
int getParent(Graph G, int u){
	if(G == NULL){
		printf("getParent error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	if(u < 1){
		printf("getParent error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(u > getOrder(G)){
		printf("getParent error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	return G->parent[u];
}

//getDist()
//returns the distance from the most recent BFS source to vertex u,
//or INF if BFS() has not yet been called
//pre: G != NULL,  1 <= u <= getOrder(G) (number of vertices)
int getDist(Graph G, int u){
	if(G == NULL){
		printf("getDist error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	if(u < 1){
		printf("getDist error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(u > getOrder(G)){
		printf("getDist error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	if(getSource(G) == NIL){ //not yet been called
		return INF;
	}else{
		return G->dist[u];
	}
}

//getPath()
//appends to the List L the vertices of a shortest path in G from source
//to u, or appends to L the value NIL if no such path exists
//pre: getSource(G) != NIL, 1 <= u <= getOrder(G) (number of vertices)
void getPath(List L, Graph G, int u){
	if(G == NULL){
		printf("getPath error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	if(u < 1){
		printf("getPath error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(u > getOrder(G)){
		printf("getPath error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	if(getSource(G) == NIL){
		append(L, NIL);
	}else{
		if(G->parent[u] == NIL){
			append(L, u);
		}else{
			//uses recursion to find the highest parent, then come back and append elements into list L
			getPath(L,G,G->parent[u]);
			append(L, u);
		}
	}
}

///********************* Manipulation procedures *********************/
//makeNull()
//deletes all edges of G, restoring it to its original (no edge) state.
//pre: G != NULL
void makeNull(Graph G){
	if(G == NULL){
		printf("makeNULL error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i < getOrder(G)+1; i++){ //reset everything
		clear(G->list[i]);
		G->color[i] = WHITE; //== 0
		G->dist[i] = INF; //== -1
		G->parent[i] = NIL; //== 0
	}
	//G->numVertex = 0; //Don't change number of vertices
	G->numEdge = 0;
	G->source = NIL; //not discovered. == 0
}

//addEdge()
//inserts a new edge joining u to v
//i.e.: u is added to the adjacency List of v, and v to the adjacency List of u.
//pre: G != NULL, 1 <= u <= getOrder(G), 1 <= v <= getOrder(G)
void addEdge(Graph G, int u, int v){
	if(G == NULL){
		printf("addEdge error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	if(u < 1){
		printf("getPath error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(u > getOrder(G)){
		printf("getPath error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	if(v < 1){
		printf("getPath error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(v > getOrder(G)){
		printf("getPath error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	//directed graphs. both ways
	//from u to v first
	List U = G->list[u];
	//moveFront(U);
	if(length(U) == 0){ //if length of list[u] is 0 == empty
		prepend(U, v); //insert in the front
	} else{
		//printf("U:1\n");
		moveFront(U);
		//printf("U:2\n");
		while(index(U) != -1 && get(U) < v){
			//while the matrix cursor is not invalid(-1), and the matrix's ith is less than j
			moveNext(U);
		}
		if(index(U) == -1){ //if the cursor falls off the list
			append(U,v);
		} else{
			insertBefore(U, v);
		}
	}

	//from v to u
	List V = G->list[v];
	//moveFront(V);
	if(length(V) == 0){ //if length of list[u] is 0 == empty
		prepend(V, u); //insert in the front
	} else{
		//printf("V:1\n");
		moveFront(V);
		//printf("V:1\n");
		while(index(V) != -1 && get(V) < u){
			//while the matrix cursor is not invalid(-1), and the matrix's ith is less than j
			moveNext(V);
		}
		if(index(V) == -1){ //if the cursor falls off the list
			append(V,u);
		} else{
			insertBefore(V, u);
		}
	}
	G->numEdge++;
//	free(&U);
//	free(&V);
}

//addArc
//inserts a new directed edge from u to v
//i.e.: v is added to the adjacency List of u (but not u to the adjacency List of v).
//pre: G != NULL, 1 <= u <= getOrder(G), 1 <= v <= getOrder(G)
void addArc(Graph G, int u, int v){
	if(G == NULL){
		printf("addArc error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	if(u < 1){
		printf("addArc error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(u > getOrder(G)){
		printf("addArc error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	if(v < 1){
		printf("addArc error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(v > getOrder(G)){
		printf("addArc error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}

	//from u to v first
	List U = G->list[u];
	//moveFront(U);
	if(length(U) == 0){ //if length of list[u] is 0 == empty
		prepend(U, v); //insert in the front
	} else{
		printf("UU:1\n");
		moveFront(U);
		printf("UU:2\n");

		while(index(U) != -1 && get(U) < v){
			//while the matrix cursor is not invalid(-1), and the matrix's ith is less than j
			moveNext(U);
		}
		if(index(U) == -1){ //if the cursor falls off the list
			append(U,v);
		} else{
			insertBefore(U, v);
		}
	}
	G->numEdge++;
}

//BFS()
//runs the BFS algorithm on the Graph G with source s, setting the color,
//distance, parent, and source fields of G accordingly
//pre: G != NULL
void BFS(Graph G, int s){
	if(G == NULL){
		printf("BFS error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	//G->source = s;
	for(int i = 1; i< getOrder(G)+1; i++){
		G->color[i] = WHITE;
		G->dist[i] = INF;
		G->parent[i] = NIL;
	}
	G->source = s;
	int i = 0;
	int j = 0;
	G->color[s] = GREY; //discovered! but not done yet
	G->dist[s] = 0; //distance of source is always 0
	G->parent[s] = NIL; //source has no parent
	List Q = newList();
	append(Q, s); //insert source into list Q
	while(length(Q) != 0){
		i = front(Q); //save the front element of list Q as x
		deleteFront(Q); //pop off list Q
		//printf("G:1\n");
		moveFront(G->list[i]); //place cursor at the front of the list Q
		//printf("G:2\n");
		while(index(G->list[i]) != -1){ //while the cursor is in bound
			j = get(G->list[i]); //y = the element the cursor is currently pointing to
			if(G->color[j] == WHITE){ //if the current element has not been discovered yet, discover it!
				G->color[j] = GREY; //discovered
				G->dist[j] = G->dist[i] + 1; //distance is 1 more than it's parent distance
				G->parent[j] = i; //y is the child of x
				append(Q,j);
			}
			moveNext(G->list[i]); //move to next element on it's list
		}
		G->color[i] = BLACK; //all elements in it's list has been discovered and done!
	} //end of while
	//prevent memory leak
	freeList(&Q);
	Q = NULL;
}//end BFS()

/********************* Other operations *********************/
//printGraph()
//prints the adjacency list representation of G to the file pointed to by out
//pre: G != NULL
void printGraph(FILE* out, Graph G){
	if(G == NULL){
		fprintf(out, "printGraph error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i < getOrder(G)+1; i++){
		fprintf(out, "%d:", i); //"i: "
		if(G->list[i] == NULL){ //if the list is empty
			//to avoid List ADT's printList error message from printList()
			fprintf(out, "");
		} else{
			printList(out, G->list[i]); //calling List ADT's printList function to print out
		}
		fprintf(out, "\n"); //new line
	}
} //end printGraph()
