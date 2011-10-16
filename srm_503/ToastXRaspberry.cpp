// BEGIN CUT HERE 
/*
// SRM 503 Div2 Easy (250)

問題
  トーストに何種類かのジャムを塗る
  1回塗るごとに 1～upper_limit 層塗ることができる
  layer_count 塗るのに何回必要か

制約条件
  upper_limit 1-100
  layer_count 1-1000

*/
// END CUT HERE
#line 46 "ToastXRaspberry.cpp"
#include <string>
#include <vector>

using namespace std;

class ToastXRaspberry {
	public:
	int apply(int upper_limit, int layer_count) {
		return (layer_count + upper_limit - 1) / upper_limit;
	}
};

// BEGIN CUT HERE 
static void Test(int u, int l, int expected)
{
	ToastXRaspberry ___test;
	int result = ___test.apply(u, l);
	printf("result: %s, returned %d, expected %d\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test(4, 13, 4);

	// example 1
	Test(8, 5, 1);

	// example 2
	Test(73, 265, 4);

	return 0;
}
// END CUT HERE
