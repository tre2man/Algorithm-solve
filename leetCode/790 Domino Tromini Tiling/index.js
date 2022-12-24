/**
 * @param {number} n
 * @return {number}
 */
var numTilings = function (n) {
  const MOD = 10 ** 9 + 7;
  if (n <= 2) {
    return n;
  }

  const f = new Array({ length: n + 1 });
  const p = new Array({ length: n + 1 });
  f[1] = 1;
  f[2] = 2;
  p[2] = 1;
  for (let k = 3; k < n + 1; k++) {
    f[k] = (f[k - 1] + f[k - 2] + 2 * p[k - 1]) % MOD;
    p[k] = (p[k - 1] + f[k - 2]) % MOD;
  }
  return f[n];
};
