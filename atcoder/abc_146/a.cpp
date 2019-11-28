// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string w[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i <= 7; ++i) {
		if (w[i] == s) {
			ans = 7 - i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
