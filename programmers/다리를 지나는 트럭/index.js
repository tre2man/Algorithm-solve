function solution(bridge_length, weight, truck_weights) {
  let answer = 0;
  const bridge = Array.from({ length: bridge_length }, () => 0);
  let bridge_sum = 0;

  // 1초 뒤 맨처음트럭 다리에있음
  answer++;
  bridge.shift();
  bridge_sum += truck_weights[0];
  bridge.push(truck_weights.shift());

  // 다리에 뭔가 있는동안
  while (bridge_sum > 0) {
    // 시간 1초 지나면
    answer++;
    // 큐의 맨 앞 꺼내기
    bridge_sum -= bridge.shift();
    // 트럭하나 더올라가도 무게를 버틸수있는지?
    if (truck_weights.length > 0 && bridge_sum + truck_weights[0] <= weight) {
      // 트럭 하나 올리기
      bridge_sum += truck_weights[0];
      bridge.push(truck_weights.shift());
    } else {
      // 무게 버틸수없으면 그냥 빈칸 넣기
      bridge.push(0);
    }
  }
  return answer;
}
