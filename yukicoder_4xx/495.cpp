#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int left = 0, right = 0;
	for (int i = 3; i < (int)s.length(); i += 5) {
		left += s[i] == '*';
		right += s[i] != '*';
	}
	cout << left << " " << right << endl;
	return 0;
}
