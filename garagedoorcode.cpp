#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

bool is_subsequence(const std::string &a, const std::string &b) {
  int i = 0;
  for (int j = 0; i < a.size() && j < b.size(); j++) {
    if (a[i] == b[j]) {
      i++;
    }
  }
  return i == a.size();
}

int main(void) {
  int K, N;
  std::cin >> K >> N;

  std::vector<std::string> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::set<std::string> codes;

  std::vector<bool> mask(A[0].size(), false);
  std::fill(mask.begin(), mask.begin() + K, true);
  do {
    std::string code;
    for (int i = 0; i < A[0].size(); i++) {
      if (mask[i]) {
        code += A[0][i];
      }
    }
    codes.insert(code);
  } while (std::prev_permutation(mask.begin(), mask.end()));

  std::vector<std::string> valid;
  for (const auto &code : codes) {
    bool is_valid = true;
    for (int i = 1; i < N; i++) {
      if (!is_subsequence(code, A[i])) {
        is_valid = false;
        break;
      }
    }

    if (is_valid) {
      valid.push_back(code);
    }
  }

  std::sort(valid.begin(), valid.end());
  std::cout << valid.size() << std::endl;
  for (const auto &code : valid) {
    std::cout << code << std::endl;
  }

  return 0;
}
