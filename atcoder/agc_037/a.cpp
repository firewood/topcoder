// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s, prev, curr;
	cin >> s;
	int ans = 0;
	for (char c : s) {
		curr += c;
		if (curr != prev) {
			++ans;
			prev = curr;
			curr = "";
		}
	}
	cout << ans << endl;
	return 0;
}
