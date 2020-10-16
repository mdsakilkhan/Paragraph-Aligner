#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int width, longestWord, lineWidth, turns;
    string inputText, finalText, format, tempWord, line;
    vector<string> allText, allTextdup;
        
	while (true) { 
        cout << "> ";
        getline (cin, inputText);
        
		if (inputText == "") { 
			break; 
		}
		
		if ((inputText.size() - 1) != inputText.find_last_of(" ")) {		// This process adds a space at the end of the each getline 
			inputText = inputText + " ";					// to make sure that the last word of one line and the first 
		}									// word of the next line are seperated.	
		
		if ((inputText.size() - 1) == inputText.find_last_of(" ")) {
			inputText = inputText;
		}
		
		finalText.insert(finalText.size(), inputText);				// This add all the getlines strings into one large string.
    }
	
    while (true) {
        tempWord = "";									// Here the letters between spaces are considered a temporary 
		tempWord.append(finalText, 0, finalText.find(" "));			// word which then is added to a vector.
        
		allText.push_back (tempWord);
        finalText.replace(0, finalText.find(" ")+1, "");
        
		if (finalText == "") { 
			break; 
		}
		
		else {
			continue;
		}
    }
	
	longestWord = 0;														
	
	for (int i = 0; i < allText.size(); ++i) {					// This will find the size of longest word in the whole text
		if (longestWord <= allText[i].size()) {					// which wil be needed later on.
			longestWord = allText[i].size();
		}
		
		else {
			longestWord = longestWord;
		}
	}

	while (true) {									// A big loop for the whole paragraph.
		cout << "Enter left|right|center and paragraph width: ";
		cin >> format >> width;
		
		if (width == 0) { 
			break; 
		}
		
		if (width < longestWord) {
			cout << "Paragraph width too small to fit the longest word of size " << longestWord << "..." << endl;
			continue;
        }
		
		if (format == "left" || format == "right" || format == "center") {
			for (int i = 0; i < (width / 10); ++i) {
				cout << "+";
				cout << "---------";
			}
			
			cout << "+";
			
			for (int i = 0; i < (width % 10); ++i) {
				cout << "-";
				}        
			
			cout << "+" << endl;
		}

		else {
			cout << "Invalid justification command..." << endl;
			continue;
		}
	
		allTextdup = allText;							// This duplicate vector can be changed without changing the original.
		
		while (true) {								// A loop for the lines.									
			if (allTextdup.size() == 0) { 
				break; 
			}
			
			line = "";							// The line variable will be the series of words that can fit in a line.
			lineWidth = width;						// This variable represents the amount of space left in a line.
			turns = allTextdup.size();
			
			while (true) {							// A loop for each word.
				if (allTextdup[0].size() <= lineWidth) {
					line.append(allTextdup[0]);	
					lineWidth = lineWidth - allTextdup[0].size();
					allTextdup.erase(allTextdup.begin());		// This takes out the fisrt string in the vector so that the next word is allTextdup[0].
					turns = turns - 1;				// The turns makes sure that the loop runs for every word.
				}
				
				else { 
					break; 
				}
				
				if (turns == 0) {
					break;
				}
				
				if (allTextdup[0].size() < lineWidth) {
					line = line + " ";
					lineWidth = lineWidth - 1;
				}			
				
				else { 
					break; 
				}
			}
			
			if (format == "left") {
				for (int i = 0; i < lineWidth; i++) {
					line.append(" ");				// Adds spaces at the end.
				}
			}
			
			if (format == "right") {
				for (int i = 0; i < lineWidth; i++) {
					line.insert(0, " "); 				// Adds spaces at the beginning.
				}
			}
            
			if (format == "center") {
                for (int i = 0; i < ceil(lineWidth / 2.0); i++) {
					line.append(" "); 
				}
				
				for (int i = 0; i < floor(lineWidth / 2.0); i++) {
					line.insert(0, " "); 
				}
			}
		
			cout << "|" << line << "|" << endl;
		}
		
		for (int i = 0; i < (width / 10); i++) {
            cout << "+";
            cout << "---------";
		}
        
		cout << "+";
        
		for (int i = 0; i < width % 10; i++) {
            cout << "-";
		}        
        
		cout << "+" << endl;
		continue;
	}
	
	cout << "Bye..." << endl;
	
	return 0;
}
