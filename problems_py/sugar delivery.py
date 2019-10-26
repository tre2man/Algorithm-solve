import sys

a=int(input())
i5=0
a5=0
i3=0

if(a%5==0):
    print(int(a/5))
    sys.exit()

while a>=i5*5:
    if((a-i5*5)%3==0):
        i3=(a-5*i5)/3
        a5=i5
    i5+=1

if(i3==0):
    print(-1)
else:
    print(int(a5+i3))