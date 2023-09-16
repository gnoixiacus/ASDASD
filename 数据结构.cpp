#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ShoppingItem {
 char name[50]; // 商品名称
 int quantity; // 商品数量
 struct ShoppingItem* next; // 指向下一个节点的指针
}; 

struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
struct ShoppingItem* z = NULL;
//1. 添加商品到购物清单：
void addItem(char itemName[], int itemQuantity) {
 struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 
 strcpy(newItem->name, itemName);
 newItem->quantity=itemQuantity;
 newItem->next=NULL; 
 if(shoppingList==NULL) shoppingList = newItem;
 else z->next=newItem;
 
 z=newItem;
}

//2. 从购物清单中移除商品：
void removeItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* previous = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (previous != NULL) {
 previous->next = current->next;
 } else {
 shoppingList = current->next;
 }
 free(current);
 break;
 }
        previous = current;
        current = current->next;
 }
}

//3. 查看购物清单：
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("购物清单:\n");
 while (current != NULL) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
        current = current->next;
 }
}

//4. 修改购物清单中商品的数量：
void updateQuantity(char itemName[], int newItemQuantity) {
 struct ShoppingItem* current = shoppingList;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 current->quantity = newItemQuantity;
 break;
 }
 current = current->next;
 }
}

//5. 清空购物清单：
void clearList() {
	 struct ShoppingItem* current = shoppingList;
 while (shoppingList != NULL) {
        struct ShoppingItem* temp = shoppingList;
        shoppingList = shoppingList->next;
 free(temp);
 }
}

//6. 计算购物清单中商品的总数量：
int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
        total += current->quantity;
        current = current->next;
 }
 return total;
}

//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("查找商品 \"%s\" ：\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 return;
 }
        current = current->next;
 }
 printf("未找到商品 \"%s\"。\n", itemName);
}

//8. 排序购物清单：
void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // 交换商品信息
                strcpy(tempName, current->name);
                strcpy(current->name, nextItem->name);
                strcpy(nextItem->name, tempName);
 tempQuantity = current->quantity;
 current->quantity = nextItem->quantity;
 nextItem->quantity = tempQuantity;
 }
 nextItem = nextItem->next;
 }
 current = current->next; 
 }
}

//9. 合并购物清单：
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 struct ShoppingItem* current = *list1;
 // 遍历到第一个购物清单的末尾
    while (current->next != NULL) {
        current = current->next;
    }
 // 将第二个购物清单连接到第一个清单的末尾
 current->next = *list2;
 *list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}

//10. 删除购物清单中的商品：
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // 如果要删除的是第一个节点
 struct ShoppingItem* temp = shoppingList;
 shoppingList = shoppingList->next;
 free(temp);
 if (!deleteAll) break;
 } else {
 // 如果要删除的不是第一个节点
    prev->next = current->next;
 free(current);
 current = prev->next;
 if (!deleteAll) break;
 }
 } else {
 prev = current;
 current = current->next;
 }
 }
}

//创建新清单 
struct ShoppingItem* createLinkedList() {
    struct ShoppingItem* head = NULL; 
    struct ShoppingItem* tail = NULL; 
	char na[50];
	int qu;
    while (1) {
	scanf("%s",na);

        if(strcmp(na, "x")==0) {
            break;
        }
	scanf("%d",&qu);
        struct ShoppingItem* newNode = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
        newNode-> quantity= qu;
        strcpy(newNode->name,na);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else { 
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head; 
}
  
int main(void)
{
	int num;
	char name[50];
	int Quantity;
	printf("输入数字开始:\n");
	printf("1. 添加商品到购物清单:\n");
	printf("2. 从购物清单中移除商品:\n");
	printf("3. 查看购物清单：\n");
	printf("4. 修改购物清单中商品的数量：\n");
	printf("5. 清空购物清单：\n");
	printf("6. 计算购物清单中商品的总数量：\n");
	printf("7. 查找购物清单中的商品：\n");
	printf("8. 排序购物清单：\n");
	printf("9. 合并购物清单：\n");
	printf("10. 删除购物清单中的商品：\n");
	printf("0.结束\n"); 
	scanf("%d",&num);
	//printf("%d\n",num);
	 while(num!=0){
	 switch(num)
	 {
	 	case 1:
			
	 		/*gets(name);
	 		*/
	 		scanf("%s %d",name,&Quantity);
			// printf("%s",name);
	 		//scanf("%d",&Quantity);
			//printf("%d\n",num);
	 		addItem(name, Quantity);
	 		//printf("德冲我儿\n");
	 		break;
	 	case 2:
	 		//gets(name);
	 		scanf("%s",name);
	 		removeItem(name);
	 		break;
	 	case 3:
	 		displayList();
	 		break;
	 	case 4:
	 		gets(name);
	 		getchar();
	 		//printf("%s",name);
	 		//scanf("%s",name);
	 		scanf("%d\n",&Quantity);
	 		updateQuantity(name, Quantity);
	 		break;
	 	case 5:
	 		clearList();
	 		break;
	 	case 6:
	 		printf("%d",totalQuantity());
	 		break;
	 	case 7:
	 		//gets(name);
	 		scanf("%s",name);
	 		findItem(name);
	 		break;
	 	case 8:
	 		sortList();
	 		break;
	 	case 9:
	 		struct ShoppingItem* h1,*h2;
			 h1=createLinkedList();
			  h2=createLinkedList();
            mergeLists(&h1,&h2);
            shoppingList=h1;
	 		break;
	 	case 10:
	 		//gets(name);
	 		scanf("%s",name);
	 		scanf("%d",&Quantity);
	 		deleteItem(name, Quantity);
	 		break;//
	 	default:break;
	 	}
	 	scanf("%d",&num);
	 }
	return 0;
}
