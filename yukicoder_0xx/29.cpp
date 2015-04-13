#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  getline(cin, s);
  int N = atoi(s.c_str());
  int cnt[16] = {};
  for (int i = 0; i < N; ++i) {
	  getline(cin, s);
	  stringstream ss(s);
	  int a, b, c;
	  ss >> a >> b >> c;
	  cnt[a] += 1;
	  cnt[b] += 1;
	  cnt[c] += 1;
  }
  int ans = 0;
  int c = 0;
  for (int i = 0; i < 16; ++i) {
	  ans += cnt[i] / 2;
	  c += cnt[i] % 2;
  }
  ans += c / 4;
  cout << ans << endl;
  return 0;
}
