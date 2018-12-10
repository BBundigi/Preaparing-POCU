#include<stdio.h>

typedef struct Node
{
	int Data;
	Node *Next;
}Node;


void AddData(int InputData, Node* InputHead)
{
	Node *currentLink = InputHead;

	while(currentLink->Next != NULL)
	{
		currentLink = currentLink->Next;
	}

	Node NewLinkedList = { InputData,NULL };
	currentLink->Next = &NewLinkedList;
}

void RemoveData(int InputIndex, Node** InputHead)
{
	int i;
	Node* targetNode = *InputHead;
	if (InputIndex == 0)
	{
		Node* tempNextNode = targetNode->Next;

		InputHead = &tempNextNode;
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
				//��ũ�� ����Ʈ ����ڿ��� ���ɾ˷��ٱ�?? return false�ϴ½��� ������!
			}
		}

		Node* tempNext = targetNode->Next->Next;
		free(targetNode->Next);

		targetNode->Next = tempNext;
	}
}

void InsertData(int InputIndex, int InputData, Node** InputHead)
{


}

int GetData(int InputIndex, Node* InputHead)
{

}
