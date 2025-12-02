#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_equal(std::string s, size_t cize) {
  if (cize == 0)
    return {};
  std::vector<std::string> parts;
  for (int i = 0; i < s.length(); i += cize) {
    parts.push_back(s.substr(i, cize));
  }
  return parts;
}

bool all_parts_equal(std::vector<std::string> parts) {
  if (parts.empty())
    return false;
  for (std::string p : parts) {
    if (p != parts[0])
      return false;
  }
  return true;
}

int main() {
  std::ifstream file("data");

  long long n;
  long long n2;
  char c;
  long long total_sum = 0;

  while (file >> n) {
    file >> c;
    file >> n2;

    for (; n <= n2; n++) {
      std::string num = std::to_string(n);
      std::vector<std::string> num_parts;
      int buf = 0;
      for (int substr_val = 1; substr_val < num.length(); substr_val++) {
        if ((float)(num.length() % substr_val) != 0)
          continue;

        num_parts = split_equal(num, substr_val);
        if (all_parts_equal(num_parts))
          buf = substr_val;
      }
      if (all_parts_equal(split_equal(num, buf))) {
        std::cout << n << '\n';
        total_sum += n;
      }
    }

    file >> c;
  }

  std::cout << total_sum << '\n';
}
