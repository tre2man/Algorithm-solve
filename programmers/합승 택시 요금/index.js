/**
 * 처음 생각한 오답
 * 공통 택시 거리를 A, 각자 택시 거리의 합을 B라고 하면
 * A+B가 최소가 되는 방법을 일일이 찾음
 */

// /**
//  *
//  * @param {number} n
//  * @param {number} start
//  * @param {number} end
//  * @param {number[][]} map
//  * @returns {number}
//  */
// function getEachLength(n, start, end, map) {
//   if (start === end) return 0;
//   const visited = Array.from({ length: n + 1 }).fill(Infinity);

//   const q = [{ to: start, length: 0 }];
//   while (q.length > 0) {
//     const { to, length } = q.shift();
//     const nexts = map[to];
//     for (const { to: nextTo, length: nextLength } of nexts) {
//       if (visited[nextTo] > length + nextLength) {
//         visited[nextTo] = length + nextLength;
//         q.push({ to: nextTo, length: length + nextLength });
//       }
//     }
//   }
//   return visited[end];
// }

// /**
//  *
//  * @param {number} n
//  * @param {number} s
//  * @param {number} a
//  * @param {number} b
//  * @param {number[][]} fares
//  * @returns
//  */
// function solution(n, s, a, b, fares) {
//   const answerArr = [];
//   const map = Array.from({ length: n + 1 }, () => []);
//   const visited = Array.from({ length: n + 1 }).fill(Infinity);
//   for (const [start, end, length] of fares) {
//     map[start].push({ to: end, length });
//     map[end].push({ to: start, length });
//   }

//   // 같이 가는 길을 0개부터 A 또는 B 까지 도달할 때 까지 탐색
//   // 각 경우마다 같이가는길 node의 마지막부터 A,B까지 가는 길 탐색
//   // 탐색 완료했으면 answerArr에 push
//   const stack = [];
//   stack.push({ to: s, length: 0 });
//   while (stack.length > 0) {
//     const { to, length } = stack.shift();
//     visited[to] = length;
//     // to부터 A, B까지 가는길의 length 구하기
//     const resA = getEachLength(n, to, a, map);
//     const resB = getEachLength(n, to, b, map);
//     // 현재까지의 length + to부터 A, B까지 가는길의 length
//     answerArr.push(length + resA + resB);
//     // 다음 노드 탐색하기
//     const nexts = map[to];
//     for (const { to: nextTo, length: nextLength } of nexts) {
//       if (visited[nextTo] > length + nextLength) {
//         visited[nextTo] = length + nextLength;
//         stack.push({ to: nextTo, length: length + nextLength });
//       }
//     }
//   }

//   const answer = Math.min(...answerArr);
//   return answer;
// }

/**
 * 정답 버전
 * 플로이드 와샬은 s에서 e까지 가는데 최단거리 구하기 위해
 * s와 e 사이의 노드인 m에 대해서 m까지 가는데 걸리는 최단거리의 합을 이용해
 * s에서 e까지 가는데 m을 경유하는 최단거리를 구한다.
 * 예) s-e 최단거리가 s-m + m-e 보다 작으면 s-e의 최단거리 값을 변경한다.
 */
/**
 *
 * @param {number} n
 * @param {number} s
 * @param {number} a
 * @param {number} b
 * @param {number[][]} fares
 * @returns
 */
function solution(n, s, a, b, fares) {
  // 전체 노드에 대한 그래프, graph[a][b] 는 a에서 b까지 가는 최단경로라고 생각하자.
  const graph = Array.from({ length: n + 1 }, () =>
    Array.from({ length: n + 1 }).fill(Infinity)
  );
  fares.forEach(([a, b, c]) => {
    // 그래프 제작
    graph[a][b] = c;
    graph[b][a] = c;
  });
  // 본인에 대한 최단경로는 0
  for (let i = 0; i <= n; i++) {
    graph[i][i] = 0;
  }
  // k는 경유, i는 시작, j는 도착
  for (let k = 1; k <= n; k++) {
    for (let i = 1; i <= n; i++) {
      for (let j = 1; j <= n; j++) {
        if (graph[i][j] > graph[i][k] + graph[k][j])
          graph[i][j] = graph[i][k] + graph[k][j];
      }
    }
  }
  // 기본답 : 두사람이 따로갈경우, s-a 최단경로 + s-b 최단경로를 반환
  let answer = graph[s][a] + graph[s][b];
  for (let i = 1; i <= n; i++) {
    const shortest = graph[s][i] + graph[i][a] + graph[i][b];
    answer = Math.min(answer, shortest);
  }
  return answer;
}
