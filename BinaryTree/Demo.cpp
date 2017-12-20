#include "BinaryTree.h"

#define MAXTABLESIZE 1000
#define ENLARGESIZE 20

#pragma warning(disable:4996)
int main() {
	//二叉树
	BinaryTree T;
	memset(&T, 0, sizeof(BinaryTree));
	
	//操作数
	int op = 1;

	//数据
	Product pro[100];
	memset(pro, 0, 100 * sizeof(Product));
	pro[0] = { 1, "1", 1.0 };
	pro[1] = { 2, "21", 2.0 };
	pro[2] = { 3, "22", 3.0 };
	pro[3] = { 4, "31", 4.0 };
	pro[4] = { 5, "32", 5.0 };
	pro[5] = { 7, "34", 6.0 };
	pro[6] = { 8, "41", 7.0 };
	pro[7] = { 10, "43", 8.0 };
	pro[8] = { 15, "47", 9.0 };
	pro[9] = { 17, "52", 10.0 };

	//二叉树定义数组
	definition def[100];
	memset(def, 0, 100 * sizeof(definition));
	def[0] = { 1, &pro[0] };
	def[1] = { 1, &pro[1] };
	def[2] = { 1, &pro[2] };
	def[3] = { 1, &pro[3] };
	def[4] = { 1, &pro[4] };
	def[5] = { 0, NULL };
	def[6] = { 1, &pro[5] };
	def[7] = { 1, &pro[6] };
	def[8] = { 0, NULL };
	def[9] = { 1, &pro[7] };
	def[10] = { 0, NULL };
	def[11] = { 0, NULL };
	def[12] = { 0, NULL };
	def[13] = { 0, NULL };
	def[14] = { 1, &pro[8] };
	def[15] = { 0, NULL };
	def[16] = { 1, &pro[9] };
	def[17] = { DEFEND, NULL };

	
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
			if (createBiTree(&T, def) == OK) {
				printf("创建成功!\n");
			}
			else {
				printf("创建失败!\n");
			}
			
			getchar(); getchar();
			break;
		case 4:
			
			getchar(); getchar();
			break;
		case 5:
			
			getchar(); getchar();
			break;
		case 6:
			
			getchar(); getchar();
			break;
		case 7:
			
			getchar(); getchar();
			break;
		case 8:
			
			getchar(); getchar();
			break;
		case 9:
			
			getchar(); getchar();
			break;
		case 10:
			
			getchar(); getchar();
			break;
		case 11:
			
			getchar(); getchar();
			break;
		case 12:
			
			getchar(); getchar();
			break;
		case 13:
			
			getchar(); getchar();
			break;
		case 14:
			
			getchar(); getchar();
			break;
		case 15:
			
			getchar(); getchar();
			break;
		case 16:

			getchar(); getchar();
			break;
		case 17:
			if (debugTraverse(T) == TRUE) {
				printf("\n");
			}
			else {
				printf("遍历失败!\n");
			}
			getchar(); getchar();
			break;
		case 18:

			getchar(); getchar();
			break;
		case 19:

			getchar(); getchar();
			break;
		case 20:

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
