#include "BinaryTree.h"
#include <stack>

#define MAXLENGTH 1000
#define END -1

status makeNode(Node node, int RL, Product *data) {
	if (node != NULL) {
		if (RL == LEFT) {
			//�����ڴ�ռ䲢��ʼ��
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

/*ʵ���������ĺ����������
  ���Ȱ�ָ��ָ����������Ľ�㣬�ڴӸ��ڵ㵽����ߵĽ��;�о�����ÿ����㶼��ջ
  Ȼ�����ջ�жϣ���ջ��Ϊ�գ�
  1.�����ǰջ��Ԫ�ص�������Ϊ�գ���ô����ֱ�����������㣬Ȼ���ջ��Ԫ��pop��ȥ
  2.���ջ��Ԫ�ص���������Ϊ�գ���ô���������������±�������ջ��ֱ������ָ�������Ϊ��*/
status destroyBiTree(BiT &T) {
	//�Ѿ�����ʼ��
	if (T.isInitialized == TRUE) {
		//�������������ջ
		std::stack<Node> s;

		//����������ָ��
		Node p = T.root; 

		int RL;

		while (p != NULL)
		{
			s.push(p);
			p = p->lChild;
		}
		if (!s.empty())
			p = s.top();
		//��ջ��Ϊ��
		while (!s.empty())
		{
			//�������Һ���
			if (p->rChild == NULL) {
				s.pop(); //��pop�����Ԫ��
				if (!s.empty()) {
					RL = p->data.No % 2;
					p = s.top(); //��pָ���µ�ջ��Ԫ��
					destroyNode(p, RL); //��ջ���ո�pop������Ԫ��ɾ��
				}
			} else {
				p = p->rChild; //�����Һ��Ӿ�ָ���Һ���
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
		//�����ƶ�ָ��
		Node p;
		//����definition�������±�
		int index = 0;

		//��ʼ�����ڵ�
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

		//�����ж�,ʹ��һ����¼����·�������飬Ȼ��ÿ�����һ���½ڵ㶼�ǴӸ��ڵ㿪ʼ���±���
		int rl[MAXLENGTH];
		int realNum = 0;
		int loop_index = 0;
		for (; d[index].isNode != DEFEND; index++) {
			if (d[index].isNode == TRUE) {
				//��¼������±�
				loop_index = 0;
				//�����е�ʵ��λ��
				realNum = index + 1;
				//���������������Ĳ������õ�·��
				while (realNum != 1)
				{
					if (loop_index < MAXLENGTH) {
						rl[loop_index++] = realNum % 2;
					}
					else
					{
						exit(ERROR); //�������ڴ治��ʱ���˳�����
					}
					realNum /= 2;
				}
				//�������Ľ�����־
				if (loop_index < MAXLENGTH) {
					rl[loop_index] = END;
				}
				//�Ӹ��ڵ㿪ʼ����
				p = T->root;
				//·�����н�
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
				//��·����ĩβ����һ�����
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