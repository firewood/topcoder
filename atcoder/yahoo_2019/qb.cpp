// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int cnt[4] = {};
	for (int i = 0; i < 3; ++i) {
		int a, b;
		cin >> a >> b;
		cnt[a - 1]++;
		cnt[b - 1]++;
	}
	bool ans = cnt[0] <= 2 && cnt[1] <= 2 && cnt[2] <= 2 && cnt[3] <= 2;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
