#include <stdio.h>
#include <limits.h>
#include "binarytrees.h"

int main(int argc, char const *argv[])
{
	tree myTree;
	myTree = create_treenode(1);
	myTree->lft = create_treenode(2);
    myTree->rght = create_treenode(3);
    myTree->lft->lft = create_treenode(4);
    myTree->lft->rght = create_treenode(5);
    myTree->rght->rght = create_treenode(6);
    myTree->lft->lft->lft = create_treenode(7);
    myTree->rght->rght->lft = create_treenode(8);
    myTree->rght->rght->rght = create_treenode(9);
    myTree->lft->lft->rght = create_treenode(10);
    myTree->lft->rght->lft = create_treenode(11);
    myTree->lft->rght->rght = create_treenode(12);
    myTree->rght->rght->rght->lft = create_treenode(13);
    myTree->rght->rght->rght->rght = create_treenode(14);
    myTree->lft->lft->lft->lft = create_treenode(15);
    myTree->lft->lft->lft->rght = create_treenode(16);
    myTree->lft->rght->lft->lft = create_treenode(17);
    myTree->lft->rght->lft->rght = create_treenode(INT_MAX);
    myTree->lft->rght->rght->lft = create_treenode(19);
    myTree->lft->rght->rght->rght = create_treenode(20);
    myTree->rght->rght->rght->lft->lft = create_treenode(21);
    myTree->rght->rght->rght->lft->rght = create_treenode(22);
    myTree->rght->rght->rght->rght->lft = create_treenode(23);
    myTree->rght->rght->rght->rght->rght = create_treenode(24);
	
    prettyprintbinarytree(myTree);

    return 0;
}