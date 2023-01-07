function solution(nums) {
  const ans = [...new Set(nums)];
  const limit = nums.length / 2;
  return ans.length > limit ? limit : ans.length;
}
