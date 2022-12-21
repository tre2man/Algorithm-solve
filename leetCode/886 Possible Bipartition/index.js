/**
 * 이분그래프 + DFS
 * DFS로 모든 곳을 탐색한다. 이때 이전 탐색한 곳과 현재 탐색하는 곳의 팀이 같으면 false 반환
 * 다음 탐색 지점에는 현재 팀과 다른 팀을 새겨 둔다.
 * @param {number} n
 * @param {number[][]} dislikes
 * @returns
 */
var possibleBipartition = function (n, dislikes) {
  const visited = Array.from({ length: n }).fill(false);
  const team = Array.from({ length: n }).fill(0);
  const map = {};

  if (dislikes.length <= 0) return true;
  for (let i = 1; i <= n; i++) {
    map[i] = [];
  }
  for (const dislike of dislikes) {
    map[dislike[0]].push(dislike[1]);
    map[dislike[1]].push(dislike[0]);
  }

  for (let i = 1; i <= n; i++) {
    const stack = [];
    stack.push(map[i][0]);
    team[map[i][0]] = 1;
    while (stack.length > 0) {
      const cur = stack.pop();
      visited[cur] = true;
      const nexts = map[cur];
      if (nexts) {
        for (const next of nexts) {
          if (visited[next]) continue;
          if (team[cur] === team[next]) return false;
          team[next] = team[cur] * -1;
          stack.push(next);
        }
      }
    }
  }
  return true;
};
