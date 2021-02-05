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

int Pop(){
	queue.Size--;
	queue.Front++;
	return queue.Arr[queue.Front-1];
}

int main(){
	int Num, Temp = 1;
	queue.Size = queue.Front = queue.Rear = 0;
	
	scanf("%d",&Num);
	for(int i=1;i<=Num;i++) Push(i);
	while(queue.Size != 1){
		Pop();
		Temp = Pop();
		Push(Temp);
	}
	printf("%d",Temp);
}
