// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

template<typename F> class [[nodiscard]] FixPoint : private F {
public:
	explicit constexpr FixPoint(F && f) noexcept : F(std::forward<F>(f)) {}

	template<typename... Args> constexpr decltype(auto)
	operator()(Args &&... args) const noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...))) {
		return F::operator()(*this, std::forward<Args>(args)...);
	}
};

template<typename F> static inline constexpr decltype(auto)
makeFixPoint(F&& f) noexcept {
	return FixPoint<F>{ std::forward<F>(f) };
}

int main() {
	int n, m, q, a, b, c, d;
	vector<tuple<int, int, int, int>> v;

	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i) {
		cin >> a >> b >> c >> d;
		v.emplace_back(a, b, c, d);
	}

	auto push_back = [](vector<int> seq, int next) {
		vector<int> v = seq;
		seq.emplace_back(next);
		return seq;
	};
	auto ans = makeFixPoint([&](auto dfs, vector<int> seq) -> int {
		int r = 0;
		if ((int)seq.size() <= n) {
			for (int d = seq.back(); d <= m; ++d) {
				r = max(r, dfs(push_back(seq, d)));
			}
		} else {
			for (int i = 0; i < q; ++i) {
				if (seq[get<1>(v[i])] - seq[get<0>(v[i])] == get<2>(v[i])) {
					r += get<3>(v[i]);
				}
			}
		}
		return r;
	})(push_back({}, 1));
	cout << ans << endl;
	return 0;
}
