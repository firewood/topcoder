// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s;
	cin >> s;
	string ans;
	if (s == "Sunny") {
		ans = "Cloudy";
	}
	if (s == "Cloudy") {
		ans = "Rainy";
	}
	if (s == "Rainy") {
		ans = "Sunny";
	}
	cout << ans << endl;
	return 0;
}
