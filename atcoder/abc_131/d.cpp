// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<II> v;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end());
	int t = 0;
	bool ans = true;
	for (int i = 0; i < n; ++i) {
		t += v[i].second;
		if (t > v[i].first) {
			ans = false;
			break;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
