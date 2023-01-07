function solution(progresses, speeds) {
  var answer = [];
  while (progresses.length > 0) {
    for (let i = 0; i < progresses.length; i++) {
      let num = 0;
      for (let j = 0; j < progresses.length; j++) {
        progresses[j] += speeds[j];
      }
      while (progresses.length > 0 && progresses[0] >= 100) {
        num++;
        progresses.shift();
        speeds.shift();
      }
      if (num) {
        answer.push(num);
      }
    }
  }
  return answer;
}
