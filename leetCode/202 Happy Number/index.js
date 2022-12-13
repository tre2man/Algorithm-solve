var isHappy = function (n) {
  const set = new Set();
  let num = String(n);
  while (true) {
    const res = num
      .split("")
      .reduce((acc, cur) => acc + Number(cur) * Number(cur), 0);
    num = String(res);
    if (set.has(num)) return false;
    if (num === "1") return true;
    set.add(num);
  }
};
