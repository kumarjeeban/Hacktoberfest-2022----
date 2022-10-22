#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node **head_ref, int data)
{
	struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;

	if (*head_ref != NULL)
	{
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; 

	*head_ref = ptr1;
}
int Length(struct Node* head)
{
    struct Node* current = head;
    int count = 0;
    if (head == NULL) {
        return 0;
    }
    else {
        do {
            current = current->next;
            count++;
        } while (current != head);
    }
    return count;
}
void DeleteFirst(struct Node** head)
{
    struct Node *previous = *head, *next = *head;
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    if (previous->next == previous) {
        *head = NULL;
        return;
    }
    while (previous->next != *head) {
 
        previous = previous->next;
        next = previous->next;
    }

    previous->next = next->next;

    *head = previous->next;
    free(next);
 
    return;
}
void deleteNodeAtGivenPos(struct Node** head, int index)
{
    int len = Length(*head);
    int count = 1;
    struct Node *previous = *head, *next = *head;
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    } 
    if (index >= len || index < 0) {
        printf("\nInvalid index\n");
        return;
    }
    if (index == 0) {
        DeleteFirst(head);
        return;
    }
    while (len > 0) {
        if (index == count) {
            previous->next = next->next;
            free(next);
            return;
        }
        previous = previous->next;
        next = previous->next;
        len--;
        count++;
    } 
    return;
}
void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("%3d", temp->data);
			temp = temp->next;
		}
		while (temp != head);
	}
}


int main()
{

	struct Node *head = NULL;
    int ch,n;
    do{
        printf("\n1.Insert Node \n");
        printf("2.Print List \n");
        printf("3.Delete a node\n");
        printf("4.Exit code\n");
        printf("Enter choice ... \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&n);
                insert(&head,n);
                break;

            case 2:
                printf("\nThe list is: ");
                printList(head);
                break;

            case 3:
                printf("\nThe list is: ");
                printList(head);
                printf("\nWhich node is to be deleted? ");
                scanf("%d",&n);
                deleteNodeAtGivenPos(&head,n);
                break;

            case 4:
                printf("\nExitting code");
                exit(0);

            default:
                printf("Wrong input...\n");
        }

    }while(1);

	return 0;
}
