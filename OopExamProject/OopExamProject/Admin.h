#pragma once
#include "Exception.h"
using namespace ExceptionNamespace;

class Admin {
	size_t _id=NULL;
	string _username = "";
	string _password = "";
public:
	static size_t AdminID;
	Admin() = default;
	Admin(const string& username, const string& password)
	{
		_id = ++AdminID;
		setUsername(username);
		setPassword(password);
	}

	size_t getId()const {
		return _id;
	}

	const string& getUsername()const {
		return _username;
	}
	void setUsername(const string& username) {
		if (username.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Admin username null!", __LINE__, __FILE__);
		}
		else _username = username;
	}
	const string& getPassword()const {
		return _password;
	}
	void setPassword(const string& password) {
		if (password.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Admin password null!", __LINE__, __FILE__);
		}
		else _password = password;
	}

	void showAdminInfo() {
		color(Green);
		cout << ">>>>>> ADMIN " << _id << " INFO <<<<<<\n";
		cout << "Username: " << getUsername() << endl;
		cout << "Password: " << string(getPassword().size(), '*') << endl;
	}
};

size_t Admin::AdminID = NULL;

