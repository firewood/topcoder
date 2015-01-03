// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	int N;
	ss >> N;
	string ans = N == 2 ? "WANWAN" : "BOWWOW";
	cout << ans << endl;
	return 0;
}
