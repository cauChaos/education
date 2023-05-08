# code by wapas
N = int(input())
arr = input().split()
M, K = map(int, input().split())

narr = []
def f(x): return arr[int(x) - 1]


for _ in range(M):
    egg_plants = map(f, input().split())
    if "P" in egg_plants:
        narr.append("P")  # P가 하나라도 있으면 그 조수는 P 품종을 만든다.
    else:
        narr.append("W")

if "W" in narr:
    print("W")  # W가 하나라도 있으면 키위는 W 품종을 만든다
else:
    print("P")
