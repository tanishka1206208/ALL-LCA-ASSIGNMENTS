#include <stdio.h>

struct student
{
    int rollno;
    char name[50];
    float marks[3];
    float total, percentage;
};

int main()
{
    struct student s[50];

    char subjects[3][10] = {"PPS", "BEEE", "EP"};

    int n, i, j, choice;

    
    printf("Enter number of students (1-50): ");
    scanf("%d", &n);

    if(n < 1 || n > 50)
    {
        printf("Invalid number of students!");
        return 0;
    }

    
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollno);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;

        for(j = 0; j < 3; j++)
        {
            printf("Enter marks in %s: ", subjects[j]);
            scanf("%f", &s[i].marks[j]);

            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3;
    }

    // Subject selection
    printf("\n========== SELECT SUBJECT ==========\n");

    for(j = 0; j < 3; j++)
        printf("%d. %s\n", j + 1, subjects[j]);

    printf("4. All Subjects\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Display result
    if(choice >= 1 && choice <= 4)
    {
        printf("\n========== STUDENT RESULT ==========\n");

        printf("+--------+----------+");

        if(choice == 4)
        {
            for(j = 0; j < 3; j++)
                printf("--------+");
        }
        else
            printf("--------+");

        printf("-------+------------+--------+\n");

        printf("| Roll No| Name     |");

        if(choice == 4)
        {
            for(j = 0; j < 3; j++)
                printf(" %-6s |", subjects[j]);
        }
        else
            printf(" %-6s |", subjects[choice - 1]);

        printf(" Total | Percentage | Result |\n");

        printf("+--------+----------+");

        if(choice == 4)
        {
            for(j = 0; j < 3; j++)
                printf("--------+");
        }
        else
            printf("--------+");

        printf("-------+------------+--------+\n");

        for(i = 0; i < n; i++)
        {
            printf("| %-6d | %-8s |",
                   s[i].rollno, s[i].name);

            if(choice == 4)
            {
                for(j = 0; j < 3; j++)
                    printf(" %-6.1f |", s[i].marks[j]);
            }
            else
            {
                printf(" %-6.1f |",
                       s[i].marks[choice - 1]);
            }

            printf(" %-5.1f | %-10.2f | %-6s |\n",
                   s[i].total,
                   s[i].percentage,
                   s[i].percentage >= 40 ? "PASS" : "FAIL");
        }

        printf("+--------+----------+");

        if(choice == 4)
        {
            for(j = 0; j < 3; j++)
                printf("--------+");
        }
        else
            printf("--------+");

        printf("-------+------------+--------+\n");
    }
    else
    {
        printf("\nInvalid Choice!");
    }

    // Marks bracket
    printf("\n\n========== MARKS BRACKET ==========\n");

    printf("90 - 100%%  : Outstanding\n");
    printf("75 - 89%%   : Excellent\n");
    printf("40 - 74%%   : Satisfactory\n");
    printf("Below 40%%  : Improvement Required\n");

    return 0;
}
