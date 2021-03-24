#include <iostream>
#include <queue>
#include <stack>
using namespace std;

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