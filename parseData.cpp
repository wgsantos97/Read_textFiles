#include <iostream>
#include <map> // A map will be used to count the words.
#include <fstream> // Will be used to read from a file.
#include <string> // The map's key value.
#include <stdio.h>

using namespace std;

int main(){
	static const char* fileName = "Interview.txt";

	// Will store the word and count.
	map<string, unsigned int> wordsCount;

	char replace[] = {'-', '_', '+', '=', '*', '&', '^', '%', '$', '#', '@', ';', ':', '\'', '"', ',', '.', '/', '<', '>', '(', ')', ' '};
	

        // Begin reading from file:
	ifstream fileStream(fileName);

        // Check if we've opened the file (as we should have).
	if(fileStream.is_open()){
		cout << "File opened." << endl;
		while (fileStream.good()){
                // Store the next word in the file in a local variable.
			string word;
			fileStream >> word;

                //Look if it's already there.
			for(int i=0; i<word.length(); i++){
				for(int j=0; j<23; j++){
					if(word[i] == replace[j]){
						cout << "Erased " << word[i] << endl;
						word.erase(i,1); //erase that character
					}
				}
			}
			if (wordsCount.find(word) == wordsCount.end()){ // Then we've encountered the word for a first time.
				wordsCount[word] = 1; // Initialize it to 1.
			}else{ // Then we've already seen it before..
				wordsCount[word]++; // Just increment it.
			}
		}
	}else{  // We couldn't open the file. Report the error in the error stream.
		cerr << "Couldn't open the file." << endl;
		return EXIT_FAILURE;
	}
	
        // Print the words map.
	for(map <string, unsigned int>::const_iterator it = wordsCount.begin(); it != wordsCount.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}
	
	return EXIT_SUCCESS;
}
