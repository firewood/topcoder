#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct Point {
	double x;
	double y;
};

static uint32_t _x = 2463534242;
static void xorshift32_seed(uint32_t seed)
{
	if (seed != 0) {
		_x = seed;
	}
}
static __inline uint32_t xorshift32(void)
{
	_x ^= (_x << 13);
	_x ^= (_x >> 17);
	return _x ^= (_x << 5);
}
static __inline uint32_t _rand() {
	return xorshift32();
}

// connect a -> b and c -> d
__inline void swap_edges(vector<int>& seq, int a, int b, int c, int d) {
	int x = c, y = b, N = (int)seq.size();
	if (y - x > a + N - d) {
		x = d, y = a + N;
	}
	while (x < y) {
		swap(seq[x < N ? x : x - N], seq[y < N ? y : y - N]);
		++x, --y;
	}
}

void two_opt(const vector<Point>& points, vector<int>& seq, int turns) {
	int N = (int)seq.size();
	vector<vector<double>> dist(N, vector<double>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			double dx = points[i].x - points[j].x, dy = points[i].y - points[j].y;
			dist[i][j] = dist[j][i] = sqrt(dx * dx + dy * dy);
		}
	}

	for (int t = 0; t < turns; ++t) {
		int a = _rand() % N, b = _rand() % N;
		if (a == b) continue;
		if (a > b) swap(a, b);
		int c = (a + 1) % N, d = (b + 1) % N;
		if (dist[seq[a]][seq[b]] + dist[seq[c]][seq[d]] + 1e-9 < dist[seq[a]][seq[c]] + dist[seq[b]][seq[d]]) {
			swap_edges(seq, a, b, c, d);
		}
	}
}

int main(int argc, const char* argv[]) {
	//const int N = 10, T = 100;
	const int N = 100, T = 25000;
	//const int N = 1000, T = 2000000;

	vector<Point> points(N);
	for (int i = 0; i < N; ++i) {
		//points[i].x = cos(2.0 * M_PI / N * i) * 100;
		//points[i].y = sin(2.0 * M_PI / N * i) * 100;
		points[i].x = (_rand() % 10000) * 0.01;
		points[i].y = (_rand() % 10000) * 0.01;
	}
	random_shuffle(points.begin(), points.end());

	FILE* fp = fopen("in.txt", "wt");
	fprintf(fp, "%d\n", N);
	for (int i = 0; i < N; ++i) {
		fprintf(fp, "%.10f %.10f\n", points[i].x, points[i].y);
	}
	fclose(fp);

	vector<int> seq(N);
	for (int i = 0; i < N; ++i) {
		seq[i] = i;
	}

	two_opt(points, seq, T);

	fp = fopen("out.txt", "wt");
	for (int i = 0; i < N; ++i) {
		fprintf(fp, " %d", seq[i]);
	}
	fclose(fp);

	return 0;
}
