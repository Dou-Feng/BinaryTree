#include "BinaryTree.h"
#include <stack>

#define MAXLENGTH 1000
#define END -1

status makeNode(Node node, int RL, Product *data) {
	if (node != NULL) {
		if (RL == LEFT) {
			//分配内存空间并初始化
			node->lChild = (Node) malloc(sizeof(BiTNode));
			memset(node->lChild, 0, sizeof(BiTNode));
			node->lChild->data = *data;
		} else if (RL == RIGHT) {
			node->rChild = (Node) malloc(sizeof(BiTNode));
			memset(node->rChild, 0, sizeof(BiTNode));
			node->rChild->data = *data;
		} else {
			return FALSE;
		}
		return OK;
	} else {
		 return INFEASIBLE;
	 }
}

status destroyNode(Node node, int RL) {
	if (node != NULL) {
		if (RL == LEFT) {
			free(node->lChild);
			node->lChild = NULL;
		}
		else {
			free(node->rChild);
			node->rChild = NULL;
		}
	}
	else {
		return FALSE;
	}
}

status initBiTree(BiT &T) {
	if (T.isInitialized == TRUE) {
		return FALSE;
	}
	else {
		T.isInitialized = 1;
		T.root = NULL;
		T.depth = 0;
		return OK;
	}
}

/*实际上是树的后序遍历过程
  首先把指针指向树的最左的结点，在从根节点到最左边的结点途中经过的每个结点都入栈
  然后进行栈判断，当栈不为空：
  1.如果当前栈顶元素的右子树为空，那么可以直接销毁这个结点，然后把栈顶元素pop出去
  2.如果栈顶元素的右子树不为空，那么进行右子树的向下遍历并入栈，直到遍历指针的左孩子为空*/
status destroyBiTree(BiT &T) {
	//已经被初始化
	if (T.isInitialized == TRUE) {
		//用来后序遍历的栈
		std::stack<Node> s;

		//用来遍历的指针
		Node p = T.root; 

		int RL;

		while (p != NULL)
		{
			s.push(p);
			p = p->lChild;
		}
		if (!s.empty())
			p = s.top();
		//当栈不为空
		while (!s.empty())
		{
			//不存在右孩子
			if (p->rChild == NULL) {
				s.pop(); //先pop出这个元素
				if (!s.empty()) {
					RL = p->data.No % 2;
					p = s.top(); //把p指向新的栈顶元素
					destroyNode(p, RL); //把栈顶刚刚pop出来的元素删除
				}
			} else {
				p = p->rChild; //存在右孩子就指向右孩子
				while (p != NULL)
				{
					s.push(p);
					p = p->lChild;
				}
				if (!s.empty())
					p = s.top();
			}
		}
		free(T.root);
		T.isInitialized = 0;
		T.root = NULL;
		T.depth = 0;
		return OK;
	}
	else {
		return FALSE;
	}
}

status createBiTree(BiT *T, definition *d) {
	if (T->isInitialized == TRUE) {
		//定义移动指针
		Node p;
		//定义definition的数组下标
		int index = 0;

		//初始化根节点
		if (d[index].isNode == TRUE) {
			T->root = (Node)malloc(sizeof(BiTNode));
			T->root->data = *d[index].data;
			T->root->lChild = NULL;
			T->root->rChild = NULL;
			index++;
		}
		else {
			return FALSE;
		}

		//左右判断,使用一个记录左右路径的数组，然后每次添加一个新节点都是从根节点开始向下遍历
		int rl[MAXLENGTH];
		int realNum = 0;
		int loop_index = 0;
		for (; d[index].isNode != DEFEND; index++) {
			if (d[index].isNode == TRUE) {
				//记录数组的下表
				loop_index = 0;
				//在树中的实际位置
				realNum = index + 1;
				//这里在做填充数组的操作，得到路径
				while (realNum != 1)
				{
					if (loop_index < MAXLENGTH) {
						rl[loop_index++] = realNum % 2;
					}
					else
					{
						exit(ERROR); //当分配内存不足时，退出程序
					}
					realNum /= 2;
				}
				//添加数组的结束标志
				if (loop_index < MAXLENGTH) {
					rl[loop_index] = END;
				}
				//从根节点开始遍历
				p = T->root;
				//路径的行进
				for (int j = loop_index - 1; j > 0; j--) {
					if (rl[j] == LEFT) {
						if (p->lChild == NULL)
							return FALSE;
						p = p->lChild;
					}
					else if (rl[j] == RIGHT) {
						if (p->rChild == NULL)
							return FALSE;
						p = p->rChild;
					}
				}
				//在路径的末尾创建一个结点
				makeNode(p, rl[0], d[index].data);
			}
		}
		return OK;
	}
	else {
		return FALSE;
	}
}


status clearBiTree(BiT &T);

status biTreeEmpty(BiT T) {
	if (T.isInitialized == TRUE) {
		if (T.root == NULL)
			return TRUE;
		else
			return FALSE;
	}
	else {
		return FALSE;
	}
}

int biTreeDepth(BiT T);

Node root(BiT T);

Product value(BiT T, Node e);

status assign(BiT &T, struct BiTNode &e, Product value);

Node parent(BiT T, Node e);

status visit(Node p) {
	if (p != NULL) {
		printf("%5d %5.2f %5s\n", p->data.No, p->data.price, p->data.name);
	}
	return OK;
}

status debugTraverse(BiT T) {
	if (T.isInitialized == TRUE) {
		std::stack<Node> s;
		Node p = T.root;
		s.push(p);
		if (p == NULL)
			return FALSE;
		printf("-----------------------\n");
		do 
		{
			if (p == NULL)
				return OK;
			visit(p);
			if (p->rChild != NULL)
				s.push(p);
			if (p->lChild != NULL)
				p = p->lChild;
			else {
				p = s.top();
				s.pop();
				p = p->rChild;
			}
		} while (!s.empty());
		printf("----------------------\n");
		return OK;
	}
	else {
		return FALSE;
	}
}