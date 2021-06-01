#pragma once
#include "Time.h"
#include<iomanip>
#include<fstream>
#include "Color.h"

namespace ExceptionNamespace {
	class Exception {
	protected:
		string errorText;
		size_t line;
		string source;
		string dateTime;
	public:
		Exception(const string& errorText, const size_t& line, const string& source)
		{
			setErrorText(errorText);
			setLine(line);
			setSource(source);
			setDateTime();
		}

		string getErrorText()const {
			return errorText;
		}
		size_t getLine()const {
			return line;
		}
		string getSource()const {
			return source;
		}
		string getDateTime()const {
			return dateTime;
		}

		void setErrorText(const string& errorText) {
			if (errorText.empty()) throw "Text is empty";
			this->errorText = errorText;
		}
		void setLine(const size_t& line) {
			if (line < 0) throw "Line cannot be negative";
			this->line = line;
		}
		void setSource(const string& source) {
			if (source.empty()) throw "Source is empty";
			this->source = source;
		}
		void setDateTime() {
			time_t currently = time(0);
			char dt[30]{};
			ctime_s(dt, sizeof dt, &currently);
			string time = dt;

			this->dateTime = dt;
		}

	public:
		void printErrorMsg() {
			color(Red);
			cout << ">>>>>> Exception Info <<<<<<" << endl;
			cout << "Text: " << getErrorText() << endl;
			cout << "Line: " << getLine() << endl;
			cout << "Source: " << getSource() << endl;
			cout << "Datetime: " << getDateTime() << endl << endl;
		}
	};

	class InvalidArgumentException :public Exception {
	public:
		InvalidArgumentException(const string& errorText, const size_t& line, const string& source)
			:Exception(errorText, line, source)
		{

		}
	};

	class NullException :public Exception {
	public:
		NullException(const string& errorText, const size_t& line, const string& source)
			:Exception(errorText, line, source)
		{

		}
	};

	class DatabaseException :public Exception {
	public:
		DatabaseException(const string& errorText, const size_t& line, const string& source)
			:Exception(errorText, line, source)
		{

		}
	};

	void writeErrorTxtToFile(const string& errorCode, const size_t& line, const string& file) {
		ofstream fout("Log.txt", ios_base::app);
		if (!fout) throw NullException("File not found!", __LINE__, __FILE__);
		if (fout.is_open()) {
			fout << "Error code: " << errorCode << endl;
			fout << "Line: " << line + 1 << endl;
			fout << "Source: " << file << endl;
			fout << "Datetime: " << dateTime() << endl << endl;
		}
		else
		{
			throw InvalidArgumentException("File not open exception!", __LINE__, __FILE__);
		}
		fout.close();
	}

}

