#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int a = atoi(s.c_str());
	int b;
	const char *p = s.c_str();
	while (!isdigit(*p)) {
		++p;
	}
	while (isdigit(*p)) {
		++p;
	}
	if (isdigit(p[1]) || p[1] == '+') {
		b = atoi(p + 1);
	} else {
		b = -atoi(p + 2);
	}
	int ans = *p == '+' ? (a - b) : (a + b);
	cout << ans << endl;
	return 0;
}
