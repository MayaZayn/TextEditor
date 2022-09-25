#ifndef MAIN_CPP_SOURCE_H
#define MAIN_CPP_SOURCE_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>
#include <sstream>
#include <vector>

using namespace std;

extern string fileContent;
extern string fileName;

void menu();
void loadFileContent(string);
string takeInput();
void addTxt();
void displayContent();
void emptyFile();
void encrypt();
void decrypt();
void mergeAnotherFile();
void countWords();
void countChars();
void countLines();
void searchWord();
void searchWord_old(); // depricated 
void wordCount();
void allUpper();
void tolowerFileContent();
void firstUpper();
void tolower(string&);
void saveFileContent();

#endif //MAIN_CPP_SOURCE_H
