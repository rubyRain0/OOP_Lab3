#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>

class Date
{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date();
	Date(unsigned int d, unsigned int m, unsigned int y);
	Date(std::string date);
	Date(const Date& date);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	void setDate(int day, int month, int year);

	void print() const;
	int maxday() const;

	Date& operator+=(int days);
	Date& operator-=(int days);
	Date& operator=(const Date& dateObj);

	static int dayDifference(const Date& dateObj1, const Date& dateObj2);
	static bool isValidDate(unsigned int day, unsigned int month, unsigned int year);
	static bool isLeapYear(unsigned int year);
	static int compareDates(const Date& date1, const Date& date2);
	static int dayInMonth(unsigned int x, unsigned int year = 1);
	static Date currentTime();
	~Date();
};

