#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int dial = 50;
  int kierunek = 1;
  int zmiana = 0;
  int czy_zero = 0;

  std::vector<std::string> zmiany;
  std::ifstream dane("/home/user/Studia/cpp/advent/zad1.txt");
  std::string wiersz;
  while (dane >> wiersz) {
    zmiany.push_back(wiersz);
  }
  dane.close();

  for (int i = 0; i < zmiany.size(); i++) {
    // std::cout << zmiany.at(i)[0] << std::endl;
    if (zmiany.at(i)[0] == 'R') {
      kierunek = 1;
    } else {
      kierunek = -1;
    }
    zmiana = std::stoi(zmiany.at(i).substr(1));

    for (int k = 0; k < zmiana; k++) {
      dial = dial + kierunek;

      if (dial > 99) {
        dial = 0;
      }
      if (dial < 0) {
        dial = 99;
      }
      if (dial == 0) {
        czy_zero += 1;
      }
    }
  }

  std::cout << czy_zero;
}
