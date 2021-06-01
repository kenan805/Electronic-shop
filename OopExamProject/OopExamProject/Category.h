#pragma once
#include "Exception.h";
using namespace ExceptionNamespace;
class Category {
	size_t _id = NULL;
	string _name = "";
public:
	static size_t categoryID;
	Category() = default;
	Category(const string& name)
	{
		_id = ++categoryID;
		setName(name);
	}

	size_t getId()const {
		return _id;
	}

	const string& getName()const {
		return _name;
	}
	void setName(const string& name) {
		if (name.empty()) {
			writeErrorTxtToFile("Error N0002", __LINE__, __FILE__);
			throw NullException("Category name null!", __LINE__, __FILE__);
		}
		else _name = name;
	}

	void showCategoryInfo() {
		cout << ">>>>>> CATEGORY " << _id << " INFO <<<<<<\n";
		cout << "Category name: " << getName() << endl;
	}
};

size_t Category::categoryID = NULL;