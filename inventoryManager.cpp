// Dylan Desmond and Jimmy Lau
// CSS 343 Assignment 4
// This is the main inventory manager file

//#include "inventoryManager.h"
#include <iostream>
#include "customerMap.h"
#include "genreMap.h"
#include "customer.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "movie.h"
#include <fstream>
#include <sstream>
#include <cctype>


using namespace std;
customerMap* customers;
genreMap<Comedy> *comedies;
genreMap<Classic> *classics;
genreMap<Drama> *dramas;





void initCustomers(string filename) {
	customers = new customerMap();
	ifstream file;
	file.open(filename);
	if (file.is_open()) {
		string singleCus;
		while (file >> singleCus) {
			stringstream test(singleCus);
			int customerId;
			test >> customerId;
			string firstname;
			string lastname;
			file >> firstname;
			file >> lastname;
			string name = firstname + " " + lastname;
			Customer* newCust = new Customer(customerId, name);
			customers->insert(newCust);
		}
	}
}

void initMovies(string filename) {
	comedies = new genreMap<Comedy>();
	classics = new genreMap<Classic>();
	dramas = new genreMap<Drama>();
	ifstream file;
	file.open(filename);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			string type;
			string stock;
			string director;
			string title;

			string tempLine = line;

			stringstream lineParts(tempLine);
			lineParts >> type;
			type = type.substr(0, type.length() - 1);

			lineParts >> stock;
			int deleteSpace = stock.length() + 3;
			stringstream count(stock);
			int stockCount;
			count >> stockCount;

			string newTemp = tempLine.substr(deleteSpace, tempLine.length());
			int commaPos = newTemp.find_first_of(',');
			director = newTemp.substr(0, commaPos);
			//director = director.substr(0, director.length() - 1);

			newTemp.erase(0, commaPos + 2);

			commaPos = newTemp.find_first_of(',');
			title = newTemp.substr(0, commaPos);	

			newTemp.erase(0, commaPos + 2);
			
			string year;
			if (type == "F") {
				// We have been passed in a Comedy
				year = newTemp;

				Comedy* newMovie = new Comedy(stockCount, title, director, year, type);
				comedies->insert(newMovie);
			}
			else if (type == "D") {
				// We have been passed in a Drama
				year = newTemp;

				Drama* newMovie = new Drama(stockCount, title, director, year, type);
				dramas->insert(newMovie);
			}
			else if (type == "C") {
				// We have been passed in a Classic
				string name;
				string date;

				stringstream tempStr(newTemp);
				string namePart;
				tempStr >> namePart;
				name = namePart;
				while (tempStr >> namePart) {
					stringstream test(namePart);
					int tester = 0;
					if ((test >> tester).fail()) {
						name = name + " " + namePart;
					}
					else {
						date += namePart + " ";
					}
				}
				date = date.substr(0, date.length() - 1);
				Classic* newMovie = new Classic(stockCount, title, director, date, type, name);
				classics->insert(newMovie);
			}
		}
	}
}

void printInventory() {
	cout << "Comedies: " << endl;
	comedies->printInventory("F");
	cout << "Dramas: " << endl;
	dramas->printInventory("D");
	cout << "Classics: " << endl;
	classics->printInventory("C");
}

void history(int id) {
	Customer* target = customers->find(id);
	target->getHistory();
}

void borrow(string line) {
	stringstream temp(line);
	int custId;
	temp >> custId;
	Customer* cust = customers->find(custId);
	if (cust == nullptr) {
		cout << "Error customer not found." << endl;
	} else {
		string isDVD;
		temp >> isDVD;
		if (isDVD != "D") {
			cout << "Invalid Type" << endl;
		}
		else {

			string type;
			temp >> type;
			string newTemp = line.substr(10, line.length());

			if (type == "F") {
				int commaPos;
				commaPos = newTemp.find_first_of(',');
				string title = newTemp.substr(0, commaPos);
				string date = newTemp.substr(commaPos + 2, newTemp.length());

				Comedy* target = comedies->find(title + date);
				if (target->inStock()) {
					target->decrementStock();
					Transaction* trans = new Transaction(custId, title, "B");

					cust->makeTransaction(trans);
				}
				else {
					cout << "No copies left in stock." << endl;
				}
			}
			else if (type == "D") {
				int commaPos;
				commaPos = newTemp.find_first_of(',');

				string director = newTemp.substr(0, commaPos);
				string title = newTemp.substr(commaPos + 2, newTemp.length() - 1);

				Drama* target = dramas->find(director + title);
				if (target->inStock()) {
					target->decrementStock();
					Transaction* trans = new Transaction(custId, title, "B");
					cust->makeTransaction(trans);
				}
				else {
					cout << "No copies left in stock." << endl;
				}
			}
			else if (type == "C") {
				stringstream tempStream(newTemp);
				string date;
				string year;
				tempStream >> date;
				tempStream >> year;
				int len = date.length() + 6;
				string actor = newTemp.substr(len, newTemp.length());
				date = date + year;

				Classic* target = classics->find(date + actor);
				if (target->inStock()) {
					target->decrementStock();
					Transaction* trans = new Transaction(custId, target->getTitle(), "B");
					cust->makeTransaction(trans);
				}
				else {
					cout << "No copies left in stock." << endl;
				}
			}
			else {
				cout << "Invalid movie type." << endl;
			}
		}
	}
}

void makeReturn(string line) {
	stringstream temp(line);
	int custId;
	temp >> custId;
	Customer* cust = customers->find(custId);
	if (cust == nullptr) {
		cout << "Error customer not found." << endl;
	}
	else {
		string isDVD;
		temp >> isDVD;
		if (isDVD != "D") {
			cout << "Invalid Type" << endl;
		}
		else {
			string type;
			temp >> type;
			string newTemp = line.substr(10, line.length());

			if (type == "F") {
				int commaPos;
				commaPos = newTemp.find_first_of(',');
				string title = newTemp.substr(0, commaPos);
				string date = newTemp.substr(commaPos + 2, newTemp.length());

				Comedy* target = comedies->find(title + date);

				target->incrementStock();
				Transaction* trans = new Transaction(custId, title, "R");

				cust->makeTransaction(trans);

			}
			else if (type == "D") {
				int commaPos;
				commaPos = newTemp.find_first_of(',');

				string director = newTemp.substr(0, commaPos);
				string title = newTemp.substr(commaPos + 2, newTemp.length() - 1);

				Drama* target = dramas->find(director + title);

				target->incrementStock();
				Transaction* trans = new Transaction(custId, title, "R");
				cust->makeTransaction(trans);
			}
			else if (type == "C") {
				stringstream tempStream(newTemp);
				string date;
				string year;
				tempStream >> date;
				tempStream >> year;
				int len = date.length() + 6;
				string actor = newTemp.substr(len, newTemp.length());
				date = date + year;

				Classic* target = classics->find(date + actor);

				target->incrementStock();
				Transaction* trans = new Transaction(custId, target->getTitle(), "R");
				cust->makeTransaction(trans);
			}
			else {
				cout << "Invalid movie type." << endl;
			}
		}
	}
}

void initialize() {
	initCustomers("data4customers.txt");
	initMovies("data4movies.txt");
}

int main() {
	initialize();
	ifstream file;
	file.open("data4commands.txt");
	if (file.is_open()) {
		string line;
		// Reading through the command file line by line and 
		while (getline(file, line)) {
			string command = line.substr(0, 1);
			if (command == "I") {
				printInventory();
			}
			else if (command == "H") {
				string custId = line.substr(2, 6);
				stringstream count(custId);
				int id;
				count >> id;
				history(id);
			}
			else if (command == "B") {
				string toPass = line.substr(2, line.length());
				borrow(toPass);
			}
			else if (command == "R") {
				string toPass = line.substr(2, line.length());
				makeReturn(toPass);
			}
			else {
				cout << "Error: Invalid command." << endl;
			}
		}
	}
}


