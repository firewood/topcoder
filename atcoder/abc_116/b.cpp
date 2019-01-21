// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int s, ans;
	cin >> s;
	vector<int> f(1000001);
	for (int i = 2; ; ++i) {
		if (s < f.size()) {
			f[s] = 1;
		}
		int next = s % 2 ? s * 3 + 1 : s / 2;
		if (f[next]) {
			ans = i;
			break;
		}
		s = next;
	}
	cout << ans << endl;
	return 0;
}
