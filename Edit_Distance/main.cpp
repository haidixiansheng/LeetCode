#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


int min (int a, int b)
{
	return (a < b) ? a : b;
}
// Dynamic Programming:
int minDistance(string word1, string word2) {
	int len1 = word1.size();
	int len2 = word2.size();

	vector<vector<int> >matrix(len1 + 1, vector<int>(len2 + 1, 1));
	for (int i = 0; i <= len1; i ++)
	{
		matrix[i][0] = i;
	}
	for (int i = 0; i <= len2; i++)
	{
		matrix[0][i] = i;
	}

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1 ; j <= len2; ++j)
		{
			if (word1[i-1] == word2[j-1])
			{
				matrix[i][j] = matrix[i-1][j-1];
			}
			else
				matrix[i][j] = min(matrix[i-1][j-1], min (matrix[i-1][j], matrix[i][j-1])) + 1;
		}
	}

	return matrix[len1][len2];
}


int main ()
{
	assert(minDistance("","") == 0);
	assert(minDistance("word","wd") == 2);
	assert(minDistance("word","ship") == 4);
	assert(minDistance("word","shid") == 3);
	return 0;
}
