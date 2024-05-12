#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

void print(struct ListNode *head){
	struct ListNode *temp = head;

	while(temp != NULL){
		printf("%d, ", temp->val);
		temp = temp->next;
	}

	printf("\n");
}

void insert(struct ListNode **head, int val){
	struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
	temp->val = val;

	if(*head == NULL){
		temp->next = NULL;
		*head = temp;
	}
	else{
		struct ListNode *current = *head;

		while(current->next != NULL){
			current = current->next;
		}

		current->next = temp;
	}
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2){
	if(list1 == NULL && list2 == NULL){
		return NULL;
	}
	else if(list1 == NULL){
		return list2;
	}
	else if(list2 == NULL){
		return list1;
	}

	struct ListNode *headOf2 = list2;
	struct ListNode *headOf1;

	// go through list2 and insert it to list1
	while(headOf2 != NULL){
		headOf1 = list1;

		// find the position to insert element from list2
		while(headOf1->next != NULL && headOf2->val > (headOf1->next)->val){
			headOf1 = headOf1->next;
		}

		// because the element from list2 is now inserted to list1,
		//   we need to store the pointer to the next element to set it as the new head
		struct ListNode *temp = headOf2->next;

		// special case where head of list1 is > element of list2 to be inserted
		if(headOf1 == list1 && headOf1->val > headOf2->val){
			headOf2->next = headOf1;
			list1 = headOf2;
		}
		else{
			headOf2->next = headOf1->next;
			headOf1->next = headOf2;
		}

		headOf2 = temp;
	}
	

	return list1;
}

int main(void){
	struct ListNode *list1 = NULL;
	struct ListNode *list2 = NULL;

	// insert(&list1, 1);
	// insert(&list1, 2);
	// insert(&list1, 4);
	// print(list1);
	// insert(&list2, 1);
	// insert(&list2, 3);
	// insert(&list2, 4);
	// print(list2);

	// insert(&list1, 1);
	// insert(&list1, 2);
	// insert(&list1, 3);
	// insert(&list1, 4);
	// print(list1);
	// insert(&list2, 5);
	// print(list2);

	insert(&list1, 2);
	print(list1);
	insert(&list2, 1);
	print(list2);

	print(mergeTwoLists(list1, list2));

	return 0;
}
