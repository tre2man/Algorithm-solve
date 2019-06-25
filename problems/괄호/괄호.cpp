#include <stdio.h>
char arr[52];

int main()
{
	int num,temp=0;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%s",&arr);
		for(int j=0;arr[j]!=NULL;j++) 
		{
			if(arr[j]=='(')
				temp++;
			else
				temp--;
			if(temp<0)
				break;
		}
		if(temp==0)
			printf("YES\n");
		else
			printf("NO\n");
		temp=0;
	}
}
