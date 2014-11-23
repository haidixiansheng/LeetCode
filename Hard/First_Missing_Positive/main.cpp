#include <iostream>
#include <algorithm>
using namespace std;


int firstMissingPositive(int A[], int n) {
	for (int i =0; i < n; ++i)
	{
		if (A[i] != i + 1)
		{
			if (A[i] > 0 && A[i] <= n)
			{
				swap(A[i],A[A[i] - 1 ]);
				i--;
			}
		}
	}

//int cur = 1;
	for (int i = 0 ; i < n; ++i)
	{
		if (A[i] != i + 1)
			return i + 1;
	}

	return n + 1;
}


int main()
{
	int A[] = { 3, 4, -1 ,1 };
	
	cout << firstMissingPositive(A, 4) << endl;
	
	return 0;
}
