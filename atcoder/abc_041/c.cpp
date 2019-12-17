// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n <= 0) return 0;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first;
			v[i].second = i + 1;
		}
		sort(v.rbegin(), v.rend());
		for (int i = 0; i < n; ++i) {
			cout << v[i].second << endl;
		}
	}
	return 0;
}
