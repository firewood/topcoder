// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	string ans = s == "ahooy" ? "YES" : "NO";
	cout << ans << endl;
	return 0;
}
