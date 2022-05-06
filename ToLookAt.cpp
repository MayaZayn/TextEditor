#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <conio.h>

using namespace std;

string fileContent = "";

// _______Text Editor_______
void loadFileContent(string);
void saveFileContent(string);
void mergeAnotherFile();
void countWords();
void countChars();
void countLines();
void searchWord();
void tolower(string&);

int main() {


    // loadFileContent("delme");
    // countWords();
    // countChars();
    // countLines();
    // searchWord();
    // mergeAnotherFile();
    // cout << fileContent;
    // saveFileContent("delme");
}


void loadFileContent(string filename) {
    fstream dataSource;

    dataSource.open(filename + ".txt", ios::in);
    while (!dataSource.eof()) {
        char chr = dataSource.get();
        if (chr != EOF) { // to avoid having multiple eof characters
            fileContent += chr;
        }
    }

    dataSource.close();
}

void saveFileContent(string filename) {
    fstream dataTarget;
    dataTarget.open(filename + ".txt", ios::out);

    dataTarget << fileContent;

    dataTarget.close();
}

void mergeAnotherFile() {
    string filename;
    cout << "Enter name of the file: ";
    cin >> filename;
    loadFileContent(filename);
}

void countWords() { // 100% accuracy
    int nWords = 0;

    for (int i = 0; i < fileContent.length(); i++) {
        if (fileContent[i] != ' ' && fileContent[i] != '\n' && (
            fileContent[i+1] == ' ' || fileContent[i+1] == '\n' || fileContent[i+1] == '\0')
            ) {
            nWords++;
        }
    }

    // for (char chr : fileContent) { // not that accurate...
    //     if (chr == ' ' || chr == '\n') {
    //         nWords++;
    //     }
    // }
    cout << nWords;
}



void countChars() {
    int nChars;
    for (char chr : fileContent) {
        nChars++;
    }
    cout << nChars;
}


void countLines() {
    int nLines = 0;
    for (int i = 0; i <= fileContent.length(); i++) {
        if (fileContent[i] == '\n' || fileContent[i] == '\0') {
            nLines++;
        }
    }
    cout << nLines;
}


void searchWord() {
    istringstream sstream(fileContent);
    string wantedWord, word;
    bool isFound = false;

    cout << "Enter a word to search for: ";
    cin >> wantedWord;
    tolower(wantedWord); // overloaded to work with string

    while (!sstream.fail()) {
        sstream >> word;
        tolower(word);
        if (wantedWord == word) {
            isFound = true;
            break;
        }
    }

    if (isFound) {
        cout << "Word was found.\n";
    }
    else {
        cout << "Word was not found.\n";
    }
}

void tolower(string& str) {
    for (char& chr : str) {
        chr = towlower(chr);
    }
}