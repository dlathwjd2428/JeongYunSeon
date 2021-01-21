#include<stdio.h>
#include<malloc.h>
#include<Windows.h>
typedef struct Node
{
	int Data;
	struct Node *Left;
	struct Node *Right;
}Node;
Node *NewNode(int Data)
{
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->Data = Data;
	tmp->Left = NULL;
	tmp->Right = NULL;
	return tmp;
}
void Print(Node *Root)
{
	if (Root == NULL)
		return;
	else
		printf("%d\n", Root->Data);
	Print(Root->Left);
	Print(Root->Right);
}
void Insert(Node **Root, int Data)
{
	if (*Root == NULL)
	{
		*Root = NewNode(Data);
		return;
	}
	if ((*Root)->Data > Data)
		Insert(&(*Root)->Left, Data);
	else if ((*Root)->Data < Data)
		Insert(&(*Root)->Right, Data);
	else
		printf("같은 데이터가 존재합니다.\n");
}
void Search(Node **Root, int index)
{
	if (*Root == NULL)
	{
		printf("%d는 존재하지 않습니다.\n", index);
		return;
	}
	if ((*Root)->Data == index)
	{
		printf("%d는 존재합니다.\n", index);
		return;
	}
	if ((*Root)->Data > index)
		Search(&(*Root)->Left, index);
	else if ((*Root)->Data < index)
		Search(&(*Root)->Right, index);
}
Node* Searchmin(Node **Root)
{
	if ((*Root)->Left == NULL)
	{
		Node *tmp = *Root;
		*Root = (*Root)->Right;
		return tmp;
	}
	return Searchmin(&(*Root)->Left);
}
void Delete(Node **Root, int index)
{
	if (*Root == NULL)
	{
		printf("삭제할 데이터가 없습니다.\n");
		return;
	}
	else if ((*Root)->Data > index)
		Delete(&(*Root)->Left, index);
	else if ((*Root)->Data < index)
		Delete(&(*Root)->Right, index);
	else
	{
		Node* tmp = *Root;
		if ((*Root)->Left == NULL && (*Root)->Right == NULL)
			*Root = NULL;
		else if ((*Root)->Left != NULL && (*Root)->Right == NULL)
			*Root = (*Root)->Left;
		else if ((*Root)->Left == NULL && (*Root)->Right != NULL)
			*Root = (*Root)->Right;
		else if ((*Root)->Left != NULL && (*Root)->Right != NULL)
		{
			*Root = Searchmin(&(*Root)->Right);
			(*Root)->Left = tmp->Left;
			(*Root)->Right = tmp->Right;
		}
		free(tmp);
	}
}
void Preorder(Node *Root)
{
	if (Root != NULL)
	{
		printf("%d ", Root->Data);
		Preorder(Root->Left);
		Preorder(Root->Right);
	}
}
void Inorder(Node *Root)
{
	if (Root != NULL)
	{
		Inorder(Root->Left);
		printf("%d ", Root->Data);
		Inorder(Root->Right);
	}
}
void Postorder(Node *Root)
{
	if (Root != NULL)
	{
		Postorder(Root->Left);
		Postorder(Root->Right);
		printf("%d ", Root->Data);
	}
}
void Release(Node *Root)
{
	if (Root == NULL)
		return;
	Release(Root->Left);
	Release(Root->Right);
	free(Root);
}
void main()
{
	Node *Root = NULL;
	int menu, data, index;
	Insert(&Root, 10);
	Insert(&Root, 20);
	Insert(&Root, 15);
	Insert(&Root, 25);
	Insert(&Root, 22);
	while (1)
	{
		Print(Root);
		printf("1. data 추가\n");
		printf("2. data 삭제\n");
		printf("3. Preorder\n");
		printf("4. Indorder\n");
		printf("5. Postorder\n");
		printf("6. data 검색\n");
		printf("7. 종료\n");
		printf(">>>>>\t");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("data 입력: ");
			scanf("%d", &data);
			Insert(&Root, data);
			break;
		case 2:
			printf("삭제할 데이터 입력: ");
			scanf("%d", &data);
			Delete(&Root, data);
			break;
		case 3:
			Preorder(Root);
			break;
		case 4:
			Inorder(Root);
			break;
		case 5:
			Postorder(Root);
			break;
		case 6:
			printf("Input data: ");
			scanf("%d", &index);
			Search(&Root, index);
			break;
		case 7:
			Release(Root);
			return;
		}
		system("pause");
		system("cls");
	}
}