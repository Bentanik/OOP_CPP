#include<iostream>
#include<string>

class Patient {
	std::string fullName, dayTime, CD;
	int ID;
	float price;
public:
	Patient() {
		fullName = "Unknown";
		ID = price = 0;
	}

	Patient(std::string fullName, int ID, std::string dayTime, std::string CD, float price) {
		this->fullName = fullName;
		this->ID = ID;
		this->dayTime = dayTime;
		this->CD = CD;
		this->price = price;
	}

	std::string getFullName() {
		return this->fullName;
	}

	void setFullName(std::string fullName) {
		this->fullName = fullName;
	}

	std::string getDayTime() {
		return this->dayTime;
	}

	void setDayTime(std::string dayTime) {
		this->dayTime = dayTime;
	}

	std::string getCodeDiseases() {
		return this->CD;
	}

	void setCodeDiseases(std::string CD) {
		this->CD = CD;
	}

	int getID() {
		return this->ID;
	}

	void setID(int ID) {
		this->ID = ID;
	}

	float getPrice() {
		return this->price;
	}

	void setPrice(float price) {
		this->price = price;
	}

	void showIntroduce() {
		std::cout << "---------------------------------------------------------\n";
		std::cout << "ID: " << ID << "\n";
		std::cout << "FullName: " << fullName << "\n";
		std::cout << "DayTime: " << dayTime << "\n";
		std::cout << "Code Diseases: " << CD << "\n";
		std::cout << "Hospital's fee: " << price << "\n";
	}
};

int main() {
	Patient* pt = new Patient("Nguyen Van A", 1, "12/3/2000", "S3231", 200.53);
	Patient* pt1 = new Patient("Nguyen Van B", 2, "12/3/2020", "S6431", 100.00);
	Patient* pt2 = new Patient("Nguyen Van C", 3, "12/3/2005", "S9231", 9.5623);
	pt->showIntroduce();
	pt1->showIntroduce();
	pt2->showIntroduce();
	delete pt, pt1, pt2;
	return 0;
}