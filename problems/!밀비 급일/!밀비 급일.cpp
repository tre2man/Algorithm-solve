#include <stdio.h>

int main()
{
	int i,k;
	while(1)
	{
		char arr[510]={0};
		i=509,k=0; 
		fgets(arr,sizeof(arr),stdin);
		
		if (arr[0]=='E'&&arr[1]=='N'&&arr[2] =='D') return 0;
				
		while(i>=0)
		{
			if(arr[i]=='\n') k=1;
			else
				if(k==1) printf("%c",arr[i]);
			i--;
		}
		printf("\n");
	}
}
