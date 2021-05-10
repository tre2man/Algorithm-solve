#include <string>
#include <vector>
#include <queue>

using namespace std;

int correct(queue<char> q)
{
    char temp;
    vector<char> v;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == '{' || temp == '[' || temp == '(')
            v.push_back(temp);
        else if (v.empty() && (temp == '}' || temp == ')' || temp == ']'))
            return (0);
        else if (!v.empty() && temp == '}' && v.back() == '{')
            v.pop_back();
        else if (!v.empty() && temp == ')' && v.back() == '(')
            v.pop_back();
        else if (!v.empty() && temp == ']' && v.back() == '[')
            v.pop_back();
    }
    if (v.empty())
        return (1);
    else
        return (0);
}

int solution(string s)
{
    int answer = 0;
    char temp;
    queue<char> q;
    queue<char> qq;

    for (int i = 0; i < s.length(); i++)
        q.push(s[i]);

    for (int i = 0; i < s.length(); i++)
    {
        temp = q.front();
        q.pop();
        q.push(temp);
        if (correct(q))
            answer++;
    }
    return answer;
}

int main()
{
    string a;
    a = "[](){}";
    printf("%d", solution(a));
}