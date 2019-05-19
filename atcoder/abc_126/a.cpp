// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <locale>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s[k - 1] = tolower(s[k - 1]);
	cout << s << endl;
	return 0;
}
