# code by wapas
from math import ceil
import sys


def input():
    return sys.stdin.readline().rstrip()


n, s = map(int, input().split())
max_time = max(map(int, input().split()))  # 가장 오래걸리는 시간 (ms)
print(ceil(max_time * s / 1000))  # s배하여 초 단위로 변환
