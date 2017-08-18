// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

//typedef pair<int, int> II;
//typedef set<II> IISet;

int main(int argc, char *argv[])
{
	bool ans = false;
	int n, m;
	cin >> n >> m;
//	IISet s;
	set<int> s[200001];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
	}
	for (int a : s[1]) {
		if (s[a].find(n) != s[a].end()) {
			ans = true;
			break;
		}
	}
	cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	return 0;
}
