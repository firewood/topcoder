#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	string s;
	string ans;
	cin >> s;
	if (s.find("ooo") != string::npos) {
		ans = "o";
	} else if (s.find("xxx") != string::npos) {
		ans = "x";
	} else {
		ans = "draw";
	}
	cout << ans << endl;
	return 0;
}
