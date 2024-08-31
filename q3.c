#include<stdio.h>
#include<string.h>
#define MAX 20
typedef struct{
	char arr[MAX];
	int top;
}Stack;
int isFull(Stack *s){
	if(s->top==MAX-1){
		printf("Stack is full!");
		return 1;
	}
	else return 0;
}
int isEmpty(Stack *s){
	if(s->top==-1){
		printf("Stack is empty!");
		return 1;
	}
	else return 0;
}
void push(Stack *s, char item){
	if(isFull(s)==1)return;
	else{
		s->arr[++(s->top)]=item;
	}
}
char pop(Stack *s){
	if(isEmpty(s)==1)return '\n';
	else return s->arr[(s->top)--];
}
int main(){
	char c[20];
	Stack or, op;
	or.top=-1;
	op.top=-1;
	printf("Enter string to be checked:\n");
	scanf("%s", c);
	for(int i=0; i<strlen(c); i++)push(&or, c[i]);
	for(int i=strlen(c)-1; i>=0; i--)push(&op, c[i]);
	int f=0;
	for(int i=0; i<strlen(c); i++){
		if(pop(&or)!=pop(&op)){
			printf("Not a palindrome!\n");
			f=1;
			break;
		}
	}
	if(f==0)printf("Palindrome!\n");
	return 0;
}
