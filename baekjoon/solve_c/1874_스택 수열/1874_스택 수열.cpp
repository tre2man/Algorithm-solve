#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*
스택과 큐를 이용하여 문제를 푼다.
스택을 이용할 곳은 스택 선언, 스택에서 빠진 수는 큐를 이용하여 보관한다.
빠진 수를 다시 넣기 위해서는 fifo 구조의 자료형이 필요함.
*/

int main()
{
    int n, a, temp;
    stack<int> s;
    queue<int> input;
    queue<char> ans;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        input.push(a);
    }
    temp = 1;
    while (input.size())
    {
        if(temp <= input.front())
        {
            while (temp <= input.front())
            {
                s.push(temp++);
                ans.push('+');
            }
        }
        else if(s.size() && s.top() == input.front())
        {
            s.pop();
            input.pop();
            ans.push('-');
        }
        else
        {
            cout << "NO\n";
            return (0);
        }
    }
    while(ans.size())
    {
        cout << ans.front() << "\n";
        ans.pop();
    }
    return (0);
}