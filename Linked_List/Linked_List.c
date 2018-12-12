#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int Data;
	Node* Next;
}Node;

typedef Node *NodePtr;

void AddData(int InputData, NodePtr InputHead)
{
	NodePtr currentLink = InputHead;

	while (currentLink->Next != NULL)
	{
		currentLink = currentLink->Next;
	}

	NodePtr NewLinkedList = malloc(sizeof(Node));

	NewLinkedList->Data = InputData;
	NewLinkedList->Next = NULL;

	currentLink->Next = NewLinkedList;
}

void RemoveData(int InputIndex, NodePtr* InputHead)
{
	int i;
	NodePtr targetNode = *InputHead;
	if (InputIndex == 0)
	{
		NodePtr tempNextNode = targetNode->Next;

		*InputHead = tempNextNode;
		free(targetNode);
	}
	else
	{
		for (i = 0; i < InputIndex - 1; i++)
		{
			targetNode = targetNode->Next;

			if (targetNode == NULL)
			{
				return;
				//링크드 리스트 사용자에게 어케알려줄까?? return false하는식이 좋을듯!
			}
		}

		NodePtr tempNext = targetNode->Next->Next;
		free(targetNode->Next);

		targetNode->Next = tempNext;
	}
}

void InsertData(int InputIndex, int InputData, NodePtr* InputHead)
{
	if (InputIndex == 0)
	{
		NodePtr newHeadNode = malloc(sizeof(Node));
		newHeadNode->Data = InputData;
		newHeadNode->Next = *InputHead;
		*InputHead = newHeadNode;
	}
	else
	{
		int i;
		NodePtr currentNode = *InputHead;
		for (i = 0; i < InputIndex - 1; i++)
		{
			currentNode = currentNode->Next;
		}

		NodePtr tempNextNode = currentNode->Next->Next;

		NodePtr newNode = malloc(sizeof(Node));

		newNode->Data = InputData;
		newNode->Next = tempNextNode;

		currentNode->Next = newNode;
	}

}

int GetData(int InputIndex, NodePtr InputHead)
{
	int i;
	NodePtr currentNode = InputHead;
	for (i = 0; i < InputIndex; i++)
	{
		currentNode = currentNode->Next;
	}

	return currentNode->Data;
}
