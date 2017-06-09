#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  cin >> s;
  int h, m;
  sscanf(s.c_str(), "%d:%d", &h, &m);
  m += 5;
  h += m / 60;
  m %= 60;
  h %= 24;
  printf("%02d:%02d\n", h, m);
	return 0;
}
