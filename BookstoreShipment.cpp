// BookstoreShipment.cpp -- Build a report based on a loaded list of books in a shipment
//CSIS 212-<D02_202440>

//Include and namespace statements

//Funciton prototypes
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "BooksReceived.h"

using namespace std;

//Function Prototypes

//Main function
int main()
{
	cout << "Zachary Seeley -- Lab 3 - Vectors and Sorting" << endl << endl << endl;

	ifstream inputFile;
	string file, nameBookstore, dateOfShipment, bookTitle;
	int numberHardbound, numberPaperback;

	//Request filename from user

	//-----Test Data-----//
	file = "C:\\Users\\loray\\OneDrive\\Documents\\School\\LUO\\CSIS112\\BookstoreShipment\\ShipmentInput.txt";
		
	//open requested file and validate if open
	//read data into appropriate variables and validate correct entries
	//exit program if not valid input
	inputFile.open(file);
	if (!inputFile.is_open())
	{
		cout << "The file path is wrong or the file does not exist." << endl
			<< "Verify entry is correct and try again." << endl;

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

	//Create BooksReceived object, passing in nameBookstore, dateOfShipment, numberHardbound, numberPaperback
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
			cout << "Book title is longer than 35 characters." << endl
				<< "Shorten book title or remove from file and try again." << endl;

			system("pause");
			return 0;
		}
		else
			booksReceived.addBook(bookTitle);
	}

	if (booksReceived.countBooksReceived() < 3)
	{
		cout << "Input file contains less than three books or one or more book titles were not read correctly." << endl
			<< "Verify input file has correct data and try again." << endl;

		system("pause");
		return 0;
	}

	//Display books received report
	booksReceived.displayBooksReceivedInfo();

	//Closing program statements
	inputFile.close();
	system("pause");
	return 0;
}

//Function Definitions