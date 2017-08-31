#include <iostream>
#include <sstream>
#include <set>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	long long n, r, i, d;
	set<string> m;
	cin >> n;
	r = sqrt(n);
	for (i = 1; i <= r; ++i) {
		d = n / i;
		if (i * d == n) {
			char w[64];
			sprintf(w, "%lld%lld", i, d);
			m.insert(w);
			sprintf(w, "%lld%lld", d, i);
			m.insert(w);
		}
	}
	cout << m.size() << endl;
	return 0;
}
