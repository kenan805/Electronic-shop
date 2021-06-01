#pragma once
#include "Exception.h"
using namespace ExceptionNamespace;

class Client {
	size_t _id = NULL;
	string _fullname = "";
	string _phone_number = "";
	string _connected_datetime = "";
public:
	static size_t ClientID;
	Client() = default;
	Client(const string& fullname, const string& phone_number)
	{
		_id = ++ClientID;
		setFullname(fullname);
		setPhoneNumber(phone_number);
		setDatetime();
	}

	size_t getId()const {
		return _id;
	}

	const string& getDatetime()const {
		return _connected_datetime;
	}
	void setDatetime() {
		_connected_datetime = dateTime();
	}

	const string& getFullname()const {
		return _fullname;
	}
	void setFullname(const string& fullname) {
		if (fullname.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Client fullname is null", __LINE__, __FILE__);
		}
		else if (fullname.size() < 3) {
			writeErrorTxtToFile("Error IN003", __LINE__, __FILE__);
			throw InvalidArgumentException("The count of fullname letters must be at least 3!", __LINE__, __FILE__);
		}
		else _fullname = fullname;
	}

	const string& getPhoneNumber()const {
		return _phone_number;
	}
	void setPhoneNumber(const string& phone_number) {
		if (phone_number.empty()) {
			writeErrorTxtToFile("Error N0001", __LINE__, __FILE__);
			throw NullException("Client phone number is null", __LINE__, __FILE__);
		}
		else if (phone_number.size() != 9) {
			writeErrorTxtToFile("Error IN004", __LINE__, __FILE__);
			throw InvalidArgumentException("Phone number must consist of 9 digits!", __LINE__, __FILE__);
		}
		else _phone_number = phone_number;
	}

	void showClientInfo() {
		cout << ">>>>>> CLIENT " << _id << " INFO <<<<<<\n";
		cout << "Fullname: " << getFullname() << endl;
		cout << "Phone number: " << "+994 " << getPhoneNumber() << endl;
		cout << "Connected datetime: " << getDatetime() << endl << endl;
	}
};

void writeClientSignInTxtToFile(const string& fullname) {
	ofstream fout("ClientsSignIn.txt", ios::app);
	if (!fout) {
		writeErrorTxtToFile("N0001", __LINE__, __FILE__);
		throw NullException("File not found!", __LINE__, __FILE__);
	}
	if (fout.is_open()) {
		fout << "New entry made." << endl;
		fout << "Client fullname: " << fullname << endl;
		fout << "Connected datetime: " << dateTime() << endl;
	}
	else
	{
		writeErrorTxtToFile("Error IN005", __LINE__, __FILE__);
		throw InvalidArgumentException("File not open exception!", __LINE__, __FILE__);
	}
	fout.close();
}

void writeClientSignUpTxtToFile(const string& fullname) {
	ofstream fout("ClientsSignUp.txt", ios::app);
	if (!fout) {
		writeErrorTxtToFile("N0001", __LINE__, __FILE__);
		throw NullException("File not found!", __LINE__, __FILE__);
	}
	if (fout.is_open()) {
		fout << "New user registered." << endl;
		fout << "Client fullname: " << fullname << endl;
		fout << "Connected datetime: " << dateTime() << endl;
	}
	else

	{
		writeErrorTxtToFile("IN005", __LINE__, __FILE__);
		throw InvalidArgumentException("File not open exception!", __LINE__, __FILE__);
	}
	fout.close();
}



size_t Client::ClientID = NULL;