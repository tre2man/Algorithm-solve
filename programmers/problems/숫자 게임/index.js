/**
 *
 * @param {number[]} A
 * @param {number[]} B
 * @returns {number}
 */
function solution(A, B) {
  let answer = 0;
  A.sort((a, b) => a - b);
  B.sort((a, b) => b - a);
  console.log({ A });
  console.log({ B });
  for (const a of A) {
    while (B.length > 0 && a >= B[B.length - 1]) {
      B.pop();
    }
    if (a < B[B.length - 1]) {
      answer++;
      B.pop();
    }
  }
  return answer;
}
