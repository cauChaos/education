# code by wapas
S = input()
for e in S:
    if e not in "IOSHZXN":  # 문자가 I, O, S, H, Z, X, N 중 하나가 아니면
        print("NO")  # NO를 출력하고 프로그램 종료
        exit(0)
print("YES")  # NO를 출력한적 없다면 YES를 출력
