#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  getline(cin, s);
  int N = atoi(s.c_str());
  getline(cin, s);
  int M = atoi(s.c_str());
  for (int i = 0; i < M; ++i) {
    getline(cin, s);
	stringstream ss(s);
	int P, Q;
	ss >> P >> Q;
	if (P == N) {
		N = Q;
	} else if (Q == N) {
		N = P;
	}
  }
  cout << N << endl;
  return 0;
}
