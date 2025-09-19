#ifndef BINARYTREES_H
#define BINARYTREES_H

//  o->key  ≤  p->key  ≤  q->key 

typedef struct recordt treenode;

struct recordt {
	int key;
	int contents;
	struct recordt *lft;
	struct recordt *rght;
};

typedef treenode *tree;
// if has parent
/*
typedef struct recordt {
	int contents;
	struct recordt *prnt;
	struct recordt *lft, *rght;
} treenode;
*/

tree initializeBinaryTree(void);
treenode* create_treenode(int val);
void fillbinarytree(tree r);
void leftrootright (tree r);
void rootleftright(tree r);
void leftrightroot(tree r);
void numberoftreenodes (tree r, int *n);
void printleaves(tree r);
void prettyprintbinarytree(tree r);
treenode *find_value(tree r, int val);
treenode *first (tree r);
treenode *nexttreenode (treenode *x);
void breadth_traversal(tree r);
// tree randombinarytree (tree r, int n);

#endif // BINARYTREES_H
