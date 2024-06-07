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
  vector<char> first_c{'H', 'D', 'C', 'S'};
  vector<char> second_c{'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  i32 N;
  cin >> N;
  vector<string> arr(N);

  rep(i, N) {
    cin >> arr[i];
  }

  rep(i, N) {
    if (find(all(first_c), arr[i][0]) == first_c.end() || find(all(second_c), arr[i][1]) == second_c.end()) {
      cout << "No" << endl;
      return 0;
    }
    for (i32 j = i + 1; j < N; j++) {
      if (arr[i] == arr[j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}