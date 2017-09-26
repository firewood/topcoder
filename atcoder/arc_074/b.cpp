// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int h, w;
	cin >> h >> w;
	cout << string(w + 2, '#') << endl;
	for (int i = 0; i < h; ++i) {
		string s;
		cin >> s;
		cout << "#" << s << "#" << endl;
	}
	cout << string(w + 2, '#') << endl;
	return 0;
}
