
/*

Google Developer Day 2011

sliding puzzle

*/

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#endif
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define HISTORIES 128		// 探索履歴数
#define QUEUES (1 << 22)	// キューの個数(4M)
#define RETRY_COUNT 3

#ifdef _DEBUG
#define MAX_COUNT 10000
#define CUT_QUEUE_THRESHOLD 1000
#else
#define MAX_COUNT 100000000
#define CUT_QUEUE_THRESHOLD 100000
#endif

#define SizeOfArray(a) (sizeof(a)/sizeof(a[0]))
typedef unsigned long long ULL;
typedef vector<string> StringVector;

enum {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

static const char * const DirSeq = "LRUD";
static const char * const Chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const int DirX[] = {-1,1,0,0};
static const int DirY[] = {0,0,-1,1};


static void DebugOutput(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	char buffer[4096];
	vsnprintf(buffer, 4096, format, args);
	va_end(args);
	printf("%s\n", buffer);
#ifdef _WIN32
	fprintf(stderr, "%s\n", buffer);
#endif
}


// 盤面 (遅くてもよいものに使用)
struct Board {
	int W;
	int H;
	int cursor;
	char b[37];

	Board(int w, int h, const char *seq) { Init(w, h, seq); }

	Board(const char *seq) {
		char temp[100] = {0};
		strncpy(temp, seq, 99);
		int w, h;
		char *p = strtok(temp, " ,");
		if (!p || sscanf(p, "%d", &w) != 1) {
			return;
		}
		p = strtok(NULL, " ,");
		if (!p || sscanf(p, "%d", &h) != 1) {
			return;
		}
		p = strtok(NULL, " ,");
		if (p) {
			Init(w,h, p);
		}
	}

	void Init(int w, int h, const char *seq) {
		memset(this, 0, sizeof(Board));
		W = w;
		H = h;
		strncpy(b, seq, 36);
		const char *p = strchr(b, '0');
		if (p) {
			cursor = (int)(p - b);
		}
	}

	// ゴールの盤面を生成
	string Goal(void) const {
		string s;
		int x, y;
		size_t pos = 0;
		for (y = 0; y < H; ++y) {
			for (x = 0; x < W; ++x, ++pos) {
				s += b[pos] == '=' ? '=' : Chars[pos + 1];
			}
		}
		s[pos - 1] = '0';
		return s;
	}

	// 経路をLRUDに変換する
	string ConvertAnswer(const string &ans) const {
		string seq;
		int cx = cursor % W;
		int cy = cursor / W;
		size_t i;
		for (i = 0; i < ans.length(); ++i) {
			int next = (int)(strchr(Chars, ans[i]) - Chars);
			int nx = next % W;
			int ny = next / W;
			int dx = nx - cx;
			int dy = ny - cy;
			int diff = abs(dx) + abs(dy);
			int j;
			for (j = 0; j < SizeOfArray(DirX); ++j) {
				if (DirX[j] == dx && DirY[j] == dy) {
					seq += DirSeq[j];
					break;
				}
			}
			if (j >= SizeOfArray(DirX)) {
				return "";
			}
			cx = nx;
			cy = ny;
		}
		return seq;
	}

	// LRUDを受け取り、盤面を進める
	bool Forward(const string &sequence) {
		int cx = cursor % W;
		int cy = cursor / W;
		size_t i;
		for (i = 0; i < sequence.length(); ++i) {
			const char *d = strchr(DirSeq, sequence[i]);
			if (d == NULL) {
				return false;
			}
			int dir = (int)(d - DirSeq);
			int nx = cx + DirX[dir];
			int ny = cy + DirY[dir];
			if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
				return false;
			}
			b[cy * W + cx] = b[ny * W + nx];
			b[ny * W + nx] = '0';
			cx = nx;
			cy = ny;
		}
		cursor = cy * W + cx;
		return b[cursor] == '0';
	}

	// ゴールに至る盤面かどうか判定する
	bool Verify(const string &answer) const {
		Board temp(W, H, b);
		Board goal(W, H, Goal().c_str());
		if (!temp.Forward(answer)) {
			return false;
		}
		if (strcmp(temp.b, goal.b) != 0) {
			DebugOutput("Verify FAILED");
			return false;
		}
		return true;
	}

	bool Solve(size_t MaxCount, string &fwd, string &rev) const;
};


// BFSでキューに入れる盤面
struct Record {
	char b[36];
	char cursor;
	char histories;
	char skip;		// 1=捨てる
	unsigned int score;
	char history[HISTORIES];

	// 評価関数
	unsigned int Evaluate(const Board &goal) {
		int Score = 0;
		int Half = goal.W * goal.H / 2;
		size_t Width = goal.W;
		size_t Height = goal.H;
		size_t x, y, pos = 0;
		for (y = 0; y < Height; ++y) {
			for (x = 0; x < Width; ++x, ++pos) {
				char c = b[pos];
				const char *p = strchr(Chars, c);
				if (p) {
					size_t index = p - Chars;
					if (index > 0) {
						--index;
						int dx = (int)((index % Width) - x);
						int dy = (int)((index / Width) - y);
						Score += dy*dy + dx*dx;
					}
				}
			}
		}
		return score = Score;
	}
};

static Record *QueueStore;
size_t q_write_pos;
size_t q_read_pos;


// 通ったかどうかの表
struct BoardState {
	char b[36];
	bool operator <(const BoardState &src) const {
		return memcmp(b, src.b, sizeof(b)) < 0;
	}
};
typedef set<BoardState> BoardStateSet;


class GCJ {
	static const size_t BufferSize = 1024000;
	FILE *m_Source;
	size_t m_BufferSize;
	char *m_Buffer;
	StringVector m_Answers;
	int m_Moves[4];
	int m_Used[4];

public:
	GCJ(FILE *source, size_t buffer_size = BufferSize) {
		m_Source = source;
		m_BufferSize = buffer_size;
		m_Buffer = new char[m_BufferSize];

		memset(m_Moves, 0, sizeof(m_Moves));
		memset(m_Used, 0, sizeof(m_Used));
		FILE *fp = fopen("solved.txt", "rt");
		if (fp) {
			m_Source = fp;
			char *p;
			while ((p = GetSingleLine()) != NULL) {
				m_Answers.push_back(p);
				char c;
				while ((c = *p++)) {
					const char *t = strchr(DirSeq, c);
					if (t) {
						++m_Used[t - DirSeq];
					}
				}
			}
			fclose(fp);
			m_Source = source;
		}
	}

	~GCJ() {
		delete [] m_Buffer;
	}

	bool Solve(void) {
		char *p = GetSingleLine();
		// L R U D
		if (sscanf(p, "%d %d %d %d", m_Moves, m_Moves+1, m_Moves+2, m_Moves+3) != 4) {
			return false;
		}

		DebugOutput("available: %d %d %d %d", m_Moves[0]-m_Used[0], m_Moves[1]-m_Used[1], m_Moves[2]-m_Used[2], m_Moves[3]-m_Used[3]);

		int cases = GetCases();
		if (cases < 1) {
			return false;
		}

		FILE *fp = fopen("solved_.txt", "wt");

		int i;
		for (i = 0; i < cases; ++i) {
			p = GetSingleLine();

			bool run = true;

			string solved;
			if ((int)m_Answers.size() > i && !m_Answers[i].empty()) {
				solved = m_Answers[i];
				Board b(p);
				if (!b.Verify(solved)) {
					DebugOutput("Invalid answer supplied");
					break;
				}
				DebugOutput("Answer # %d is verified", i + 1);
				run = false;
			}

			string answer;
			if (run) {
				if (!Solve(i + 1, p, MAX_COUNT, answer)) {

				}
			} else {
				answer = solved;
			}

			if (fp) {
				fprintf(fp, "%s\n", answer.c_str());
				fflush(fp);
			}
		}

		return true;
	}

	static void Solve(const char *seq) {
		GCJ g(NULL);
		string answer;
		g.Solve(1, seq, MAX_COUNT, answer);
	}

private:
	bool Solve(int number, const char *start_sequence, size_t MaxCount, string &answer) {
		string all_seq;

		Board Current(start_sequence);
		int retry;
		for (retry = 0; retry < RETRY_COUNT; ++retry) {
			DebugOutput("Trying: # %d (count %d)", number, retry);

			string fwd, rev;
			if (!Current.Solve(MaxCount, fwd, rev)) {
				DebugOutput("Solve() FAILED");
				break;
			}

			if (fwd.empty()) {
				DebugOutput("fwd is empty");
				break;
			}

			reverse(rev.begin(), rev.end());
			fwd += rev;

			string seq = Current.ConvertAnswer(fwd);
			all_seq += seq;
			DebugOutput("seq: %s", seq.c_str());

			if (rev.empty()) {
				if (!Current.Forward(seq)) {
					DebugOutput("Forward() FAILED");
					break;
				}
				continue;
			}

			Board Start(start_sequence);
			if (!Start.Verify(all_seq)) {
				DebugOutput("Verify() FAILED");
				return false;
			}

			DebugOutput("SOLVED: # %d", number);
			DebugOutput("  Q: %s", start_sequence);
			DebugOutput("  A: %s", all_seq.c_str());

			answer = all_seq;
			return true;
		}

		return false;
	}

	bool _Solve(const Board &Start, size_t MaxCount, string &f, string &r);

	int GetCases(void) {
		int cases;
		return GetInt(cases) ? cases : -1;
	}

	bool GetInt(int &i) {
		char *p = GetSingleLine();
		return p != NULL && sscanf(p, "%d", &i) >= 1;
	}

	char *GetSingleLine(void) {
		char *p = fgets(m_Buffer, (int)m_BufferSize, m_Source);
		if (!p) {
			return NULL;
		}
		char *term = p + strlen(p) - 1;
		if (term >= p && *term == '\n') {
			*term = 0;
		}
		return p;
	}
};


static __inline Record *StoreQueue(const Record &r) {
	Record *w = QueueStore + q_write_pos;
	memcpy(w, &r, sizeof(Record));
	return w;
}


typedef vector<Record *> RecordPtrVector;
static bool CompareRecordPtr(Record *&l, Record *&r) {
	return l->score < r->score;
}


static void DropQueue(const Board &Goal, size_t q_pos, size_t q_size, Record *top = NULL) {
	if (q_size < CUT_QUEUE_THRESHOLD) {
		return;
	}

	RecordPtrVector vec;

	unsigned int Min = 999999;
	unsigned int Max = 0;
	ULL score = 0;
	ULL dist = 0;
	size_t i;
	for (i = 0; i < q_size; ++i) {
		Record *r = QueueStore + ((q_pos + i) & (QUEUES - 1));
		unsigned int s = r->Evaluate(Goal);
		score += s;
		dist += s * s;
		Min = min(Min, s);
		Max = max(Max, s);
		vec.push_back(r);
	}

	sort(vec.begin(), vec.end(), CompareRecordPtr);
	for (i = CUT_QUEUE_THRESHOLD; i < vec.size(); ++i) {
		(vec[i])->skip = 1;
	}

	if (top) {
		memcpy(top, vec[0], sizeof(Record));
	}
}


bool Board::Solve(size_t MaxCount, string &fwd, string &rev) const {
	DebugOutput("Problem: %d%c%d %s", W, 'x', H, b);

	// direction candidates
	size_t Dirs[36] = {0};
	size_t NextPos[36][4] = {0};

	// generate direction candidates
	int x, y, d;
	size_t pos = 0;
	for (y = 0; y < H; ++y) {
		for (x = 0; x < W; ++x, ++pos) {
			size_t dirs = 0;
			for (d = 0; d < SizeOfArray(DirX); ++d) {
				int nx = x + DirX[d];
				int ny = y + DirY[d];
				size_t next_pos = ny * W + nx;
				if (nx < 0 || nx >= W || ny < 0 || ny >= H ||
						b[next_pos] == '=') {
					continue;
				}
				NextPos[pos][dirs++] = next_pos;
			}
			Dirs[pos] = dirs;
		}
	}

	Board Goal(W, H, Goal().c_str());
	if (strcmp(b, Goal.b) == 0) {
		DebugOutput("Needless to solve");
		return true;
	}

	// reset queue
	q_write_pos = 0;
	q_read_pos = 0;
	memset(QueueStore, 0, sizeof(Record)*QUEUES);

	Record _start = {0};
	memcpy(_start.b, b, 36);
	_start.cursor = cursor;
	StoreQueue(_start);
	size_t q_pos = q_write_pos++;
	size_t q_size = 1;

	Record _goal = {0};
	memcpy(_goal.b, Goal.b, 36);
	_goal.cursor = Goal.cursor;
	StoreQueue(_goal);
	size_t rq_pos = q_write_pos++;
	size_t rq_size = 1;

	BoardStateSet visited, rvisited;
	{
		BoardState *s = (BoardState *)(b);
		visited.insert(*s);
		BoardState *g = (BoardState *)(Goal.b);
		rvisited.insert(*g);
	}

	// main loop
	size_t Depth = 0, Count = 0;
	for (; Depth < HISTORIES && Count < MaxCount; ++Depth) {
#ifdef _WIN32
		DWORD StartTick = GetTickCount();
#endif

		Count += q_size + rq_size;
		DebugOutput("Depth: %d, q: %d, rq: %d", Depth, q_size, rq_size);

		size_t nq_pos = q_write_pos;
		size_t nq_size = 0;
		size_t i, d;

		for (i = 0; i < q_size; ++i) {
			const Record *r = QueueStore + q_pos;
			q_pos = (q_pos + 1) & (QUEUES - 1);
			if (r->skip) {
				continue;
			}

			size_t cursor = r->cursor;
			size_t dirs = Dirs[cursor];
			for (d = 0; d < dirs; ++d) {
				Record *w = StoreQueue(*r);
				size_t next_pos = NextPos[cursor][d];
//				++(w->histories);
				w->b[cursor] = w->b[next_pos];
				w->b[next_pos] = '0';
				w->cursor = (char)next_pos;
				w->history[Depth] = Chars[next_pos];
				BoardState *s = (BoardState *)w->b;

				if (rvisited.find(*s) != rvisited.end()) {
					fwd.assign(w->history, Depth + 1);

					for (i = 0; i < rq_size; ++i) {
						r = QueueStore + rq_pos;
						rq_pos = (rq_pos + 1) & (QUEUES - 1);
						if (memcmp(w->b, r->b, sizeof(w->b)) == 0) {
							rev.assign(r->history, Depth);
							break;
						}
					}

					DebugOutput("Solved(F)");
					return true;
				}

				if (visited.find(*s) == visited.end()) {
					q_write_pos = (q_write_pos + 1) & (QUEUES - 1);
					++nq_size;
					visited.insert(*s);
				}
			}
		}
		q_pos = nq_pos;
		q_size = nq_size;
		if ((q_size + rq_size) >= QUEUES) {
			DebugOutput("Too many queues(F)");
			break;
		}
		DropQueue(Goal, q_pos, q_size);

		size_t rnq_pos = q_write_pos;
		size_t rnq_size = 0;
		for (i = 0; i < rq_size; ++i) {
			const Record *r = QueueStore + rq_pos;
			rq_pos = (rq_pos + 1) & (QUEUES - 1);
			if (r->skip) {
				continue;
			}

			size_t cursor = r->cursor;
			size_t dirs = Dirs[cursor];
			for (d = 0; d < dirs; ++d) {
				Record *w = StoreQueue(*r);
				size_t next_pos = NextPos[cursor][d];
//				++(w->histories);
				w->b[cursor] = w->b[next_pos];
				w->b[next_pos] = '0';
				w->cursor = (char)next_pos;
				w->history[Depth] = Chars[cursor];		// current pos
				BoardState *s = (BoardState *)w->b;

				if (visited.find(*s) != visited.end()) {
					rev.assign(w->history, Depth + 1);

					for (i = 0; i < q_size; ++i) {
						r = QueueStore + q_pos;
						q_pos = (q_pos + 1) & (QUEUES - 1);
						if (memcmp(w->b, r->b, sizeof(w->b)) == 0) {
							fwd.assign(r->history, Depth + 1);
							break;
						}
					}

					DebugOutput("Solved(R)");
					return true;
				}

				if (rvisited.find(*s) == rvisited.end()) {
					q_write_pos = (q_write_pos + 1) & (QUEUES - 1);
					++rnq_size;
					rvisited.insert(*s);
				}
			}
		}
		rq_pos = rnq_pos;
		rq_size = rnq_size;
		if ((q_size + rq_size) >= QUEUES) {
			DebugOutput("Too many queues(R)");
			break;
		}
		DropQueue(Goal, rq_pos, rq_size);

#ifdef _WIN32
		DWORD ConsumedTick = GetTickCount() - StartTick;
		if (ConsumedTick >= 10000) {
			DebugOutput("TLE by ticks");
			break;
		}
#endif
	}

	DebugOutput("TLE");
	return false;
}


int main() {
	int result = 0;
	QueueStore = new Record[QUEUES];

	GCJ gcj(stdin);
	result = gcj.Solve() ? 0 : -1;

	delete [] QueueStore;
	return result;
}

