#include "source.h"

int main() {
    string option;
    char filename[151];
    cout << "Please enter the name of the text file you want to open:" << endl;
    cin >> filename;
    strcat_s(filename, ".txt");
    fstream database(filename, ios::in);
    if (database.fail()){
        database.open(filename, ios::app);
        cout << "This is a new file. I have created it for you.\nWhat do you want to do today?" << endl;
        // there should be a sleep here
    }
    else{
        cout << "This file already exists.\nI have opened it for you.\nWhat do you want to do today?" << endl;
        // there should be a sleep here
    }
    // cin.ignore();
    database.close();

    loadFileContent(filename);

    while (true) {
        menu();
        cin >> option;
        if (option == "1") {   // there's a problem here in the loop that returns to the menu
            addTxt();          // FIXED
        }
        else if (option == "2"){
            displayContent();
        }
        else if (option == "3"){
            fileContent = "";
            cout << "The contents of the file has been deleted successfully!";
            emptyFile(filename);
        }
        else if (option == "4"){
            encrypt();
        }
        else if (option == "5"){
            decrypt();
        }
        else if (option == "15"){
            saveFileContent(filename);
        }
        else if (option == "16") {
            cout << "Bye Bye User...";
            break;
        }
        
        else {
            cout << "Please choose a valid option!\n";
            // there should be a sleep here
            // return main();      //needs something to handle wrong input of a different type like string
            continue;             
        }                      

        cout << "\nWhat else do you want to do?\n\n";
        // there should be a sleep here
    }


    return 0;
}
