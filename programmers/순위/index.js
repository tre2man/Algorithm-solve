/**
 * 플로이드-와샬 알고리즘 사용
 * n명의 선수가 있을때, 각 선수는 n-1번의 승패를 알아야 순위확정이 가능하다.
 * 선수와 선수 간 대전 결과를 알아야 한다. 단, 무조건 이기거나 지는 경우가 있으면 승부예측이 가능하다.
 * @param {number} n
 * @param {numbers[][]} results
 * @returns {number}
 */
function solution(n, results) {
  const connection = Array.from({ length: n + 1 }, () =>
    Array.from({ length: n + 1 }).fill(0)
  );
  results.forEach(([win, lose]) => {
    connection[win][lose] = 1;
    connection[lose][win] = -1;
  });

  // i는 중간지점, j는 시작지점, k는 종료지점
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      for (let k = 1; k <= n; k++) {
        // j->i 와 i->k 가 이기면, j->k는 무조건 이긴다.
        if (connection[j][i] === 1 && connection[i][k] === 1) {
          connection[j][k] = 1;
        }
        // j->i 와 i->k 가 지면, j->k는 무조건 진다.
        else if (connection[j][i] === -1 && connection[i][k] === -1) {
          connection[j][k] = -1;
        }
      }
    }
  }

  let answer = 0;
  // 한명의 결과가 n-1개 있으면, 승부 결과가 확실하다.
  for (let i = 1; i <= n; i++) {
    const res = connection[i].reduce((acc, cur) => (cur ? acc + 1 : acc), 0);
    if (res === n - 1) answer++;
  }
  return answer;
}
