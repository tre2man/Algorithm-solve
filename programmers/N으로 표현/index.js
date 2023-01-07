function solution(N, number) {
  if (N == number) return 1;

  const use = Array.from(new Array(9), () => new Set());
  use.forEach((element, index) => {
    if (index !== 0) element.add(Number(String(N).repeat(index)));
  });
  for (let i = 1; i <= 8; i++) {
    for (let j = 1; j < i; j++) {
      for (const first of use[j]) {
        for (const second of use[i - j]) {
          use[i].add(first + second);
          use[i].add(first - second);
          use[i].add(first * second);
          use[i].add(first / second);
        }
      }
    }
    if (use[i].has(number)) return i;
  }
  return -1;
}
