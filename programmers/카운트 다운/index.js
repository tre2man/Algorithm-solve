/**
 *
 * @param {number} target
 * @returns {number[]}
 */
function solution(target) {
  // dp[n][0] : 다트개수, dp[n][1] : 보너스 점수 (bool + single)
  // 다트 숫자는 적을수록 좋으니 기본값 Inf, 보너스 점수는 많을수록 좋으니 기본값 0
  const dp = Array.from({ length: 300000 }).map((_) => [Infinity, 0]);
  const darts = Array.from({ length: 20 }).map((_, idx) => idx + 1);

  // 초기값 리셋
  dp[0][0] = 0;
  // 1 * target이 최악의 경우라 가정하고, 반복문 돌리기
  for (let i = 0; i < target; i++) {
    function check(num, bonus) {
      // 만약 다트숫자가 같거나 클경우
      if (dp[i + num][0] >= dp[i][0] + 1) {
        // 다트 숫자가 같을 때 : 보너스 점수를 보고 보너스 점수(개수) 업데이트 결정
        if (dp[i + num][0] === dp[i][0] + 1) {
          dp[i + num][1] = Math.max(dp[i + num][1], dp[i][1] + bonus);
        }
        // 다트 숫자가 다를때 : 다트 숫자만 보고 업데이트
        else {
          dp[i + num] = [dp[i][0] + 1, dp[i][1] + bonus];
        }
      }
    }
    for (const dart of darts) {
      [
        [1, 1],
        [2, 0],
        [3, 0],
      ].forEach(([n, v]) => {
        check(dart * n, v);
      });
    }
    // 불 일때
    check(50, 1);
  }
  return dp[target];
}
