#include <stdio.h>
#include <stdlib.h>



void display_options(void){
	printf("0 - Exit program\n");
	printf("1 - Print the list\n");
	printf("2 - Add a node to the start of the list\n");
	printf("3 - Add a node to the end of the list\n");
	printf("4 - Delete a node at the start\n");
	printf("\n");
}


struct node{
	int value;
	struct node* next;
};


struct node *HEAD = NULL;
struct node *CURRENT = NULL;


struct node* create_node(int val){
	struct node *result = malloc(sizeof(struct node));
	result->value = val;
	result->next = NULL;
	return result;
}


void print_list(struct node *head){
	struct node *temp = head;
	while(temp != NULL){
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}


int main(void){
	int user_input = 0;
	int user_choice = 0;
	int program_loop = -1;
	struct node* tmp_ptr;
	
	while(program_loop){
		display_options();
		scanf("%d", &user_choice);
		switch(user_choice){
			case 0:
			//exit program
				program_loop = user_choice;
				break;
			case 1:
			//print list
				print_list(HEAD);
				break;
			case 2:
			//add node to start
				printf("Value of new node: ");
				scanf("%d", &user_input);
				tmp_ptr = HEAD;
				HEAD = create_node(user_input);
				HEAD->next = tmp_ptr;
				if(CURRENT == NULL){
					CURRENT = HEAD;
				}
				break;
			case 3:
			//add node to end of the list
				printf("Value of new node: ");
				scanf("%d", &user_input);
				if(CURRENT == NULL && HEAD == NULL){
					CURRENT = HEAD = create_node(user_input);
				}else{
					CURRENT->next = create_node(user_input);
					CURRENT = CURRENT->next;
				}
			case 4:
			//delete node at start
				if(HEAD == NULL){
					printf("No nodes to delete\n");
				}else{
					tmp_ptr = HEAD;
					HEAD = HEAD->next;
					free(tmp_ptr);
				}
			default:
				break;
		}
	}
	return 0;
}
