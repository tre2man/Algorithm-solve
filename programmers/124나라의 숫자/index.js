function solution(n) {
  let answer = "";
  const str = "412";
  while (n) {
    answer = str[n % 3] + answer;
    n = n % 3 == 0 ? n / 3 - 1 : Math.floor(n / 3);
  }
  return answer;
}
