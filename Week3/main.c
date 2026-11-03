#include <stdio.h>

int main()
{
    char studentName[50];
    float test1, test2, assignment, totalScore;

    printf("=========================================\n");
    printf("      STUDENT GRADE CALCULATOR SYSTEM    \n");
    printf("=========================================\n\n");

    printf("Enter Student Name: ");
    scanf(" %[^\n]s", studentName); 

    printf("Enter Test 1 Mark: ");
    scanf("%f", &test1);

    printf("Enter Test 2 Mark: ");
    scanf("%f", &test2);

    printf("Enter Assignment Mark: ");
    scanf("%f", &assignment);

    totalScore = test1 + test2 + assignment;

    printf("\n-----------------------------------------\n");
    printf("             ASSESSMENT REPORT           \n");
    printf("-----------------------------------------\n");
    printf("Student Name : %s\n", studentName);
    printf("Total Score  : %.2f\n", totalScore);

    if (totalScore >= 75.0 && totalScore <= 100.0)
    {
        printf("Classification: Distinction\n");
    }
    else if (totalScore >= 60.0 && totalScore < 75.0)
    {
        printf("Classification: Credit\n");
    }
    else if (totalScore >= 50.0 && totalScore < 60.0)
    {
        printf("Classification: Pass\n");
    }
    else
    {
        printf("Classification: Fail\n");
    }
    printf("-----------------------------------------\n");

    return 0;
}
