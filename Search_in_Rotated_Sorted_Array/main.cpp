#include <iostream>

using namespace std;


int searchHelper(int A[], int start, int end, int target)
{
	if (start > end)
		return -1;
	int mid = (start + end)/2;
	if (A[mid] == target)
		return mid;
	
	if (A[mid] < A[end])
	{
		if (target > A[mid] && A[end] >= target)
			return searchHelper(A, mid + 1, end, target);
		else
			return searchHelper(A, start, mid -1 , target);
	}
	else {
		if (target >= A[start] && target < A[mid])
			return searchHelper(A, start, mid - 1, target);
		else
			return searchHelper(A, mid + 1, end, target);
	}
}
int search(int A[], int n, int target) {
	
	return searchHelper(A, 0, n -1 , target);
}

int main()
{
	int A[] = {1};
	cout << search(A, 0, 0) << endl;
	return 0;
}
