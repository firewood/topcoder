#include <cassert>
#include <climits>
#include <iostream>
#ifdef _MSC_VER
#include <intrin.h>
#pragma intrinsic(_mul128)
#endif

using namespace std;

inline bool is_mul_overflow(long long a, long long b) {
#ifdef _MSC_VER
	long long high, low = _mul128(a, b, &high);
	return !((high == 0 && low >= 0) || (high == -1 && low < 0));
#else
	long long low;
	return __builtin_smulll_overflow(a, b, &low);
#endif
}

int main(int argc, char* argv[]) {
	assert(is_mul_overflow(1, 1) == false);
	assert(is_mul_overflow(1, -1) == false);
	assert(is_mul_overflow(-1, -1) == false);
	assert(is_mul_overflow(-1, 1) == false);

	assert(is_mul_overflow(LLONG_MAX, 1) == false);
	assert(is_mul_overflow(LLONG_MAX / 2 + 1, 2) == true);		// LLONG_MAX + 1

	assert(is_mul_overflow(LLONG_MIN, 1) == false);
	assert(is_mul_overflow(LLONG_MIN, 2) == true);		// 0xFFFFFFFF00000000

	return 0;
}
