/**
 * 파괴되지 않은 건물
 * 누적 합 알고리즘을 사용
 * 2차원 배열일 경우에는 행,열 두번씩 누적합을 한다.
 * 누적에 관한 배열이 완성되면 원래 배열과 합친다.
 * @param {number[][]} board
 * @param {number[][]} skill
 * @returns {number}
 */
function solution(board, skill) {
  let answer = 0;
  const N = board.length;
  const M = board[0].length;
  const acc = Array.from({ length: N + 1 }, () =>
    Array.from({ length: M + 1 }).fill(0)
  );

  // 각 포인트에 대하여 누적합 배열 생성 준비
  for (const [type, r1, c1, r2, c2, dmg] of skill) {
    const attack = dmg * (type === 1 ? -1 : 1);
    acc[r1][c1] += attack;
    acc[r2 + 1][c1] += attack * -1;
    acc[r1][c2 + 1] += attack * -1;
    acc[r2 + 1][c2 + 1] += attack;
  }

  // 누적합 실행하기
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      acc[i + 1][j] += acc[i][j];
    }
  }
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      acc[i][j + 1] += acc[i][j];
    }
  }

  // 기존 배열과 합치기
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      board[i][j] += acc[i][j];
      if (board[i][j] > 0) {
        answer++;
      }
    }
  }

  return answer;
}
