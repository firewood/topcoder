// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	bool three = true;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "Y") {
			three = false;
		}
	}
	cout << (three ? "Three" : "Four") << endl;
	return 0;
}
