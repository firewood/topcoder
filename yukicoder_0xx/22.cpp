#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  getline(cin, s);
  int N, K;
  stringstream ss(s);
  ss >> N >> K;
  getline(cin, s);
  --K;
  int c = 1;
  int i;
  if (s[K] == '(') {
	  for (i = K + 1; i < N; ++i) {
		  if (s[i] == ')') {
			  if (--c == 0) {
				  break;
			  }
		  } else {
			  ++c;
		  }
	  }
  } else {
	  for (i = K - 1; i >= 0; --i) {
		  if (s[i] == '(') {
			  if (--c == 0) {
				  break;
			  }
		  } else {
			  ++c;
		  }
	  }
  }
  cout << (i + 1) << endl;
  return 0;
}
