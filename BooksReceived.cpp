#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include "BooksReceived.h"

using namespace std;

void BooksReceived::addBook(string book) { books.push_back(book); }

void BooksReceived::sortBookList()
{
	int location;
	string temp;

	//Loop through books vector
	for (int outOfOrder = 1; outOfOrder < BooksReceived::books.size(); outOfOrder++)
	{
		//If current item starting at books[1] is less than previous item
		if (books[outOfOrder] < books[outOfOrder - 1])
		{
			location = outOfOrder;
			temp = books[location];

			//loop through list starting at current item
			//Assign previous value to current position until current value is greater than previous value
			do
			{
				books[location] = books[location - 1];
				location--;
			} while (location > 0 && books[location - 1] > temp);

			books[location] = temp;
		}
	}
}

int BooksReceived::countBooksReceived()
{
	int bookNum = 0;

	//Loop through the book list and increment bookNum by one for every book in the list
	for (auto value : books)
		bookNum++;

	return bookNum;
}

double BooksReceived::calcHardboundPercentage() { return ((numberHardBound * 1.0) / (countBooksReceived() * 1.0) * 100); }

double BooksReceived::calcPaperbackPercentage() { return ((numberPaperback * 1.0) / (countBooksReceived() * 1.0) * 100); }

void BooksReceived::setNameBookstore(string bookstore) { nameBookstore = bookstore; }

string BooksReceived::getNameBookstore() { return BooksReceived::nameBookstore; }

void BooksReceived::setDateOfShipment(string dateShipment) { dateOfShipment = dateShipment; }

string BooksReceived::getDateOfShipment() { return BooksReceived::dateOfShipment; }

void BooksReceived::setNumberHardbound(int numHardbound) { numberHardBound = numHardbound; }

int BooksReceived::getNumberHardbound() { return BooksReceived::numberHardBound; }

void BooksReceived::setNumberPaperback(int numPaperback) { numberPaperback = numPaperback; }

int BooksReceived::getNumberPaperback() { return BooksReceived::numberPaperback; }

void BooksReceived::displayBooksReceivedInfo()
{
	//Sort the book list
	sortBookList();

	//Output first section of the report
	cout << nameBookstore << endl << endl
		<< "Book Shipment - Received" << endl << endl
		<< "Books In Shipment:" << endl
		<< "  Hardbound: " << numberHardBound << endl
		<< "  Paperback: " << numberPaperback << endl << endl
		<< "Percentage of Shipment:" << endl
		<< "  Hardbound: " << fixed << setprecision(1) << calcHardboundPercentage() << '%' << endl
		<< " Paperback: " << setprecision(1) << calcPaperbackPercentage() << '%' << endl << endl
		<< "Sorted List Of Books Received:" << endl << endl;

	//Output each book title
	for (int book = 0; book < books.size(); book++)
		cout << "  " << books[book] << endl;

	//Output list section of the report
	cout << endl << "Total Books Received: " << countBooksReceived() << endl << endl;
}

BooksReceived::BooksReceived(string bookstore, string dateShipment, int numHardbound, int numPaperback)
{
	//Initialize each appropriate data member with file input data
	nameBookstore = bookstore;
	dateOfShipment = dateShipment;
	numberHardBound = numHardbound;
	numberPaperback = numPaperback;
}

BooksReceived::BooksReceived()
{
	//Initialize each appropriate data member to "" or 0 as applicable
	nameBookstore = "";
	dateOfShipment = "";
	numberHardBound = 0;
	numberPaperback = 0;
}