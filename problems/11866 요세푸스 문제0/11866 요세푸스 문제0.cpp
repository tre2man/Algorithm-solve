#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue{
	int Size;
	int Arr[2000000]={};
}Queue;

Queue queue;

void Push(int Input){
	queue.Arr[queue.Size] = Input;
	queue.Size++;
}

void Pop(int Input){
	Input-=1;
	queue.Arr[Input] = 0;
	for(int i=Input;i<queue.Size;i++){
		queue.Arr[i] = queue.Arr[i+1];
	}
	queue.Arr[queue.Size-1] = 0;
	queue.Size--;
}

int main(){
	int N, K, Delete;
	queue.Size = 0;
	
	scanf("%d %d",&N, &K);
	Delete = K;
	for(int i=1;i<=N;i++) Push(i);
		
	while(queue.Size != 0){
		printf("Delete : %d\n",Delete);
		printf("%d \n",queue.Arr[Delete-1]);
		Pop(Delete);
		Delete = (Delete+3)%queue.Size;
		if(!Delete) Delete=queue.Size;
	}
}
