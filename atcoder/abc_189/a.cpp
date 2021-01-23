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
	cin >> s;
	sort(s.begin(), s.end());
	if (s.front() == s.back()) {
		cout << "Won" << endl;
	} else {
		cout << "Lost" << endl;
	}
	return 0;
}
