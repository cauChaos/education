#include <stdio.h>

int A,B,V;

int ok(int x)
{
	if(x*A-(x-1)*B >= V) return 1;
	else return 0; 
}

int main()
{
	scanf("%d %d %d", &A, &B, &V);	 
	
  int l = 1, r = V;
	
  while (l <= r)
  {
		int mid = (l+r)/2; 
		if (ok(mid)) r = mid-1; 
		else l = mid+1;
	}
	
  printf("%d", l);
	
  return 0; 
}
