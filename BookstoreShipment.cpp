// BookstoreShipment.cpp -- Build a report based on a loaded list of books in a shipment
//CSIS 212-<D02_202440>

//transform() logicin BooksReceived.cpp derived from https://www.geeksforgeeks.org/how-to-convert-std-string-to-lower-case-in-cpp/
//Sorting logic in BooksReceived.cpp derived from textbook chapter 16-1c pseudocode

//Include and namespace statements
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "BooksReceived.h"

using namespace std;

//Function Prototypes
string requestUserFileInput();
bool validateNotEmptyString(string& strToTest);
string changeWhitespaceToNull(string& str);

//Main function
int main()
{
	cout << "Zachary Seeley -- Lab 3 - Vectors and Sorting" << endl << endl << endl;

	ifstream inputFile;
	string file, nameBookstore, dateOfShipment, bookTitle;
	int numberHardbound, numberPaperback;

	//Request filename from user
	file = requestUserFileInput();
		
	//open requested file and validate if open
	//read data into appropriate variables and validate correct entries
	//exit program if not valid input
	inputFile.open(file);
	if (!inputFile.is_open())
	{
		cout << "The file path is wrong or the file does not exist." << endl
			<< "Verify entry is correct including file extension and try again." << endl;

		system("pause");
		return 0;
	}

	if (!getline(inputFile, nameBookstore))
	{
		cout << "Error reading bookstore name. Verify file contains correct data and try again." << endl;

		system("pause");
		return 0;
	}

	if (!getline(inputFile, dateOfShipment))
	{
		cout << "Error reading date of shipment. Verify file contains correct data and try again." << endl;

		system("pause");
		return 0;
	}

	inputFile >> numberHardbound;
	if (inputFile.fail() || numberHardbound < 0)
	{
		cout << "Value for hardbound books is not numeric, less than 0, or missing." << endl
			<< "Verify file contains correct data and try again." << endl;
		
		system("pause");
		return 0;
	}

	inputFile >> numberPaperback;
	if (inputFile.fail() || numberPaperback < 0)
	{
		cout << "Value for paperback books is not numeric, less than 0, or missing." << endl
			<< "Verify file contains correct data and try again." << endl;

		system("pause");
		return 0;
	}

	//Create BooksReceived object using the four argument constructor
	BooksReceived booksReceived(nameBookstore, dateOfShipment, numberHardbound, numberPaperback);

	//Loop through input file while not end of field
	// If next book entry is blank, discard input
	// If next book entry is greater than 35 characters, display error message and exit program
	// If next book entry is valid, use addBook() in BooksReceived to add book to books vector
	while (getline(inputFile, bookTitle))
	{
		if (bookTitle == "")
			continue;
		else if (bookTitle.length() > 35)
		{
			cout << "A book title is longer than 35 characters." << endl
				<< "Shorten the book title(s) or remove from file and try again." << endl;

			system("pause");
			return 0;
		}
		else
			booksReceived.addBook(bookTitle);
	}

	//Validate input file follows the business requirement of have three or more books
	if (booksReceived.countBooksReceived() < 3)
	{
		cout << "Input file contains less than three books or one or more book titles were not read correctly." << endl
			<< "Verify input file has correct data and try again." << endl;

		system("pause");
		return 0;
	}

	cout << endl;

	//Display books received report
	booksReceived.displayBooksReceivedInfo();

	//Closing program statements
	inputFile.close();
	system("pause");
	return 0;
}

//Function Definitions

//request user input for file including path
string requestUserFileInput()
{
	string file;

	do
	{
		cout << "Shipment File Name: ";

		getline(cin, file);
	} while (!validateNotEmptyString(file));

	return file;
}

//validate input string is not empty
bool validateNotEmptyString(string& strToTest)
{
	bool containsNonWhitespaceChars = false;
	string str = changeWhitespaceToNull(strToTest);

	for (int position = 0; position < str.length(); position++)
		if (str[position] != '\0')
		{
			containsNonWhitespaceChars = true;
			break;
		}

	if (containsNonWhitespaceChars == false)
	{
		cout << endl << "Input cannot be only whitespace characters." << endl
			<< "Input the filename in current directory or include full path if file is not in current directory." << endl
			<< "Input must also include the file extension" << endl << endl;
	}

	return containsNonWhitespaceChars;
}

//Convert all whitespace characters to the null character, return the string
string changeWhitespaceToNull(string& str)
{
	for (int position = 0; position < str.length(); position++)
	{
		char evalChar = str[position];

		//if current character is one of the 6 whitespace characters, replace with the null character
		if (evalChar == 9 || evalChar == 10 || evalChar == 11 || evalChar == 12 || evalChar == 13 || evalChar == 32)
		{
			str[position] = '\0';
		}
	}

	return str;
}