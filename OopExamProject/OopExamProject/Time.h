#pragma once
#include<iostream>
using namespace std;

string dateTime() {
	time_t currently = time(0);
	char dt[30]{};
	ctime_s(dt, sizeof dt, &currently);
	string time = dt;
	return time;
}