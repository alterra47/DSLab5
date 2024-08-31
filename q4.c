#include<stdio.h>
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
int pop(Stack *s){
	if(isEmpty(s)==1)return -1;
	else return s->arr[(s->top)--];
}
int main(){
	Stack s;
	s.top=-1;
	int arr[20], n, k;
	printf("Enter size of array:\n");
	scanf("%d", &n);
	printf("Enter elements of array:\n");
	for(int i=0; i<n; i++)scanf("%d", &arr[i]);
	printf("Enter value of k:\n");
	scanf("%d",&k);
	for(int i=n-1; i>=0; i--) push(&s,arr[i]);
	Stack t;
	t.top=-1;
	while(k>0){
		while(1){
			int a = pop(&s);
			int b = pop(&s);
			if(a<b){
				push(&t, b);
				k--;
				break;
			}
			else{
				push(&t, a);
				push(&s, b);
			}
		}
		int size = t.top;
		for(int i=size; i>=0; i--) push(&s, pop(&t));
	}
	printf("Required array is:\n");
	for(int i=n-k-1; i>1; i--)printf("%d ", pop(&s));
	printf("\n");
}
