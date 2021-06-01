#pragma once
#include<list>
#include<iomanip>
#include "Product.h"
using namespace std;


class Stock {
public:
	list<Product*> stock;
	list<Category*> categories;
	list<Product*> cartProducts;

	auto getProductById(size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id must be greater than 0!", __LINE__, __FILE__);
		}
		if (isExistsProducts(id))
		{
			for (auto& i : stock)
			{
				if (id == i->getId()) return i;
			}
		}
		else cout << "Product not found" << endl;
	}

	void addProduct(Product* product) {
		size_t id = stock.size() + 1;
		cin >> *product;
		product->setId(id);
		stock.push_back(product);
		cout << "The product is added .";
		for (size_t i = 0; i < 2; i++)
		{
			Sleep(1000);
			cout << ".";
		}
		cout << "\nThe product was successfully added!" << endl;
		writeNewProductTxtToFile(product);
		Sleep(2000);
	}

	void updateProduct(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id must be greater than 0!", __LINE__, __FILE__);
		}
		else
		{
			cin >> *getProductById(id);
			cout << "Successfully updated." << endl;
			getProductById(id)->showProductPreview();
		}
	}

	void addCategory(Category* category) {
		categories.push_back(category);
		cout << "The category is added .";
		for (size_t i = 0; i < 2; i++)
		{
			Sleep(1000);
			cout << ".";
		}
		cout << "\nThe category was successfully added!" << endl;
		Sleep(2000);
	}

	void addProductToCart(const size_t id) {
		cartProducts.push_back(getProductById(id));
	}

	void deleteAllProductFromCart() {
		cartProducts.clear();
		cout << "The products in the basket have been removed." << endl;
	}

	void deleteProductFromCartById(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		}
		else if (isExistsProducts(id)) {
			cartProducts.remove(getProductById(id));
			cout << "The product is deleted from the cart.";
			for (size_t i = 0; i < 2; i++)
			{
				Sleep(500);
				cout << ".";
			}
			cout << "\nThe product has been successfully deleted from the cart!" << endl;
			Sleep(1400);

		}
		else {
			writeErrorTxtToFile("Error IN006", __LINE__, __FILE__);
			throw InvalidArgumentException("There is no product in this id!", __LINE__, __FILE__);
		}
	}

	void showCart() {


		color(BACKGROUND_INTENSITY);
		double sum = 0;
		for (auto& cartProduct : cartProducts)
		{
			cout << cartProduct->getName() << " id: " << cartProduct->getId() << endl;
			cout << cartProduct->getName() << " name: " << cartProduct->getBrand() << " " << cartProduct->getModel() << endl;
			cout << cartProduct->getName() << " price: " << cartProduct->getPrice() << endl;
			cout << "Quantity remaining in stock: " << cartProduct->getQuantity() << endl << endl;
			sum += cartProduct->getPrice();
		}
		color(Green);
		cout << "Umumi mebleg: " << sum << endl;
		cout << "Umumi mehsul sayi: " << cartProducts.size() << endl;


	}

	bool isExistsCategoriesById(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		}
		for (auto& category : categories)
		{
			if (id == category->getId()) return true;
		}
		return false;
	}

	bool isExistsCategoriesByName(const string& categoryName) {
		if (categoryName == "") {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Category name null!", __LINE__, __FILE__);
		}
		for (auto& category : categories)
		{
			if (categoryName == category->getName()) return true;
		}
		return false;
	}

	void deleteByIdCategory(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		}
		else if (isExistsCategoriesById(id)) {
			auto itr = categories.begin();
			advance(itr, id - 1);
			categories.erase(itr);
			cout << "The category is deleted from the stock.";
			for (size_t i = 0; i < 2; i++)
			{
				Sleep(500);
				cout << ".";
			}
			cout << "\nThe category has been successfully deleted from the stock!" << endl;
			Sleep(1500);
		}
		else {
			writeErrorTxtToFile("Error IN006", __LINE__, __FILE__);
			throw InvalidArgumentException("There is no product in this id!", __LINE__, __FILE__);
		}
	}

	bool isExistsProducts(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		}
		for (auto& product : stock)
		{
			if (id == product->getId()) return true;
		}
		return false;
	}


	list<int> checkId;
	void addCheckId(const size_t id) {
		checkId.push_back(id);
	}

	void deleteAllCheckId() {
		checkId.clear();
	}

	void deleteCheckId(const size_t id) {
		checkId.remove(id);
	}

	bool isExistCartCheckId(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		}
		for (auto& check : checkId)
		{
			if (id == check) return true;
		}
		return false;
	}

	void deleteByIdProductById(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		}
		else if (isExistsProducts(id)) {
			cartProducts.remove(getProductById(id));
			cout << "The product is deleted from the stock.";
			for (size_t i = 0; i < 2; i++)
			{
				Sleep(1000);
				cout << ".";
			}
			cout << "\nThe product has been successfully deleted from the stock!" << endl;
			Sleep(2000);
		}
		else {
			writeErrorTxtToFile("Error IN006", __LINE__, __FILE__);
			throw InvalidArgumentException("There is no product in this id!", __LINE__, __FILE__);
		}
	}

	void showAllProductsDetailInfo() {
		color(Gray);
		cout << setw(60) << ">>>>>> Product detail info <<<<<<" << endl;
		cout << "Count of all products: " << stock.size() << endl;
		int count = 0;
		for (auto& category : categories)
		{
			color(Purple);
			cout << "Category: " << category->getName() << endl;
			for (auto& product : stock)
			{
				if (product->getCategoryId() == category->getId()) {
					count++;
					if (count == 1)
					{
						cout << "Products name: " << product->getName() << endl;
					}
					product->showProductDetail();
				}
			}
			count = 0;
		}
	}

	void showAllProductPreviewInfo() {
		color(Gray);
		cout << setw(60) << ">>>>>> Product preview info <<<<<<" << endl;
		cout << "Count of all products: " << stock.size() << endl;
		int count = 0;
		for (auto& category : categories)
		{
			color(Purple);
			cout << "Category: " << category->getName() << endl;
			for (auto& product : stock)
			{
				if (product->getCategoryId() == category->getId()) {
					count++;
					if (count == 1)
					{
						cout << "Products name: " << product->getName() << endl;
					}
					product->showProductPreview();
				}
			}
			count = 0;
		}
	}

	void showAllCategoryNames() {
		color(Gray);
		cout << setw(60) << ">>>>>> Category names <<<<<<" << endl;
		cout << "Count of all categories: " << categories.size() << endl;
		for (auto& category : categories)
		{
			color(Purple);
			cout << "Category id: " << category->getId() << endl;
			cout << "Category name: " << category->getName() << endl;
		}
		cout << endl;
	}

};