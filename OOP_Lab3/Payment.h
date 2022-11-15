#pragma once
#include "Date.h" 
#include <iostream>
#include <string>

class Payment : public Date
{
private:
    std::string fullName; //���
    double wage; //�����
    Date entryDate; //���� ����������� �� ������
    double buffPercent; //������� ��������
    int daysWorked; //���-�� ������������ ����
    int totalWorkDays; //���-�� ������� ����
    int experience; //���� (������ ���-�� ���)
    double salary; //��������
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