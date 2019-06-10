// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<pair<string, pair<int, int>>> v;
	for (int i = 0; i < n; ++i) {
		string s;
		int p;
		cin >> s >> p;
		v.push_back(make_pair(s, make_pair(-p, i + 1)));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		cout << v[i].second.second << endl;
	}
	return 0;
}
