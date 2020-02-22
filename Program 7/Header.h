// Tuyen Vu
// tvkqd@mail.umkc.edu
// Program 7
// Due 12/01/2019

#pragma once
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;

//This struct holds information of a car
struct Car {
	string name;
	string model;
	string plate;
	Car *next = NULL;
};


//This class hold functions for a car type
class queue {
	int count;
	Car *head;
	Car *tail;

public:
	//Constructor
	queue();

	//Add a regular car (add from the bottom of the queue)
	void AddCar(string name, string model, string plate);
	
	//Add a VIP car (add to the top of the queue)
	void AddVIP(string name, string model, string plate);

	//Pop a car from the queue
	void pop();

	//Remove a car from the queue
	void Cancel(string name, string model, string plate);

	//Output all the cars in the queue
	void PrintAll();

	//Check if the queue is empty
	bool isEmpty();

	//Check if the queue is full
	bool isFull();
	
	//Print a car information
	void Print(Car *car);
};

//This function displays main menu, then return user choice from the menu
int mainMenu();

//This function takes an int, display menu of each car type, then return user choice from the menu
int menu(int num);

//This function takes an int and a queue, then perform corresponding function base on the choice
void carTypeFunctions(queue &Queue, int choice);