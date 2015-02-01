#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int N, K;
	string s;
	getline(cin, s);
	int a, b, c;
	sscanf(s.c_str(), "%d.%d.%d", &a, &b, &c);
	getline(cin, s);
	int d, e, f;
	sscanf(s.c_str(), "%d.%d.%d", &d, &e, &f);
	bool old = d < a || d == a && (e < b || e == b && f <= c);
	string ans = old ? "YES" : "NO";
	cout << ans << endl;
	return 0;
}
