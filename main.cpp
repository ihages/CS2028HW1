#include<iostream>
#include<fstream>

int main() {
	std::string fileName;
	std::cout << "What is the file you wish to open?" << std::endl;
	std::cin >> fileName;
	std::ifstream textFile(fileName);

	if (textFile) {
		std::cout << "Opening file..." << std::endl;

		//array that has 26 slots//
		std::string bookTitle;
		std::string firstName;
		std::string lastName;

		textFile >> bookTitle;
		textFile >> firstName;
		textFile >> lastName;

		//editing file
		


		int letterArray[26] = { 0,0,0,0,0,0,0,0,
								0,0,0,0,0,0,0,0,
								0,0,0,0,0,0,0,0,
								0,0 };

		int letterCount{ 0 };

		char character;
		while (textFile.get(character)) {
			int letterInt = character - 'a';
			letterArray[letterInt]++;
			letterCount++;
		}
		
		std::cout << "the letter A occurred " << letterArray[0] << " imes out of " << letterCount << " letters"''
	}
	else {
		std::cout << "The file was not able to be openned." << std::endl;
		return 0;
	}
	

	return 0;
}
