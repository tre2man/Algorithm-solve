/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var answerQueries = function (nums, queries) {
  const answer = [];
  const sumNums = nums.sort((a, b) => a - b);
  for (let i = 0; i < sumNums.length; i++) {
    if (i) {
      sumNums[i] += sumNums[i - 1];
    }
  }
  for (const query of queries) {
    let tic = true;
    for (let i = 0; i < sumNums.length; i++) {
      if (sumNums[i] > query) {
        answer.push(i);
        tic = false;
        break;
      }
    }
    if (tic) answer.push(sumNums.length);
  }
  return answer;
};
