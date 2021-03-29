#include <iostream>
#include <stack>
using namespace std;

/*
스택을 이용한 후위 표기식 문제.
피연산자는 바로 출력하고, 연산자를 스택에 저장하여 제어한다.
우선순위가 높은 연산자 순서대로 출력하는 것을 기본으로 한다.
*/

int main()
{
    char *input = (char *)malloc(sizeof(char) * 101);
    stack<char> sign;

    scanf("%s", input);
    while (*input)
    {
        /* 더하기 빼기일때, 우선순위까지 출력한 후 연산자를 push한다. */
        if (*input == '+' || *input == '-')
        {
            while (sign.size() && sign.top() != '(')
            {
                printf("%c",sign.top());
                sign.pop();
            }
            sign.push(*input);
        }
        /* 곱하기 나누기일때, 앞의 연산자가 곱/나누기 이면 앞에거 먼저 출력후 연산자 push */
        else if (*input == '*' || *input == '/')
        {
            if (sign.size() && (sign.top() == '*' || sign.top() == '/'))
            {
                printf("%c",sign.top());
                sign.pop();
                sign.push(*input);
            }
            else
                sign.push(*input);
        }
        /* 닫는 괄호 연산자일경우, '(' 까지 그대로 출력한다. */
        else if (*input == ')')
        {
            while (sign.top() != '(')
            {
                printf("%c",sign.top());
                sign.pop();
            }
            sign.pop();
        }
        /* 여는 괄호 연산자, 스택에 입력 */
        else if (*input == '(')
            sign.push(*input);
        /* 피연산자는 그대로 출력 */
        else
            printf("%c",*input);
        input++;
    }
    /* 남은 수식이 있을경우, 그대로 출력 */
    while (sign.size())
    {
        printf("%c",sign.top());
        sign.pop();
    }
    return (0);
}