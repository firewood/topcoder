// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	string s = "ATCG";
	string b;
	cin >> b;
	for (int i = 0; i < 4; ++i) {
		if (s[i] == b[0]) {
			cout << s[i ^ 1] << endl;
		}
	}
	return 0;
}
