// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
// открываем файл на чтение
  std::ifstream file(filename);
// если файл не открылся, прекращаем работу
  if (!file) {
    std::cout << "File error!" << std::endl;
  }
  char symbol;
  std::string word;
  BST<std::string> tree;
  while (file.get(symbol)) {
    if (isalpha(symbol)) { //определяет латинская буква ли символ
      word += tolower(symbol); // функция tolower выполняет преобразование прописных букв в строчные
    } else if (!word.empty()) {
      tree.add(word);
      word.clear();
    }
  }
  file.close();
  return tree;
}
