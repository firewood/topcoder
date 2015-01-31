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
	long long N = atoi(s.c_str());
	long long ans = 0;
	for (long long i = 1; i <= N; ++i) {
		ans += (N - i) + 1;
	}
	cout << ans << endl;
	return 0;
}
