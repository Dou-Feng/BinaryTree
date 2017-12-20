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
		return TRUE;
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

status createBiTree(BiT *T, Product *d) {
	if (T->isInitialized == TRUE) {
		//定义移动指针
		Node p;
		//定义definition的数组下标
		int index = 0;

		//初始化根节点
		if (d[index].No  == 1) {
			T->root = (Node)malloc(sizeof(BiTNode));
			T->root->data = d[index];
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
		int isWrongData = 0;
		for (; d[index].No != DEFEND; index++) {
			isWrongData = 0;
			if (d[index].No >= TRUE) {
				//记录数组的下表
				loop_index = 0;
				//在树中的实际位置
				realNum = d[index].No;
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
				for (int j = loop_index - 1; j > 0 && isWrongData == 0; j--) {
					if (rl[j] == LEFT) {
						if (p->lChild == NULL) {
							isWrongData = 1;
						}
						else {
							p = p->lChild;
						}
					}
					else if (rl[j] == RIGHT) {
						if (p->rChild == NULL) {
							isWrongData = 1;
						}
						else {
							p = p->rChild;
						}
					}
				}
				//在路径的末尾创建一个结点
				if (isWrongData == 0)
					makeNode(p, rl[0], &d[index]);
			}
		}
		return OK;
	}
	else {
		return FALSE;
	}
}

status clearBiTree(BiT &T) {
	if (destroyBiTree(T) == OK) {
		T.isInitialized = 1;
		return OK;
	}
	else {
		return FALSE;
	}
}

status biTreeEmpty(BiT T) {
	if (T.isInitialized == TRUE) {
		if (T.root == NULL)
			return TRUE;
		else
			return FALSE;
	}
	else {
		return INFEASIBLE;
	}
}

int biTreeDepth(BiT T) {
	if (T.isInitialized == TRUE) {
		int max_No = 0;
		int depth = 1;
		if (T.depth <= 0) {
			//进行前序遍历
			std::stack<Node> s;
			Node p = T.root;
			if (p == NULL)
				return FALSE;
			s.push(p);
			do 
			{
				if (p == NULL)
					return OK;
				//比max_No大的序号作为新的max_No
				if (p->data.No > max_No)
					max_No = p->data.No;
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
			//遍历结束之后进行序号解析
			while (max_No != 1) {
				max_No /= 2;
				depth++;
			}
			return depth;
		}
		else {
			return T.depth;
		}
	}
	else {
		return FALSE;
	}
}

Node root(BiT T) {
	if (T.isInitialized == OK) {
		return T.root;
	}
	else {
		return NULL;
	}
}

status nodeEqual(Node a, Node b) {
	if (a != NULL && b != NULL) {
		if (a->data.No == b->data.No
			&& (a->data.price - b->data.price <= 0.0001)
			&& strcmp(a->data.name, b->data.name) == 0)
			return TRUE;
		else
			return FALSE;
	}
	else
		return INFEASIBLE;
}

Node getNode(BiT T, Node e) {
	if (T.isInitialized == TRUE) {
		if (T.depth <= 0) {
			//进行前序遍历
			std::stack<Node> s;
			Node p = T.root;
			if (p == NULL)
				return NULL;
			do
			{
				while (p != NULL)
				{
					//比较操作
					if (nodeEqual(p, e) == OK)
						return p;
					if (p->rChild != NULL)
						s.push(p);
					p = p->lChild;
				}
				if (!s.empty()) {
					p = s.top()->rChild;
					s.pop();
				}
			} while (!s.empty() || p != NULL);
			return NULL;
		}
		else {
			return NULL;
		}
	}
	else {
		return NULL;
	}
}

Product *value(BiT T, Node e) {
	Node p = getNode(T, e);
		if (p != NULL)
			return &p->data;
		else
			return NULL;
}

status assignValue(Node n, Product value) {
	if (n != NULL) {
		int No = n->data.No;
		n->data = value;
		n->data.No = No;
		return TRUE;
	}
	else {
		return FALSE;
	}
}

status assign(BiT &T, struct BiTNode &e, Product value) {
	Node p = getNode(T, &e);
	if (p != NULL) {
		assignValue(p, value);
		return OK;
	}
	else
		return FALSE;
}

Node parent(BiT T, Node e) {
	//已经被初始化
	if (T.isInitialized == TRUE) {
		std::stack<Node> s;
		Node p = T.root;
		if (p == NULL)
			return FALSE;
		do
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->lChild;
			}
			if (!s.empty()) {
				p = s.top();
				s.pop();
				if (nodeEqual(p->lChild, e) == TRUE || nodeEqual(p->rChild, e) == TRUE)
					return p;
				p = p->rChild;
			}
		} while (!s.empty() || p != NULL);
	}
	else {
		return NULL;
	}
}

Node leftChild(BiT T, Node e) {
	Node p = getNode(T, e);
	if (p != NULL) {
		return p->lChild;
	}
}

Node rightChild(BiT T, Node e) {
	Node p = getNode(T, e);
	if (p != NULL) {
		return p->rChild;
	}
	else {
		return NULL;
	}
}

Node leftSibling(BiT T, Node e) {
	Node p = parent(T, e);
	if (p != NULL && nodeEqual(p->lChild, e) == FALSE) {
		return p->lChild;
	}
	else
	{
		return NULL;
	}
}

Node rightSibling(BiT T, Node e) {
	Node p = parent(T, e);
	if (p != NULL && nodeEqual(p->rChild, e) == FALSE) {
		return p->rChild;
	}
	else
	{
		return NULL;
	}
}

status insertChild(BiT T, Node e, int LR, BiT c) {
	Node p = getNode(T, e);
	Node p_next;
	if (c.root->rChild != NULL)
		return FALSE;
	if (p != NULL) {
		if (LR == LEFT) {
			p_next = p->lChild;
			p->lChild = c.root;
			c.root->rChild = p_next;
		} else if (LR == RIGHT) {
			p_next = p->rChild;
			p->rChild = c.root;
			c.root->rChild = p_next;
		}	
	}
	else {
		return FALSE;
	}
}

status deleteChild(BiT T, Node p, int LR) {
	Node find_p = getNode(T, p);
	Node root_p = NULL;
	if (find_p != NULL) {
		if (LR == LEFT)
			root_p = find_p->lChild;
		else if (LR == RIGHT)
			root_p = find_p->rChild;
		if (root_p == NULL)
			return FALSE;
		//用来后序遍历的栈
		std::stack<Node> s;

		//用来遍历的指针
		Node q = root_p;

		int RL;

		while (q != NULL)
		{
			s.push(q);
			q = q->lChild;
		}
		if (!s.empty())
			q = s.top();
		//当栈不为空
		while (!s.empty())
		{
			//不存在右孩子
			if (q->rChild == NULL) {
				s.pop(); //先pop出这个元素
				if (!s.empty()) {
					RL = q->data.No % 2;
					q = s.top(); //把p指向新的栈顶元素
					destroyNode(q, RL); //把栈顶刚刚pop出来的元素删除
				}
			}
			else {
				q = q->rChild; //存在右孩子就指向右孩子
				while (q != NULL)
				{
					s.push(q);
					q = q->lChild;
				}
				if (!s.empty())
					q = s.top();
			}
		}
		free(root_p);
		if (LR == LEFT)
			find_p->lChild = NULL;
		else if (LR == RIGHT)
			find_p->rChild = NULL;
		else
			return FALSE;
		return OK;
	}
	else {
		return FALSE;
	}
}

status visit(Node p) {
	if (p != NULL) {
		printf("No:%5d Price:%5.2f Description:%20s\n", p->data.No, p->data.price, p->data.name);
	}
	return OK;
}


status preOrderTraverse(BiT T, status (visit(Node))) {
	if (T.isInitialized == TRUE) {
		std::stack<Node> s;
		Node p = T.root;
		if (p == NULL)
			return FALSE;
		printf("-----------------------\n");
		do
		{
			while (p != NULL)
			{
				visit(p);
				if (p->rChild != NULL)
					s.push(p);
				p = p->lChild;
			}
			if (!s.empty()) {
				p = s.top()->rChild;
				s.pop();
			}
		} while (!s.empty() || p != NULL);
		printf("----------------------\n");
		return OK;
	}
	else {
		return INFEASIBLE;
	}
}

status inOrderTraverse(BiT T, status(*visit)(Node)) {
	if (T.isInitialized == TRUE) {
		std::stack<Node> s;
		Node p = T.root;
		if (p == NULL)
			return FALSE;
		printf("-----------------------\n");
		do
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->lChild;
			}
			if (!s.empty()) {
				p = s.top();
				s.pop();
				visit(p);
				p = p->rChild;
			}
		} while (!s.empty() || p != NULL);
		printf("----------------------\n");
		return OK;
	}
	else {
		return INFEASIBLE;
	}
}

status postOrderTraverse(BiT T, status(*visit)(Node)) {
	if (T.isInitialized == TRUE) {
		std::stack<Node> s;
		Node p = T.root;
		//用来保存上次访问的结点
		Node last = T.root;
		s.push(p);
		if (p == NULL)
			return FALSE;
		printf("-----------------------\n");
		while (!s.empty())
		{
			p = s.top();
			if (p->lChild == NULL && p->rChild == NULL || p->rChild == NULL && last == p->lChild || last == p->rChild){
				visit(p);
				last = p;
				s.pop();
			}
			else {
				if (p->rChild)
					s.push(p->rChild);
				if (p->lChild)
					s.push(p->lChild);
			}
			
		}
		printf("----------------------\n");
		return OK;
	}
	else {
		return INFEASIBLE;
	}
}

status levelOrderTraverse(BiT T, status(*visit)(Node)) {
	if (T.isInitialized == TRUE) {
		
		
		return OK;
	}
	else {
		return INFEASIBLE;
	}
}