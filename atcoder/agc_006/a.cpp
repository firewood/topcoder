// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	string s, t, ans;
	cin >> N >> s >> t;
	for (int i = 0; i <= N; ++i) {
		ans = s.substr(0, i) + t;
		if (ans.substr(0, N) == s) {
			break;
		}
	}
	cout << ans.length() << endl;
	return 0;
}
