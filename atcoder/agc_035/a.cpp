// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m[a[i]] += 1;
	}
	set<int> s(a.begin(), a.end());
	vector<int> v(n);
	for (int t = 0; t < 500; ++t) {
		int ar = rand() % n, br = rand() % n;
		if (ar == br) continue;
		int p = a[ar];
		int q = a[br];
		int x = p ^ q;
		if (s.find(x) != s.end()) {
			map<int, int> r = m;
			r[p] -= 1;
			r[q] -= 1;
			r[x] -= 1;
			if (r[x] >= 0) {
				v[0] = p;
				v[1] = q;
				v[2] = x;
				int i;
				for (i = 3; i < n; ++i) {
					x = v[i - 2] ^ v[i - 1];
					v[i] = x;
					r[x] -= 1;
					if (r[x] < 0) {
						break;
					}
				}
				if (i >= n && (v[0] == (v[1] ^ v[n - 1]))) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
