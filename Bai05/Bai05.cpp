#include<iostream>
#include<string>
#include<vector>

class Employees {
private:
	std::string fullName;
	float price;
	int numberYear;
public:
	Employees() {
	}

	Employees(std::string fullName, float price, int numberYear) {
		this->fullName = fullName;
		this->price = price;
		this->numberYear = numberYear;
	}

	void setFullName(std::string fullName) {
		this->fullName = fullName;
	}

	std::string getFullName() {
		return this->fullName;
	}

	void setPrice(float price) {
		this->price = price;
	}

	float getPrice() {
		return this->price;
	}

	void setNumberYear(int numberYear) {
		this->numberYear = numberYear;
	}

	int getNumberYear() {
		return this->numberYear;
	}

	virtual void Occupation() {
		std::cout << "Employess";
	}
};

class HR : public Employees {
private:
public:
	HR() {};
	HR(std::string fullName, float price, int numberYear) : Employees(fullName, price, numberYear) {};

	void Occupation() override {
		std::cout << "HR\n";
	}
};

class PGEngineer : public Employees {
private:
public:
	PGEngineer() {};
	PGEngineer(std::string fullName, float price, int numberYear) : Employees(fullName, price, numberYear + numberYear * 0.25) {};

	void setPrice(float price) {
		Employees::setPrice(price + price * 0.25);
	}

	void Occupation() override {
		std::cout << "Programming engineer\n";
	}

};

// Bussiness Employees 
class BE : public Employees {
private:
	int numberContract = 0;
public:
	BE() {};
	BE(std::string fullName, float price, int numberYear, int numberContract = 0) : Employees(fullName, price + price * numberContract * 1.0 / 100, numberYear) {
		this->numberContract = numberContract;
	};

	void setPrice(float price, int numberContract) {
		Employees::setPrice(price + price * numberContract * 1.0 / 100);
	}

	void setNumberContract(int numberContract) {
		this->numberContract = numberContract;
	}

	int getNumberContract() {
		return this->numberContract;
	}

	void Occupation() override {
		std::cout << "Business man\n";
	}

};

int main() {
	int option = 1;
	std::vector<Employees*>Employees_list;
	do {
		std::cout << "----------------------------------------\n";
		std::cout << "1. Add Employee\n";
		std::cout << "2. Delete Employee\n";
		std::cout << "3. Employee salary\n";
		std::cout << "4. Turn off\n";
		std::cout << "Enter choose: ";
		std::cin >> option;

		if (option == 1) { 
			std::string fullName, titleName[3] = {"HR staff", "Programming engineer", "Business man"};
			float price = 0;
			int numberYear = 0, choose = 0;
			std::cout << "Enter name: ";
			std::cin.ignore();
			getline(std::cin, fullName);
			std::cout << "Enter price: ";
			std::cin >> price;
			std::cout << "Enter number year service: ";
			std::cin >> numberYear;
			std::cout << "Names of positions:\n";
			for (int i = 0; i < 3; ++i) {
				std::cout << i + 1 << " " << titleName[i] << "\n";
			}
			std::cout << "Please choose: ";
			std::cin >> choose;
			if (choose == 1) {
				Employees* em = new HR(fullName, price, numberYear);
				Employees_list.push_back(em);
			}
			else if (choose == 2) {
				Employees* em = new PGEngineer(fullName, price, numberYear);
				Employees_list.push_back(em);
			}
			else if (choose == 3) {
				int contract = 0;
				std::cout << "Enter contract: ";
				std::cin >> contract;
				Employees* em = new BE(fullName, price, numberYear, contract);
				Employees_list.push_back(em);
			}
		}

		if (option == 2) {

		}
	} while (option != 4);
	for (int i = 0; i < Employees_list.size(); ++i) {
		std::cout << "FullName: " << Employees_list[i]->getFullName() << "\n";
		std::cout << "Occupation: "; 
		Employees_list[i]->Occupation();
		std::cout << "Salary: " << Employees_list[i]->getPrice() << "\n";
		std::cout << "Year of service: " << Employees_list[i]->getNumberYear() << "\n";
	}
	return 0;
}