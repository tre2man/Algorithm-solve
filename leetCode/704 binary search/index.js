function rec(nums, start, end, target) {
  // 범위안에없음
  if (nums[start] > target || nums[end] < target) return -1;
  // 답찾음
  if (start === end && nums[start] === target) return start;
  const left = rec(nums, start, Math.floor((start + end) / 2), target);
  const right = rec(nums, Math.ceil((start + end) / 2), end, target);
  return Math.max(left, right);
}

var search = function (nums, target) {
  const rtn = rec(nums, 0, nums.length - 1, target);
  return rtn;
};
