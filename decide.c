#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/times.h>

typedef struct node {
	char* data;
	struct node *next;
} linked_node;

linked_node* push(linked_node* head,char *data){
	linked_node *curr = head;
	while (curr->next != NULL){
		curr = curr->next;
	}
	curr = curr->next = (linked_node*)malloc(sizeof(linked_node));
	curr->data = (char*)malloc(strlen(data) + 1);
	strcpy(curr->data, data);
	curr->next = NULL;
	return head;
}

/*
 ** Unused sequence 
 void print_list(linked_node *head){
 linked_node *curr = head->next;
 int i= 0;
 while (curr != NULL){
 printf("%d: %s\n", ++i, curr->data);
 curr = curr->next;
 }
 }
 */

char* return_line(linked_node* head, int number){
	linked_node *curr = head->next;
	while (curr != NULL && number){
		number--;
		curr = curr->next;
	}
	if (number == 0)
		return curr->data;
	else
		return NULL;
}
/* 
 ** head node contains empty data
 */
linked_node *create_list(){
	linked_node *curr = (linked_node*)malloc(sizeof(linked_node));
	curr->data = "";
	curr->next = NULL;
	return curr;
}

int main(int argc, char** argv){
	int count = 0; 
	struct timeval inst;
	linked_node* list = create_list();
	char str[BUFSIZ];
	if (argc >= 2){
		while (count + 1 < argc){
			push(list, argv[count + 1]);
			count++;
		};
		goto fin;
	}
	printf("To choose random option enter '.'\nEnter lines of text:\n");
	while(fgets(str, BUFSIZ, stdin) != NULL){
		if(str[0] == '.')
			break;
		push(list, str);
		count++;
	};
	printf("//-------//\n");
fin:
	if (count){
		gettimeofday(&inst, NULL);
		srand(inst.tv_usec);
		printf("%s\n",return_line(list, rand() % count));
	}
	exit(0);
}

