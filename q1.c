#include<stdio.h>
#define MAX 3
typedef struct{
	char arr[MAX];
	int top;
}Stack;
int isFull(Stack *s){
	if(s->top==MAX-1){
		printf("Stack is full!\n");
		return 1;
	}
	else return 0;
}
int isEmpty(Stack *s){
        if(s->top==-1){
                printf("Stack is empty!\n");
                return 1;
        }
        else return 0;
}
void push(Stack *s){
	if(isFull(s)==1) return;
	printf("Enter charecter to be pushed:\n");
	char c;
	scanf(" %c", &c);
	s->arr[++(s->top)] = c;
	printf("top: %d\n", s->top);
}
void pop(Stack *s){
	if(isEmpty(s)==1) return;
	printf("Popped element is %c\n", s->arr[(s->top)--]);
}
void display(Stack *s){
	if(isEmpty(s)==1) return;
	printf("Elements of stack are:\n");
	for(int i=0; i<=s->top; i++){
		printf("%c\t", s->arr[i]);
	}
	printf("\n");
}
int main(){
	Stack s;
	s.top=-1;
	int ch;
	do{
		printf("Enter to 1.Push 2.Pop 3.Display 4.Quit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:  push(&s);
				 break;
			case 2: pop(&s);
				break;
			case 3: display(&s);
				break;
			default: ch=4;
		}
	}
	while(ch!=4);
	return 0;
}
