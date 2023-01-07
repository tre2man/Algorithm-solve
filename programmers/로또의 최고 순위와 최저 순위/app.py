def solution(lottos, win_nums):
    answer = []
    rank = [6, 6, 5, 4, 3, 2, 1]
    zero = lottos.count(0)
    correct = len(set(lottos) & set(win_nums))
    answer.append(rank[correct+zero])
    answer.append(rank[correct])
    return answer
