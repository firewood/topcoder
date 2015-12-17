#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string S;
	int t, u;
	cin >> S >> t >> u;
	S.erase(S.begin() + t);
	if (u < t) {
		S.erase(S.begin() + u);
	} else if (u > t) {
		S.erase(S.begin() + u - 1);
	}
	cout << S << endl;
	return 0;
}
