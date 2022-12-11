function cal(numbers, beforeValue, depth, target) {
  if (depth === numbers.length) {
    if (beforeValue === target) {
      return 1;
    } else {
      return 0;
    }
  }
  const val1 = cal(numbers, beforeValue + numbers[depth], depth + 1, target);
  const val2 = cal(numbers, beforeValue - numbers[depth], depth + 1, target);
  return val1 + val2;
}

function solution(numbers, target) {
  let answer = cal(numbers, 0, 0, target);
  return answer;
}
