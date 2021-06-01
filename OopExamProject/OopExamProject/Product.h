#pragma once
#include "Exception.h"
#include<string>
using namespace ExceptionNamespace;

class Product {
protected:
	size_t _id = NULL;
	size_t _category_id = NULL;
	string _name = "";
	string _brand = "";
	string _model = "";
	double _price = NULL;
	size_t _quantity = NULL;
public:
	static size_t productID;
	Product() = default;
	Product(const size_t categoryId, const string& name, const string& brand, const string& model, const double& price, const size_t quantity)
	{
		_id = ++productID;
		setCategoryId(categoryId);
		setName(name);
		setBrand(brand);
		setModel(model);
		setPrice(price);
		setQuantity(quantity);
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

	size_t getCategoryId()const {
		return _category_id;
	}
	void setCategoryId(const size_t categoryId) {
		if (categoryId < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id must be greater than 0!", __LINE__, __FILE__);
		}
		else _category_id = categoryId;
	}

	const string& getName()const {
		return _name;
	}
	void setName(const string& name) {
		if (name.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Product name null!", __LINE__, __FILE__);
		}
		else _name = name;
	}

	const string& getBrand()const {
		return _brand;
	}
	void setBrand(const string& brand) {
		if (brand.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Product brand null!", __LINE__, __FILE__);
		}
		else _brand = brand;
	}

	const string& getModel()const {
		return _model;
	}
	void setModel(const string& model) {
		if (model.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Product model null!", __LINE__, __FILE__);
		}
		else _model = model;
	}

	double getPrice()const {
		return _price;
	}
	void setPrice(const double price) {
		if (price < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Price must be greater than 0!", __LINE__, __FILE__);
		}
		else _price = price;
	}

	size_t getQuantity()const {
		return _quantity;
	}
	void setQuantity(const size_t quantity) {
		if (_quantity < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Quantity must be greater than 0!", __LINE__, __FILE__);
		}
		else _quantity = quantity;
	}

	virtual void input() {}

	virtual void showProductDetail() {}

	virtual void showProductPreview() {}

	friend istream& operator >> (istream& in, Product& p);

};

istream& operator >> (istream& in, Product& p) {
	p.input();
	return in;
}

size_t Product::productID = NULL;

void writeNewProductTxtToFile(Product* product) {
	ofstream fout("Addproduct.txt", ios::app);
	if (!fout) {
		writeErrorTxtToFile("N0002", __LINE__, __FILE__);
		throw NullException("File not found!", __LINE__, __FILE__);
	}
	if (fout.is_open()) {
		fout << "New product added." << endl;
		fout << "Product category id: " << product->getCategoryId() << endl;
		fout << "Product id: " << product->getId() << endl;
		fout << "Product name: " << product->getName() << endl;
		fout << "Product brand: " << product->getBrand() << endl;
		fout << "Product price: " << product->getPrice() << endl;
		fout << "Product quantity: " << product->getQuantity() << endl;
		fout << "Connected datetime: " << dateTime() << endl;
	}
	else
	{
		writeErrorTxtToFile("IN004", __LINE__, __FILE__);
		throw InvalidArgumentException("File not open exception!", __LINE__, __FILE__);
	}
	fout.close();
}

