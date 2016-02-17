#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	set<string> c;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		c.insert(s);
	}
	const string suite = "DCHS";
	const string number = "A23456789TJQK";
	string delim = "";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			string s = suite.substr(i, 1) + number.substr(j, 1);
			if (c.find(s) != c.end()) {
				cout << delim << s;
				delim = " ";
			}
		}
	}
	cout << endl;
	return 0;
}
