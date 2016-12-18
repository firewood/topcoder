// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	set<string> x;
	x.insert(s);
	for (int i = 0; i != s.length(); ++i) {
		string a = s.substr(1) + s[0];
		x.insert(s);
		s = a;
	}
	cout << x.size() << endl;
	return 0;
}
