#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ShoppingItem {
 char name[50]; // ��Ʒ����
 int quantity; // ��Ʒ����
 struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
}; 

struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
struct ShoppingItem* z = NULL;
//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
 struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 
 strcpy(newItem->name, itemName);
 newItem->quantity=itemQuantity;
 newItem->next=NULL; 
 if(shoppingList==NULL) shoppingList = newItem;
 else z->next=newItem;
 
 z=newItem;
}

//2. �ӹ����嵥���Ƴ���Ʒ��
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

//3. �鿴�����嵥��
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("�����嵥:\n");
 while (current != NULL) {
 printf("%s - ������%d\n", current->name, current->quantity);
        current = current->next;
 }
}

//4. �޸Ĺ����嵥����Ʒ��������
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

//5. ��չ����嵥��
void clearList() {
	 struct ShoppingItem* current = shoppingList;
 while (shoppingList != NULL) {
        struct ShoppingItem* temp = shoppingList;
        shoppingList = shoppingList->next;
 free(temp);
 }
}

//6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
        total += current->quantity;
        current = current->next;
 }
 return total;
}

//7. ���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("������Ʒ \"%s\" ��\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - ������%d\n", current->name, current->quantity);
 return;
 }
        current = current->next;
 }
 printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}

//8. �������嵥��
void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // ������Ʒ��Ϣ
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

//9. �ϲ������嵥��
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 struct ShoppingItem* current = *list1;
 // ��������һ�������嵥��ĩβ
    while (current->next != NULL) {
        current = current->next;
    }
 // ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
 current->next = *list2;
 *list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}

//10. ɾ�������嵥�е���Ʒ��
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // ���Ҫɾ�����ǵ�һ���ڵ�
 struct ShoppingItem* temp = shoppingList;
 shoppingList = shoppingList->next;
 free(temp);
 if (!deleteAll) break;
 } else {
 // ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
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

//�������嵥 
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
	printf("�������ֿ�ʼ:\n");
	printf("1. �����Ʒ�������嵥:\n");
	printf("2. �ӹ����嵥���Ƴ���Ʒ:\n");
	printf("3. �鿴�����嵥��\n");
	printf("4. �޸Ĺ����嵥����Ʒ��������\n");
	printf("5. ��չ����嵥��\n");
	printf("6. ���㹺���嵥����Ʒ����������\n");
	printf("7. ���ҹ����嵥�е���Ʒ��\n");
	printf("8. �������嵥��\n");
	printf("9. �ϲ������嵥��\n");
	printf("10. ɾ�������嵥�е���Ʒ��\n");
	printf("0.����\n"); 
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
	 		//printf("�³��Ҷ�\n");
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
