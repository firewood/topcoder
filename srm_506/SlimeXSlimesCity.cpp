// BEGIN CUT HERE
/*
// SRM 506 Div2 Medium (500)

問題

任意の二つの町を取り出して合併させる。
町の名前は人口の多いほうのものになる。
最終的に町の名前として残るのは何通りか答える。


*/
#line 86 "SlimeXSlimesCity.cpp"
// END CUT HERE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long __ll;

class SlimeXSlimesCity {
	public:
	int merge(vector <int> population) {
		sort(population.begin(), population.end());
		int result = population.size();

		int max_index = (int)population.size() - 1;
		int i;
		for (i = 1; i <= max_index; ++i) {
			__ll sum = 0;

			int j;
			for (j = 0; j < i; ++j) {
				sum += population[j];
			}
			if (sum < (__ll)population[i]) {
				result = population.size() - i;
			}
		}

		return result;
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *seq, int expected)
{
	vector <int> v = getVector<int>(seq);
	SlimeXSlimesCity ___test;
	int result = ___test.merge(v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("2,3,4", 2);

	// example 1
	Test("1,2,3", 2);

	// example 2
	Test("8,2,3,8", 2);

	// example 3
	Test("1000000000,999999999,999999998,999999997", 3);

	// example 4
	Test("1,1,1", 3);

	// example 5
	Test("1,2,4,6,14,16,20", 3);


	Test("1,2", 1);
	Test("1,1", 2);


	return 0;
}
// END CUT HERE
