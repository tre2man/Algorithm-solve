/**
 * 그래프 탐색? dp?
 * 백트래킹으로 탐색할 경우 시간복잡도 늘어날 가능성
 * dp로 탐색하자
 * @param {number[]} sticker
 * @returns {number}
 */
function solution(sticker) {
  if (sticker.length === 1) {
    return sticker[0];
  }

  const len = sticker.length;
  // 첫번째 스티커 뜯음
  const dp = [sticker[0], sticker[0]];
  // 첫번째 스티커 안뜯음
  const dp2 = [0, sticker[1]];

  // dp는 첫번째 스티커를 뜯었으므로, 마지막에 뜯으면 안됨
  for (let i = 2; i < len - 1; i++) {
    dp[i] = Math.max(dp[i - 2] + sticker[i], dp[i - 1]);
  }
  const val1 = Math.max(...dp);
  for (let i = 2; i < len; i++) {
    dp2[i] = Math.max(dp2[i - 2] + sticker[i], dp2[i - 1]);
  }
  const val2 = Math.max(...dp2);

  // 바로 Math.max에 때려박으면 런타임 에러 남
  return Math.max(val1, val2);
}
