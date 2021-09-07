#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	string x, y;
	set<string> s;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		s.insert(x + " " + y);
	}
	bool ans = s.size() < N;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
