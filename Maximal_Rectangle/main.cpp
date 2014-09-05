#include <vector>
#include <iostream>
using namespace std;


int max(vector<bool>& check)
{
		int max = 0;
		int current = 0;
		for (unsigned int i = 0, len = check.size(); i < len; ++i ) 
		{   
				if(!check[i]){
						max = current > max ? current : max;
						current = 0;
				}
				else
						current ++;
		}
			max = current > max ? current : max;


		return max;
}
int maximalRectangle(vector<vector<char> > &matrix) {
		if(matrix.size() == 0 )
				return 0;
		int row = matrix.size(), col = matrix[0].size();
		vector<bool> rowCheck(row, true);
		vector<bool> colCheck(col, true);
		for (unsigned int i = 0; i < row; ++i)
		{
				for (unsigned int j = 0; j < col; ++j)
				{
						if(matrix[i][j] == '0'){
								rowCheck[i] = false;
								colCheck[j] = false;
						}
				}
		}

		return max(rowCheck) * max(colCheck);
}

int main() {

	vector<vector<char> > input(1, vector<char>(1,'1'));
	cout << maximalRectangle(input) <<endl;
return 0;
}
