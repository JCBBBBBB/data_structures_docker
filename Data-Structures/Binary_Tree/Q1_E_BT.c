//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section E - Binary Trees Questions
Purpose: Implementing the required functions for Question 1 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////
typedef struct _btnode{ // 이진트리의 노드
	int item; //저장하는 값
	struct _btnode *left; //왼쪽 자식
	struct _btnode *right; //오른쪽 자식
} BTNode;   // You should not change the definition of BTNode

/////////////////////////////////////////////////////////////////////////////////

typedef struct _stackNode{ // 스택의 노드(BTNode의 포인터를 저장)
    BTNode *btnode; // BTNode를 가리키는 포인터
    struct _stackNode *next;
}StackNode;

typedef struct _stack{ // 스택 구조체
    StackNode *top; // 스택의 top
}Stack;

///////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
int identical(BTNode *tree1, BTNode *tree2);

// 정수 item을 가진 새 트리 노드 하나를 만들고 주소를 반환하는 함수
BTNode* createBTNode(int item); // 하나 동적할당 후 반환


BTNode* createTree(); // 사용자 입력받아 트리 생성. 내부적으로 스택써서 BFS 방식으로 노드 추가
void push( Stack *stk, BTNode *node); // 스택에 트리 노드 주소를 넣는 함수
BTNode* pop(Stack *stk); // 스택에서 하나 꺼내는 함수

void printTree(BTNode *node); // 중위 순회로 출력
void removeAll(BTNode **node);//재귀로 트리 전체 메모리 해제

///////////////////////////// main() /////////////////////////////////////////////

int main()
{
    int c, s;
    char e;
    BTNode *root1, *root2;

    root1 = NULL;
    root2 = NULL;
    c = 1;

    printf("1: Create a binary tree1.\n");
    printf("2: Create a binary tree2.\n");
    printf("3: Check whether two trees are structurally identical.\n");
    printf("0: Quit;\n");

    while(c != 0){
        printf("Please input your choice(1/2/3/0): ");
        if(scanf("%d", &c) > 0)

        {

            switch(c)
            {
            case 1:
                removeAll(&root1); //기존 tree1이 있으면 전부 해제
                printf("Creating tree1:\n");
                root1 = createTree();//새 트리 만들고 루트 주소 root1에 저장
                printf("The resulting tree1 is: ");
                printTree(root1); // 중위 순회로 tree1 출력
                printf("\n");
                break;
            case 2:
                removeAll(&root2);
                printf("Creating tree2:\n");
                root2 = createTree();
                printf("The resulting tree2 is: ");
                printTree(root2);
                printf("\n");
                break;
            case 3:
                s = identical(root1, root2);// 두 트리 비교하고 결과를 s에 저장
                if(s){ // s가 0이 아니면 참
                printf("Both trees are structurally identical.\n");
                }
                else{
                printf("Both trees are different.\n");
                }
                removeAll(&root1);
                removeAll(&root2);
                break;
            case 0:
                removeAll(&root1);
                removeAll(&root2);
                break;
            default:
                printf("Choice unknown;\n");
                break;
            }
		}
        else
        {
            scanf("%c",&e);
        }

    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

int identical(BTNode *tree1, BTNode *tree2)
{
    if(tree1 == NULL && tree2 == NULL)
    {
        return 1;
    }
    if(tree1 == NULL || tree2 == NULL)
    {
        return 0;
    }
    if(tree1->item != tree2->item)
    {
        return 0;
    }

    return identical(tree1->left, tree2->left) && identical(tree1->right, tree2->right);
}

/////////////////////////////////////////////////////////////////////////////////

BTNode *createBTNode(int item){ // 새 트리 노드 하나를 생성하는 함수 시작
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//////////////////////////////////////////////////////////////////////////////////


BTNode *createTree() // 사용자 입력으로 트리를 만드는 함수
{
    Stack stk;
    BTNode *root, *temp;
    char s;
    int item;

    stk.top = NULL;
    root = NULL;

    printf("Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.\n");
    printf("Enter an integer value for the root: ");
    if(scanf("%d",&item) > 0)
    {
        root = createBTNode(item); // 루트 노드 생성
        push(&stk,root);
    }
    else
    {
        scanf("%c",&s);
    }

    while((temp =pop(&stk)) != NULL) // 스택에서 하나 꺼내서 temp에 저장
    {

        printf("Enter an integer value for the Left child of %d: ", temp->item);

        if(scanf("%d",&item)> 0)
        {
            temp->left = createBTNode(item);
        }
        else
        {
            scanf("%c",&s);
        }

        printf("Enter an integer value for the Right child of %d: ", temp->item);
        if(scanf("%d",&item)>0)
        {
            temp->right = createBTNode(item);
        }
        else
        {
            scanf("%c",&s);
        }

        if(temp->right != NULL)
            push(&stk,temp->right);
        if(temp->left != NULL)
            push(&stk,temp->left);
    }
    return root;
}

void push( Stack *stk, BTNode *node){ // 스택에 BTNode*를 넣는 함수
    StackNode *temp;

    temp = malloc(sizeof(StackNode));
    if(temp == NULL)
        return;
    temp->btnode = node;
    if(stk->top == NULL){
        stk->top = temp;
        temp->next = NULL;
    }
    else{
        temp->next = stk->top;
        stk->top = temp;
    }
}

BTNode* pop(Stack *stk){ // 스택에서 하나 꺼내는 함수
   StackNode *temp, *top;
   BTNode *ptr;
   ptr = NULL;

   top = stk->top;
   if(top != NULL){
        temp = top->next;
        ptr = top->btnode;

        stk->top = temp;
        free(top);
        top = NULL;
   }
   return ptr;
}

void printTree(BTNode *node){
    if(node == NULL) return;

    printTree(node->left);
    printf("%d ",node->item);
    printTree(node->right);
}

void removeAll(BTNode **node){
    if(*node != NULL){
        removeAll(&((*node)->left));
        removeAll(&((*node)->right));
        free(*node);
        *node = NULL;
    }
}
