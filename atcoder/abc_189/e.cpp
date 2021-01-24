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

typedef long long LL;

template <size_t Size>
struct Matrix {
	LL e[Size][Size];

	Matrix() {
		memset(e, 0, sizeof(e));
	}

	void setIdentity() {
		for (LL i = 0; i < Size; ++i) {
			e[i][i] = 1;
		}
	}

	Matrix mul(const Matrix& a) {
		Matrix r;
		for (LL i = 0; i < Size; ++i) {
			for (LL j = 0; j < Size; ++j) {
				for (LL k = 0; k < Size; ++k) {
					r.e[i][j] += e[i][k] * a.e[k][j];
				}
			}
		}
		return r;
	}

	Matrix pow(LL x) {
		Matrix r, b = *this;
		r.setIdentity();
		for (; x > 0; x >>= 1) {
			if (x & 1) {
				r = r.mul(b);
			}
			b = b.mul(b);
		}
		return r;
	}
};

int main() {
	int N, M, Q, op, p, a, b;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<Matrix<3>> mats(1);
	mats.back().setIdentity();
	cin >> M;
	for (int i = 0; i < M; ++i) {
		Matrix<3> mat;
		cin >> op;
		switch (op) {
		case 1:
			mat.e[0][1] = 1;
			mat.e[1][0] = -1;
			mat.e[2][2] = 1;
			break;
		case 2:
			mat.e[0][1] = -1;
			mat.e[1][0] = 1;
			mat.e[2][2] = 1;
			break;
		case 3:
			cin >> p;
			mat.e[0][0] = -1;
			mat.e[0][2] = 2 * p;
			mat.e[1][1] = 1;
			mat.e[2][2] = 1;
			break;
		case 4:
			cin >> p;
			mat.e[0][0] = 1;
			mat.e[1][1] = -1;
			mat.e[1][2] = 2 * p;
			mat.e[2][2] = 1;
			break;
		}
		mats.emplace_back(mat.mul(mats.back()));
	}
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> a >> b;
		LL sx = X[b - 1], sy = Y[b - 1];
		const Matrix<3> &mat = mats[a];
		LL x = mat.e[0][0] * sx + mat.e[0][1] * sy + mat.e[0][2];
		LL y = mat.e[1][0] * sx + mat.e[1][1] * sy + mat.e[1][2];
		cout << x << " " << y << endl;
	}
	return 0;
}
