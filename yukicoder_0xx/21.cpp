#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  getline(cin, s);
  int N = atoi(s.c_str());
  getline(cin, s);
  int K = atoi(s.c_str());
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    getline(cin, s);
    A[i] = atoi(s.c_str());
  }
  sort(A.begin(), A.end());
  int ans = A.back() - A.front();
  cout << ans << endl;
  return 0;
}
