#pragma once
#include "Product.h"

class Refrigerator :public Product {
	size_t _id = NULL;
	string _color;
	double _totalVolume;
	double _weight;
	size_t	_countDoors;
public:
	static size_t refID;
	Refrigerator() {
		_id = ++refID;
	}
	Refrigerator(const size_t categoryId, const string& productName, const string& brand, const string& model, const double price, const string& color, const double totalVolume, const double weight, const size_t countDoors, const size_t quantity)
		:Product(categoryId, productName, brand, model, price, quantity)
	{
		_id = ++refID;
		setColor(color);
		setTotalVolume(totalVolume);
		setWeight(weight);
		setCountDoors(countDoors);
	}

	size_t getId()const {
		return _id;
	}

	double getTotalVolume()const {
		return _totalVolume;
	}
	void setTotalVolume(const double totalVolume) {
		if (totalVolume < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Volume must be greater than 0!", __LINE__, __FILE__);
		}
		else _totalVolume = totalVolume;
	}

	double getWeight()const {
		return _totalVolume;
	}
	void setWeight(const double weight) {
		if (weight < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Weight must be greater than 0!", __LINE__, __FILE__);
		}
		else _weight = weight;
	}

	size_t getCountDoors()const {
		return _countDoors;
	}
	void setCountDoors(const size_t countDoors) {
		if (countDoors < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Count must be greater than 0!", __LINE__, __FILE__);
		}
		else _countDoors = countDoors;
	}

	const string& getColor()const {
		return _color;
	}
	void setColor(const string& color) {
		if (color.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Refrigerator color null!", __LINE__, __FILE__);
		}
		else _color = color;
	}

	void input() override {
		cout << "Enter refrigerator category id: ";
		cin >> _category_id;
		cout << "Enter refrigerator brand: ";
		cin.ignore();
		getline(cin, _brand);
		cout << "Enter refrigerator model: ";
		getline(cin, _model);
		cout << "Enter refrigerator price: ";
		cin >> _price;
		cout << "Enter notebook color: ";
		cin.ignore();
		getline(cin, _color);
		cout << "Enter notebook total volume: ";
		cin >> _totalVolume;
		cout << "Enter notebook weight: ";
		cin >> _weight;
		cout << "Enter notebook count doors: ";
		cin >> _countDoors;
		cout << "Enter refrigerator quantity: ";
		cin >> _quantity;
		cout << endl;
	}

	void showProductDetail() override {
		color(6);
		cout << ">>>>>> Product " << Product::getId() << " Info <<<<<<\n";
		cout << "Refrigerator id: " << _id << endl;
		cout << "Refrigerator brand: " << getBrand() << endl;
		cout << "Refrigerator model: " << getModel() << endl;
		cout << "Refrigerator price: " << getPrice() << " AZN" << endl;
		cout << "Refrigerator color: " << getColor() << endl;
		cout << "Refrigerator weight: " << getWeight() << " kq" << endl;
		cout << "Refrigerator total volume: " << getTotalVolume() << " lt" << endl;
		cout << "Refrigerator count doors: " << getCountDoors() << endl;
		cout << "Refrigerator quantity: " << getQuantity() << endl<<endl;

	}

	void showProductPreview() override {
		color(6);
		cout << "Product id: " << Product::getId() << endl;
		cout << "Refrigerator id: " << _id << endl;
		cout << "Refrigerator name: " << getBrand() << " " << getModel() << endl;
		cout << "Refrigerator price: " << getPrice() << endl;
		cout << "Refrigerator quantity: " << getQuantity() << endl << endl;
	}

	friend istream& operator >> (istream& in, Refrigerator& rf);
};


istream& operator >> (istream& in, Refrigerator& rf) {
	rf.input();
	return in;
}

size_t Refrigerator::refID = NULL;