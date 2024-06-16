#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (i32 i = 1; i <= (n); (i)++)
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
  vector<i32> product(N), person(M);
  vector<bool> purchase(N);
  rep(i, N) cin >> product[i];
  rep(i, M) cin >> person[i];

  sort(all(product));
  sort(all(person));

  i32 start = -1, end = -1;
  rep(i, N) {
    if (product[i] >= person[0] && start == -1) start = i;
    if (product[i] >= person[M - 1]) {
      if (product[i] == product[end] || end == -1)
        end = i;
    }
  }

  i64 sum = 0;
  i32 idx = start, buy_counter = 0;

  rep(i, M) {
    for (i32 j = idx; j < end + 1; ++j) {
      if (product[j] >= person[i]) {
        sum += product[j];
        idx = j + 1;
        ++buy_counter;
        break;
      }
    }
  }
  cout << (buy_counter == M ? sum : -1) << endl;
}