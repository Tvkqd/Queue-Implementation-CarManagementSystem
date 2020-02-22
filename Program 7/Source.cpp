// Tuyen Vu
// tvkqd@mail.umkc.edu
// Program 7
// Due 12/01/2019

#include"Header.h"

//Constructor
queue::queue() {
	count = 0;
	head = NULL;
	tail = NULL;
}

//Add a regular car (add from the bottom of the queue)
void queue::AddCar(string name, string model, string plate) {
	//Create new car node
	Car *car = new Car;
	car->name = name;
	car->model = model;
	car->plate = plate;

	//Check if the queue is empty
	if (isEmpty()) {
		head = car;
		tail = car;
		count++;
	}
	//Check if the queue is full
	else if (isFull())
		cout << "Unsucessful process! The queue is full.\n";
	else{
		tail->next = car;
		tail = car;
		count++;
	}
}

//Add a VIP car (add to the top of the queue)
void queue::AddVIP(string name, string model, string plate) {
	//Create new car node
	Car *car = new Car;
	car->name = name;
	car->model = model;
	car->plate = plate;

	//Check if the queue is empty
	if (isEmpty()) {
		head = car;
		tail = car;
		count++;
	}
	//Check if the queue is full
	else if (isFull())
		cout << "Unsucessful process! The queue is full.\n";
	else {
		car->next = head;
		head = car;
		count++;
	}
}

//Pop a car from the queue
void queue::pop() {
	//Check if the queue is empty
	if (isEmpty())
		cout << "No more cars." << endl;
	else {
		Car *temp = new Car;
		temp = head;
		head = head->next;
		
		//Display before delete
		Print(temp);
		delete temp;
		count--;
	}
}

//Remove a car from the queue
void queue::Cancel(string name, string model, string plate) {
	//Check if the queue is empty
	if (!isEmpty()) {
		Car *temp = new Car;
		temp = head;
		//Option 1: remove head
		if (temp->name == name && temp->model == model && temp->plate == plate) {
			pop();
		}
		//Option 2: remove any car between head and tail
		else {
			int check = 0;
			if (count >= 3){
				for (int i = 1; i < count - 1; i++) {
					//remove if found
					if (temp->next->name == name && temp->next->model == model && temp->next->plate == plate) {
						Car *temp2 = new Car;
						temp2 = temp->next;
						temp->next = temp2->next;
						Print(temp2);
						delete temp2;
						check = 1;
						count--;
						break;
					}
					//Update temp
					temp = temp->next;
				}
			}
			//Option 3: remove tail
			if (check == 0 || count == 2) {
				if (temp->next->name == name && temp->next->model == model && temp->next->plate == plate) {
					tail = temp;
					temp = temp->next;
					tail->next = NULL;
					Print(temp);
					delete temp;
					count--;
				}
				else
					cout << "Car does not exist." << endl;
			}
		}
	}
	else
		cout << "No car to be remove." << endl;
}

//Output all the cars in the queue
void queue::PrintAll() {
	system("CLS");
	if (isEmpty())
		cout << "No car to be display." << endl;
	else {
		//Create temporary pointer
		Car *temp = new Car;
		temp = head;
		cout << "List of Cars in this queue...\n";
		for(int i = 1; i <= count; i++){
			cout << i << endl;
			Print(temp);
			//Update temp
			temp = temp->next;
			cout << endl;
		}
	}
	system("pause");
}

//Check if the queue is empty
bool queue::isEmpty() {
	if (count == 0)
		return true;
	else
		return false;
}

//Check if the queue is full
bool queue::isFull() {
	if (count == 100)
		return true;
	else
		return false;
}

//Print a car information
void queue::Print(Car *car) {
	cout << "\tCar name: " << car->name << endl;
	cout << "\tModel   : " << car->model << endl;
	cout << "\tPlate # : " << car->plate << endl;
}

//This function displays main menu, then return user choice from the menu
int mainMenu() {
	int choice;

	do {
		//Clear the screen
		system("CLS");
		cout << "Welcome to Mercedes\n";
		cout << "1. Fast Cars\n";
		cout << "2. Old Cars\n";
		cout << "3. Luxury Cars\n";
		cout << "4. Exit\n";
		cout << "Please enter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice > 4);
	return choice;
}

//This function takes an int, display menu of each car type, then return user choice from the menu
int menu(int num) {
	int choice;

	do {
		system("CLS");
		cout << "Welcome to exhibition: ";
		if (num == 1)
			cout << "Fast Cars\n";
		else if (num == 2)
			cout << "Old Cars\n";
		else
			cout << "Luxury Cars\n";
		cout << "1. Add Car\n";
		cout << "2. Add VIP Car\n";
		cout << "3. Take Car to Auction\n";
		cout << "4. Cancel Car\n";
		cout << "5. List All Current Queued Cars\n";
		cout << "6. Back to Main Menu\n";
		cout << "Please enter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice > 6);

	return choice;
}

//This function takes an int and a queue, then perform corresponding function base on the choice
void carTypeFunctions(queue &Queue, int choice) {
	string name;
	string model;
	string plate;

	//Add Car
	if (choice == 1){ 
		//Get new car information
		cout << "========================================\n";
		cout << "Please enter car information to AddCar\n";
		cout << "Car name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Model: ";
		getline(cin, model);
		cout << "Plate number: ";
		getline(cin, plate);

		//Confirm screen
		system("CLS");
		cout << "This car will be added to the queue...\n";
		cout << "Car name: " << name << endl;
		cout << "Model   : " << model << endl;
		cout << "Plate # : " << plate << endl;

		//Add to the queue
		Queue.AddCar(name, model, plate);
		system("pause");
	}

	//Add VIP Car
	else if (choice == 2) {
		//Get new car information
		cout << "========================================\n";
		cout << "Please enter car information to AddVIPCar\n";
		cout << "Car name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Model: ";
		getline(cin, model);
		cout << "Plate number: ";
		getline(cin, plate);

		//Confirm screen
		system("CLS");
		cout << "This car will be added to the queue...\n";
		cout << "Car name: " << name << endl;
		cout << "Model   : " << model << endl;
		cout << "Plate # : " << plate << endl;
		
		//Add to the queue
		Queue.AddVIP(name, model, plate);
		system("pause");
	}

	//Take Car to Auction
	else if (choice == 3) {
		system("CLS");
		cout << "This car will be taken to the auction...\n";
		Queue.pop();
		system("pause");
	}

	//Cancel Car
	else if (choice == 4) {
		//Get car information
		cout << "========================================\n";
		cout << "Please enter car information to Remove\n";
		cout << "Car name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Model: ";
		getline(cin, model);
		cout << "Plate number: ";
		getline(cin, plate);

		system("CLS");
		cout << "Removing car for the queue...\n";
		Queue.Cancel(name, model, plate);
		system("pause");
	}

	//List All Current Queued Cars
	else {
		Queue.PrintAll();
	}
}