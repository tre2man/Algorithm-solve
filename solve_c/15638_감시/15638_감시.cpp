#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 2147483647

/*
미완성
*/

typedef struct
{
    int x;
    int y;
    int input;
} location;

typedef struct
{
    int x;
    int y;
    int cctv;
    int direction;
} explore;

int N, M, ans = INT_MAX, temp = 0;
int map[9][9];
int map2[9][9];
vector<location> v;
vector<explore> explore_v;

void copy_map()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            map2[i][j] = map[i][j];
}

void looking_up(int x, int y)
{
    for (int i = x; i >= 1; i--)
    {
        if (map[i][y] == 6)
            break;
        else if (map[i][y] == 0)
            map[i][y] = 7;
    }
}

void looking_down(int x, int y)
{
    for (int i = x; i <= N; i++)
    {
        if (map[i][y] == 6)
            break;
        else if (map[i][y] == 0)
            map[i][y] = 7;
    }
}

void looking_left(int x, int y)
{
    for (int i = y; i >= 1; i--)
    {
        if (map[x][i] == 6)
            break;
        else if (map[x][i] == 0)
            map[x][i] = 7;
    }
}

void looking_right(int x, int y)
{
    for (int i = y; i <= M; i++)
    {
        if (map[x][i] == 6)
            break;
        else if (map[x][i] == 0)
            map[x][i] = 7;
    }
}

void fill_map()
{
    for (int i = 0; i < explore_v.size(); i++)
    {
        int x = explore_v[i].x;
        int y = explore_v[i].y;
        int cctv = explore_v[i].cctv;
        int dir = explore_v[i].direction;
        //지도에 볼수 있는 곳 채우기
    }
}

void cal_empty()
{
    temp = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (map2[i][j] == 0)
                temp++;
    if (temp < ans)
        ans = temp;
}

void print_map()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            printf("%2d ", map2[i][j]);
        }
        printf("\n");
    }
}

void cal(int index)
{
    if (index == v.size())
    {
        copy_map();
        fill_map();
        //전체 계산
        return;
    }
    else
    {
        int x = v[index].x;
        int y = v[index].y;
        int loc = v[index].input;
        if (loc == 1 || loc == 3 || loc == 4)
        {
            for (int i = 1; i <= 4; i++)
            {
                explore_v.push_back({x, y, loc, i});
                cal(index + 1);
                explore_v.pop_back();
            }
        }
        else if (loc == 2)
        {
            for (int i = 1; i <= 2; i++)
            {
                explore_v.push_back({x, y, loc, i});
                cal(index + 1);
                explore_v.pop_back();
            }
        }
        else
        {
            explore_v.push_back({x, y, loc, 1});
            cal(index + 1);
            explore_v.pop_back();
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", map[i][j]);
            if (1 <= map[i][j] && map[i][j] <= 5)
                v.push_back({i, j, map[i][j]});
        }
    }
    cal(0);
}