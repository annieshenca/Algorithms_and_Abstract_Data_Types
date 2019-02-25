/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa5
 * Due March 13, 2017
 * Graph.c
 */

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

#define WHITE 0
#define GREY 1
#define BLACK 2

void Visit(Graph G, List S, int x, int* time);

//Private GraphObj type
typedef struct GraphObj{
	List* list;
	int* color;		//white=0, grey=1, black=2
	int* parent;	//parent vertex
	int* disc;		//discover time between vertices
	int* fin;		//finished
	int numVertex;	//number of vertices
	int numEdge; 	//number of edges
}GraphObj;

/********************* Constructors-Destructors *********************/
//newGraph()
//returns a Graph pointing to a newly created GraphObj representing a
//graph having n vertices and no edges.
Graph newGraph(int n){
	Graph graph = malloc(sizeof(GraphObj));
	graph->list = malloc(sizeof(List)*(n+1));
	graph->color = malloc(sizeof(int)*(n+1));
	graph->parent = malloc(sizeof(int)*(n+1));
	graph->disc = malloc(sizeof(int)*(n+1));
	graph->fin = malloc(sizeof(int)*(n+1));
	graph->numVertex = n; //given n = number of vertices the new Graph has
	graph->numEdge = 0;
	for(int i = 1; i < n+1; i++){
		graph->list[i] = newList();
		graph->color[i] = WHITE; 	//color = 0(white)
		graph->disc[i] = UNDEF; 	//distance = infinity
		graph->parent[i] = NIL; 	//parent = 0
		graph->fin[i] = UNDEF;
	}
	return graph;
}

//freeGraph()
//frees all dynamic memory associated with the Graph *pG, then sets the handle *pG to NULL
void freeGraph(Graph* pG){
	if(pG != NULL && *pG != NULL){ //check if there's anything in pG to be freed.
		//free array of lists
		for(int i = 1; i < getOrder(*pG)+1; i++){
			freeList(&((*pG)->list[i]));
		}
		//free arrays
		free((*pG)->list);
		free((*pG)->color);
		free((*pG)->disc);
		free((*pG)->parent);
		free((*pG)->fin);
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

//getParent()
//return the parent of vertex u in the DFS tree created by BFS(),
//or NIL if DFS() has not yet been called
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

//getDiscover()
//return discover time
//pre:G!= NULL, 1 <= u <= getOrder(G)
int getDiscover(Graph G, int u){
	if(G == NULL){
			printf("getDiscover error: calling NULL Graph.");
			exit(EXIT_FAILURE);
	}
	if(u < 1){
		printf("getDiscover error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(u > getOrder(G)){
		printf("getDiscover error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	return G->disc[u];
}

//getFinish()
//return finish time
//pre:1 <= u <= n = getOrder(G)
int getFinish(Graph G, int u){
	if(G == NULL){
			printf("getFinish error: calling NULL Graph.");
			exit(EXIT_FAILURE);
	}
	if(u < 1){
		printf("getFinish error: vertex u < 1.");
		exit(EXIT_FAILURE);
	}
	if(u > getOrder(G)){
		printf("getFinish error: vertex u > numVertex.");
		exit(EXIT_FAILURE);
	}
	return G->fin[u];
}


/********************* Manipulation procedures *********************/

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
	if(length(U) == 0){ //if length of list[u] is 0 == empty
		prepend(U, v); //insert in the front
	} else{
		moveFront(U);
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
	if(length(V) == 0){ //if length of list[u] is 0 == empty
		prepend(V, u); //insert in the front
	} else{
		moveFront(V);
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
	if(length(U) == 0){ //if length of list[u] is 0 == empty
		prepend(U, v); //insert in the front
	} else{
		moveFront(U);
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

//DFS()
//Depth-First Search algorithm of G. List S defines the order in which vertices will
//be processed in main loop, then when DFS is complete, it will store the vertices in order
//of decreasing finish times (S is a stack).
//pre: G != NULL, length(S)==getOrder(G)
void DFS(Graph G, List S){
	if(G == NULL){
		printf("DFS error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	if(length(S) != getOrder(G)){
		printf("DFS error: length(S) != getOrder(G).");
		exit(EXIT_FAILURE);
	}

	for(int i = 1; i < getOrder(G)+1; i++){
		G->color[i] = WHITE;
		G->parent[i] = NIL;
		G->disc[i] = UNDEF;
		G->fin[i] = UNDEF;
	}
	int time = 0; //initialize time variable to keep track of disc & fin time
	moveFront(S); //move cursor to the front of the list S of vertices
	while(index(S) != -1){ //while cursor in bound
		if(G->color[get(S)] == WHITE){ //if the vertex haven't been discovered
			Visit(G, S, get(S), &time);
		}
		moveNext(S);
	}

	for(int i = 1; i < getOrder(G)+1; i++){
		deleteBack(S);
	}
}

//Visit()
//recursive function to help DFS() work
void Visit(Graph G, List S, int x, int* time){
	G->color[x] = GREY;
	G->disc[x] = ++*time; //set discover time to current time
	moveFront(G->list[x]); //move cursor to the front
	while(index(G->list[x]) != -1){
		int y = get(G->list[x]);
		if(G->color[y] == WHITE){ //if the vertex is WHITE(undiscovered), discover it
			G->parent[y] = x;
			Visit(G, S, y, time); //recursive Visit
		}
		moveNext(G->list[x]); //move on to next list
	}
	G->color[x] = BLACK; //discovered and finished, set color to BLACK
	G->fin[x] = ++*time; //set finish time
	prepend(S, x); //prepend to Stack S
}

/********************* Other operations *********************/

//transpose()
//returns a reference to a new graph object representing the transpose of G
//pre: G != NULL
Graph transpose(Graph G){
	if(G == NULL){
		printf("transpose error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	Graph T = newGraph(getOrder(G)); //created a new graph to store transposed graph in
	for(int i = 1; i < getOrder(G)+1; i++){
		moveFront(G->list[i]); //move to the front of the list[i]
		//printf("index num: %i\n", index(G->list[i]));
		while(index(G->list[i]) != -1){ //while in bound
			//insert arc based on what vertex cursor is pointing to , then store into corresponding list number
			addArc(T, get(G->list[i]), i);
			//printf("what? %i\n",get(G->list[i]));
			moveNext(G->list[i]); //move on to the next element
		}
	}
	return T;
}

//copyGraph()
//returns a reference to a new graph which is a direct copy of G
//pre: G != NULL
Graph copyGraph(Graph G){
	if(G == NULL){
		printf("copyGraph error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	Graph C = newGraph(getOrder(G)); //new graph to store copied graph in
	for(int i = 1; i < getOrder(G)+1; i++){
		moveFront(G->list[i]);
		while(index(G->list[i]) != -1){ //while in bound
			//Almost the same process as transpose()
			//printf("index & vertex: %i %i\n", index(G->list[i]),get(G->list[i]));
			addArc(C, i, get(G->list[i]));
			moveNext(G->list[i]);
		}
	}
	return C;
}

//printGraph()
//prints the adjacency list representation of G to the file pointed to by out
//pre: G != NULL
void printGraph(FILE* out, Graph G){
	if(G == NULL){
		fprintf(out, "printGraph error: calling NULL Graph.");
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i < getOrder(G)+1; i++){
		fprintf(out, "%d: ", i); //"i: "
		if(G->list[i] == NULL){ //if the list is empty
			//to avoid List ADT's printList error message from printList()
			fprintf(out, "");
		} else{
			printList(out, G->list[i]); //calling List ADT's printList function to print out
		}
		fprintf(out, "\n"); //new line
	}
} //end printGraph()
