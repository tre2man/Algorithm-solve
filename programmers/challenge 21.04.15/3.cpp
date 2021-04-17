#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> input[300000];

long long cal(vector<int> a, vector<vector<int>> edges, int start)
{
    vector<int> location[300000];
    queue<int> q;
    int visited[300000];
    int temp[2];
    int temp_num = 0;
    int min_num = 1000000;
    int max_num = -1000000;
    
    memset(visited,0,sizeof(visited));
    
    for (vector<int> vec : edges)
    {
        int index = 0;
        for (int num : vec)
            temp[index++] = num;
        location[temp[0]].push_back(temp[1]);
        location[temp[1]].push_back(temp[0]);
    }
    
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int start_node = q.front();
        q.pop();
        for(auto i = location[start_node].begin(); i != location[start_node].end(); i++)
        {
            if (!visited[*i])
            {
                q.push(*i);
                visited[*i] = 1;
            }
        }
    }
    for(int i=0 ; i<300000; i++)
    {
        if (visited[i] && i < a.size())
        {
            temp_num += a[i];
            if (a[i] < min_num)
                min_num = a[i];
            if (a[i] > max_num)
                max_num = a[i];
        }
    }
    if (temp_num)
        return (-1);
    else
    {
        if (-min_num > max_num)
            return ((long long)(-min_num * 2 - 1));
        else
            return ((long long)(max_num * 2 - 1));
    }
}

long long solution(vector<int> a, vector<vector<int>> edges)
{
    long long answer = 0;
    long long temp;
    for(int i=0;i<a.size();i++)
    {
        temp = cal(a, edges, a[i]);
        if (temp == -1)
            return (-1);
        else
            answer = temp;
    }
    return answer;
}

int main()
{
    vector<int> a = {-5,0,2,1,2};
    vector<vector<int>> edges = {{0,1},{3,4},{2,3},{0,3}};
    cout << solution(a, edges);
    return (0);
}