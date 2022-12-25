/**
 * @param {number} n
 * @return {number}
 */
var numTilings = function (n) {
  const MOD = 10 ** 9 + 7;
  if (n <= 2) {
    return n;
  }

  const answer = Array.from({ length: n + 1 }, () => Array(2).fill(0));
  answer[1][0] = 1;
  answer[2][0] = answer[2][1] = 2;
  for (let i = 3; i <= n; i++) {
    answer[i][0] =
      (answer[i - 1][0] + answer[i - 2][0] + answer[i - 1][1]) % MOD;
    answer[i][1] = (2 * answer[i - 2][0] + answer[i - 1][1]) % MOD;
  }
  return answer[n][0];
};
