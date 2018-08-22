// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  long long k;
  cin >> s;
  cin >> k;
  char c;
  for (int i = 0; i != s.length(); ++i) {
    c = s[i];
    if (c == '1') {
      --k;
      if (k <= 0) {
        break;
      }
    } else {
      break;
    }
  }
	cout << c << endl;
	return 0;
}
