#include <iostream>
#include <sstream>
#include <assert.h>

using namespace std;

int count(string::const_iterator& cur, string::const_iterator end)
{
		int result = 0;
		if (cur == end)
				return result;

		char first = *cur;
		for (;cur != end; ++cur)
		{
				if (*cur != first)
						break;
				result ++;
		}

		return result;
}
string nextString(const string& cur)
{
		stringstream ss;
		string::const_iterator it = cur.begin(), end = cur.end();
		while( it != end)
		{
				char num = *it;
				int occur = count(it, end);
				ss << occur << num;
		}
		return ss.str();
}
string countAndSay(int n) {

	string result = "1";
	if (n == 1)
		return result;
	while (n > 1)
	{
		result = nextString(result);
		n --;
	}
	return result;
}


int main()
{

	assert(countAndSay(1) == "1");
	assert(countAndSay(2) == "11");
	assert(countAndSay(3) == "21");
	assert(countAndSay(4) == "1211");
	assert(countAndSay(5) == "111221");
	assert(countAndSay(6) == "312211");
return 0;
}

