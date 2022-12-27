/**
 * @param {number[]} capacity
 * @param {number[]} rocks
 * @param {number} additionalRocks
 * @return {number}
 */
var maximumBags = function (capacity, rocks, additionalRocks) {
  let answer = 0;
  const diffs = capacity
    .map((cur, idx) => cur - rocks[idx])
    .sort((a, b) => a - b);
  for (let i = 0; i < diffs.length; i++) {
    const diff = (additionalRocks -= diffs[i]);
    if (diff < 0) break;
    answer++;
  }
  return answer;
};
