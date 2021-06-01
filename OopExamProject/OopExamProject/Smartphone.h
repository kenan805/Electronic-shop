#pragma once
#include "Product.h"

class Smartphone :public Product {
	size_t _id = NULL;
	size_t _ram = NULL;
	size_t _memory = NULL;
	string _operating_system = "";
	size_t _sim_card_count = NULL;
	bool _isFingerReader = false;
public:
	static size_t phoneID;
	Smartphone() {
		_id = ++phoneID;
	}
	Smartphone(const size_t categoryId, const string& productName, const string& brand, const string& model, const double price, const size_t ram, const size_t memory, const string& operating_system, const size_t sim_card_count, const bool isFingerReader, const size_t quantity)
		:Product(categoryId, productName, brand, model, price, quantity)
	{
		_id = ++phoneID;
		setRam(ram);
		setMemory(memory);
		setOperatingSystem(operating_system);
		setSimCardCount(sim_card_count);
		setIsFingerReader(isFingerReader);
	}

	size_t getId()const {
		return _id;
	}

	size_t getRam()const {
		return _ram;
	}
	void setRam(const size_t ram) {
		if (ram < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Ram must be greater than 0!", __LINE__, __FILE__);
		}
		else _ram = ram;
	}

	size_t getMemory()const {
		return _memory;
	}
	void setMemory(const size_t memory) {
		if (memory < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Memory must be greater than 0!", __LINE__, __FILE__);
		}
		else _memory = memory;
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

	size_t getSimCardCount()const {
		return _memory;
	}
	void setSimCardCount(const size_t sim_card_count) {
		if (sim_card_count < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Sim card count must be greater than 0!", __LINE__, __FILE__);
		}
		else _sim_card_count = sim_card_count;
	}

	bool getIsFingerReader()const {
		return _isFingerReader;
	}
	void setIsFingerReader(const bool& isFingerReader) {
		_isFingerReader = isFingerReader;;
	}




	void input() override {
		cout << "Enter smartphone category id: ";
		cin >> _category_id;
		cout << "Enter smartphone brand: ";
		cin.ignore();
		getline(cin, _brand);
		cout << "Enter smartphone model: ";
		getline(cin, _model);
		cout << "Enter smartphone price: ";
		cin >> _price;
		cout << "Enter smartphone ram: ";
		cin >> _ram;
		cout << "Enter smartphone memory: ";
		cin >> _memory;
		cout << "Enter smartphone sim card count: ";
		cin >> _sim_card_count;
		cout << "Enter smartphone finger reader(1 or 0): ";
		cin >> _isFingerReader;
		cout << "Enter smartphone quantity: ";
		cin >> _quantity;
		cout << endl;
	}

	void showProductDetail()override {
		color(14);
		cout << ">>>>>> Product " << Product::getId() << " Info <<<<<<\n";
		cout << "Smartphone id: " << _id << endl;
		cout << "Smartphone brand: " << getBrand() << endl;
		cout << "Smartphone model: " << getModel() << endl;
		cout << "Smartphone price: " << getPrice() << " AZN" << endl;
		cout << "Smartphone ram: " << getRam() << endl;
		cout << "Smartphone memory: " << getMemory() << endl;
		cout << "Smartphone sim card count: " << getSimCardCount() << endl;
		cout << "Smartphone finger reader: ";
		(getIsFingerReader()) ? cout << "Yes\n" : cout << "No\n";
		cout << "Smartphone quantity: " << getQuantity() << endl << endl;
	}

	void showProductPreview() override {
		color(14);
		cout << "Product id: " << Product::getId() << endl;
		cout << "Smartphone id: " << getId() << endl;
		cout << "Smartphone name: " << getBrand() << " " << getModel() << endl;
		cout << "Smartphone price: " << getPrice() << endl;
		cout << "Smartphone quantity: " << getQuantity() << endl << endl;
	}
};

size_t Smartphone::phoneID = NULL;