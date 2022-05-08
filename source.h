#ifndef MAIN_CPP_SOURCE_H
#define MAIN_CPP_SOURCE_H
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>

using namespace std;

extern string fileContent;

void menu();
void loadFileContent(string);
void saveFileContent(string);

void addTxt();
void displayContent();
void emptyFile(char file[151]);
void encrypt();
void decrypt();
void mergeAnotherFile();
void countWords();
void countChars();
void countLines();
void searchWord();
void tolower(string&);
#endif //MAIN_CPP_SOURCE_H
