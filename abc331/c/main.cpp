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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<i64, i64> count, ans;

  i32 N;
  cin >> N;
  vector<i64> A(N), B(N), psum(N + 1);
  rep(i, N) {
    cin >> A[i];
    B[i] = A[i];
  }

  sort(all(B));

  psum[0] = 0;
  for (i32 i = 0; i < N; ++i) {
    psum[i + 1] = psum[i] + B[i];
  }

  for (auto x : A) {
    auto it = upper_bound(all(B), x);
    i32 idx = it - B.begin();
    cout << psum[N] - psum[idx] << ' ';
  }
  cout << endl;
}