#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int cnt[] = {3,1,1,1,3,1,3,1,5,3};
	int cnt2[] = {3,2,2,2,3,2,3,2,4,3};
	string s;
	cin >> s;
	int ans = 2;
	int ans2 = 1;
	for (char c : s) {
		ans += cnt[c - '0'];
		ans2 += cnt2[c - '0'];
	}
	cout << min(ans, ans2) << endl;
	return 0;
}
