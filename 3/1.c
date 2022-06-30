/* Exercise 3-1 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
	/* even, left-out, false */
	int arr1[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(-1, arr1, 8));
	/* even, right-out, false */
	int arr2[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(13, arr2, 8));
	/* even, left, false */
	int arr3[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(3, arr3, 8));
	/* even, left, true */
	int arr4[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(2, arr4, 8));
	/* even, right, false */
	int arr5[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(8, arr5, 8));
	/* even, right, true */
	int arr6[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(10, arr6, 8));
	/* even, mid-left, true */
	int arr7[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(6, arr7, 8));
	/* even, mid-right, true */
	int arr8[] = {0, 2, 4, 6, 7, 9, 10, 11};
	printf("%d\n", binsearch(7, arr8, 8));
	/* odd, left-out, false */
	int arr9[] = {0, 2, 4, 6, 7, 9, 10, 11, 14};
	printf("%d\n", binsearch(-1, arr9, 9));
	/* odd, right-out, false */
	int arr10[] = {0, 2, 4, 6, 7, 9, 10, 11, 14};
	printf("%d\n", binsearch(15, arr10, 9));
	/* odd, left, false */
	int arr11[] = {0, 2, 4, 6, 7, 9, 10, 11, 14};
	printf("%d\n", binsearch(3, arr11, 9));
	/* odd, left, true */
	int arr12[] = {0, 2, 4, 6, 7, 9, 10, 11, 14};
	printf("%d\n", binsearch(4, arr12, 9));
	/* odd, right, false */
	int arr13[] = {0, 2, 4, 6, 7, 9, 10, 11, 14};
	printf("%d\n", binsearch(12, arr13, 9));
	/* odd, right, true */
	int arr14[] = {0, 2, 4, 6, 7, 9, 10, 11, 14};
	printf("%d\n", binsearch(10, arr14, 9));
	/* odd, mid, true */
	int arr15[] = {0, 2, 4, 6, 7, 9, 10, 11, 14};
	printf("%d\n", binsearch(7, arr15, 9));
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low < high) {
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}
	if (v[low] == x)
		return low;
	else
		return -1;

}
