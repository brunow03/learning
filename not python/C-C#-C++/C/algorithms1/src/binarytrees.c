#include "../include/binarytrees.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/randarray.h"

// Receives the root r of a binary tree
// and prints the contents of its nodes
// in left-root-right order.

void leftrootright (tree r) {
	if (r != NULL) {
		leftrootright (r->lft);
		printf ("%d\n", r->contents);
		leftrootright (r->rght); 
	}
}

node *createNode(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode != NULL) {
        newNode->contents = value;
        newNode->lft = NULL;
        newNode->rght = NULL;
    }
    return newNode;
}

tree initializeBinaryTree() {
    // Create nodes for the tree structure
    node *root = createNode(1);
    node *leftChild = createNode(2);
    node *rightChild = createNode(3);

    // Build the tree structure
    root->lft = leftChild;
    root->rght = rightChild;

    return root; // Return the root of the binary tree
}

void numberofnodes (tree r, int *n) {
	if (r != NULL) {
		*n++;
		numberofnodes (r->lft, n);
		numberofnodes (r->rght, n); 
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
tree randombinarytree (tree r, int n){





	return ret_tree;
}
*/