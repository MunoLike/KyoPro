#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};

inline int64_t div_floor(int64_t a, int64_t b) {
  if (b < 0) {
    a *= -1;
    b *= -1;
  }
  if (a < 0) {
    return (a + 1) / b - 1;
  } else {
    return a / b;
  }
}

inline int64_t div_ceil(int64_t a, int64_t b) {
  return div_floor(a + b - 1, b);
}

int main() {
  i32 N, M, K;
  cin >> N >> M >> K;

  vector<i32> try_count(N, 0);
  rep(i, M) {
    i32 C;
    cin >> C;
    vector<bool> try_key(N);
    rep(j, C) {
      i32 A;
      cin >> A;
      try_key[A - 1] = true;
    }

    char res;
    cin >> res;
    rep(k, N) {
      if (try_key[k]) {
        try_count[k] += (res == 'o' ? 1 : -1);
      }
    }
  }

  i32 sum = 0;
  rep(i, N) {
    if (try_count[i] == 0) {
      sum++;
    }
  }

  cout << sum << endl;
}