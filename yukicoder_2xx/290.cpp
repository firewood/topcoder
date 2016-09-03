#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	string s;
	cin >> N >> s;
	string ans = "YES";
	if (N <= 3 && s.find("00") == string::npos && s.find("11") == string::npos) {
		ans = "NO";
	}
	cout << ans << endl;
	return 0;
}
