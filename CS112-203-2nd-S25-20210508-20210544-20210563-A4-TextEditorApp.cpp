#include "CS112-203-2nd-S25-20210508-20210544-20210563-A4-TextEditorFunctions.h"

using namespace std;

int main() {
    int option;
    char filename[151];

    std::cout << "Please enter the name of the text file you want to open:" << endl;
    cin >> filename;
    strcat_s(filename, ".txt");
    fstream database(filename, ios::in);

    if (database.fail()) {
        database.open(filename, ios::app);
        std::cout << "This is a new file. I have created it for you."
            << "\n------------------------------\nWhat do you want to do today ? "
            << endl;
    }
    else {
        std::cout << "This file already exists.\n"
            << "I have opened it for you.\n------------------------------\n"
            << "What do you want to do today ? " << endl;
    }

    database.close();

    fileName = filename;

    loadFileContent(filename);

    void (*menuFunctions[16])(void) = { // first element is neglected 
        nullptr, addTxt, displayContent, emptyFile,
        encrypt, decrypt, mergeAnotherFile, countWords,
        countChars, countLines, searchWord, wordCount,
        allUpper, tolowerFileContent, firstUpper, saveFileContent
    };

    while (true) {
        menu();
        cin.clear();
        cin >> option;
        cin.ignore();

        if (option == 16) {
            break;
        }

        if (option < 1 || option > 15) {
            std::cout << "Wrong Input.\nTry Again.\n\n";
            continue;
        }

        (*menuFunctions[option])();

        std::cout << "\n-----------------------------";
        std::cout << "\nWhat else do you want to do?\n\n";
    }
    std::cout << "Bye Bye User...\n";
    // sleep(2);
    return 0;
}
