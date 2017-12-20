#include "BinaryTree.h"

#define MAXTABLESIZE 1000
#define ENLARGESIZE 20

#pragma warning(disable:4996)
int main() {
	//������
	BinaryTree T;
	memset(&T, 0, sizeof(BinaryTree));

	BinaryTree C;
	memset(&C, 0, sizeof(BinaryTree));
	
	//������
	int op = 1;

	status e;

	Node temp_p;
	Product *temp_pro;

	Node test_s = (Node)malloc(sizeof(BiTNode));
	test_s->rChild = NULL;
	test_s->rChild = NULL;
	test_s->data = { 2, "21", 2.0 };

	//����
	Product pro[100];
	memset(pro, 0, 100 * sizeof(Product));
	pro[0] = { 1, "1", 1.0 };
	pro[2] = { 7, "����ʾ��", 1.0 };
	pro[1] = { 2, "21", 2.0 };
	pro[3] = { 3, "22", 3.0 };
	pro[4] = { 4, "31", 4.0 };
	pro[5] = { 5, "32", 5.0 };
	pro[6] = { 7, "34", 6.0 };
	pro[7] = { 8, "41", 7.0 };
	pro[8] = { 10, "43", 8.0 };
	pro[9] = { 15, "47", 9.0 };
	pro[10] = { 17, "52", 10.0 };
	pro[11] = { 16, "51", 11.0 };
	pro[7] = { DEFEND, "0" ,0 };

	while (op) {
		system("cls");	printf("\n\n");
		printf("      Menu for Binary Tree On Chain Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitBiTree           2. DestroyBiTree  \n");
		printf("    	  3. CreateBiTree         4. ClearBiTree\n");
		printf("    	  5. BiTreeEmpty          6. BiTreeDepth\n");
		printf("    	  7. Root                 8. Value\n");
		printf("    	  9. Assign              10. Parent\n");
		printf("    	 11. LeftChild           12. RightChild\n");
		printf("         13. LeftSibling         14. RightSibling\n");
		printf("         15. InsertChild         16. DeleteChild\n");
		printf("         17. PreOrderTraverse    18. InOrderTraverse\n");
		printf("         19. PostOrderTraverse   20. LevelOrderTraverse\n");
		printf("         21. TableSwitch         22. ReadDataFromFiles\n");
		printf("         23. SaveDataIntoFiles\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~23]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			if (initBiTree(T) == OK) {
				printf("��ʼ���ɹ�!\n");
			}
			else {
				printf("��ʼ��ʧ��!\n");
			}
			
			getchar(); getchar();
			break;
		case 2:
			if (destroyBiTree(T) == OK) {
				printf("�ݻٳɹ�!\n");
			}
			else {
				printf("�ݻ�ʧ��!\n");
			}
			getchar(); getchar();
			break;
		case 3:
			if (createBiTree(&T, pro) == OK) {
				printf("�����ɹ�!\n");
			}
			else {
				printf("����ʧ��!\n");
			}
			
			getchar(); getchar();
			break;
		case 4:
			if (clearBiTree(T) == OK) {
				printf("��ճɹ�!\n");
			}
			else {
				printf("���ʧ��!\n");
			}
			getchar(); getchar();
			break;
		case 5:
			if ((e = biTreeEmpty(T)) == OK) {
				printf("��Ϊ�գ�\n");
			}
			else if (e == FALSE) {
				printf("����Ϊ�գ�\n");
			}
			else {
				printf("��δ��ʼ����\n");
			}
			getchar(); getchar();
			break;
		case 6:
			if ((e = biTreeDepth(T)) > 0) {
				printf("The tree's depth is %d\n", e);
			}
			else if (e == FALSE) {
				printf("����ʧ�ܣ�\n");
			}
			else {
				printf("��δ��ʼ����\n");
			}
			getchar(); getchar();
			break;
		case 7:
			if ((temp_p = root(T)) != NULL) {
				printf("Root Information:\n");
				printf("No:%d Description:%s Price:%.2f\n",temp_p->data.No, 
					temp_p->data.name, temp_p->data.price);
			}
			else {
				printf("��δ��ʼ����");
			}
			getchar(); getchar();
			break;
		case 8:
			if ((temp_pro = value(T, test_s)) != NULL) {
				printf("The value is :\nNo:%d Description:%s Price:%.2f\n", temp_pro->No, 
					temp_pro->name, temp_pro->price);
			}
			else {
				printf("��ȡ����ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 9:
			if ((e = assign(T, *test_s, {4, "new Child", 1.9f})) != FALSE) {
				printf("��ֵ�ɹ���\n");
			}
			else {
				printf("��ֵʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 10:
			if ((temp_p = parent(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("û��˫�׽��������ֲ����ڽ�㣡\n");
			}
			getchar(); getchar();
			break;
		case 11:
			if ((temp_p = leftChild(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("�����ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 12:
			if ((temp_p = rightChild(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("�����ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 13:
			if ((temp_p = leftSibling(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("�����ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 14:
			if ((temp_p = rightSibling(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("�����ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 15:
			if ((e = insertChild(T, test_s, LEFT, C)) == TRUE) {
				printf("����ɹ���\n");
			}
			else {
				printf("����ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 16:
			if ((e = deleteChild(T, test_s, LEFT)) == TRUE) {
				printf("ɾ���ɹ���\n");
			}
			else {
				printf("ɾ��ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 17:
			if ((e = preOrderTraverse(T, visit)) == TRUE) {
				printf("\n");
			}
			else if (e == INFEASIBLE){
				printf("����ʧ��!\n");
			}
			else if (e == FALSE) {
				printf("��Ϊ�գ�\n");
			}
			getchar(); getchar();
			break;
		case 18:
			if ((e = inOrderTraverse(T, visit)) == TRUE) {
				printf("\n");
			}
			else if (e == INFEASIBLE) {
				printf("����ʧ��!\n");
			}
			else if (e == FALSE) {
				printf("��Ϊ�գ�\n");
			}
			getchar(); getchar();
			break;
		case 19:
			if ((e = postOrderTraverse(T, visit)) == true) {
				printf("\n");
			}
			else if (e == INFEASIBLE) {
				printf("����ʧ��!\n");
			}
			else if (e == false) {
				printf("��Ϊ�գ�\n");
			}
			getchar(); getchar();
			break;
		case 20:
			if ((e = levelOrderTraverse(T, visit)) == true) {
				printf("\n");
			}
			else if (e == INFEASIBLE) {
				printf("����ʧ��!\n");
			}
			else if (e == false) {
				printf("��Ϊ�գ�\n");
			}
			getchar(); getchar();
			break;
		case 21:

			getchar(); getchar();
			break;
		case 22:

			getchar(); getchar();
			break;
		case 23:

			getchar(); getchar();
			break;

		default:
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
