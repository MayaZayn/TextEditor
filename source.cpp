#include "source.h"

string fileContent = "";

void menu(){
    cout << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n";
    cout << "4. Encrypt the file content\n5. Decrypt the file content\n6. Merge another file\n";
    cout << "7. Count the number of words in the file.\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n";
    cout << "10. Search for a word in the file\n11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n";
    cout << "13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital)\n15. Save\n16. Exit\n";
}

void loadFileContent(string filename) {
    fstream dataSource;

    dataSource.open(filename, ios::in);
    while (!dataSource.eof()) {
        char chr = dataSource.get();
        if (chr != EOF) { // to avoid having multiple eof characters
            fileContent += chr;
        }
    }

    dataSource.close();
}


/* menu functions */


void saveFileContent(string filename) { // ambigouos function @_@
    fstream dataTarget;
    printf("Enter a new file name or press enter to save on the same file\n");
    char chr; string input;
    while (true) {
        chr = getch();
        if (chr == 13) {                 //ascii of \n
            break;
        }
        if ((int)chr == 8) {             // ascii of Backspace
            if (input.length() < 1 || input[input.length() - 1] == '\n') { // to avoid unwanted erasing
                continue;
            }                            
			cout << '\b' << ' ' << '\b'; // '\b' pushes the cursor 1 step back
                                         // and then ' ' erases the last character
            
            input.pop_back();            // erase from actual input
			continue;
        }
        input += chr;
        cout << chr;
    }
    if (input == "") {                          // if Enter is pressed
        dataTarget.open(filename, ios::out);    // open the same file and save in it
        dataTarget << fileContent;
        dataTarget.close();
        cout << "Changes have been saved to the same file!\n";
    }
    else {                                              // save to new file with the name entered
        printf("\nNew file has been created.\n");
        dataTarget.open(input + ".txt", ios::app);
        dataTarget << fileContent;
        dataTarget.close();
        printf("Changes have been saved!.\n");
    }
}

void addTxt(){
    //needs to work on something other than the external console and to delete the ctrl+z symbol
    string txt;
    cout << "Enter the text you want to add to the file or ctrl + z + enter to exit: " << endl;
    getline(cin >> ws, txt, '\0');
    fileContent += txt + '\n';
}

void displayContent(){
    cout << fileContent;
}

void emptyFile(char file[151]){
    char ans;
    cout << "\nDo you want to delete the file itself? (y/n)\n"; // this option contradicts with
    cin >> ans; ans = tolower(ans);                             // save-at-end mechanism???
    if (ans == 'y'){                                            // not sure though...
        int status = remove(file);
        if(status==0)
            cout<<"\nFile Deleted Successfully!\n";
        else
            cout<<"\nError Occurred!";
    }
    else        //this does not empty the file yet. 
        cout << "\nThe file is empty now but not deleted!\n";
    cout<<endl;
}

void encrypt(){
    for (char & i : fileContent) {
        if (i == 'z')
            i = 'a';
        else if (i == 'Z')
            i = 'A';
        else
            i += 1;
    }
    cout << "\nFile contents have been encrypted!\n";
}
void decrypt(){
    for (char & i : fileContent) {
        if (i == 'a')
            i = 'z';
        else if (i == 'A')
            i = 'Z';
        else
            i -= 1;
    }
    cout << "\nFile contents have been decrypted!\n";
}

void mergeAnotherFile() {
    string filename;
    
    cout << "Enter name of the file: ";
    cin >> filename;
    loadFileContent(filename);
}

void countWords() { 
    int nWords = 0;

    for (int i = 0; i < fileContent.length(); i++) {
        if ((fileContent[i] != ' ' && fileContent[i] != '\n') && (
            fileContent[i + 1] == ' ' || fileContent[i + 1] == '\n' || fileContent[i + 1] == '\0'
            )
            )
        {
            nWords++;
        }
    }
    cout << "Number of words: " << nWords << endl;
}



void countChars() {
    int nChars;
    for (char chr : fileContent) {
        nChars++;
    }
    cout << "Number of charctars: " << nChars << endl;
}


void countLines() {
    int nLines = 0;
    for (int i = 0; i <= fileContent.length(); i++) {
        if (fileContent[i] == '\n' || fileContent[i] == '\0') {
            nLines++;
        }
    }
    cout << "Number of lines: " << nLines << endl;
}


void searchWord() {
   istringstream contentStream(fileContent);
   string wantedWord, word;

   cout << "Enter a word to search for: ";
   cin >> wantedWord;
   tolower(wantedWord); // overloaded to work with string

   while (!contentStream.fail()) {
       contentStream >> word;
       tolower(word);
       if (wantedWord == word) {
           cout << "Word was found.\n";
           return;
       }
   }

   cout << "Word was not found.\n";
}


void allUpper() {
    for (char& chr : fileContent) {         // make every char uppercase
        chr = toupper(chr);
    }
}

void firstUpper() {
    tolower(fileContent);       // turns entire string to lower
    fileContent[0] = toupper(fileContent[0]);       // make first letter Cap
    for (int i = 0; i <= fileContent.length(); i++) {
        if (fileContent[i] == ' ' || fileContent[i] == '\n') {
            fileContent[i + 1] = toupper(fileContent[i + 1]);   // if a space or newline is found
        }                                                       // the character after it is turned Cap
    }
}




void wordcount() {
    vector<string> arr;                 // vector to store each word individually
    int count = 0; string word, temp = "";
    for (int i = 0; i <= fileContent.length(); i++) {       // loop to find each word
        if (fileContent[i] != ' ' && fileContent[i] != '\n')
            temp += fileContent[i];
        else {
            tolower(temp);              // store it in lower case
            arr.push_back(temp);
            temp = "";                  // reset the value of temp to store another word
        }
    }
    
    printf("Enter word to count the number of times it occurs in the text: ");
    cin >> word;
    cout << "The count of the word " << word << " is: ";
    tolower(word);                      // to lower the wanted word to match it with
    for (string st : arr) {             // loop on vector
        if (st == word)                 // add 1 to count if the index = word
            count++;
    }
    cout << count << " times!\n";
}



/* other functions */

void tolower(string& str) {
    for (char& chr : str) {
        chr = towlower(chr);
    }
}

string takeInput() { // in case someone fancy using it
	string input;    // just like cleanStream() ;=;
	char chr;
	while (true) { 
        chr = (char)_getch();
        if ((int)chr == 26) { // ascii of '^Z'
            break;
        }
		if ((int)chr == 8) { // ascii of Backspace
            if (input.length() < 1 || input[input.length() - 1] == '\n') { 
                continue; // to avoid unwanted erasing
            }                            
			cout << '\b' << ' ' << '\b'; // '\b' pushes the cursor 1 step back
                                         // and then ' ' erases the last character
            
            input.pop_back(); // erase from actual input
			continue;
        }
        if ((int)chr == 13) {
            cout << endl;
            input += '\n';
            continue;
        }
        input += chr;
        cout << chr;
	}
	cout << endl;

	return input;
}

