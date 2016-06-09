#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int a = (int)s.find("OOO");
  int b = (int)s.find("XXX");
  if (a >= 0 && (b < 0 || b > a)) {
    cout << "East" << endl;
  } else if (b >= 0) {
    cout << "West" << endl;
  } else {
    cout << "NA" << endl;
  }
	return 0;
}
