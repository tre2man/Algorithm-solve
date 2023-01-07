function solution(n, stations, w) {
  let answer = 0;
  const cov = w * 2 + 1;

  const end =
    n -
    stations.reduce((prev, cur) => {
      const appartments = cur - w - 1 - prev;
      answer += appartments > 0 ? Math.floor((appartments - 1) / cov) + 1 : 0;
      return cur + w;
    }, 0);

  if (end > 0) answer += Math.floor((end - 1) / cov) + 1;

  return answer;
}
