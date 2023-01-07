function climbingLeaderboard(ranked, player) {
  const result = [];
  // 중복 제거 후 내림차순 정렬
  const rank = [...new Set(ranked)].sort((a, b) => b - a);

  player.forEach((score) => {
    // 현재 점수가 랭크보다 높으면 랭크에서 제거
    while (rank.length > 0 && score >= rank[rank.length - 1]) {
      rank.pop();
    }
    result.push(rank.length + 1);
  });

  return result;
}
