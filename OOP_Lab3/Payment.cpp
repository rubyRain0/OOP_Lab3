#include "Payment.h"

Payment::Payment() : entryDate()
{
    this->fullName = "";
    this->wage = 0;
    this->buffPercent = 0;
    this->daysWorked = 0;
    this->totalWorkDays = 0;
    this->experience = 0;
    this->salary = 0;
}

Payment::Payment(std::string date) : entryDate(date)
{
    setData();
}

Payment::Payment(unsigned int d, unsigned int m, unsigned int y) : entryDate(d, m, y)
{
    setData();
}

double Payment::getAccruedSum() const
{
    return (wage * daysWorked);
}

std::string Payment::getFullName() const
{
    return fullName;
}

Date Payment::getEntryDate() const
{
    return entryDate;
}

double Payment::getWithheldSum() const
{
    double accruedSum = wage * daysWorked;
    return (accruedSum * 0.01 + accruedSum * 0.13);
}

double Payment::getSalary() const
{
    return (daysWorked * wage - (daysWorked * wage * 0.13));
}

int Payment::getExperience() const
{
    Date currentDate = Date::currentTime();
    return dayDifference(currentDate, entryDate) / 365;
}

void Payment::setData()
{
    std::cout << "������� ������� ���������� - ";
    std::cin >> fullName;
    std::cout << "������� ����� ����������  - ";
    std::cin >> wage;
    std::cout << "������� ���-�� ������������ ���� - ";
    std::cin >> daysWorked;
    std::cout << "--------------------------" << '\n';
}

void Payment::print() const
{
    std::cout << "������� ����������: " << getFullName() << '\n';
    std::cout << "���� ���������� �� ���������: "; getEntryDate().print();
    std::cout << "����������� ����� ����������: " << getAccruedSum() << "\n";
    std::cout << "���������� ����� ����������: " << getWithheldSum() << "\n";
    std::cout << "�����, ���������� �� ���� ����������: " << getSalary() << "\n";
    std::cout << "���� ����������: " << getExperience() << "\n";
    std::cout << "--------------------------" << "\n";
}

Payment::~Payment()
{
}
