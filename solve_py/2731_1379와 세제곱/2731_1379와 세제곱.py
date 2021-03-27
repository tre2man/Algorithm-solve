'''
일반적인 백트래킹을 이용한 문제.
주어지는 값은 모두 답이 있다고 가정한다.
세제곱한 결과의 마지막 n자리 까지의 숫자가 답의 마지막 n자리 까지 같으면, 다음 자리로 넘어간다.
무턱대고 세제곱을 하게 되면 계산량이 많이 늘어난다.
중간에 n자리까지 남겨둔 후, 다시 곱해 주자.
'''

check = 0
ans = 0
end = 0
inputs = 0
powarr=[]

#백트래킹으로 탐색하는 함수
def cal(start):
    global ans, check, end, inputs
    #end 플래그가 1이면, 람수 종료
    if end == 1:
        return
    #0부터 9까지 검사
    for i in range (0,10):
        #세제곱을 하는 과정
        check = ans + i * powarr[start]
        check *= check
        check %= powarr[start + 1]
        check *= (ans + i * powarr[start])
        #마지막 n자리의 숫자가 세제곱한 결과와 입력값이 같으면?
        if (inputs % powarr[start + 1]) == (check % powarr[start + 1]):
            #답에다가 추가해준다.
            ans = ans + i * powarr[start]
            #만약 답을 찾았다면? end 플래그 1로 변경
            if inputs == (check % powarr[start + 1]):
                end = 1
            #다음 자리수 탐색
            cal(start + 1)

#main 함수
def main():
    global ans, check, end, inputs
    T = int(input())
    powarr.append(1)
    for i in range(1,17):
        powarr.append(powarr[i - 1] * 10)
    for i in range(0,T):
        check = ans = end = 0
        inputs = int(input())
        cal(0)
        print(ans)

main()