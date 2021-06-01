#pragma once
#include "Product.h"
#include<iomanip>

class Notebook :public Product {
	size_t _id = NULL;
	string _processor = "";
	size_t _ram = NULL;
	size_t _memoryHDD = NULL;
	size_t _memorySSD = NULL;
	string _operating_system = "";
	bool _isOpticalDrive = false;
public:
	static size_t notebookID;
	Notebook() {
		_id = ++notebookID;
	}
	Notebook(const size_t categoryId, const string& productName, const string& brand, const string& model, const string& processor, const double price, const size_t ram, const size_t memoryHDD, const size_t memorySSD, const string& operating_system, const bool isOpticalDrive, const size_t quantity)
		:Product(categoryId, productName, brand, model, price, quantity)
	{
		_id = ++notebookID;
		setProcessor(processor);
		setRam(ram);
		setMemoryHDD(memoryHDD);
		setMemorySSD(memorySSD);
		setOperatingSystem(operating_system);
		setIsOpticalDrive(isOpticalDrive);
	}

	size_t getId()const {
		return _id;
	}
	void setId(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id must be greater than 0!", __LINE__, __FILE__);
		}
		else _id = id;
	}

	const string& getProcessor()const {
		return _processor;
	}
	void setProcessor(const string& processor) {
		if (processor.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Notebook processor null!", __LINE__, __FILE__);
		}
		else _processor = processor;
	}

	size_t getRam()const {
		return _ram;
	}
	void setRam(const size_t ram) {
		if (ram < 0) {
			writeErrorTxtToFile("Error N0002", __LINE__, __FILE__);
			throw InvalidArgumentException("Ram must be greater than 0!", __LINE__, __FILE__);
		}
		else _ram = ram;
	}

	size_t getMemoryHDD()const {
		return _memoryHDD;
	}
	void setMemoryHDD(const size_t memoryHDD) {
		if (memoryHDD < 0) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw InvalidArgumentException("Memory must be greater than 0!", __LINE__, __FILE__);
		}
		else _memoryHDD = memoryHDD;
	}

	size_t getMemorySSD()const {
		return _memorySSD;
	}
	void setMemorySSD(const size_t memorySSD) {
		if (memorySSD < 0) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw InvalidArgumentException("Memory must be greater than 0!", __LINE__, __FILE__);
		}
		else _memorySSD = memorySSD;
	}


	const string& getOperatingSystem()const {
		return _operating_system;
	}
	void setOperatingSystem(const string& operating_system) {
		if (operating_system.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Notebook operating system null!", __LINE__, __FILE__);
		}
		else _operating_system = operating_system;
	}

	bool getIsOpticalDrive()const {
		return _isOpticalDrive;
	}
	void setIsOpticalDrive(const bool& isOpticalDrive) {
		_isOpticalDrive = isOpticalDrive;;
	}

	/*void UpdateProduct() override {
		string brand, model,processor;
		double price;
		size_t ram, memoryHDD, memorySSD;
		bool isOpticDrive;
		cout << "Enter update brand: ";
		cin.ignore();
		getline(cin, brand);
		cout << "Enter update model: ";
		getline(cin, model);
		cout << "Enter update processor: ";
		getline(cin, processor);
		cout << "Enter update price: ";
		cin >> price;
		cout << "Enter update ram: ";
		cin >> ram;
		cout << "Enter update memory(HDD): ";
		cin >> memoryHDD;
		cout << "Enter update memory(SSD): ";
		cin >> memorySSD;
		cout << "Enter update optical drive: ";
		cin >> isOpticDrive;
	}*/

	void input() override {
		cout << "Enter notebook category id: ";
		cin >> _category_id;
		cout << "Enter notebook brand: ";
		cin.ignore();
		getline(cin, _brand);
		cout << "Enter notebook model: ";
		getline(cin, _model);
		cout << "Enter notebook processor: ";
		getline(cin, _processor);
		cout << "Enter notebook price: ";
		cin >> _price;
		cout << "Enter notebook ram: ";
		cin >> _ram;
		cout << "Enter notebook memory(HDD): ";
		cin >> _memoryHDD;
		cout << "Enter notebook memory(SSD): ";
		cin >> _memorySSD;
		cout << "Enter notebook operating system: ";
		cin.ignore();
		getline(cin, _operating_system);
		cout << "Enter notebook optical drive(1 or 0): ";
		cin >> _isOpticalDrive;
		cout << "Enter notebook quantity: ";
		cin >> _quantity;
		cout << endl;
	}

	void showProductDetail() override {
		color(Aqua);
		cout << ">>>>>> Product " << Product::getId() << " Info <<<<<<\n";
		cout << "Notebook id: " << _id << endl;
		cout << "Notebook brand: " << getBrand() << endl;
		cout << "Notebook model: " << getModel() << endl;
		cout << "Notebook processor: " << getProcessor() << endl;
		cout << "Notebook price: " << getPrice() << " AZN" << endl;
		cout << "Notebook ram: " << getRam() << " GB" << endl;
		cout << "Notebook memory (HDD): ";
		(getMemoryHDD() == 0) ? cout << " No" << endl : cout << getMemoryHDD() << " GB" << endl;
		cout << "Notebook memory (SSD): ";
		(getMemorySSD() == 0) ? cout << " No" << endl : cout << getMemorySSD() << " GB" << endl;
		cout << "Notebook operating system: " << getOperatingSystem() << endl;
		cout << "Notebook optical drive: ";
		(getIsOpticalDrive()) ? cout << "Yes\n" : cout << "No\n";
		cout << "Notebook quantity: " << getQuantity() << endl << endl;
	}

	void showProductPreview() override {
		color(Aqua);
		cout << "Product id: " << Product::getId() << endl;
		cout << "Notebook id: " << _id << endl;
		cout << "Notebook name: " << getBrand() << " " << getModel() << endl;
		cout << "Notebook price: " << getPrice() << endl;
		cout << "Notebook quantity: " << getQuantity() << endl << endl;
	}

	friend istream& operator >> (istream& in, Notebook& nb);
};


istream& operator >> (istream& in, Notebook& nb) {
	nb.input();
	return in;
}

size_t Notebook::notebookID = NULL;