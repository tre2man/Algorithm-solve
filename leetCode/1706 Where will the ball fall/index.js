/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findBall = function (grid) {
  const result = [];
  const row = grid.length;
  const col = grid[0].length;

  // 가로
  for (let i = 0; i < col; i++) {
    // 세로
    let nowI = i;
    let t = false;
    for (let j = 0; j < row; j++) {
      if (grid[j][nowI] === 1) {
        if (nowI + 1 >= col || grid[j][nowI + 1] === -1) {
          result.push(-1);
          t = true;
          break;
        }
        nowI++;
      }
      if (grid[j][nowI] === -1) {
        if (nowI - 1 < 0 || grid[j][nowI - 1] === 1) {
          result.push(-1);
          t = true;
          break;
        }
        nowI--;
      }
    }
    if (t === true) continue;
    result.push(nowI);
  }
  return result;
};
