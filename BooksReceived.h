class BooksReceived
{
public:
	void addBook(string book);
		//Accepts a book value and adds it to the "books" vector

	void sortBookList();
		//Sorts the vector that contains the list of books received

	int countBooksReceived();
		//Returns the number of books in the vector

	double calcHardboundPercentage();
		//Calculates the percentage of hardbound books in the shipment

	double calcPaperbackPercentage();
		//Calculates the percentage of paperback books in the shipment

	void setNameBookstore(std::string bookstore);
		//Accepts bookstore name and updates the nameBookstore data member

	std::string getNameBookstore();
		//Returns the nameBookstore data member stored value

	void setDateOfShipment(std::string dateShipment);
		//Accepts date of shipment and updates dateOfShipment data member

	std::string getDateOfShipment();
		//Returns the dateOfShipment data member stored value

	void setNumberHardbound(int numHardbound);
		//Accepts number of hardbound books in the shipment and updates numberHardbound data member

	int getNumberHardbound();
		//Returns numberHardbound data member stored value

	void setNumberPaperback(int numPaperback);
		//Accepts number of paperback books in the shipment and updates the numberPaperback data member

	int getNumberPaperback();
		//Returns numberPaperback data member stored value

	void displayBooksReceivedInfo();
		//Creates and displays the formatted book shipment report


private:
	std::string nameBookstore;
	std::string dateOfShipment;
	int numberHardBound;
	int numberPaperback;
	std::vector<string> books;
};