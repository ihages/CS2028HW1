#include <string>

struct BookInfo {
public:
	std::string title;
	std::string firstName;
	std::string lastName;
	int wordCount;
	double letterFrequency[26];
	int lineCount;
};
