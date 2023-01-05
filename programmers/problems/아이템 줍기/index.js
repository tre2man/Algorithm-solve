/**
 * 상하좌우 모두 갈 수는 없는 길이므로 모든 길이의 2배로 계산한다.
 * @param {number[][]} rectangle
 * @param {number} characterX
 * @param {number} characterY
 * @param {number} itemX
 * @param {number} itemY
 * @returns {number}
 */
function solution(rectangle, characterX, characterY, itemX, itemY) {
  // 모든 환경을 이미 2배씩 해둠
  rectangle = rectangle.map((r) => r.map((t) => t * 2));
  characterX *= 2;
  characterY *= 2;
  itemX *= 2;
  itemY *= 2;

  const mapLen = Math.max(
    ...rectangle.flat(),
    characterX,
    characterY,
    itemX,
    itemY
  );
  const map = Array.from({ length: mapLen + 1 }, () =>
    Array.from({ length: mapLen + 1 }).fill(0)
  );
  const visit = Array.from({ length: mapLen + 1 }, () =>
    Array.from({ length: mapLen + 1 }).fill(0)
  );

  // map 채우기
  rectangle.forEach(([lx, ly, rx, ry]) => {
    for (let i = lx; i <= rx; i++) {
      for (let j = ly; j <= ry; j++) {
        map[i][j] = 1;
      }
    }
  });
  // 안쪽 비우기
  rectangle.forEach(([lx, ly, rx, ry]) => {
    for (let i = lx + 1; i < rx; i++) {
      for (let j = ly + 1; j < ry; j++) {
        map[i][j] = 0;
      }
    }
  });

  const q = [];
  const dx = [1, -1, 0, 0];
  const dy = [0, 0, 1, -1];
  q.push({ x: characterX, y: characterY, len: 0 });
  visit[characterX][characterY] = 1;
  while (q.length > 0) {
    const { x, y, len } = q.shift();
    // 답 찾았을 경우
    if (x === itemX && y === itemY) {
      return len / 2;
    }
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (nx > 0 && nx <= mapLen && ny > 0 && ny <= mapLen) {
        if (!visit[nx][ny] && map[nx][ny]) {
          q.push({ x: nx, y: ny, len: len + 1 });
          visit[nx][ny] = 1;
        }
      }
    }
  }
  return 0;
}
