#pragma once
#include "Date.h" 
#include <iostream>
#include <string>

class Payment : public Date
{
private:
    std::string fullName; //Фио
    double wage; //оклад
    Date entryDate; //дата поступления на работу
    double buffPercent; //процент надбавки
    int daysWorked; //кол-во отработанных дней
    int totalWorkDays; //кол-во рабочих дней
    int experience; //стаж (полное кол-во лет)
    double salary; //зарплата
public:
    Payment();
    Payment(std::string date);
    Payment(unsigned int d, unsigned int m, unsigned int y);

    double getAccruedSum() const;
    std::string getFullName() const;
    Date getEntryDate() const;
    double getWithheldSum() const;
    double getSalary() const;
    int getExperience() const;

    void setData();
    void print() const;

    ~Payment();
};