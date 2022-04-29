#include<stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void menu();
void addTxt(fstream&);
void displayContent(fstream&);
void emptyFile(char file[151]);
void encrypt(fstream&, char filename[151]);
void decrypt(fstream&, char filename[151]);

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

    while (option != 16){
        if (option == 1){   //there's a problem here in the loop that returns to the menu
            database.open(filename, ios::app);
            addTxt(database);
            database.close();
        }
        else if (option == 2){
            database.open(filename, ios::in);
            displayContent(database);
            database.close();
        }
        else if (option == 3){
            database.open(filename, ios::out);
            database.close();
            cout << "The contents of the file has been deleted successfully!";
            emptyFile(filename);
        }
        else if (option == 4){
            database.open(filename);
            encrypt(database, filename);
            database.close();
        }
        else if (option == 5){
            database.open(filename);
            decrypt(database, filename);
            database.close();
        }
        else {
            cout << "Please choose a valid option!\n";
            return main();      //needs something to handle wrong input of a different type like string
        }
        database.close();

        cout << "\nWhat else do you want to do?\n\n";
        menu();
        cin >> option;
    }


    return 0;
}

void menu(){
    cout << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n";
    cout << "4. Encrypt the file content\n5. Decrypt the file content\n6. Merge another file\n";
    cout << "7. Count the number of words in the file.\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n";
    cout << "10. Search for a word in the file\n11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n";
    cout << "13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital)\n15. Save\n16. Exit\n";
}

void addTxt(fstream& file){
    //needs to work on something other than the external console and to delete the ctrl+z symbol
    string txt;
    cout << "\nEnter the text you want to add to the file or ctrl + z + enter to exit: " << endl;
    getline(cin >> ws, txt, '\0');
    file << txt << endl;
}

void displayContent(fstream& file){
    char sentence[151];
    file.getline(sentence, 151);
    while (!file.eof()){
        cout << sentence << endl;
        file.getline(sentence, 151);
    }
}

void emptyFile(char file[151]){
    char ans;
    cout << "\nDo you want to delete the file itself? (y/n)\n";
    cin >> ans; ans = tolower(ans);
    if (ans == 'y'){
        int status = remove(file);
        if(status==0)
            cout<<"\nFile Deleted Successfully!\n";
        else
            cout<<"\nError Occurred!";
    }
    else
        cout << "\nThe file is empty now but not deleted!\n";
    cout<<endl;
}

void encrypt(fstream& file, char filename[151]){
    string content;
    while (!file.eof()) {
        if (file.peek() != EOF)
            content += (char)file.get();
    }
    for (char & i : content) {
        if (i == 'z')
            i = 'a';
        else if (i == 'Z')
            i = 'A';
        else
            i += 1;
    }
    file.close();
    file.open(filename, ios::out);
    file << content;
    cout << "\nFile contents have been encrypted!\n";
}
void decrypt(fstream& file, char filename[151]){
    string content;
    while (!file.eof()) {
        if (file.peek() != EOF)
            content += (char)file.get();
    }
    for (char & i : content) {
        if (i == 'a')
            i = 'z';
        else if (i == 'A')
            i = 'Z';
        else
            i -= 1;
    }
    file.close();
    file.open(filename, ios::out);
    file << content;
    cout << "\nFile contents have been decrypted!\n";
}