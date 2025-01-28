#include<iostream>
#include<fstream>
#include<string>

struct BookInfo {
public:
	std::string title;
	std::string firstName;
	std::string lastName;
	int wordCount;
	int letterFrequency;
	int lineCount;
};


void bookCat(std::ifstream& textFile, std::ofstream& outputFile);
void letterFreq(char, std::string);

int main() {
	std::ofstream outputFile("CardCatalog.txt", std::ios::app);
	char promptAnother = 'y';

	while (promptAnother == 'y') {
		std::string fileName;
		std::ifstream textFile;

		std::cout << "What is the file you wish to open?" << std::endl;
		std::cin >> fileName;

		textFile.open(fileName);

		if (textFile.fail()) {
			while (textFile.fail()) {
				std::cout << "Failed to open file." << std::endl;
				std::cout << "What is the file you wish to open?" << std::endl;
				std::cin >> fileName;
				textFile.open(fileName);
			}
		}

		bookCat(textFile, outputFile);

		std::cout << "Would you like the frequencies of each letter? y/n " << std::endl;
		char promptFreq;
		std::cin >> promptFreq;

		letterFreq(promptFreq, fileName);

		std::cout << "Would you like to catalog another book? y/n " << std::endl;
		std::cin >> promptAnother;
	} 

	outputFile.close();

	return 0;
}

void bookCat(std::ifstream &textFile, std::ofstream& outputFile) {

	//calling on the structure//
	BookInfo bookInfo;

	getline(textFile, bookInfo.title);
	textFile >> bookInfo.firstName;
	textFile >> bookInfo.lastName;

	outputFile << "Book Title: " << bookInfo.title << std::endl;
	outputFile << "Author Name: " << bookInfo.firstName << " " << bookInfo.lastName << std::endl;
	outputFile << "First Name: " << bookInfo.firstName << std::endl;
	outputFile << "Last Name: " << bookInfo.lastName << std::endl;

	outputFile << std::endl;

	textFile.close();
}

void letterFreq(char freqPrompt, std::string fileName){
	
	std::ifstream textFile(fileName);

	//portion of the program that prompts the reader if they want to see the letter frequencies//

	if (freqPrompt == 'y') {

		//ignores empty lines//
		std::string line;
		while (line == "") {
			getline(textFile, line);
		}

		//ignores line that says "Contents:"
		std::string contentsLine;
		getline(textFile, contentsLine);
		textFile >> contentsLine;

		//program for letter frequencies//
		int letterArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		char letCharArray[26] = { 'a','b','c','d','e','f','g','h','i','j',
			'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		int letterCount{ 0 };
		char character{ 0 };
		//int charInt = static_cast<int>(character) - 'a';
		while (textFile.get(character)) {
			char lowerChar = std::tolower(character);
			if (islower(lowerChar)) {
				letterArray[(lowerChar - 'a')]++;
				letterCount++;
			}
		}
		for (int ct = 0; ct < 26; ct++) {
			character = ct;
			double frequency = 100.00 * static_cast<double>(letterArray[character]) / static_cast<double>(letterCount);
			std::cout << letCharArray[ct] << ": " << frequency << "%" << std::endl;
		}
	}
	else if (freqPrompt != 'n') {
		std::cout << "invalid response has been assumed to be a 'no'" << std::endl;
	}
	else if (freqPrompt == 'n') {
	}

	textFile.close();
}
