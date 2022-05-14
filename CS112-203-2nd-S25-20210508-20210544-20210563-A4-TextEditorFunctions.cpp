#include "CS112-203-2nd-S25-20210508-20210544-20210563-A4-TextEditorFunctions.h"

string fileContent = ""; // initialization to avoid unexpected values

void menu(){
    cout << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n";
    cout << "4. Encrypt the file content\n5. Decrypt the file content\n6. Merge another file\n";
    cout << "7. Count the number of words in the file.\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n";
    cout << "10. Search for a word in the file\n11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n";
    cout << "13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital)\n15. Save\n16. Exit\n";
}

void loadFileContent(string filename) { // appends a given file's contents
    fstream dataSource;                 // to the current content 
    
    dataSource.open(filename, ios::in);
    while (!dataSource.eof()) { // keep loading characters until end of file
        char chr = dataSource.get();
        if (chr != EOF) { // to avoid having EOF characters in the string
            fileContent += chr;
        }
    }

    dataSource.close();
}


/* menu functions */


void saveFileContent(string filename) {
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
    if (input == "" || input + ".txt" == filename) {        // if Enter is pressed or opened the same file
        dataTarget.open(filename, ios::out);                // open the same file and save in it
        dataTarget << fileContent;
        dataTarget.close();
        cout << "\nChanges have been saved to the same file!\n";
    }
    else {
        fstream dataTarget(input + ".txt", ios::in);        // open in read mode to check if file exist
        if (dataTarget.fail()) {                            // if file doesn't exist  
            printf("\nNew file has been created.\n");      
            dataTarget.open(input + ".txt", ios::app);      // create new file and save in it
            dataTarget << fileContent;
            dataTarget.close();
            printf("Changes have been saved!.\n");
        }
        else {                                              // if file exists in directory
            printf("\nThis text file already exists.\nChanges have been overwritten to this file\n");
            dataTarget.close();                             // close read mode
            dataTarget.open(input + ".txt", ios::out);      // open write mode and overwrite changes
            dataTarget << fileContent;
            dataTarget.close();
        }
    }
}

//uses takeInput function to add text until ctrl+z is pressed
void addTxt(){
    cout << "Enter the text you want to add to the file or ctrl + z to exit: " << endl;
    fileContent += takeInput();
}

//print out the contents of the file
void displayContent(){
    cout << fileContent;
}

//deletes the content in the file and gives the user a choice to whether delete the file itself or not
void emptyFile(char file[151]){
    fileContent = "";
    cout << "The contents of the file has been deleted successfully!";
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

//encrypts file content (increase the ascii code of the letter by one)
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

//decrypts file content (decrease the ascii code of the letter by one)
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
    fstream testFile;
    cout << "Enter name of the file: ";
    cin >> filename;
    filename += ".txt";
    testFile.open(filename, ios::app);
    if (testFile.fail()) {
        cout << "Could not open file.";
        return; // terminate if it does not exist
    }
    testFile.close();
    
    fileContent += '\n'; // to have the new content at the end of current content
    loadFileContent(filename);
    // since loadContent() appends given file's content to the current content
}   // it is enough to call it, and it will add the given content to the current 


void countWords() {
    int nWords = 0;

    for (int i = 0; i < fileContent.length(); i++) {
        if ((fileContent[i] != ' ' && fileContent[i] != '\n') && (
            fileContent[i + 1] == ' ' || fileContent[i + 1] == '\n' || fileContent[i + 1] == '\0'
            ) // if any non-space-non-newline is found to be
            ) // next to a space or a newline or end of string
        {     // then it is a word
            nWords++;
        }
    }
    cout << "Number of words: " << nWords << endl;
}



void countChars() {
    int nChars = 0;
    for (char chr : fileContent) {
        nChars++;
    }
    cout << "Number of characters: " << nChars << endl;
}


void countLines() {
    int nLines = 0;
    for (int i = 0; i <= fileContent.length(); i++) {
        if (fileContent[i] == '\n' || fileContent[i] == '\0') {
            nLines++; // if a newline or an end of string character is found
        }             // then it is the end of a line
    }
    cout << "Number of lines: " << nLines << endl;
}


void searchWord() {
   istringstream contentStream(fileContent); // fill a string stream with file contents
   string wantedWord, word;

   cout << "Enter a word to search for: ";
   cin >> wantedWord;
   tolower(wantedWord); // overloaded to work with string

   while (!contentStream.fail()) { // until end of stream
       
       contentStream >> word; // stream will separate each insert with a space/newline
                              // so each word will be taken separately
       tolower(word);       
       if (wantedWord == word) {
           cout << "Word was found.\n";
           return; // terminate function
       }
   }

   cout << "Word was not found.\n";
}


void allUpper() {
    for (char& chr : fileContent) {         // make every char uppercase
        chr = toupper(chr);
    }
    printf("The contents of the file has been transformed to upper case!\n");
}

void firstUpper() {
    tolower(fileContent);       // turns entire string to lower
    fileContent[0] = toupper(fileContent[0]);       // makes first letter Cap
    for (int i = 0; i <= fileContent.length(); i++) {
        if (fileContent[i] == ' ' || fileContent[i] == '\n') {
            fileContent[i + 1] = toupper(fileContent[i + 1]);   // if a space or newline is found
        }                                                       // the character after it is turned Cap
    }
    printf("First Caps Applied!\n");
}


void wordCount() {
    vector<string> arr;                 // vector to store each word individually
    int count = 0; string word, temp = "";
    for (int i = 0; i <= fileContent.length(); i++) {       // loop to find each word
        if (fileContent[i] != ' ' && fileContent[i] != '\n' && fileContent[i] != '\0')
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


void tolower(string& str) {
    for (char& chr : str) {
        chr = towlower(chr);
    }
}



/* other functions */

string takeInput() {
	string input;
	char chr;
	while (true) { // keep taking input until break
        chr = (char)_getch();
        if ((int)chr == 26) { // ascii of '^Z'
            break;            // break on ctrl+z 
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
        if ((int)chr == 13) { // if input is a newline
            cout << endl;     // print newline
            input += '\n';    // add newline to input
            continue;
        }
        input += chr;
        cout << chr; // to display what _getch() have caught
	}
	cout << endl;

	return input;
}

