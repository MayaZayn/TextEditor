#ifndef MAIN_CPP_HEADER_H
#define MAIN_CPP_HEADER_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

void menu();
void loadFileContent(string);
void saveFileContent(string);

void addTxt(fstream&);
void displayContent(fstream&);
void emptyFile(char file[151]);
void encrypt(fstream&, char filename[151]);
void decrypt(fstream&, char filename[151]);
void mergeAnotherFile();
void countWords();
void countChars();
void countLines();
void searchWord();
void tolower(string&);

#endif //MAIN_CPP_HEADER_H
