#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue{
	int Front;
	int Rear; 
	int Size;
	int Arr[2000000]={};
}Queue;

Queue queue;

void Push(int Input){
	queue.Arr[(queue.Rear)] = Input;
	queue.Size++;
	queue.Rear++;
}

void Pop(){
	if(queue.Size == 0) printf("-1");
	else{
		printf("%d",queue.Arr[queue.Front]);
		queue.Size--;
		queue.Front++;
	}
	printf("\n");
}

void Size(){
	printf("%d", queue.Size);
	printf("\n");
}

void Empty(){
	if(queue.Size) printf("0");
	else printf("1");
	printf("\n");
}

void Front(){
	if(!queue.Size) printf("-1");
	else printf("%d", queue.Arr[queue.Front]);
	printf("\n");
}

void Back(){
	if(!queue.Size) printf("-1");
	else printf("%d", queue.Arr[queue.Rear-1]);
	printf("\n");
}

int main(){
	int Num, Input;
	char Order[10];
	queue.Size = queue.Front = queue.Rear = 0;
	
	scanf("%d",&Num);
	for(int i=0; i<Num; i++){
		scanf("%s",Order);
		
		if(!strcmp(Order,"push")){
			scanf("%d",&Input);	
			Push(Input);
		}
		
				else if(!strcmp(Order,"pop")){
			Pop();
		}
		
		else if(!strcmp(Order,"size")){
			Size();
		}
		
		else if(!strcmp(Order,"empty")){
			Empty();
		}
		
		else if(!strcmp(Order,"front")){
			Front();
		}
		
		else if(!strcmp(Order,"back")){
			Back();
		}
	}
}
