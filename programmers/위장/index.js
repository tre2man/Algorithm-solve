function solution(clothes) {
  let ans = 1;
  const obj = {};
  for (const c of clothes) {
    if (typeof obj[c[1]] === "undefined") {
      obj[c[1]] = 1;
    } else {
      obj[c[1]]++;
    }
  }
  for (const key in obj) {
    ans *= obj[key] + 1;
  }
  return ans - 1;
}
