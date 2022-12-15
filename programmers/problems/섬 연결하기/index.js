/**
 * MST(Minimum Spanning Tree) 알고리즘으로 풀어야 한다.
 * 간선의 가중치의 합이 최소, 사이클 없음, n=노드의 수 일때 간선의 수는 n-1, 최종적으로는 트리 구조가 된다.
 * Kuskal MST : 가중치를 오름차순으로 정렬, 사이클이 없는 간선을 계속 추가한다. 사이클 판별은 union-find 알고리즘으로 판별
 * Prim MST : dfs 탐색, 현재 노드와 연결된 최소 비용 간선으로 탐색, 모든 노드를 시작으로 순회 -> 방사형 그래프에서 안되었던걸로 기억함
 */

// 사이클을 확인하기 위한 obj
// p[a] : 부모 노드, a: 자식 노드(간선 1개)
let p = {};

/**
 * 해당 노드의 최종 부모 노드 확인하기
 * @param {number} e
 * @returns
 */
function getParent(e) {
  if (p[e] === e) {
    return e;
  } else {
    return getParent(p[e]);
  }
}

/**
 * 입력받은 두개의 노드를 연결한다
 * @param {number[]} e
 * @returns {number}
 */
function unionParent(e) {
  let a = getParent(e[0]);
  let b = getParent(e[1]);

  // 입력받은 노드들의 최종 부모 노드가 같다면?
  if (a === b) {
    return -1;
  }

  // 부모 노드와 자식 노드의 관계 재정의
  if (a > b) {
    p[a] = b;
  } else {
    p[b] = a;
  }
  return e[2];
}

/**
 * @param {number} n
 * @param {number[][]} costs
 * @returns {number}
 */
function solution(n, costs) {
  let answer = 0;

  // 가중치 정렬
  costs.sort((a, b) => a[2] - b[2]);

  // 사이클 확인 객체 초기화
  for (let i = 0; i < n; i++) {
    p[i] = i;
  }

  // cost가 낮은 순서로 간선 연결하기. 단, 사이클이 있는 경우는 제외
  costs.forEach((e) => {
    let cost = unionParent(e);
    if (cost !== -1) {
      answer += cost;
    }
  });
  return answer;
}
