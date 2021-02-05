#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 2000000

typedef struct{
	int Front;
	int Rear; 
	int Size;
	int Arr[MAX_SIZE];
}Queue;

void Push(Queue *Queue,int Input){
	Queue->Arr[(Queue->Rear)] = Input;
	Queue->Size++;
	Queue->Rear++;
}

void Pop(Queue *Queue){
	if(Queue->Size == 0) printf("-1");
	else{
		printf("%d",Queue->Arr[Queue->Front]);
		Queue->Size--;
		Queue->Front++;
	}
	printf("\n");
}

void Size(Queue Queue){
	printf("%d", Queue.Size);
	printf("\n");
}

void Empty(Queue Queue){
	if(Queue.Size) printf("0");
	else printf("1");
	printf("\n");
}

void Front(Queue Queue){
	if(!Queue.Size) printf("-1");
	else printf("%d", Queue.Arr[Queue.Front]);
	printf("\n");
}

void Back(Queue Queue){
	if(!Queue.Size) printf("-1");
	else printf("%d", Queue.Arr[Queue.Rear-1]);
	printf("\n");
}

int main(){
	int Num, Input;
	char Order[10];
	Queue Queue;
	Queue.Size = Queue.Front = Queue.Rear = 0;
	
	scanf("%d",&Num);
	for(int i=0; i<Num; i++){
		scanf("%s",Order);
		
		if(!strcmp(Order,"push")){
			scanf("%d",&Input);	
			Push(&Queue,Input);
		}
		
		else if(!strcmp(Order,"pop")) Pop(&Queue);
		else if(!strcmp(Order,"size")) Size(Queue);
		else if(!strcmp(Order,"empty")) Empty(Queue);
		else if(!strcmp(Order,"front")) Front(Queue);
		else if(!strcmp(Order,"back")) Back(Queue);
	}
}
