/**
 * n*n 행렬 만들면 터짐. arr push 하자
 * @param {number} n
 * @param {number[][]} edge
 * @returns
 */
function solution(n, edge) {
  const visit = [0, 1];
  const map = Array.from({ length: n + 1 }, () => []);
  edge.forEach(([a, b]) => {
    map[a].push(b);
    map[b].push(a);
  });

  const q = [];
  q.push(1);
  while (q.length > 0) {
    const pop = q.shift();
    const nextNodes = map[pop];
    for (const nextNode of nextNodes) {
      if (!visit[nextNode]) {
        q.push(nextNode);
        visit[nextNode] = visit[pop] + 1;
      }
    }
  }
  const maxNum = Math.max(...visit);
  return visit.reduce((acc, cur) => acc + (cur === maxNum ? 1 : 0), 0);
}
