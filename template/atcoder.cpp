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

using namespace std;

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;
{% if mod %}
static const int64_t MOD = {{ mod }};
static const size_t TABLE_SIZE = 1000000;		// 1e6

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
	static modint permutation(int n, int r);
	static modint combination(int n, int r);
	static modint nHr(int n, int r);
};

static vector<modint> fact(TABLE_SIZE + 1, 0), inv(TABLE_SIZE + 1, 0);

static __inline void build_fact_table() {
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= TABLE_SIZE; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[TABLE_SIZE] = modint::modinv(fact[TABLE_SIZE]);
		for (int i = TABLE_SIZE; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
}

modint modint::permutation(int n, int r) {
	if (r > n) return 0;
	build_fact_table();
	return fact[n] * inv[n - r];
}

modint modint::combination(int n, int r) {
	if (r > n) return 0;
	build_fact_table();
	return (fact[n] * inv[r]) * inv[n - r];
}

modint modint::nHr(int n, int r) {
	return combination(n + r - 1, r);
}
{% endif %}
{% if prediction_success %}

{% if yes_str %}
bool solve({{ formal_arguments }}) {
	bool ans = false;
{% else %}
int64_t solve({{ formal_arguments }}) {
	{% if mod %}
	modint ans = 0;
	{% else %}
	int64_t ans = 0;
	{% endif %}
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
{% else %}
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
