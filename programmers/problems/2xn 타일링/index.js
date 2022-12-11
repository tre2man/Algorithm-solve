function solution(n) {
  const ans = [1, 2];
  const originN = n;
  while (n > 2) {
    const len = ans.length;
    ans.push((ans[len - 1] + ans[len - 2]) % 1000000007);
    n--;
  }
  return ans[originN - 1];
}
