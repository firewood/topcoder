// L.
 
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
 
using namespace std;
 
typedef long long LL;
 
int s_to_i[256];
int v[20];
 
LL calc(const char *exp) {
	LL len = strlen(exp);
	LL tot = 0;
	LL prev = v[0];
	for (LL i = 2; i < len; i += 2) {
		if (exp[i - 1] == '+') {
			tot += prev;
			prev = v[s_to_i[exp[i]]];
		} else {
			prev *= v[s_to_i[exp[i]]];
		}
	}
	return tot + prev;
}
 
int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	memset(s_to_i, -1, sizeof(s_to_i));
	s_to_i['+'] = s_to_i['*'] = 0;
	LL cnt = 0;
	for (LL i = 0; i < s.length(); ++i) {
		char c = s[i];
		if (s_to_i[c] < 0) {
			s_to_i[c] = cnt++;
		}
	}
	LL ans = 0;
	if (cnt <= 20) {
		LL m = 1LL << 30;
		LL b = 1LL << cnt;
		for (LL i = 0; i < b; ++i) {
			for (LL j = 0; j < cnt; ++j) {
				v[j] = ((1LL << j) & i) ? 1 : -1;
			}
			LL a = calc(s.c_str());
			if (a < m) {
				m = a;
				ans = 0;
			}
			ans += a == m;
		}
	}
	cout << ans << endl;
	return 0;
}
