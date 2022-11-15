#include "Payment.h"
#include "Windows.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Date date1("07.10.2022");
	date1 -= 2;
	date1.print();
	Date date2(03, 11, 1799);
	date2.print();
	Date date3;
	date3.print();

	cout << Date::dayDifference(date1, date2) << '\n';
	Date currentDate = Date::currentTime();
	currentDate.print();
	cout << Date::compareDates(date1, date2) << '\n';
	cout << Date::isLeapYear(1904) << '\n';
	cout << Date::isValidDate(31, 13, 2000) << '\n';
	cout << Date::dayInMonth(2) << '\n';

	cout << "--------------------------" << '\n';

	/*Payment worker1;
	worker1.print();*/

	Payment worker2(31, 12, 2000);
	worker2.print();

	Payment worker3("01.01.2005");
	worker3.print();

}