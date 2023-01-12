/**
 * 주차 요금 계산
 * @param {number[]} fees
 * @param {string[]} records
 * @returns
 */
function solution(fees, records) {
  var answer = [];
  const infos = records.map((r) => r.split(" "));
  const obj = {};

  infos.forEach(([time, carnum, _]) => {
    if (obj[carnum]) {
      obj[carnum].push(time);
    } else {
      obj[carnum] = [time];
    }
  });

  Object.keys(obj).forEach((r) => {
    // 홀수일경우 마지막 시간 추가하기
    if (obj[r].length % 2) {
      obj[r].push("23:59");
    }
  });

  function getMinute(input) {
    return input.split(":").reduce((acc, cur, idx) => {
      if (idx) {
        return acc + Number(cur);
      }
      return acc + Number(cur) * 60;
    }, 0);
  }

  Object.keys(obj)
    .sort()
    .forEach((carnum) => {
      const times = obj[carnum];
      let total = 0;
      let ans = 0;
      for (let i = 0; i < times.length; i += 2) {
        const start = getMinute(times[i]);
        const end = getMinute(times[i + 1]);
        const diff = end - start;
        total += diff;
      }
      if (total <= fees[0]) {
        ans += fees[1];
      } else {
        ans += fees[1] + Math.ceil((total - fees[0]) / fees[2]) * fees[3];
      }
      answer.push(ans);
    });

  return answer;
}
