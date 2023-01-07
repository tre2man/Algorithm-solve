/**
 *
 * @param {number} w
 * @param {number} h
 * @returns {number}
 */
function solution(w, h) {
  let b = Math.max(w, h);
  let s = Math.min(w, h);
  let r = b % s;
  while (r > 0) {
    b = s;
    s = r;
    r = b % s;
  }
  // s는 최대공약수
  const newW = w / s;
  const newH = h / s;
  // 가로세로 길이가 소수인 경우, 거치는 사각형 개수는 가로+세로-1
  return w * h - s * (newW + newH - 1);
}
