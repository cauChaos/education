#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int arr[10001];

int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return -1;
	else if (*(int*)first < *(int*)second)
		return 1;
	else
		return 0;
}

int main()
{
	int n, max1, max2, maxA, maxB;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	max1 = arr[0] * arr[1] * arr[2];

	max2 = arr[0] * arr[1];

	if (max1 > max2) maxA = max1;
	else maxA = max2;

	max1 = arr[0] * arr[n - 2] * arr[n - 1];

	max2 = arr[n - 2] * arr[n - 1];

	if (max1 > max2) maxB = max1;
	else maxB = max2;

	if (maxA > maxB) printf("%d", maxA);
	else printf("%d", maxB);
}
