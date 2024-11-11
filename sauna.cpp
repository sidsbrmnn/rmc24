#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int N;
  std::cin >> N;

  std::vector<int> lows(N), highs(N);
  for (int i = 0; i < N; i++) {
    std::cin >> lows[i] >> highs[i];
  }

  int low = *std::max_element(lows.begin(), lows.end());

  int count = 0;
  for (const auto &h : highs) {
    if (low <= h) {
      count++;
    }
  }

  if (count != N) {
    std::cout << "bad news" << std::endl;
  } else {
    int high = *std::min_element(highs.begin(), highs.end());
    std::cout << (high - low + 1) << " " << low << std::endl;
  }

  return 0;
}
