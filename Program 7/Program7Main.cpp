// Tuyen Vu
// tvkqd@mail.umkc.edu
// Program 7
// Due 12/01/2019

#include"Header.h"

int main() {

	int mainChoice;
	int choice;
	queue Fast;
	queue Old;
	queue Luxury;
	//Get choice from main menu
	mainChoice = mainMenu();
	while (mainChoice != 4) {
		//Fast Cars
		if (mainChoice == 1) {
			//Get choice from car type menu
			choice = menu(mainChoice);
			while (choice != 6) {
				carTypeFunctions(Fast, choice);
				choice = menu(mainChoice);
			}
		}

		//Old Cars
		else if (mainChoice == 2) {
			//Get choice from car type menu
			choice = menu(mainChoice);
			while (choice != 6) {
				carTypeFunctions(Old, choice);
				choice = menu(mainChoice);
			}
		}

		//Luxury Cars
		else {
			//Get choice from car type menu
			choice = menu(mainChoice);
			while (choice != 6) {
				carTypeFunctions(Luxury, choice);
				choice = menu(mainChoice);
			}
		}

		//Get choice from main menu
		mainChoice = mainMenu();
	}
	
	
	cout << "\nTHANK YOU FOR VISITING\n";
	system("pause");
	return 0;
}