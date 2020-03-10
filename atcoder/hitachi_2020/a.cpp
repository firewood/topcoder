// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int main(int argc, char* argv[]) {
		string s;
		cin >> s;
		int len = (int)s.length();
		bool ans = len % 2 == 0;
		if (ans) {
			for (int i = 0; i < len; i += 2) {
				if (s[i] == 'h' && s[i + 1] == 'i') {

				} else {
					ans = false;
				}
			}
		}
		cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
