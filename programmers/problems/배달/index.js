/**
 *
 * @param {number} N
 * @param {number[][]} road
 * @param {number} K
 */
function solution(N, road, K) {
  const len = Array.from({ length: N + 1 }).fill(Number.MAX_SAFE_INTEGER);
  const map = Array.from(Array(N + 1), () => []);

  road.forEach(([a, b, c]) => {
    map[a].push({ to: b, cost: c });
    map[b].push({ to: a, cost: c });
  });

  const stack = [{ to: 1, cost: 0 }];
  len[1] = 0;

  while (stack.length > 0) {
    // 모든 노드 탐색
    const { to } = stack.pop();
    map[to].forEach((next) => {
      // 도로가 2개 이상 있을경우, 최소 길이의 도로만 통과한다
      if (len[next.to] > len[to] + next.cost) {
        len[next.to] = len[to] + next.cost;
        stack.push(next);
      }
    });
  }

  return len.filter((item) => item <= K).length;
}
