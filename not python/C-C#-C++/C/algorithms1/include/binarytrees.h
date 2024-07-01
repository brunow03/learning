#ifndef BINARYTREES_H
#define BINARYTREES_H

typedef struct recordt node;

struct recordt {
	int contents;
	struct recordt *lft;
	struct recordt *rght;
};

typedef node *tree;
// if has parent
/*
typedef struct recordt {
	int contents;
	struct recordt *prnt;
	struct recordt *lft, *rght;
} node;
*/

tree initializeBinaryTree(void);
node* create_node(int val);
void fillbinarytree(tree r);
void leftrootright (tree r);
void rootleftright(tree r);
void leftrightroot(tree r);
void numberofnodes (tree r, int *n);
void printleaves(tree r);
void prettyprintbinarytree(tree r);
node *find_value(tree r, int val);
node *first (tree r);
node *nextnode (node *x);
void breadth_traversal(tree r);
// tree randombinarytree (tree r, int n);

#endif // BINARYTREES_H
