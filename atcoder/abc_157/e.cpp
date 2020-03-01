// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, q, t, l, r;
		cin >> n;
		if (n < 0) return 0;
		string s;
		cin >> s;
		cin >> q;
		BIT bits[26];
		for (int i = 0; i < 26; ++i) {
			bits[i].init(n + 2);
		}
		for (int i = 0; i < n; ++i) {
			int c = s[i] - 'a';
			bits[c].add(i + 1, 1);
		}
		for (int i = 0; i < q; ++i) {
			cin >> t >> l;
			char c;
			if (t == 1) {
				cin >> c;
				bits[s[l - 1] - 'a'].add(l, -1);
				s[l - 1] = c;
				bits[s[l - 1] - 'a'].add(l, 1);
			} else {
				cin >> r;
				int cnt = 0;
				for (int x = 0; x < 26; ++x) {
					cnt += (bits[x].sum(r) - bits[x].sum(l - 1)) > 0;
				}
				cout << cnt << endl;
			}
		}
	}
	return 0;
}
