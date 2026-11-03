#include <stdio.h>

#define SIZE 50 

int main() 
{
    float salaries[SIZE];
    float total = 0;
    float average = 0;
    float highest = 0;
    float lowest = 0;
    float searchSalary;
    float temp;
    int found = 0;

    printf("==================================================\n");
    printf("        MUNICIPAL EMPLOYEE SALARY SYSTEM          \n");
    printf("==================================================\n\n");

    for (int i = 0; i < SIZE; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        
        total += salaries[i];

        if (i == 0) {
            highest = salaries[i];
            lowest = salaries[i];
        }
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    printf("\n--- Captured Salaries List ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    average = total / SIZE;

    printf("\n==================================================\n");
    printf("                SALARY ANALYSIS REPORT             \n");
    printf("==================================================\n");
    printf("Total Salary Expenditure : NAD %.2f\n", total);
    printf("Average Employee Salary  : NAD %.2f\n", average);
    printf("Highest Captured Salary  : NAD %.2f\n", highest);
    printf("Lowest Captured Salary   : NAD %.2f\n", lowest);
    printf("--------------------------------------------------\n");

    printf("\nEnter a specific salary amount to search for: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < SIZE; i++) {
        if (salaries[i] == searchSalary) {
            printf("Success: Value %.2f found at Employee Position %d\n", searchSalary, i + 1);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Notice: Salary amount %.2f was not found in the system.\n", searchSalary);
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\n==================================================\n");
    printf("          SORTED SALARIES (LOWEST TO HIGHEST)      \n");
    printf("==================================================\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Position %d: NAD %.2f\n", i + 1, salaries[i]);
    }
    printf("==================================================\n");

    return 0;
}
