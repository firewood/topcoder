// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s, h;
  cin >> s >> h;
  cout << ((s[0] == 'S' && h[0] == 'H') ? "YES" : "NO") << endl;
	return 0;
}
