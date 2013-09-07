
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 500;
const int REPEAT = 10000;
const int WINDOW_SIZE = 50;
const int SLIDE_NUM = 30;

static const int pat[][9][9] = {
	{
		// best: offset = 69
		{1,2,3,4,5,6,7,8,9},
		{4,5,6,7,8,9,1,2,3},
		{7,8,9,1,2,3,4,5,6},
		{2,3,1,5,6,4,8,9,7},
		{5,6,4,8,9,7,2,3,1},
		{8,9,7,2,3,1,5,6,4},
		{3,1,2,6,4,5,9,7,8},
		{6,4,5,9,7,8,3,1,2},
		{9,7,8,3,1,2,6,4,5}
	},
	{
		// best: offset = 52
		{1,2,3,4,5,6,7,8,9},
		{4,5,6,7,8,9,1,2,3},
		{7,8,9,1,2,3,4,5,6},
		{3,1,2,6,4,5,9,7,8},
		{6,4,5,9,7,8,3,1,2},
		{9,7,8,3,1,2,6,4,5},
		{2,3,1,5,6,4,8,9,7},
		{5,6,4,8,9,7,2,3,1},
		{8,9,7,2,3,1,5,6,4}
	},
};

struct Board {
	char _b[512][512];
	char _p[512][512];
	bool _f[512][512];

	void dump(void) const {
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				cout << (int)_b[r][c];
			}
			cout << endl;
		}
	}

	void load(void) {
		memset(_b, 0, sizeof(_b));
		memset(_p, 0, sizeof(_p));
		memset(_f, 0, sizeof(_f));
		string line;
		for (int i = 0; i < N; ++i) {
			cin >> line;
			for (int j = 0; j < N; ++j) {
				int c = line[j] - '0';
				if (c) {
					_b[i][j] = c;
					_f[i][j] = true;
				}
			}
		}
	}

	int evaluateHorizontal(int row_st = 0, int row_ed = N, int col_st = 0, int col_ed = N) const {
		int ret = 0;
		for (int r = row_st; r < row_ed; ++r) {
			for (int c = col_st; c <= col_ed - 9; ++c) {
				int b = 0;
				for (int i = 0; i < 9; ++i) {
					b |= 1 << _b[r][c+i];
				}
				ret += b == 1022;
			}
		}
		return ret;
	}

	int evaluateVertical(int row_st = 0, int row_ed = N, int col_st = 0, int col_ed = N) const {
		int ret = 0;
		for (int r = row_st; r <= row_ed - 9; ++r) {
			for (int c = col_st; c < col_ed; ++c) {
				int b = 0;
				for (int i = 0; i < 9; ++i) {
					b |= 1 << _b[r+i][c];
				}
				ret += b == 1022;
			}
		}
		return ret;
	}

	int evaluateBlock(int row_st = 0, int row_ed = N, int col_st = 0, int col_ed = N) const {
		int ret = 0;
		for (int r = row_st; r <= row_ed - 3; ++r) {
			for (int c = col_st; c <= col_ed - 3; ++c) {
				int b = 0;
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						b |= 1 << _b[r+i][c+j];
					}
				}
				ret += b == 1022;
			}
		}
		return ret;
	}

	int evaluate(int row_st = 0, int row_ed = N, int col_st = 0, int col_ed = N) const {
		row_st = max(0, row_st);
		row_ed = min(N, row_ed);
		col_st = max(0, col_st);
		col_ed = min(N, col_ed);
		int ret = evaluateHorizontal(row_st, row_ed, col_st, col_ed);
		ret += evaluateVertical(row_st, row_ed, col_st, col_ed);
		ret += evaluateBlock(row_st, row_ed, col_st, col_ed);
		return ret;
	}

	bool inside(int pos) const {
		return 0 <= pos && pos < N;
	}

	bool inside(int r, int c) const {
		return inside(r) && inside(c);
	}

	bool fixed(int r, int c) const {
		return _f[r][c];
	}

	void fill(int pattern_no, int offset) {
		int row_offset = offset/9, col_offset = offset%9;
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				_p[r][c] = pat[pattern_no][(r+row_offset)%9][(c+col_offset)%9];
				if (!fixed(r, c)) {
					_b[r][c] = _p[r][c];
				}
			}
		}
	}

	int hoge(int r_offset, int c_offset, int r_center, int c_center, int r_range, int c_range, int prev_score) {
		if (!inside(r_center - r_range, c_center - c_range) || !inside(r_center + r_range, c_center + c_range)) {
			return -1;
		}
		int errors = 0;
		int err_fix[10] = {};
		int err_val[10] = {};
		int val_r[10] = {};
		int val_c[10] = {};
		for (int r = r_center - r_range; r <= r_center + r_range; ++r) {
			for (int c = c_center - c_range; c <= c_center + c_range; ++c) {
				if (fixed(r, c)) {
					int val = _p[r][c];
					if (_b[r][c] != val) {
						err_fix[errors] = _b[r][c];
						err_val[errors] = val;
						++errors;
					}
				} else {
					val_r[_b[r][c]] = r+1;
					val_c[_b[r][c]] = c+1;
				}
			}
		}
		if (errors <= 0) {
			return -1;
		}
		for (int i = 0; i < errors; ++i) {
			int val = err_fix[i];
			if (val_r[val] >= 0) {
				int r = val_r[val]-1, c = val_c[val]-1;
				int prev_val = _b[r][c];
				_b[r][c] = err_val[i];
				int score = evaluate(r_offset, r_offset + WINDOW_SIZE, c_offset, c_offset + WINDOW_SIZE);
				if (score > prev_score) {
					return score;
				}
				_b[r][c] = prev_val;
			}
		}
		return -1;
	}

	int hoge2(int r_offset, int c_offset, int r, int c, int prev_score) {
		int prev_val = _b[r][c];
		for (int val = 1; val <= 9; ++val) {
			_b[r][c] = val;
			int score = evaluate(r_offset, r_offset + WINDOW_SIZE, c_offset, c_offset + WINDOW_SIZE);
			if (score > prev_score) {
				return score;
			}
		}
		_b[r][c] = prev_val;
		return -1;
	}

};

int main() {
	int bestScore = 0;
	Board board, bestBoard;
	board.load();

	bestBoard = board;

//	for (int pat_no = 0; pat_no < (sizeof(pat)/sizeof(pat[0])); ++pat_no) {
	int pat_no = 1; {
//		for (int offset = 0; offset < 81; ++offset) {
		int offset = 52; {
			Board curBoard = board;

			// fill with fixed pattern
			curBoard.fill(pat_no, offset);

			// 9x1, 1x9, 3x3 block
			for (int r_offset = 0; r_offset <= (N-WINDOW_SIZE); r_offset += SLIDE_NUM) {
				for (int c_offset = 0; c_offset <= (N-WINDOW_SIZE); c_offset += SLIDE_NUM) {
					int score = curBoard.evaluate(r_offset, r_offset + WINDOW_SIZE, c_offset, c_offset + WINDOW_SIZE);
					int r_start = r_offset == 0 ? 0 : r_offset + 9;
					int r_end = r_offset == (N-WINDOW_SIZE) ? N : (r_offset+WINDOW_SIZE-9);
					int c_start = c_offset == 0 ? 0 : c_offset + 9;
					int c_end = c_offset == (N-WINDOW_SIZE) ? N : (c_offset+WINDOW_SIZE-9);
					for (int r = r_start; r < r_end; ++r) {
						for (int c = c_start; c < c_end; ++c) {
							score = max(score, curBoard.hoge(r_offset, c_offset, r, c, 0, 4, score));
							score = max(score, curBoard.hoge(r_offset, c_offset, r, c, 4, 0, score));
							score = max(score, curBoard.hoge(r_offset, c_offset, r, c, 1, 1, score));
						}
					}
				}
			}

			// random
			for (int r_offset = 0; r_offset <= (N-WINDOW_SIZE); r_offset += SLIDE_NUM) {
				for (int c_offset = 0; c_offset <= (N-WINDOW_SIZE); c_offset += SLIDE_NUM) {
					int score = curBoard.evaluate(r_offset, r_offset + WINDOW_SIZE, c_offset, c_offset + WINDOW_SIZE);
					int r_start = r_offset == 0 ? 0 : r_offset + 9;
					int r_end = r_offset == (N-WINDOW_SIZE) ? N : (r_offset+WINDOW_SIZE-9);
					int c_start = c_offset == 0 ? 0 : c_offset + 9;
					int c_end = c_offset == (N-WINDOW_SIZE) ? N : (c_offset+WINDOW_SIZE-9);
					for (int i = 0; i < REPEAT; ++i) {
						int r = (rand()*(r_end-r_start))/(RAND_MAX+1) + r_start;
						int c = (rand()*(c_end-c_start))/(RAND_MAX+1) + c_start;
						if (!curBoard.fixed(r, c)) {
							score = max(score, curBoard.hoge2(r_offset, c_offset, r, c, score));
						}
					}
				}
			}

			int curScore = curBoard.evaluate();
			if (curScore > bestScore) {
				bestBoard = curBoard;
				bestScore = curScore;
				cout << "pat:" << pat_no << ", offset:" << offset << ", score:" << curScore << endl;
			}
		}

	}

	// verify
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (board._b[r][c] != 0 && board._b[r][c] != bestBoard._b[r][c]) {
				cout << "ERROR! " << r << "," << c << endl;
				return 1;
			}
		}
	}

	// output result
	bestBoard.dump();
	cout << endl;
	cout << "vertical score  : " << bestBoard.evaluateVertical() << " / " << (N * (N-8)) << endl;
	cout << "horizontal score: " << bestBoard.evaluateHorizontal() << " / " << (N * (N-8)) << endl;
	cout << "3*3 block score : " << bestBoard.evaluateBlock() << " / " << ((N-2) * (N-2)) << endl;
	cout << "total score     : " << bestBoard.evaluate() << " / " << ((N-2) * (N-2) + 2 * N * (N-8)) << endl;

	return 0;
}

