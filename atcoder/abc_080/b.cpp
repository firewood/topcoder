// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int len = s.length();
	int sum = 0;
	for (char c : s) {
		sum += c - '0';
	}
	bool ans = stoi(s) % sum == 0;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
