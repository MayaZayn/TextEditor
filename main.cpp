#include "source.cpp"

int main() {
    int option;
    char filename[151];
    cout << "Please enter the name of the text file you want to open:" << endl;
    cin >> filename;
    strcat_s(filename, ".txt");
    fstream database (filename, ios::in);

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
        else if (option == 11) {
            wordcount(filename);
        }
        else if (option == 12) {
            allUpper();
            printf("The contents of the file has been transformed to upper case!\n");
        }
        else if (option == 13) {
            tolower(fileContent);
            printf("The contents of the file has been transformed to lower case!\n");
        }
        else if (option == 14) {
            firstUpper();
            printf("First Caps Applied!\n");
        }
        else if (option == 15) {
            saveFileContent(filename);
        }
        else {
            cout << "Please choose a valid option!\n";
            sleep(2);
            // return main();      //needs something to handle wrong input of a different type like string
            continue;
        }

        cout << "\nWhat else do you want to do?\n\n";
        menu();
        cin.clear();
        cin >> option;
        cin.ignore();
    }
    cout << "Bye Bye User...\n";

    return 0;
}
