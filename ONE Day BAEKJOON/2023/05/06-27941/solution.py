# code by wapas
import sys


def input():
    return sys.stdin.readline().rstrip()


ans = [0] * 11  # 꼭짓점은 같은 좌표가 두 번 나타납니다
for _ in range(2047):
    arr = list(map(int, input().split()))
    for i in range(11):
        ans[i] ^= arr[i]  # 따라서 꼭짓점을 모두 Xor를 하면 단 한 번만 나타난 좌표들만 남습니다
print(*ans)  # 그것이 남은 꼭짓점의 좌표 입니다
