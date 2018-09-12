// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int l;
	cin >> l;
	int r;
	for (r = 0; (1 << r) <= l; ++r) {
		;
	}
	--r;
	vector<int> a, b, c;
	for (int i = 0; i < r; ++i) {
		a.push_back(i + 1);
		a.push_back(i + 1);
		b.push_back(i + 2);
		b.push_back(i + 2);
		c.push_back(0);
		c.push_back(1 << i);
	}
	for (int t = r; t >= 0; --t) {
		if ((l - (1 << t)) >= (1 << r)) {
			a.push_back(t + 1);
			b.push_back(r + 1);
			c.push_back(l - (1 << t));
			l -= 1 << t;
		}
	}
	cout << (r + 1) << " " << a.size() << endl;
	for (int i = 0; i < (int)a.size(); ++i) {
		cout << a[i] << " " << b[i] << " " << c[i] << endl;
	}
	return 0;
}
