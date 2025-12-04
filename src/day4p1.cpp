#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  std::ifstream file("data");
  std::vector<std::string> stuff;
  string thing;
  while (getline(file, thing))
    stuff.push_back(thing);

  int x = 0;
  for (int i = 0; i < stuff.size(); i++) {
    for (int j = 0; j < stuff[i].length(); j++) {
      if (stuff[i][j] == '@') {
        int c = 0;

        for (int new_i = -1; new_i <= 1; new_i++) {
          for (int new_j = -1; new_j <= 1; new_j++) {
            if (new_i == 0 && new_j == 0)
              continue;
            int new_ii = i + new_i;
            int new_jj = j + new_j;

            if (new_ii >= 0 && new_ii < stuff.size() && new_jj >= 0 &&
                new_jj < stuff[i].length() && stuff[new_ii][new_jj] == '@') {
              c++;
            }
          }
        }

        if (c < 4) {
          x++;
        }
      }
    }
  }

  cout << x << '\n';
}
