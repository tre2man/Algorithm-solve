#include <stdio.h>

int main()
{
	int countme,countdr,i=0;
	char me[1001];
	char dr[1001];
	
	scanf("%s",&me);
	scanf("%s",&dr);
	
	while(1)
	{
		if(me[i]=='h'&&dr[i]=='a')
		{
			printf("no");
			break;
		}
		if(me[i]=='a'&&dr[i]=='h'||me[i]=='h'&&dr[i]=='h')
		{
			printf("go");
			break;
		}
		i++;
	}
}
