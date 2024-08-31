#include<stdio.h>
#define MAX 10
typedef struct{
	int arr[MAX];
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
void push(Stack *s, int item){
	if(isFull(s)==1)return;
	else{
		s->arr[++(s->top)]=item;
	}
}
void pop(Stack *s){
	if(isEmpty(s)==1)return;
	else printf("Popped item is %d", s->arr[(s->top)--]);
}
void display(Stack *s){
	if(isEmpty(s)==1) return;
	else{
		for(int i=s->top; i>=0; i--)printf("%d", s->arr[i]);
		printf("\n");
	}
}
int main(){
	Stack s;
	s.top=-1;
	int num;
	printf("Enter any decimal format integer:\n");
	scanf("%d", &num);
	while(num>0){
		push(&s, num%2);
		num=num/2;
	}
	printf("Equivalent binary is: ");
	display(&s);
}
