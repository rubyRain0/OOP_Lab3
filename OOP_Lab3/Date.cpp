#include "Date.h"
Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

Date::Date(unsigned int d = 0, unsigned int m = 0, unsigned int y = 0)
{
	setDate(d, m, y);
}
Date::Date(std::string date)
{
	std::vector<std::string> result;
	std::stringstream ss(date);
	std::string item;
	char delim = '.';

	while (std::getline(ss, item, delim)) {
		result.push_back(item);
	}
	setDate(stoi(result[0]), stoi(result[1]), stoi(result[2]));
}

Date::Date(const Date& date)
{
	setDate(date.day, date.month, date.year);
}

int Date::compareDates(const Date& date1, const Date& date2)
{
	int result = 1;
	if (date1.year < date2.year ||
		date1.year == date2.year && date1.month < date2.month ||
		date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)
		result = -1;
	else
		if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
			result = 0;
	return result;
}

bool Date::isLeapYear(unsigned int year) {
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}


int Date::dayInMonth(unsigned int x, unsigned int year)
{
	if (x == 2 && isLeapYear(year))
		return 29;
	else
		return 28 + (x + (x / 8)) % 2 + 2 % x + 2 * (1 / x);
}

Date::~Date()
{
}

bool Date::isValidDate(unsigned int day, unsigned int month, unsigned int year) {
	if ((day < 1 || day>31) ||
		(month < 1 || month>12))
		return false;
	return true;
}

Date& Date::operator+=(int days)
{
	if (this->day + days > maxday())
	{
		this->day = this->day + days - maxday();
		if (++month > 12)
		{
			month = 1;
			year++;
		}
	}
	else this->day += days;
	return *this;
}

Date& Date::operator-=(int days)
{
	int day = this->day;
	if ((day - days) < 1) {
		if (--month == 0) {
			month = 12;
			year--;
		}
		this->day = maxday() - (days - this->day);
	}
	else this->day -= days;
	return *this;
}

Date& Date::operator=(const Date& dateObj)
{
	if (&dateObj != this)
	{
		this->day = dateObj.day;
		this->month = dateObj.month;
		this->year = dateObj.year;
		return *this;
	}
}

int Date::dayDifference(const Date& dateObj1, const Date& dateObj2)
{
	int daysCount = 0;
	if (compareDates(dateObj1, dateObj2) == 1) //dateObj1>dateObj2
	{
		Date copyObj2 = dateObj2;
		while (compareDates(dateObj1, copyObj2) != 0)
		{
			copyObj2 += 1;
			++daysCount;
		}
	}
	else if (compareDates(dateObj1, dateObj2) == -1) // dateObj1<dateObj2
	{
		Date copyObj1 = dateObj1;
		while (compareDates(copyObj1, dateObj2) != 0)
		{
			copyObj1 += 1;
			++daysCount;
		}
	}
	return daysCount;
}

void Date::setDate(int day, int month, int year)
{
	if (isValidDate(day, month, year)) {
		setDay(day);
		setMonth(month);
		setYear(year);
	}
	else {
		throw std::string("Not valid date");
	}
}

int Date::maxday() const
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(this->year))
		days[1] = 29;
	return days[month - 1];
}

Date Date::currentTime()
{
#pragma warning(disable : 4996)
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	Date currentDate(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	return currentDate;
}
int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

void Date::print() const {
	std::cout << day << '/'
		<< month << '/'
		<< year << std::endl;
}