//1자형 linked list

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;

}ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}



ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; // pre의 link가 node p전체를 가리키고 있다.

	return head;

}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)return NULL;
	removed = head;
	head = removed->link;

	free(removed);
	return head;
}



//pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);

	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");

}

//뭐지...



int getNodeCnt(ListNode* case0) {
	int cnt = 0;
	for (ListNode* root = case0; ; root = root->link) {
		cnt++;
		if (root->link == NULL) {
			return cnt;
		}
	}
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;

	head = p;
	return head;
}
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	for (ListNode* root = head; ; root = root->link)
	{	
		if (root->link == NULL)
		{
			root->link = p;
			p->data = value;
			p->link = NULL;
			return head;
		}

	}
}
ListNode* alternate(ListNode* head1, ListNode* head2)
{
	ListNode* root = (ListNode*)malloc(sizeof(ListNode));
	root->link = NULL;
	while (1) {
		if (!head1 && !head2)break;
		root = insert_last(root, head1->data);
		head1 = head1->link;
		root = insert_last(root, head2->data);
		head2 = head2->link;
	}
	
	return root->link;
}



int main(void)
{
	ListNode* head1 = NULL;

	printf("<실행결과>\n");
	head1 = insert_first(head1, 3);
	head1 = insert_first(head1, 2);
	head1 = insert_first(head1, 1);
	print_list(head1);

	ListNode* head2 = NULL;
	head2 = insert_first(head2, 5);
	head2 = insert_first(head2, 4);
	head2 = insert_first(head2, 0);
	//head2 = insert_last(head2, 30);
	print_list(head2);

	ListNode* head3 = NULL;
	head3 = alternate(head1, head2);

	print_list(head3);
	return 0;
}
