#include <iostream>	
#include <string>

using namespace std;

int main() {

	string englishText;
	cout << "This program will replace the most frequently occuring letter from your input with '-' dashes." << endl;
	cout << "If no letter occurs most frequently, the letter that comes first in the alphabet will be dashed." << endl;
	cout << "Input some text to see this for yourself: ";
	getline(cin, englishText);

	char mostFrequentLetter = 'a';
	int topOccurCount = 0;
	for (char currentLetter = 'a'; currentLetter <= 'z'; ++currentLetter) {
		int counter = 0;
		//cout << "run: " << currentLetter << " counter: " << counter << endl;
		for (auto i : englishText) {
			if (i == currentLetter || i == (currentLetter - 32)) {
				++counter;
			}
		}
		if (counter == topOccurCount) {
			if (currentLetter < mostFrequentLetter) {
				mostFrequentLetter = currentLetter;
			}
		}
		else if (counter > topOccurCount) {
			mostFrequentLetter = currentLetter;
			topOccurCount = counter;
		}
	}
	cout << mostFrequentLetter << endl;
	for (auto i : englishText) {
		if (i == mostFrequentLetter || i == (mostFrequentLetter - 32)) {
			i = '-';
		}
		cout << i;
	}
	cout << endl;

	return 0;
}
