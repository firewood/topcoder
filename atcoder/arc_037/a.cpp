// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int m;
		ss >> m;
		ans += max(0, 80 - m);
	}
	cout << ans << endl;
	return 0;
}
