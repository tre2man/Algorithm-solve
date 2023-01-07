function solution(number, k) {
  let answer = "";
  const stack = [];
  for (let i = 0; i < number.length; i++) {
    const end = number[i];
    // 제일 큰 수가 나올때까지 스택에서 뺀다.
    while (k > 0 && stack[stack.length - 1] < end) {
      stack.pop();
      k--;
    }
    stack.push(end);
  }
  stack.splice(stack.length - k, k);
  answer = stack.join("");
  return answer;
}
