#include<iostream>
#include<string>
#include<vector>

class Person {
	std::string fullName, Address;
	int Age;
	float Height, Weight;
public:	
	Person() {
		fullName = "Unknown";
		Address = "Unknown";
		Height = Weight = Age = 0;
	}

	Person(std::string fullName, int Age, std::string Address, float Height, float Weight) {
		this->fullName = fullName; 
		this->Age = Age;
		this->Address = Address;
		this->Height = Height;
		this->Weight = Weight;
	}

	void Introduce() {
		std::cout<<"Enter FullName: ";
		getline(std::cin, this->fullName);
		std::cout << "Enter Age: ";
		std::cin >> this->Age;
		std::cin.ignore(32767, '\n');
		std::cout << "Enter Address: ";
		getline(std::cin, this->Address);
		std::cout << "Enter Height: ";
		std::cin >> this->Height;
		std::cout << "Enter Weight: ";
		std::cin >> this->Weight;
	}

	std::string getfullName() {
		return this->fullName;
	}

	void setfullName(std::string fullName) {
		this->fullName = fullName;
	}

	int getAge() {
		return this->Age;
	}

	void setAge(int age) {
		this->Age = age;
	}

	std::string getAddress() {
		return this->Address;
	}

	void setAddress(std::string Address) {
		this->Address = Address;
	}

	float getHeight() {
		return this->Height;
	}

	void setHeight(float Height) {
		this->Height = Height;
	}

	float getWeight() {
		return this->Weight;
	}

	void setWeight(float Weight) {
		this->Weight = Weight;
	}

	void ShowInformation() {
		std::cout << "FullName: " << " " << this->fullName << "\n";
		std::cout << "Age: " << " " << this->Age << "\n";
		std::cout << "Address: " << " " << this->Address << "\n";
		std::cout << "Height: " << " " << this->Height << "\n";
		std::cout << "Weight: " << " " << this->Weight << "\n";
	}
};

class Student {
	int id = 0;
	float score[8] = { 0 };
	Person* ps = new Person();
	std::string subjectTitle[8] =
	{ "Mathematics", "Physics", "Chemistry", "Literature", "English", "Biology", "History", "Georaphy" };
public:
	
	Student() {
	}

	Student(int id, Person* ps, float score[]) {
		this->id = id;
		this->ps = ps;
		for (int i = 0; i < 8; ++i) {
			this->score[i] = score[i];
		}
	}

	int getId() {
		return this->id;
	}

	void setId(int id) {
		this->id = id;
	}

	void setScore() {
		std::string name;
		std::cout << "Enter subject title: ";
		std::cin >> name;
		for (int i = 0; i < 8; ++i) {
			if (subjectTitle[i] == name) {
				std::cout << "Enter score: ";
				std::cin >> score[i];
				return;
			}
		}
		std::cout << "There is no name this subject";
	}

	void Transcript() {
		std::cout << "\t\tScores of subjects\n";
		for (int i = 0; i < 8; ++i) {
			std::cout << subjectTitle[i] << ": " << score[i] << "\n";
		}
	}

	void Achievement() {
		std::cout << "Achivement: ";
		float sum = 0;
		for (int i = 0; i < 8; ++i) {
			sum += score[i];
		}
		sum /= 8;
		if (sum >= 8) {
			std::cout << "Very good\n";
		}
		else if (sum >= 5) {
			std::cout << "Good\n";
		}
		else {
			std::cout << "Average\n";
		}
	}

	void Introduce() {
		std::cout << "Enter ID: ";
		std::cin >> id;
		std::cin.ignore();
		ps->Introduce();
		for (int i = 0; i < 8; ++i) {
			std::cout << "Enter " <<subjectTitle[i] << ": ";
			std::cin >> score[i];
		}
	}

	void Information() {
		std::cout << "\t\tInformation\n";
		std::cout << "ID: " << this->id << "\n";
		ps->ShowInformation();
	}

	void setInformation() {
		std::cout << "\t\tSet Information Student\n";
		std::string name[6] = { "ID", "FullName", "Age", "Address", "Height", "Weight" };
		for (int i = 0; i < 6; ++i) {
			std::cout << i+1 << ":" << name[i] << "\n";
		}
		int index = 0;
		std::cout << "Enter choose: ";
		std::cin >> index;
		if (index == 1) {
			int id = 0;
			std::cout << "Enter ID: ";
			std::cin >> id;
			this->setId(id);
		}
		if (index == 2) {
			std::cin.ignore();
			std::string fullName;
			std::cout << "Enter FullName: ";
			getline(std::cin, fullName);
			ps->setfullName(fullName);
		}
		if (index == 3) {
			int age = 0;
			std::cout << "Enter Age: ";
			std::cin >> age;
			ps->setAge(age);
		}
		if (index == 4) {
			std::cin.ignore();
			std::string address;
			std::cout << "Enter Address: ";
			getline(std::cin, address);
			ps->setAddress(address);
		}
		if (index == 5) {
			float height = 0;
			std::cout << "Enter Height: ";
			std::cin >> height;
			ps->setHeight(height);
		}
		if (index == 6) {
			float weight = 0;
			std::cout << "Enter Weight: ";
			std::cin >> weight;
			ps->setHeight(weight);
		}
	}

	~Student() {
		delete ps;
	}
};

class ClassRoom {
	std::string idClass;
	std::vector<Student *>studentList;
	Student* monitor = new Student();
public: 
	static int numberClass;
	ClassRoom() {
		numberClass++;
	}

	ClassRoom(std::string idClass, std::vector<Student*>studentList, Student* monitor) {
		this->idClass = idClass;
		this->studentList = studentList;
		this->monitor = monitor;
	}

	std::string getIdClass() {
		return this->idClass;
	}

	void setIdClass(std::string idClass) {
		this->idClass = idClass;
	}

	void addStudent(Student* st) {
		studentList.push_back(st);
	}

	void deleteStudent(int id) {
		int size = studentList.size();
		for (int i = 0; i < size; ++i) {
			if (studentList[i]->getId() == id) {
				studentList.erase(studentList.begin() + i);
				return;
			}
		}
		std::cout << "ID not exist\n";
	}

	void setInformation(int id) {
		int size = studentList.size();
		for (int i = 0; i < size; ++i) {
			if (studentList[i]->getId() == id) {
				studentList[i]->setInformation();
				return;
			}
		}
		std::cout << "ID not exist\n";
	}

	void show() {
		for (Student* it : studentList) {
		std::cout << "---------------------------------\n";
			it->Information();
			it->Transcript();
			it->Achievement();
		}
	}

	void setMonitor(int id) {
		int size = studentList.size();
		for (int i = 0; i < size; ++i) {
			if (studentList[i]->getId() == id) {
				monitor = studentList[i];
				return;
			}
		}
		std::cout << "ID not exist\n";
	}

	void showMonitor() {
		std::cout << "\nMonitor class information:\n";
		monitor->Information();
		monitor->Transcript();
		monitor->Achievement();
	}

	static void NumberClass() {
		std::cout << numberClass;
	}

};

int ClassRoom::numberClass = 0;

int main() {
	/// Person
	Person* ps = new Person("Nguyen Van A", 20, "VietNam", 1.83, 69);
	Person* ps1 = new Person("Nguyen Van B", 19, "VietNam", 1.80, 70);
	Person* ps2 = new Person("Nguyen Van C", 34, "VietNam", 1.75, 60);
	Person* ps3 = new Person("Michale Jam", 20, "USA", 2.00, 95);

	/// Student
	float score[] = { 8, 9, 5, 6, 6, 7.8, 6 ,9 };
	Student* st = new Student(2321, ps, score);

	float score1[] = { 8, 9, 9, 9, 7, 7, 9 ,10 };
	Student* st1 = new Student(2322, ps1, score1);

	float score2[] = { 10, 9.2, 5.6, 7, 7, 8, 6 ,8 };
	Student* st2 = new Student(2323, ps2, score2);

	float score3[] = { 8, 9, 10, 7.6, 8, 10, 9 ,9 };
	Student* st3 = new Student(2324, ps3, score3);

	///Classroom
	ClassRoom* cr = new ClassRoom();
	cr->addStudent(st);
	cr->addStudent(st1);
	cr->addStudent(st2);
	cr->addStudent(st3);
	cr->show();
	cr->setMonitor(2324);
	cr->showMonitor();

	delete ps, ps1, ps2, ps3, st, st1, st2, st3, cr;
	return 0;
}