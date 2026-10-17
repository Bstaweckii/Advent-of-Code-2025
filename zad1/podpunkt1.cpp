#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {

  int dial = 50;
  int direction = 1;
  int wystapienia = 0;
  int change = 0;
  std::vector<std::string> rotations;

  std::ifstream dane("/home/user/Studia/cpp/advent/zad1.txt");

  std::string wiersz;
  while (dane >> wiersz) {
    rotations.push_back(wiersz);
  }
  dane.close();

  for (int i = 0; i < rotations.size(); i++) {
    std::vector<std::string> pomocniczy;
    pomocniczy.push_back(rotations.at(i));

    if (pomocniczy.at(0)[0] == 'R') {
      direction = 1;
    } else {
      direction = -1;
    }
    change = std::stoi(pomocniczy.at(0).substr(1));
    // std::cout << change * direction << std::endl;

    dial = (dial + (change * direction)) %
           100; // inaczej rotacje ponad 100 sie wywalaja

    if (dial == 0) {
      // std::cout << "MAMY ZERO";
      wystapienia += 1;
    } else {

      if (dial > 99) {
        dial = dial - 100;
        if (dial == 0) {
          // std::cout << "MAMY ZERO";
          wystapienia += 1;
        }
      }
      if (dial < 0) {
        dial = dial + 100;
        if (dial == 0) {
          // std::cout << "MAMY ZERO";
          wystapienia += 1;
        }
      }
    }
  }
  std::cout << wystapienia;
}
