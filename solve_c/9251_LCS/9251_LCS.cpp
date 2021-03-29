#include <iostream>
#include <string.h>
using namespace std;

/*
LCS 알고리즘을 이용한 문제.
공백 + 문자열을 가로 세로로 배치.
겹치는 칸의 숫자는 해당 문자열의 LSC 숫자.
문자가 겹치면 + 1
해당 칸의 숫자 = max(위, 아래)
문자열의 길이 : 오른쪽 아래 숫자
*/

int dp[1010][1010];

int main()
{
    int len_input1, len_input2;
    char input1[1010];
    char input2[1010];

    scanf("%s", input1);
    scanf("%s", input2);
    len_input1 = strlen(input1);
    len_input2 = strlen(input2);
    for (int i = 1; i <= len_input2; i++)
    {
        for (int j = 1; j <= len_input1; j++)
        {
            if (input2[i - 1] == input1[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    printf("%d\n", dp[len_input2][len_input1]);
}