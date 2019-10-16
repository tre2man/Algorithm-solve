a=int(input())
b=0
c=0
count=1
ans=a

while True:
    b=ans%10  #일의자리
    c=int(ans/10)  #십의자리
    ans=b*10+(b+c)%10
    if ans==a:
        break
    count+=1
print(count)
