#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int ans = 0;
	char prev = 0;
	for (char c : s) {
		switch (c) {
		case 'i':
			if (prev != 'm') {
				c = 0;
			}
			break;
		case '-':
			if (prev != 'i' && prev != '-') {
				c = 0;
			}
			break;
		case 'n':
			if (prev == 'i' || prev == '-') {
				++ans;
			}
			break;
		}
		prev = c;
	}
	cout << ans << endl;
	return 0;
}
