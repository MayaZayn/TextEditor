#ifndef MAIN_CPP_SOURCE_H
#define MAIN_CPP_SOURCE_H

#include <string> // C++ string definition 

extern string fileContent;
extern string fileName;

void menu();
void loadFileContent(std::string);
std::string takeInput();
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
void tolower(std::string&);
void saveFileContent();

void hold_screen(int); // for ms

#endif //MAIN_CPP_SOURCE_H
