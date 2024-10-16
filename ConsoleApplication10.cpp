#include <iostream>
using namespace std;

//1
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

int daysFromStartOfYear(int day, int month, int year) {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        days += daysInMonth(m, year);
    }
    days += day;
    return days;
}

int differenceInDays(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = 0, days2 = 0;

    for (int y = 0; y < year1; ++y) {
        days1 += isLeapYear(y) ? 366 : 365;
    }
    for (int y = 0; y < year2; ++y) {
        days2 += isLeapYear(y) ? 366 : 365;
    }

    days1 += daysFromStartOfYear(day1, month1, year1);
    days2 += daysFromStartOfYear(day2, month2, year2);

    return abs(days2 - days1);
}




//2
double average(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    cout << "Enter the first date (day month year): ";
    cin >> day1 >> month1 >> year1;

    cout << "Enter the second date (day month year): ";
    cin >> day2 >> month2 >> year2;

    int result = differenceInDays(day1, month1, year1, day2, month2, year2);
    cout << "Difference in days: " << result << endl;



    int size;

    cout << "Enter the number of array elements: ";
    cin >> size;

    int arr[size];  

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];

    }
    double avg = average(arr, size);

    cout << "Arithmetic average of array elements: " << avg << endl;

}
