/**
 *
 * @param {number[][]} routes
 * @returns
 */
function solution(routes) {
  var answer = 0;
  // 시작지점을 기준으로 오름차순 정렬
  routes.sort((a, b) => a[0] - b[0]);
  // 카메라가 설치된 위치
  let camera = -30001;
  for (let i = 0; i < routes.length; i++) {
    // 카메라가 설치된 위치가 다음 차량의 진입 지점보다 작으면 카메라를 설치
    if (camera < routes[i][0]) {
      camera = routes[i][1];
      answer++;
    } else {
      // 카메라가 설치된 위치가 다음 차량의 진입 지점보다 크면 카메라를 다음 차량의 진출 지점으로 이동
      camera = Math.min(camera, routes[i][1]);
    }
  }
  return answer;
}
