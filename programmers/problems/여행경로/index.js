/**
 * 기존 나의 풀이
 * - 일반적인 dfs로 풀이함. 알파벳 순서가 빠른 경로부터 탐색하도록 함.
 * - 링크의 개수를 visit으로 체크해서, 링크를 방문하면 -1을 한다.
 * ---
 * 모범답안
 * - dfs라고 하지만, 알고보니 백트래킹 문제였음...
 * - dfs로 탐색하며 정답에 조건에 맞을 때까지 탐색한다.
 * @param {string[][]} tickets
 * @returns {string[]}
 */
function solution(tickets) {
  let answer = [];
  const result = [];
  // 여기서 vistied는 티켓을 가리킴 (티켓=노드)
  const visited = [];

  // 순차적으로 노드를 방문하기 위해 알파벳 순서대로 정렬
  // 출발지를 기준으로 오름차순 정렬
  // 출발지가 같으면 도착지를 기준으로 오름차순 정렬
  tickets.sort((a, b) => {
    if (a[0] === b[0]) return a[1].localeCompare(b[1]);
    return a[0].localeCompare(b[0]);
  });

  const len = tickets.length;
  function dfs(str, count) {
    result.push(str);
    // 모든 노드를 탐색했을경우 true 반환 (탈출조건)
    if (count === len) {
      answer = result;
      return true;
    }
    for (let i = 0; i < len; i++) {
      // 해당 노드를 방문하지 않았으면서, 현재 노드(티켓)와 출발지가 같으면
      if (!visited[i] && tickets[i][0] === str) {
        visited[i] = true;
        if (dfs(tickets[i][1], count + 1)) return true;
        visited[i] = false;
      }
    }
    result.pop();
    return false;
  }
  dfs("ICN", 0);
  return answer;
}
