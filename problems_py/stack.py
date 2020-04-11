import sys

input_data = int(input())
stack = []

for i in range(input_data):
    value = input().split()
    if value[0] == 'push':
        stack.append(int(value[1]))
    elif value[0] == 'pop':
        if len(stack) :
            print(stack[-1])
            stack.pop()
        else:
            print('-1')
    elif value[0] == 'top' :
        if len(stack):
            print(stack[-1])
        else:
            print('-1')
    elif value[0] == 'size':
        print(len(stack))
    elif value[0] == 'empty':
        print(0 if len(stack) else 1)