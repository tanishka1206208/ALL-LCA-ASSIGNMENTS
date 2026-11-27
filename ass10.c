#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int daysInMonth[] =
        {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31};

    char *months[] =
        {
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"};

    printf("Enter year: ");
    scanf("%d", &year);

    if (year < 1900 || year > 9999)
    {
        printf("Please enter a year between 1900 and 9999.");
        return 1;
    }

    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        daysInMonth[1] = 29;
    }

    struct tm firstDay = {0};

    firstDay.tm_year = year - 1900;
    firstDay.tm_mon = 0;
    firstDay.tm_mday = 1;
    firstDay.tm_isdst = -1;

    time_t t = mktime(&firstDay);

    if (t == (time_t)-1)
    {
        printf("Unable to calculate calendar.");
        return 1;
    }

    struct tm *date = localtime(&t);

    if (date == NULL)
    {
        printf("Unable to determine date.");
        return 1;
    }

    int startDay = date->tm_wday;

    for (month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);

        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        for (day = 0; day < startDay; day++)
        {
            printf("    ");
        }

        for (day = 1; day <= daysInMonth[month]; day++)
        {
            printf("%4d", day);

            if ((startDay + day) % 7 == 0)
            {
                printf("\n");
            }
        }

        printf("\n");

        startDay = (startDay + daysInMonth[month]) % 7;
    }

    return 0;
}