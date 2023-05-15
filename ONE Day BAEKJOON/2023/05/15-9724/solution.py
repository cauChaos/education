# code by wapas
import sys

def input():
    return sys.stdin.readline().rstrip()

def solution(T):
    A, B = map(int, input().split())
    ans = 0
    n = 1
    while n ** 3 <= B:  # n의 세제곱이 B보다 커질 때 까지 반복
        if A <= n ** 3:  # n의 세제곱이 A보다 크면 ans += 1
            ans += 1
        n += 1  # 반복을 거듭할 수록 n += 1
    print(f"Case #{T}: {ans}")

for T in range(1, int(input()) + 1):
    solution(T)
