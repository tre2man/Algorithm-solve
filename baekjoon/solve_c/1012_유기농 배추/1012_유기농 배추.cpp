#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int bot[51][51] = {0};
int visit[51][51] = {0};
int zir = 0;

void dfs(int x, int y) //dfs 수행 및 방문한곳 표시
{
	visit[x][y] = 1;

	if (bot[x - 1][y] == 1 && visit[x - 1][y] == 0)
		dfs(x - 1, y);
	if (bot[x][y + 1] == 1 && visit[x][y + 1] == 0)
		dfs(x, y + 1);
	if (bot[x + 1][y] == 1 && visit[x + 1][y] == 0)
		dfs(x + 1, y);
	if (bot[x][y - 1] == 1 && visit[x][y - 1] == 0)
		dfs(x, y - 1);
}

void run(int x, int y) //배추가 심어져 있는 곳부터 dfs 실행
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (bot[i][j] == 1 && visit[i][j] == 0)
			{
				zir++;
				dfs(i, j);
			}
		}
	}
}

void print(int x, int y) //맞는지 확인하는 테스트용
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d", bot[i][j]);
		}
		printf("\n");
	}
}

void reset() //배열 초기화
{
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			bot[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

int main()
{
	int num, xmax, ymax, x, y, baecu;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d", &xmax, &ymax, &baecu);
		reset(); //배열 및 지렁이 수 초기화
		zir = 0;
		for (int j = 0; j < baecu; j++)
		{
			scanf("%d %d", &x, &y);
			bot[x][y] = 1;
		}
		run(xmax, ymax);
		printf("%d\n", zir);
		//print(xmax,ymax);
	}
}