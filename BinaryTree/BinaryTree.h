#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LEFT 0
#define RIGHT 1
#define DEFEND -1

typedef int status;

typedef struct {
	int No;
	char name[20];
	float price;
}Product;

typedef struct {
	int isNode;
	Product *data;
}definition;

//定义树的结点
typedef struct BiTNode{
	struct BiTNode *lChild;
	struct BiTNode *rChild;
	Product data;
}*Node, BiTNode;


//定义二叉树
typedef struct BinaryTree {
	Node root;
	int depth;
	int isInitialized;
}BiT;

/*创建结点*/
status makeNode(Node node, int position, Product *data);

/*销毁结点*/
status destroyNode(Node node, int RL);

status initBiTree(BiT &T);

status destroyBiTree(BiT &T);

status createBiTree(BiT *T, definition *d);

status clearBiTree(BiT &T);

status biTreeEmpty(BiT T);

int biTreeDepth(BiT T);

Node root(BiT T);

Product value(BiT T, Node e);

status assign(BiT &T, struct BiTNode &e, Product value);

Node parent(BiT T, Node e);

Node leftChild(BiT T, Node e);

Node rightChild(BiT T, Node e);

Node leftSibling(BiT T, Node e);

Node rightSibling(BiT T, Node e);

status insertChild(BiT T, Node e, int LR, BiT c);

status deleteChild(BiT T, Node p, int LR);

status visit();

status PreOrderTraverse(BiT T, status *(visit()));

status debugTraverse(BiT T);



