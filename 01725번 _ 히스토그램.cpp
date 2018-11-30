#include <stdio.h>
#define MAX_N 100000

long long stack[MAX_N + 1];
int t;

void push(long long data) { stack[t++] = data; }
void pop(void) { t--; }
int empty(void) { return (t == 0); }
long long top(void) { return stack[t - 1]; }


long long h[MAX_N + 1];

int main(void)
{
    int n;
    long long i, j, w;
    long long ans = 0;
    scanf("%d", &n);
    for(i = 0;i < n;i++) scanf("%lld", &h[i]);
    
    h[n] = 0;
    t = 0;
    
    for(i = 0;i < n + 1;++i)
    {
        while(!empty() && h[top()] >= h[i])
        {
            j = top();
            pop();
            w = -1;
            if(empty()) w = i;
            else w = (i - top() - 1);
            if(ans < h[j] * w)
                ans = h[j] * w;
        }
        push(i);
    }
    printf("%lld\n", ans);
    return 0;
}
