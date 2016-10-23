#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s) {
		if (c == 'C' && cnt == 0) {
			cnt = 1;
		}
		if (c == 'F' && cnt == 1) {
			cnt = 2;
		}
	}
	cout << (cnt == 2 ? "Yes" : "No") << endl;
	return 0;
}
