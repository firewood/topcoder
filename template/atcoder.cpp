#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>
{% if mod %}
#include <atcoder/modint>
{% endif %}

using namespace std;

{% if mod == 998244353 %}
using mint = atcoder::modint998244353;
const mint div2 = mint(2).inv();
{% elif mod == 1000000007 %}
using mint = atcoder::modint1000000007;
const mint div2 = mint(2).inv();
{% elif mod %}
using mint = atcoder::modint;
{% endif %}
typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;
{% if prediction_success %}

{% if yes_str %}
bool solve({{ formal_arguments }}) {
	bool ans = false;
{% elif mod %}
mint solve({{ formal_arguments }}) {
	mint ans = 0;
{% if mod == 998244353 %}
{% elif mod == 1000000007 %}
{% else %}
	modint::set_mod({{ mod }});
{% endif %}

{% else %}
//vector<int64_t> solve({{ formal_arguments }}) {
int64_t solve({{ formal_arguments }}) {
//	vector<int64_t> ans(N);
	int64_t ans = 0;
{% endif %}
{% if hw %}

	int sy = -1, sx = -1, ey = -1, ex = -1;
	for (int i = 0; i < H; i++) {
		if (sy < 0) {
			sx = (int)s[i].find('S');
			if (sx >= 0) sy = i;
		}
		if (ey < 0) {
			ex = (int)s[i].find('G');
			if (ex >= 0) ey = i;
		}
	}
{% endif %}



	return ans;
}
{% endif %}

int main() {
{% if prediction_success %}
	{{input_part}}
{% if yes_str %}
	cout << (solve({{ actual_arguments }}) ? "{{ yes_str }}" : "{{ no_str }}") << endl;
{% elif mod %}
	cout << solve({{ actual_arguments }}).val() << endl;
{% else %}
//	vector<int64_t> ans = solve({{ actual_arguments }});
	cout << solve({{ actual_arguments }}) << endl;
{% endif %}
{% else %}
	int64_t N, M, ans = 0;

	cin >> N >> M;

	std::vector<int64_t> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}



	cout << ans << endl;
{% endif %}
	return 0;
}
