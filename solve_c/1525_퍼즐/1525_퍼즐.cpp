#include <iostream>
#include <queue>
using namespace std;

typedef struct
{
	int arr[3][3];
} maps;

typedef struct
{
	int x, y, move;
} loc;

int map[3][3];
int ans[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int visited[3][3][10];

int mapcmp(maps m)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (m.arr[i][j] != ans[i][j])
				return (0);
	return (1);
}

void mapcpy(maps *a, maps *b)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			(a->arr)[i][j] = (b->arr)[i][j];
}

void printmap(maps a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout << a.arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int bfs(int x, int y)
{
	int move_x[4] = {1, -1, 0, 0};
	int move_y[4] = {0, 0, 1, -1};
	queue<loc> q;
	queue<maps> m;
	maps tempmap;

	q.push((loc){x, y, 0});
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tempmap.arr[i][j] = map[i][j];
	m.push(tempmap);
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int move = q.front().move;
		q.pop();
		tempmap = m.front();
		m.pop();
		/* 답이 나왔을 경우 */
		if (mapcmp(tempmap))
			return (move);
		for (int i = 0; i < 4; i++)
		{
			int dx = x + move_x[i];
			int dy = y + move_y[i];
			maps newmap;
			printmap(tempmap);
			cout << "move : " << move << "\n" << dx << dy << "\n";
			cout << "map : " << visited[y][x][map[dy][dx]] << "\n";
			/* 옮길 블록이 현재 0의 위치를 방문하지 않았을 경우 */
			if (dx >= 0 && dx < 3 && dy >= 0 && dy < 3 && !visited[y][x][map[dy][dx]])
			{
				visited[y][x][map[dy][dx]] = 1;
				mapcpy(&newmap, &tempmap);
				newmap.arr[y][x] = tempmap.arr[dy][dx];
				newmap.arr[dy][dx] = 0;
				q.push((loc){dx, dy, move + 1});
				m.push(newmap);
			}
		}
	}
	return (-1);
}

int main()
{
	freopen("test", "r", stdin);
	int x, y;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map[i][j];
			if (!map[i][j])
			{
				y = i;
				x = j;
			}
		}
	}
	cout << bfs(x, y);
	return (0);
}