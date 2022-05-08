#include "source.h"

int main() {
    int option;
    char filename[151];
    cout << "Please enter the name of the text file you want to open:" << endl;
    cin >> filename;
    strcat_s(filename, ".txt");
    fstream database (filename);
    if (database.fail()){
        database.open(filename, ios::app);
        cout << "This is a new file. I have created it for you.\nWhat do you want to do today?" << endl;
        menu();
        cin >> option;
    }
    else{
        cout << "This file already exists.\nI have opened it for you.\nWhat do you want to do today?" << endl;
        menu();
        cin >> option;
    }
    cin.ignore();
    database.close();

    loadFileContent(filename);

    while (option != 16){
        if (option == 1){   //there's a problem here in the loop that returns to the menu
            addTxt();
        }
        else if (option == 2){
            displayContent();
        }
        else if (option == 3){
            fileContent = "";
            cout << "The contents of the file has been deleted successfully!";
            emptyFile(filename);
        }
        else if (option == 4){
            encrypt();
        }
        else if (option == 5){
            decrypt();
        }
        else if (option == 15){
            saveFileContent(filename);
        }
        else {
            cout << "Please choose a valid option!\n";
            return main();      //needs something to handle wrong input of a different type like string
        }                       // you could use char type instead (Kilany)
        database.close();

        cout << "\nWhat else do you want to do?\n\n";
        menu();
        cin >> option;
    }


    return 0;
}
