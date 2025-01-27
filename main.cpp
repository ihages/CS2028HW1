#include<iostream>
#include<fstream>

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

    struct BookInfo{
        public:
            std::string title;
            std::string firstName;
            std::string lastName;
            int wordCount;
            int letterFrequency;
            int lineCount;
     };

    BookInfo bookInfo;
    
    getline(textFile, bookInfo.title);
    textFile >> bookInfo.firstName;
    textFile >> bookInfo.lastName;

    outputFile << "Book Title: " << bookInfo.title << std::endl;
    outputFile << "Author Name: " << bookInfo.firstName << " " << bookInfo.lastName << std::endl;
    outputFile << "First Name: " << bookInfo.firstName << std::endl;
    outputFile << "Last Name: " << bookInfo.lastName << std::endl;


     


    

    textFile.close();
    outputFile.close();
/*
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
		
*/

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
