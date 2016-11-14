#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	string A, B, ans;
	cin >> A >> B;
	if (A.length() > B.length()) {
		swap(A, B);
	}
	if (B.length() < 8) {
		int a = atoi(A.c_str());
		int b = atoi(B.c_str());
		ans = a + b == a * b ? "E" : (a + b > a * b ? "S" : "P");
	} else if (A == "0" || A == "1") {
		ans = "S";
	} else {
		ans = "P";
	}
	cout << ans << endl;
	return 0;
}
