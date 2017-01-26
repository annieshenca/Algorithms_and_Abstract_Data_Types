/*
 * Annie Shen
 * ashen7 #1562848
 * CMPS 101 pa2
 * List.c
 */

include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"

//private types -------------------------------------------------------

//NodeObj
typedef struct NodeObj{
    char* key;
    char* value;
    struct NodeObj* next;
} NodeObj;

//Node
typedef NodeObj* Node;

//newNode()
//constructor for Node type
Node newNode(char* k, char* v) {
    Node N = malloc(sizeof(NodeObj));
    assert(N!=NULL); //die if N equals to NULL
    N->key = k;
    N->value = v;
    N->next = NULL;
    return(N);
}

//freeNode()
//destructor for the Node type
void freeNode(Node* pN){
    if( pN!=NULL && *pN!=NULL ){
        free(*pN); //prevent memory leak
        *pN = NULL;
    }
}

//DictionaryObj
typedef struct DictionaryObj{
   Node top;
   int numItems;
} DictionaryObj;


//public functions -----------------------------------------------

//newDictionary()
//constructor for the Dictionary type
Dictionary newDictionary(void){
   Dictionary D = malloc(sizeof(DictionaryObj));
   assert(D!=NULL);
   D->top = NULL;
   D->numItems = 0;
   return D;
}

//freeDictionary()
//destructor for the Dictionary type
void freeDictionary(Dictionary* pD){
   if( pD!=NULL && *pD!=NULL ){
       if( !isEmpty(*pD) ){
           makeEmpty(*pD);
       }
       free(*pD);
       *pD = NULL;
   }
}

//isEmpty()
//returns 1 (true) if D is empty, 0 (false) otherwise
int isEmpty(Dictionary D) {
    if (D == NULL) { //when Dictionary is NULL
        fprintf(stderr, "Dictionary Error: calling isEmpty() on NULL Dictionary reference\n");
    } else if(D->numItems == 0) {
        return 1; //return true because it is empty
    } else{
        return 0; //return false saying it is NOT empty
    }
}

//size()
//returns the size of (key,value) pair in D
int size(Dictionary D){
    return D->numItems;
}

//lookup()
//return the value that is in D's (key, value), else return NULL if there's no such key
char* lookup(Dictionary D, char* k){
    Node N = D->top;

    while (N != NULL){
        if(strcmp(N->key, k) == 0){ //(=0) means true, (=1) equals false
            //printf("lookup: %s\n",N->value);
            return N->value;
        }
        N = N->next;
    }
    //printf("null\n");
    return NULL; //return NULL if there's no such pair
}

//insert()
//insert new (key, value) into D
void insert(Dictionary D, char* k, char* v) {
    //considering if D is empty or already had contents
    Node N = newNode(k, v); //new Node

    if (lookup(D, k) == NULL) { //the pair doesn't exist in D yet
            N->next = D->top;
            D->top = N;
            D->numItems++;
        }
     else{ //the key is duplicate!
        fprintf(stderr, "Dictionary error: cannot insert duplicate keys\n");
        exit(EXIT_FAILURE);
    }
    //Forgot this is Stack, not Queue!
//    Node top = D->top;
//    Node new = newNode(k, v);
//
//    if(lookup(D, k) == NULL) { //if the pair doesn't exist
//        if(top == NULL) { //if D is empty
//            top = new;
//        } else { //if D is NOT empty
//            if(top->next != NULL) {
//                top = top->next;
//            }
//            top->next = new;
//        }
//        D->numItems++; //now one more item
//    } else{ //as in if the key existed
//        fprintf(stdout, "Dictionary error: cannot insert duplicate keys");
//    }
}

//delete()
//delete k key from D's (key, value)
void delete(Dictionary D, char* k){
    Node N = D->top;

    if(lookup(D, k) == NULL){
        fprintf(stderr, "Dictionary error: cannot delete non-existing keys\n");
        exit(EXIT_FAILURE);
    }

    //If the key is found! then:
    if(strcmp(N->key, k) == 0){ //if the first node matches the key
        D->top = N->next;
        freeNode(&N); //prevent memory leak
        N = NULL; //initialize
        D->numItems--;

    } else{ //if it's after the first node
        //int found = 0;
        while(N != NULL && N->next != NULL){
            if(strcmp(N->next->key, k) == 0){//(=0) means true, (=1) equals false
                Node G = N;
                Node C = N->next;
                G->next = C->next;
                N = G;
                freeNode(&C);
                //Node temp = N->next; //set M as N
                //N->next = N->next->next; //set temp as N's next key
                //freeNode(&temp); //discard temp
                //temp = NULL;
                D->numItems--;
                //found =1;
            }
            N = N->next; //loop until key is found
        }

    }
}

void empty(Node N){
    if(N != NULL){
        empty(N->next);
        freeNode(&N);
    }
}

//makeEmpty()
//resets-empty Dictionary D
void makeEmpty(Dictionary D){
    empty(D->top);
    D->top = NULL;
    D->numItems = 0;
}

//printRec()
//additional help for printDictionary() to print recursively
void printRec(FILE* out, Node N){
    //printf("in printRec, outside of while loop");
    if(N != NULL) {
        printRec(out, N->next);
        //printf("in printRec");
        fprintf(out, "%s %s\n", N->key, N->value);
    }
}

//printDictionary()
//prints a text representation of D to the file pointed to by out
void printDictionary(FILE* out, Dictionary D){
    //Node N;

    if(D == NULL){
        fprintf(stderr, "Dictionary Error: calling printDictionary() on NULL Dictionary reference\n");
        exit(EXIT_FAILURE);
    }
    //printf("in printDictionary, in loop before calling printRec\n");
    printRec(out, D->top);

//    for(N=D->top; N!=NULL; N=N->next){
//        fprintf(out, "%s %s\n", N->key, N->value);
//    }
}
