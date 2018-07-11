//
// Facebook Hacker Cup 2018 Qualification Round
// A. Tourist
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		LL n, k, v;
		cin >> n >> k >> v;
		vector<string> names(n);
		for (LL i = 0; i < n; ++i) {
			cin >> names[i];
		}
		LL st = ((v - 1) * k) % n;
		vector<LL> seq;
		for (LL i = 0; i < k; ++i) {
			seq.push_back((st + i) % n);
		}
		sort(seq.begin(), seq.end());
		cout << "Case #" << t << ":";
		for (LL i = 0; i < k; ++i) {
			cout << " " << names[seq[i]];
		}
		cout << endl;
	}
	return 0;
}
