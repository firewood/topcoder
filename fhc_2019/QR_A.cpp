//
// Facebook Hacker Cup 2019 Qualification Round
// A. Leapfrog: Ch. 1
//

#include <iostream>
#include <sstream>

using namespace std;

bool solve(string s) {
	int betas = count(s.begin(), s.end(), 'B');
	int empties = count(s.begin(), s.end(), '.');
	return empties > 0 && betas >= empties;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		cin >> s;
		bool ans = solve(s);
		cout << "Case #" << t << ": " << (ans ? "Y" : "N") << endl;
	}
	return 0;
}
