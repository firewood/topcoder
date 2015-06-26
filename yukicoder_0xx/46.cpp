#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	int A, B;
	ss >> A >> B;
	int ans = (B + A - 1) / A;
	cout << ans << endl;
	return 0;
}
