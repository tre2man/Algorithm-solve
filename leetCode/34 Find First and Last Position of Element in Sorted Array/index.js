var searchRange = function (nums, target) {
  let result = [];
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === target) result.push(i);
  }
  if (result.length === 0) return [-1, -1];
  else if (result.length === 1) return [result[0], result[0]];
  else return [result[0], result.pop()];
};
