#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int N;
  std::cin >> N;

  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  int max = *std::max_element(A.begin(), A.end());
  int min = *std::min_element(A.begin(), A.end());

  int diff = min - (max / 2);
  if (diff < 0) {
    diff = 0;
  }

  std::cout << diff << std::endl;

  return 0;
}
