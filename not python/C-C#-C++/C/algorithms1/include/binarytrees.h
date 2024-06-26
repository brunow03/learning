#ifndef BINARYTREES_H
#define BINARYTREES_H

typedef struct recordt node;

struct recordt {
	int contents;
	struct recordt *lft;
	struct recordt *rght;
};

typedef node *tree;

tree initializeBinaryTree();
node* create_node(int value);
void leftrootright (tree r);
void numberofnodes (tree r, int *n);
tree randombinarytree (tree r, int n);
void printbinarytree(tree r);

#endif // BINARYTREES_H
