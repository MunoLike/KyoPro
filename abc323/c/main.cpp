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

template <class S, class T>
inline S prevent_oor(S a, const T b) {
  a %= b;
  if (a < 0) {
    a += b;
  }
  return a;
}

template <class S, class T>
inline S chmax(S &a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

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
  i32 N, M;
  cin >> N >> M;
  vector<i32> prob(M);
  rep(i, M) cin >> prob[i];

  vector<string> solved(N);
  rep(i, N) cin >> solved[i];

  vector<i32> sums(N, 0);
  rep(i, N) {
    rep(j, M) sums[i] += prob[j] * (solved[i][j] == 'o');
    sums[i] += i + 1;
  }

  i32 max_sum = *max_element(all(sums));

  rep(i, N) {
    if (sums[i] == max_sum) {
      cout << 0 << '\n';
      continue;
    }

    vector<i32> remain;
    rep(j, M) {
      if (solved[i][j] == 'x') remain.push_back(prob[j]);
    }
    sort(all(remain), greater());

    i32 acc = sums[i], count = 0;
    while (max_sum > acc) {
      acc += remain[count++];
    }
    cout << count << '\n';
  }
}