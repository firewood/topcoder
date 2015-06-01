#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	int cnt[100001] = {};
	int m = 0, n = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		ss >> a;
		cnt[a] += 1;
		if (cnt[a] > m) {
			m = cnt[a];
			n = a;
		} else if (cnt[a] == m) {
			n = max(a, n);
		}
	}
	cout << n << endl;
	return 0;
}
