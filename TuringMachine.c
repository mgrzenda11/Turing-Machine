#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct Node {
	char data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct State {
	char write;
	char direction;
	char newState;
}State;


Node *head = NULL;
Node *tail = NULL;

int length() {
	int counter = 0;
	Node* temp;
	for(temp = head; temp->next!= NULL; temp = temp->next) {
		counter++;
	}
	free(temp);
	return counter;
}

void append(int num) {
	if(head == NULL && tail == NULL) {
		head = malloc(sizeof(Node));
		tail = malloc(sizeof(Node));
		head->data = num;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	}

	else {
		Node* temp = malloc(sizeof(Node));
		temp->data = num;
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}	
}

void prepend(int num) {
	if(head == NULL && tail == NULL) {
		head = malloc(sizeof(Node));
		tail = malloc(sizeof(Node));
		head->data = num;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	}
	else {
		Node *temp = malloc(sizeof(Node));
		temp->data = num;
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
}



void printList() {
	Node* temp = head;
	while(temp != NULL){
		printf("%c", temp->data);
		printf(" ");
		temp = temp->next;
	}
	free(temp);
} 


int main() {
	int numStates;
	int startState;
	int endState;
	char *input = malloc(20*sizeof(char));
	printf("Please enter the file you would like the machine to read: ");
	scanf("%s", input);
	FILE *f = fopen(input, "r");
	char buffer[255];
	char *single = malloc(sizeof(char));
	
	while(*single != '\n') {
		fscanf(f, "%c", single);
		if(*single != '\n'){
			append(*single);
		}
	}
	printf("Initial tape contents: ");
	printList();
	fscanf(f, "%d", &numStates);
	fscanf(f, "%d", &startState);
	fscanf(f, "%d", &endState);

	
	State** table = malloc(numStates*sizeof(State*));
	for(int i = 0; i<numStates; i++) {
		table[i] = malloc(255*sizeof(State));
	}

	while(!feof(f)) {
		char moveDir [1];
		int state;
		char readVal [1];
		char writeVal [1];
		int newSta;

		fscanf(f, "%d %c %c %c %d", &state, readVal, writeVal, moveDir, &newSta);
		table[state][(int)(*readVal)].write = writeVal[0];
		table[state][(int)(*readVal)].direction = moveDir[0];
		table[state][(int)(*readVal)].newState = newSta;
	}

	
	printf("\nWriting tape...");
	Node* temp = head;
	int current = startState;
	while(current != endState) {
		int tempRead = temp->data;
		temp->data = table[current][tempRead].write;
		if(table[current][tempRead].direction == 'R') {
			if(temp->next!=NULL){
				temp = temp->next;
			}
			else {
				append('B');
				temp = temp->next;
			}
		}
		else {
			if(temp->prev!=NULL) {
				temp = temp->prev;
			}
			else {
				prepend('B');
				temp = temp->prev;
			}

		}
		current = table[current][tempRead].newState;
	}
	

	printf("\nFinal Tape Contents: ");
	printList();
	printf("\n"); 
}	
