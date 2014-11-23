#include <iostream>
#include <algorithm>


using namespace std;


/* this solution is the best solution. O(n) in time and constant in space.

   There is a solution that is O(n) in time and O(n) in space. easier to think of
 */
int trap(int A[], int n) {

		int cur = 0, total = 0, left = 0, right = n-1;
		while (left <= right)
		{
				int tempMin = min(A[left], A[right]);
				if (tempMin > cur)
				{
						total += (tempMin - cur) * (right - left + 1);
						cur = tempMin;
				}

				if (tempMin == A[left])
				{
						total -= A[left ++ ];
				}
				else 
				{
						total -= A[right --];
				}
		}

		return total;

}

int main()
{

		int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
		cout << trap(A, 12) << endl;
		return 0;
}
