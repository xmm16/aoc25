
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
        if (begin == 0)
          count++;
      }

      break;
    case 'R':
      for (int i = 0; i < temp_num; i++) {
        begin++;
        if (begin == 100) {
          begin = 0;
        }
        if (begin == 0)
          count++;
      }

      break;
    default:
      std::cout << "wtf" << thing << '\n';
      break;
    }
  }

  std::cout << count;
}
