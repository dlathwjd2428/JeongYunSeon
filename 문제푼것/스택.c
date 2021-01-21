#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int Data;
	struct Node* Link;
}Node;
void push(Node** Top, int Data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Link = *Top;
	newNode->Data = Data;
	*Top = newNode;
}
void pop(Node **Top)
{
	Node* tmp = *Top;
	if (tmp == NULL)
	{
		printf("삭제할 정보가 없습니다.\n");
		return;
	}
	*Top = tmp->Link;
	free(tmp);
}
void ShowStack(Node *Top)
{
	printf("%d", Top->Data);
	Top = Top->Link;
	printf("\n");
	system("pause");
}
void main()
{
	Node* Top = NULL;
	push(&Top, 10);
	ShowStack(Top);
	push(&Top, 7);
	ShowStack(Top);
	push(&Top, 23);
	ShowStack(Top);

	pop(&Top);
	ShowStack(Top);
	pop(&Top);
	ShowStack(Top);
	pop(&Top);
	ShowStack(Top);

}