#include <fstream>
#include <iostream>
#include <string>

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
      if (num.length() % 2 != 0)
        continue;

      std::string num1 = num.substr(0, num.length() / 2);
      std::string num2 = num.substr(num.length() / 2, num.length());
      std::cout << num1 << "    " << num2 << '\n';
      if (num1 == num2) {
        total_sum += n;
      }
    }

    file >> c;
  }

  std::cout << total_sum << '\n';
}
