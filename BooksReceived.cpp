#include <string>
#include <vector>
#include <cmath>
#include "BooksReceived.h"

using namespace std;

void BooksReceived::addBook(std::string book) { books.push_back(book); }

void BooksReceived::sortBookList()
{

}

int BooksReceived::countBooksReceived()
{
	int bookNum = 0;

	for (auto value : books)
		bookNum++;

	return bookNum;
}

double BooksReceived::calcHardboundPercentage()
{

}

double BooksReceived::calcPaperbackPercentage()
{

}

void BooksReceived::setNameBookstore(std::string bookstore) { nameBookstore = bookstore; }

std::string BooksReceived::getNameBookstore() { return BooksReceived::nameBookstore; }

void BooksReceived::setDateOfShipment(std::string dateShipment) { dateOfShipment = dateShipment; }

std::string BooksReceived::getDateOfShipment() { return BooksReceived::dateOfShipment; }

void BooksReceived::setNumberHardbound(int numHardbound) { numberHardBound = numHardbound; }

int BooksReceived::getNumberHardbound() { return BooksReceived::numberHardBound; }

void BooksReceived::setNumberPaperback(int numPaperback) { numberPaperback = numPaperback; }

int BooksReceived::getNumberPaperback() { return BooksReceived::numberPaperback; }

void BooksReceived::displayBooksReceivedInfo()
{

}

BooksReceived::BooksReceived(string bookstore, string dateShipment, int numHardbound, int numPaperback)
{
	nameBookstore = bookstore;
	dateOfShipment = dateShipment;
	numberHardBound = numHardbound;
	numberPaperback = numPaperback;
}

BooksReceived::BooksReceived()
{
	nameBookstore = "";
	dateOfShipment = "";
	numberHardBound = 0;
	numberPaperback = 0;
}