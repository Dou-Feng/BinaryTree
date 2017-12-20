#include "BinaryTree.h"

#define MAXTABLESIZE 1000
#define ENLARGESIZE 20

#pragma warning(disable:4996)
int main() {
	//二叉树
	BinaryTree T;
	memset(&T, 0, sizeof(BinaryTree));

	BinaryTree C;
	memset(&C, 0, sizeof(BinaryTree));
	
	//操作数
	int op = 1;

	status e;

	Node temp_p;
	Product *temp_pro;

	Node test_s = (Node)malloc(sizeof(BiTNode));
	test_s->rChild = NULL;
	test_s->rChild = NULL;
	test_s->data = { 2, "21", 2.0 };

	//数据
	Product pro[100];
	memset(pro, 0, 100 * sizeof(Product));
	pro[0] = { 1, "1", 1.0 };
	pro[2] = { 7, "错误示范", 1.0 };
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
		printf("    请选择你的操作[0~23]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			if (initBiTree(T) == OK) {
				printf("初始化成功!\n");
			}
			else {
				printf("初始化失败!\n");
			}
			
			getchar(); getchar();
			break;
		case 2:
			if (destroyBiTree(T) == OK) {
				printf("摧毁成功!\n");
			}
			else {
				printf("摧毁失败!\n");
			}
			getchar(); getchar();
			break;
		case 3:
			if (createBiTree(&T, pro) == OK) {
				printf("创建成功!\n");
			}
			else {
				printf("创建失败!\n");
			}
			
			getchar(); getchar();
			break;
		case 4:
			if (clearBiTree(T) == OK) {
				printf("清空成功!\n");
			}
			else {
				printf("清空失败!\n");
			}
			getchar(); getchar();
			break;
		case 5:
			if ((e = biTreeEmpty(T)) == OK) {
				printf("树为空！\n");
			}
			else if (e == FALSE) {
				printf("树不为空！\n");
			}
			else {
				printf("树未初始化！\n");
			}
			getchar(); getchar();
			break;
		case 6:
			if ((e = biTreeDepth(T)) > 0) {
				printf("The tree's depth is %d\n", e);
			}
			else if (e == FALSE) {
				printf("操作失败！\n");
			}
			else {
				printf("表未初始化！\n");
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
				printf("树未初始化！");
			}
			getchar(); getchar();
			break;
		case 8:
			if ((temp_pro = value(T, test_s)) != NULL) {
				printf("The value is :\nNo:%d Description:%s Price:%.2f\n", temp_pro->No, 
					temp_pro->name, temp_pro->price);
			}
			else {
				printf("获取数据失败！\n");
			}
			getchar(); getchar();
			break;
		case 9:
			if ((e = assign(T, *test_s, {4, "new Child", 1.9f})) != FALSE) {
				printf("赋值成功！\n");
			}
			else {
				printf("赋值失败！\n");
			}
			getchar(); getchar();
			break;
		case 10:
			if ((temp_p = parent(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("没有双亲结点或者树种不存在结点！\n");
			}
			getchar(); getchar();
			break;
		case 11:
			if ((temp_p = leftChild(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("不存在！\n");
			}
			getchar(); getchar();
			break;
		case 12:
			if ((temp_p = rightChild(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("不存在！\n");
			}
			getchar(); getchar();
			break;
		case 13:
			if ((temp_p = leftSibling(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("不存在！\n");
			}
			getchar(); getchar();
			break;
		case 14:
			if ((temp_p = rightSibling(T, test_s)) != NULL) {
				visit(temp_p);
			}
			else {
				printf("不存在！\n");
			}
			getchar(); getchar();
			break;
		case 15:
			if ((e = insertChild(T, test_s, LEFT, C)) == TRUE) {
				printf("插入成功！\n");
			}
			else {
				printf("插入失败！\n");
			}
			getchar(); getchar();
			break;
		case 16:
			if ((e = deleteChild(T, test_s, LEFT)) == TRUE) {
				printf("删除成功！\n");
			}
			else {
				printf("删除失败！\n");
			}
			getchar(); getchar();
			break;
		case 17:
			if ((e = preOrderTraverse(T, visit)) == TRUE) {
				printf("\n");
			}
			else if (e == INFEASIBLE){
				printf("遍历失败!\n");
			}
			else if (e == FALSE) {
				printf("表为空！\n");
			}
			getchar(); getchar();
			break;
		case 18:
			if ((e = inOrderTraverse(T, visit)) == TRUE) {
				printf("\n");
			}
			else if (e == INFEASIBLE) {
				printf("遍历失败!\n");
			}
			else if (e == FALSE) {
				printf("表为空！\n");
			}
			getchar(); getchar();
			break;
		case 19:
			if ((e = postOrderTraverse(T, visit)) == true) {
				printf("\n");
			}
			else if (e == INFEASIBLE) {
				printf("遍历失败!\n");
			}
			else if (e == false) {
				printf("表为空！\n");
			}
			getchar(); getchar();
			break;
		case 20:
			if ((e = levelOrderTraverse(T, visit)) == true) {
				printf("\n");
			}
			else if (e == INFEASIBLE) {
				printf("遍历失败!\n");
			}
			else if (e == false) {
				printf("表为空！\n");
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
	printf("欢迎下次再使用本系统！\n");
}//end of main()
