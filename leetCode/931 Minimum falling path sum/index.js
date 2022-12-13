var minFallingPathSum = function (matrix) {
  const n = matrix.length;
  const results = Array.from(Array(n), () => new Array(n).fill(0));
  for (let i = 0; i < n; i++) {
    // 첫번째일 경우
    if (i === 0) {
      for (let j = 0; j < n; j++) {
        results[i][j] = matrix[i][j];
      }
      continue;
    }
    for (let j = 0; j < n; j++) {
      const lists = [];
      for (let k = -1; k <= 1; k++) {
        const bf = j + k;
        if (bf >= 0 && bf < n) {
          lists.push(matrix[i][j] + results[i - 1][bf]);
        }
      }
      results[i][j] = Math.min(...lists);
    }
  }
  return Math.min(...results[n - 1]);
};
