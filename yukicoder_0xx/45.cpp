#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	int m[1008] = {};
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int n;
		ss >> n;
		int a = max(m[i - 2 + 4] + n, m[i - 3 + 4] + n);
		m[i + 4] = a;
		ans = max(ans, a);
	}
	cout << ans << endl;
	return 0;
}
