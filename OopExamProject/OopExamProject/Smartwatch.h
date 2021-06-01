#pragma once
#include "Product.h"

class Smartwatch :public Product {
	size_t _id;
	string _screen_type;
	string _processor;
	size_t _memory;
public:
	static size_t smartwatchID;
	Smartwatch() {
		_id = ++smartwatchID;
	}
	Smartwatch(const size_t categoryId, const string& productName, const string& brand, const string& model, const string& screen_type, const string& processor, const size_t memory, const size_t price, const size_t quantity)
		:Product(categoryId, productName, brand, model, price, quantity)
	{
		_id = ++smartwatchID;
		setScreenType(screen_type);
		setProcessor(processor);
		setMemory(memory);
	}

	size_t getId()const {
		return _id;
	}
	void setId(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
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

	const string& getScreenType()const {
		return _screen_type;
	}
	void setScreenType(const string& screen_type) {
		if (screen_type.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Smartwatch screen type null!", __LINE__, __FILE__);
		}
		else _screen_type = screen_type;
	}

	void input() override {
		cout << "Enter smartwatch category id: ";
		cin >> _category_id;
		cout << "Enter smartwatch brand: ";
		cin.ignore();
		getline(cin, _brand);
		cout << "Enter smartwatch model: ";
		getline(cin, _model);
		cout << "Enter smartwatch processor: ";
		getline(cin, _processor);
		cout << "Enter smartwatch screen type: ";
		getline(cin, _screen_type);
		cout << "Enter smartwatch memory: ";
		cin >> _memory;
		cout << "Enter smartwatch price: ";
		cin >> _price;
		cout << "Enter smartwatch quantity: ";
		cin >> _quantity;
		cout << endl;
	}
	void showProductDetail() override {
		color(Aqua);
		cout << ">>>>>> Product " << Product::getId() << " Info <<<<<<\n";
		cout << "Smartwatch id: " << _id << endl;
		cout << "Smartwatch brand: " << getBrand() << endl;
		cout << "Smartwatch model: " << getModel() << endl;
		cout << "Smartwatch processor: " << getProcessor() << endl;
		cout << "Smartwatch memory: " << getMemory() << " GB" << endl;
		cout << "Smartwatch screen type: " << getScreenType() << endl;
		cout << "Smartwatch price: " << getPrice() << " AZN" << endl;
		cout << "Smartwatch quantity: " << getQuantity() << endl << endl;
	}

	void showProductPreview() override {
		color(Aqua);
		cout << "Product id: " << Product::getId() << endl;
		cout << "Smartwatch id: " << _id << endl;
		cout << "Smartwatch name: " << getBrand() << " " << getModel() << endl;
		cout << "Smartwatch price: " << getPrice() << endl;
		cout << "Smartwatch quantity: " << getQuantity() << endl << endl;
	}

	friend istream& operator >> (istream& in, Smartwatch& nb);
};


istream& operator >> (istream& in, Smartwatch& sw) {
	sw.input();
	return in;
}

size_t Smartwatch::smartwatchID = NULL;