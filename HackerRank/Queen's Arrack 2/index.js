function queensAttack(n, k, r_q, c_q, obstacles) {
  // Write your code here
  let answer = 0;
  let obj = {};
  for (const obstacle of obstacles) {
    obj[JSON.stringify(obstacle)] = 1;
  }
  const turn_x = [1, 1, 0, -1, -1, -1, 0, 1];
  const turn_y = [0, -1, -1, -1, 0, 1, 1, 1];
  for (let i = 0; i < 8; i++) {
    let s_r = r_q;
    let s_c = c_q;
    while (true) {
      s_r += turn_x[i];
      s_c += turn_y[i];
      if (s_r <= 0 || s_r > n || s_c <= 0 || s_c > n) {
        break;
      }
      if (obj[JSON.stringify([s_r, s_c])]) {
        break;
      }
      answer++;
    }
  }
  return answer;
}
