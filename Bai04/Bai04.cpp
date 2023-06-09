#include<iostream>

class Phone {
private:
	std::string nameProduct, version;
	float size = 0;
	int yearWarrenty = 0;

public:
	Phone() {
	}

	Phone(std::string nameProduct, int version, float size, int yearWarrenty) {
		this->nameProduct = nameProduct;
		this->version = version;
		this->size = size;
		this->yearWarrenty = yearWarrenty;
	}

	void Reboot() {
		std::cout << "Phone was rebooted\n";
	}

	void Call() {
		std::cout << "Calling\n";
	}

	void Introduce() {
		std::cout << "Product: " << nameProduct << "\n";
		std::cout << "Version: " << version << "\n";
		std::cout << "Size: " << size << "\n";
		std::cout << "Warrenty year: " << yearWarrenty << "\n";
	}
};

class Iphone : public Phone {
private:
public:
	Iphone() {};
	Iphone(std::string nameProduct, int version, float size, int yearWarrenty) : Phone(nameProduct,version,size,yearWarrenty) {};
	void faceId() {
		std::cout << "Face ID\n";
	}

	void shareFile() {
		std::cout << "Share file by airdrop\n";
	}

	void openStore() {
		std::cout << "Open AppStore\n";
	}
};

class GalaxyS : public Phone {
private:
public:
	GalaxyS() {};
	GalaxyS(std::string nameProduct, int version, float size, int yearWarrenty) : Phone(nameProduct, version, size, yearWarrenty) {};
	void OpenPencil() {
		std::cout << "S-pen pencil\n";
	}

	void openStore() {
		std::cout << "Open Google play\n";
	}

};

int main() {
	Iphone* ip = new Iphone("Iphone 13 pro max", 13, 18, 3);
	GalaxyS* gs = new GalaxyS("Galaxy S7", 7, 18, 2);
	std::cout << "Iphone: \n";
	ip->Introduce();
	ip->Reboot();
	ip->Call();
	ip->faceId();
	ip->shareFile();
	ip->openStore();
	std::cout << "Galaxy S:\n";
	gs->Introduce();
	gs->Reboot();
	gs->Call();
	gs->OpenPencil();
	gs->openStore();
	delete ip, gs;
	return 0;
}