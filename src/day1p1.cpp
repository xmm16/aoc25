#include <fstream>
#include <iostream>

int main() {
  int begin = 50;

  std::ifstream file("data");

  int count = 0;
  char thing;
  int temp_num;
  while (file >> thing) {
    file >> temp_num;

    switch (thing) {
    case 'L':
      for (int i = 0; i < temp_num; i++) {
        begin--;
        if (begin == -1) {
          begin = 99;
        }
      }

      break;
    case 'R':
      for (int i = 0; i < temp_num; i++) {
        begin++;
        if (begin == 100) {
          begin = 0;
        }
      }

      break;
    default:
      std::cout << "wtf" << thing << '\n';
      break;
    }
    if (begin == 0)
      count++;
  }

  std::cout << count;
}
