#include "source.h" // he yells, still he runs

int main() {
    string option;
    char filename[151];
    cout << "Please enter the name of the text file you want to open:" << endl;
    cin >> filename;
    strcat_s(filename, ".txt");
    fstream database (filename, ios::in);

    if (database.fail()){
        database.open(filename, ios::app);
        cout << "This is a new file. I have created it for you.\nWhat do you want to do today?" << endl;
    }
    else{
        cout << "This file already exists.\nI have opened it for you.\nWhat do you want to do today?" << endl;
    }
    sleep(2);
    
    database.close();

    loadFileContent(filename);

    while (true){
        menu();
        cin.clear();
        cin >> option;
        cin.ignore();
        if (option == "1"){
            addTxt();
        }
        else if (option == "2"){
            displayContent();
        }
        else if (option == "3"){
            emptyFile(filename);
        }
        else if (option == "4"){
            encrypt();
        }
        else if (option == "5"){
            decrypt();
        }
        else if (option == "6"){
            mergeAnotherFile();
        }
        else if (option == "7"){
            countWords();
        }
        else if (option == "8"){
            countChars();
        }
        else if (option == "9"){
            countLines();
        }
        else if (option == "10"){
            searchWord();
        }
        else if (option == "11"){
            wordCount();
        }
        else if (option == "12") {
            allUpper();
        }
        else if (option == "13") {
            tolower(fileContent);
            printf("The contents of the file has been transformed to lower case!\n");
        }
        else if (option == "14") {
            firstUpper();
        }
        else if (option == "15") {
            saveFileContent(filename);
        }
        else if (option == "16") {
            break;
        }
        else {
            cout << "Please choose a valid option!\n";
            sleep(1);
            continue;
        }   

        cout << "\nWhat else do you want to do?\n\n";
        sleep(2);
    }
    cout << "Bye Bye User...\n"; // say bye bye
    sleep(2);
    return 0;
}
