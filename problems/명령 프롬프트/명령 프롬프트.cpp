#include <stdio.h>
#include <string.h>

int main()
{
	char ans[51]={0};
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++) 
	{
		char input[51];
		scanf("%s",&input);
		if(i==0) strcpy(ans,input);
		else
		{
			for(int j=0;j<51;j++)
			{
				if(input[j]!=ans[j]) ans[j]=' ';
			}
		}
	}
	
	for(int i=0;ans[i]!=NULL;i++)
	{
		if(ans[i]==' ') printf("?");
		else printf("%c",ans[i]);
	}
 } 
