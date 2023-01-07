
from queue import Queue


def solution(begin, target, words):
    visited = [0 for i in range(len(words))]
    q = Queue()
    alphabet = "qwertyuiopasdfghjklzxcvbnm"

    q.put({"depth": -1, "idx": -1})
    while not q.empty():
        now = q.get()
        depth = now["depth"]
        idx = now["idx"]
        if idx != -1 and words[idx] == target:
            return depth
        if depth == -1:
            depth = 0
        # 전체 단어 순회
        for alpha in alphabet:
            # 단어 하나씩 바꾸기
            searchWord = ""
            if idx == -1:
                searchWord = begin
            else:
                searchWord = words[idx]
            for wordIdx, _ in enumerate(searchWord):
                newWordList = list(searchWord)
                newWordList[wordIdx] = alpha
                newWord = "".join(newWordList)
                if newWord in words:
                    newIdx = words.index(newWord)
                    if not visited[newIdx]:
                        q.put({"depth": depth + 1, "idx": newIdx})
                        visited[newIdx] = depth + 1
    return 0
