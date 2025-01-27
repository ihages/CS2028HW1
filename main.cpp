#include<iostream>
#include<fstream>
#include<string>

struct BookInfo{
	public:
		std::string title;
		std::string firstName;
		std::string lastName;
		int wordCount;
		int letterFrequency;
		int lineCount;
};

//working notes: look to turn current main funtion into a void and re-write the main funtion to prompt user to input a first book and then the second book if they wish//

int main() {
	std::string fileName;
	std::cout << "What is the file you wish to open?" << std::endl;
	std::cin >> fileName;
	std::ifstream textFile(fileName);
	std::ofstream outputFile("CardCatalog.txt");
    
	if (textFile.fail()){
		std::cout << "Failed to open file" << std::endl;
		exit(0);
    	} else {
		std::cout << "Worked!" << std::endl;
    	}

	//calling on the structure//
	BookInfo bookInfo;
	    
	getline(textFile, bookInfo.title);
	textFile >> bookInfo.firstName;
	textFile >> bookInfo.lastName;
	textFile >> currWord;

	/*
    std::streampos currPos = textFile.tellg();
    //std::cout << currPos;
	while(textFile >> currWord){
		bookInfo.wordCount++;
	}

    textFile.seekg(currPos);

    while(getline(textFile, currWord)){
        bookInfo.lineCount++;
        getline(textFile, currWord);
        outputFile << currWord;
    }
	*/
	
	outputFile << "Book Title: " << bookInfo.title << std::endl;
	outputFile << "Author Name: " << bookInfo.firstName << " " << bookInfo.lastName << std::endl;
	outputFile << "First Name: " << bookInfo.firstName << std::endl;
	outputFile << "Last Name: " << bookInfo.lastName << std::endl;

	std::string contentsLine;
	getline(textFile, contentsLine);
	textFile>>contentsLine;

	//portion of the program that prompts the reader if they want to see the letter frequencies//
	std::cout << "Would you like the frequencies of each letter? y/n ";
	char freqPrompt;
	std::cin >> freqPrompt;
	if (freqPrompt == 'y') {
		//program for letter frequencies//
		int letterArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		char letCharArray[26] = { 'a','b','c','d','e','f','g','h','i','j',
			'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		int letterCount{ 0 };
		char character{ 0 };
		//int charInt = static_cast<int>(character) - 'a';
		while (textFile.get(character)) {
			char lowerChar = std::tolower(character);
			if (!(isspace(lowerChar)||ispunct(lowerChar))) {
				letterArray[(lowerChar-'a')]++;
				std::cout << "increased " << lowerChar << std::endl;
				letterCount++;
			}
		}
		for (int ct = 0; ct < 26; ct++) {
			character = ct; 
			double frequency = 100.00 * static_cast<double>(letterArray[character]) / static_cast<double>(letterCount);
			std::cout << letCharArray[ct] << ": " << frequency << "%" << std::endl;
		}
	}else if (freqPrompt != 'n') {
		std::cout << "invalid response. Please exit the program and try again." << std::endl;
	}
	else if (freqPrompt == 'n') {
		std::cout << "alright, no frequencies for you!" << std::endl;
	}
	   
	textFile.close();
   	outputFile.close();

	return 0;
}
