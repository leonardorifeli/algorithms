#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Define main functions
int isLeapYear(int year);
void showAllLeapYearInAge(int age);
void startShowAllLeapYear(int start, int page);

int main() {
    // Set Portuguese with locale
    setlocale(LC_ALL, "Portuguese");

    // Define year and age variables
    int year, age;

    printf("Please, insert the year (ex: 2020): ");
    scanf("%d", &year);

    // Validate year is leap year
    if(isLeapYear(year) == 1)
        printf("- %d is a leap year!\n", year);
    else
        printf("- %d is not a leap year!\n", year);
    
    // Getting age to show all leap year
    printf("\nPlease, insert the age (ex: 16): ");
    scanf("%d", &age);

    // Calling function to show all leap age
    showAllLeapYearInAge(age);

    return 0;
}

// isLeapYear function to validate is leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
        return 1;

    return 0;
}

// showAllLeapYearInAge is main function to show all leap year on age
void showAllLeapYearInAge(int age) {
    int count = 0, i;
    int start = (100 * age) - 99;

    printf("\n***SHOWING ALL LEAP YEAR ON %d AGE.\n", age);

    startShowAllLeapYear(start, 1);
}

// startShowAllLeapYear is recursive function to show all leap year on age
void startShowAllLeapYear(int start, int page) {
    // Validate page == 100 to cancel execution (execute to 99 only)
    if(page == 100)
        return;

    if(isLeapYear(start) == 1)
        printf("- %d is a leap year!\n", start);

    startShowAllLeapYear(++start, ++page);
}