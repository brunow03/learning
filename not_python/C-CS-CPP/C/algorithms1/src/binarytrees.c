#include <stdlib.h>
#include <stdio.h>
#include "binarytrees.h"
#include "randarray.h"

static int lv = 0;

void prettyprintbinarytree(tree r){	// =============>>>>>>>> check if this works!!!!!!!

	for (int i = 0; i < lv; ++i) {
		printf("\t");
	}

	if (r == NULL) {
		printf("-\n");
		return;
	}
	else {
		printf ("%d\n", r->contents);
		lv++;
		prettyprintbinarytree (r->lft);
		prettyprintbinarytree (r->rght);
		printf("\b");
		lv--;
	}
}

// Receives the root r of a binary tree
// and prints the contents of its treenodes
// in left-root-right order.

void leftrootright (tree r) {
	if (r != NULL) {
		leftrootright (r->lft);
		printf ("%d\n", r->contents);
		leftrootright (r->rght); 
	}
}

void rootleftright(tree r){
	if (r != NULL) {
		printf ("%d\n", r->contents);
		rootleftright (r->lft);
		rootleftright (r->rght); 
	}
}

void leftrightroot(tree r){
	if (r != NULL) {
		leftrootright (r->lft);
		leftrootright (r->rght); 
		printf ("%d\n", r->contents);
	}
}

// Breadth-firt travaersal

// User filled binary tree in root left right order
/*
void fillbinarytree(tree r){
	if (r == NULL)
	{
		fprintf(stderr, "Error. Tree uninitialized. Initialize binary tree first.\n");
	}

	// Tree gets filled up as if it was read in a leftroot right traversal (for now)
	if (r != NULL) {
		rootleftright (r->lft);
		rootleftright (r->rght);

	}
}*/

treenode *create_treenode(int val) {
    treenode *newtreenode = (treenode *)malloc(sizeof(treenode));
    if (newtreenode != NULL) {
    	newtreenode->contents = val;
        newtreenode->lft = NULL;
        newtreenode->rght = NULL;
    }
    return newtreenode;
}
/*
tree initializeBinaryTree() {
    // Create treenodes for the tree structure
    treenode *root = createtreenode();
    return root; // Return the root of the binary tree
}*/

void numberoftreenodes (tree r, int *n) {
	if (r != NULL) {
		(*n)++;
		numberoftreenodes (r->lft, n);
		numberoftreenodes (r->rght, n); 
	}
}

// Returns the height of the binary tree r.

int height (tree r) {
	if (r == NULL) 
		return -1; // height of empty tree
	else {
		int he = height (r->lft);
		int hd = height (r->rght);
		if (he < hd) return hd + 1;
		else return he + 1;
	}
}
/*
treenode * find_value(tree r, int val){

}*/


// Receives a nonempty binary tree r and
// returns the first treenode of the tree in
// the left-root-right traversal.

treenode *first (tree r) {  
	while (r->lft != NULL) 
		r = r->lft;
	return r;
}

// Receives a treenode x. Returns the successor of
// x in the left-root-right traversal or NULL
// if x is the last treenode. The function assumes
// that x != NULL.
/*
treenode *nexttreenode (treenode *x) {  
	if (x->rght != NULL) {
		treenode *y = x->rght; 
		while (y->lft != NULL) y = y->lft;
		return y;                                  // A
	}
	while (x->prnt != NULL && x->prnt->rght == x) // B 
		x = x->prnt;                               // B
	return x->prnt;
}*/

void printleaves(tree r){
	if (r != NULL) {
		printleaves (r->lft);
		if (r->lft == NULL && r->rght == NULL)
			printf ("%d\n", r->contents);
		printleaves (r->rght); 
	}
}

treenode *find_value(tree r, int val){
	if (r != NULL) {
        treenode *found = find_value(r->lft, val); 
        if (found != NULL) return found;
        if (r->contents == val)	return r;
        return find_value(r->rght, val);
    }
    return NULL; // Value not found
}

int isbinarytree(tree r) {
	if (r->lft == NULL && r->rght == NULL) return 1;
	else if (r->key < r->lft->key && r->key > r->rght->key) return 0;
	else return isbinarytree(r->lft) && isbinarytree(r->rght);
}