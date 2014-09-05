#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


void reverseString(string::iterator st, string::iterator end) {
		while(st < end) {
				swap(*st, *end);
				st ++;
				end --;
		}

		//	cout << "OK" <<endl;
}
void reverseWords(string &s) {
		if (s.length() <= 0)
				return;
		reverseString(s.begin(), s.begin()+s.length()-1);

		string result = "";
		int startIndex = 0, length = s.length();

		for ( int i = 0, len = s.length();
						i< len; ++i) {
				if(s[i] == ' ' || i == len-1)
				{
					if(startIndex == i && s[i] == ' ')
						startIndex ++;
					else {
						string temp = s.substr(startIndex, ((s[i]==' ') ? i : i+1) - startIndex);
						reverseString(temp.begin(), temp.begin() + temp.length()-1);
						result.append(temp);
						result.push_back(' ');
						startIndex = i +1;
						}
				}
		}
		s = result.substr(0,result.length()-1);

}


int main()
{
		string s= "a";
		reverseWords(s);

		cout <<s << "."<<endl;

		return 0;
}
