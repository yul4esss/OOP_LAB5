#include <iostream>
#include <string>

using namespace std;

class Osoba {
protected:
	int age;

public:

	virtual void SetAge() {
		cout << "Enter age: " << endl;
		cin >> age;
	}

	int GetAge() {
		return age;
	}

	void printAge() {
		cout << "Your current age: " << age << endl;
	}

	// creating virtual method which changes person's age
	virtual void changeAge() {
		cout << "Do you want to change age?" << endl;
		int option;
		cout << "1-Yes, 2-No" << endl;
		cin >> option;
		if (option == 1) {
			cout << "Enter age: ";
			cin >> age;
			cout << "Your new age: " << age << endl;
		}
		else if (option == 2) {
			cout << "Current age: " << age << endl;
		}
		else {
			cout << "Please, enter 1 or 2" << endl;
			exit(0);
		}
	}

};

class Student :public Osoba {

public:

	void SetAge() override {
		cout << "Set student age: " << endl;
		cin >> age;
	}

	// override method
	void changeAge() override {

		if (age == 17) {
			cout << "Congrats! You're 1st course" << endl;
		}
		else if (age == 18) {
			cout << "Congrats! You're 2nd course" << endl;
		}
		else if (age == 19) {
			cout << "Congrats! You're 3rd course" << endl;
		}
		else if (age == 20) {
			cout << "Congrats! You're 4th course" << endl;
		}
		else if (age < 17) {
			cout << "You're just a baaaaby" << endl;
		}
		else {
			cout << "Get yourself a job!" << endl;
		}
	}

};

int main() {
	Osoba personOne;
	Student studentOne;

	personOne.SetAge();
	personOne.changeAge();

	Osoba* person = &studentOne;

	studentOne.SetAge();
	person->changeAge();
	person->printAge();
}