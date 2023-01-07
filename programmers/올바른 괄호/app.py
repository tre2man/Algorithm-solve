def solution(s):
    stack = []
    for char in s:
        if char == ')':
            if len(stack) == 0:
                return False
            if stack[len(stack) - 1] == '(':
                stack.pop()
        elif char == '(':
            stack.append('(')
    if len(stack) > 0:
        return False
    return True
