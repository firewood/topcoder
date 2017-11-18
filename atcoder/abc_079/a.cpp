// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string n;
	cin >> n;
	int prev = 0, cnt = 0;
	bool ans = false;
	for (char c : n) {
		if (prev == c) {
			if (++cnt >= 3) {
				ans = true;
			}
		} else {
			cnt = 1;
		}
		prev = c;
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
