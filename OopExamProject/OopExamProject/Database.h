#pragma once
#include"Exception.h"
#include<list>
#include "Product.h"
#include "Notebook.h"
#include "Smartphone.h"
#include "Client.h"
#include "Category.h"
#include"Admin.h"
#include "Stock.h"
using namespace ExceptionNamespace;

template<typename T>
class DbSet {
	list<T> _items;
public:
	DbSet() = default;

	list<T> getItems()const {
		return _items;
	}

	void add(T* item) {
		_items.push_back(*item);
	}

	bool isExistsItems(const size_t id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id must be greater than 0!", __LINE__, __FILE__);
		}
		for (auto& item : _items)
		{
			if (id == item.getId()) return true;
		}
		return false;
	}

	void deleteById(const size_t& id) {
		if (id < 0) {
			writeErrorTxtToFile("Error IN001", __LINE__, __FILE__);
			throw InvalidArgumentException("Id must be greater than 0!", __LINE__, __FILE__);
		}
		else if (isExistsItems(id)) {
			auto itr = _items.begin();
			advance(itr, id - 1);
			_items.erase(itr);
		}
		else {
			writeErrorTxtToFile("Error DB001", __LINE__, __FILE__);
			throw DatabaseException("There is no product in this id!", __LINE__, __FILE__);
		}
	}

	bool isExistsClients(const string& fullname) {
		if (fullname.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Fullname is null!", __LINE__, __FILE__);
		}
		for (auto& item : _items)
		{
			if (fullname == item.getFullname()) return true;
		}
		return false;
	}


};


class Database {
public:
	Stock* stockDb;
	Category* categories;
	DbSet<Admin>* admins;
	DbSet<Client>* clients;
	Database() = default;
	Database(Stock* stockDb, Category* categories, DbSet<Admin>* admins, DbSet<Client>* clients)
	{
		this->categories = categories;
		this->stockDb = stockDb;
		this->admins = admins;
		this->clients = clients;
	}

	Stock* getStock()const {
		return stockDb;
	}

	Category* getCategories()const {
		return categories;
	}

	DbSet<Admin>* getAdmins()const {
		return admins;
	}

	DbSet<Client>* getClients()const {
		return clients;
	}

	void showAllClients() {
		color(Gray);
		cout << setw(60) << ">>>>>> ALL CLIENTS INFO <<<<<<\n";
		color(Aqua);
		for (auto& i : clients->getItems())
		{
			i.showClientInfo();
		}
	}

	void showAllAdmins() {
		color(Gray);
		cout << setw(60) << ">>>>>> ALL ADMINS INFO <<<<<<\n";
		color(Aqua);
		for (auto& i : admins->getItems())
		{
			i.showAdminInfo();
		}
	}

	bool adminLogin(const string& username, const string& password) {
		for (auto& i : admins->getItems())
		{
			if (i.getUsername() == username) {
				if (i.getPassword() == password) return true;
			}
			else return false;
		}
	}

	bool clientLogin(const string& fullname) {
		for (auto& i : clients->getItems())
		{
			if (i.getFullname() == fullname) return true;
		}
		return false;
	}

	~Database()
	{
		delete stockDb;
		delete categories;
		for (auto& i : admins->getItems())
		{
			delete[] &i;
		}
		delete admins;

		for (auto& i : clients->getItems())
		{
			delete[] &i;
		}
		delete clients;
	}

};
