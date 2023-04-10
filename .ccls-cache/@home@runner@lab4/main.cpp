#include "dataio.h"
#include "functions.h"
#include <fstream>
#include <iostream>
using std::cout;
int main() {
  std::ifstream fin("in.txt");
  std::ofstream fout("out.txt");
  unsigned char inl;
  unsigned char outl;
  unsigned n{0};
  std::string s;
  std::string ent;
  while (true) {
    if (fin.is_open() && fout.is_open()) {
      cout << "Ввод с консоли (0) или с файл(1): ";
      inl = read_0_1();
      cout << "Вывод в консоли (0) или в файл(1): ";
      outl = read_0_1();
      if (inl == '0') {
        cout << "Введите n: ";
        n = read_uint("");
        cout << "Введите " << n << " символа(ов): ";
        getline(std::cin, s);
      } else if (inl == '1') {
        getline(fin, ent);
        n = read_uint(ent);
        getline(fin, s);
      }
      if(n==s.length()){
        s = task(s, n);
        if (outl == '0') {
        cout << s << '\n';
      } else if (outl == '1') {
        fout << s;
      }
      }else{
        cout << "Введено "<<s.length()<<" символов надо "<<n <<'\n';
      }
      

      if (inl == '0') {
        cout << "Хотите продолжить(0/1): ";
        inl = read_0_1();
        if (inl == '0') {
          break;
        }
      }else{
        break;
      }
    }else{
      cout << "Ошибка ввода в файл.";
      break;
    }
  }
}