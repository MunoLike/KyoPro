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
  i32 N;
  cin >> N;

  vector<bool> cutdeg(360);
  cutdeg[0] = true;
  i32 sum = 0;
  rep(i, N) {
    i32 A;
    cin >> A;
    sum = (sum + A) % 360;
    cutdeg[sum] = true;
  }

  i32 distmax = 0;
  i32 cur = 0;
  for (i32 i = 0; i <= 360; i++) {
    if (cutdeg[i % 360]) {
      chmax(distmax, cur);
      cur = 0;
    }
    cur++;
  }
  cout << distmax << endl;
}