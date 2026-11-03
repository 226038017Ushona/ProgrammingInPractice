#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employees.h"
#include "utilities.h"

static char empNames[100][MAX_NAME];
static float empSalaries[100];
static int empCount = 0;

void addEmployee() {
    if (empCount >= 100) {
        printf("\nError: Maximum employee storage reached.\n");
        return;
    }
    printf("\nEnter employee name: ");
    fgets(empNames[empCount], MAX_NAME, stdin);
    removeNewline(empNames[empCount]);

    printf("Enter basic salary (NAD): ");
    scanf("%f", &empSalaries[empCount]);
    while (getchar() != '\n'); // clear buffer

    empCount++;
    printf("Employee added successfully.\n");
}

void displayEmployees() {
    printf("\n--- CURRENT EMPLOYEE DIRECTORY ---\n");
    if (empCount == 0) {
        printf("No records in memory. Load from file or add a new entry.\n");
        return;
    }
    for (int i = 0; i < empCount; i++) {
        printf("ID: %d | Name: %-20s | Salary: NAD %.2f\n", i + 1, empNames[i], empSalaries[i]);
    }
}

void searchEmployee() {
    char query[MAX_NAME];
    printf("\nEnter employee name to search: ");
    fgets(query, MAX_NAME, stdin);
    removeNewline(query);

    int found = 0;
    for (int i = 0; i < empCount; i++) {
        if (strcmp(empNames[i], query) == 0) {
            printf("Found! ID: %d | Name: %s | Salary: NAD %.2f\n", i + 1, empNames[i], empSalaries[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee record not found.\n");
}

void saveEmployeesToFile() {
    FILE *fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        perror("Error saving employee data");
        return;
    }
    for (int i = 0; i < empCount; i++) {
        fprintf(fp, "%s|%.2f\n", empNames[i], empSalaries[i]);
    }
    fclose(fp);
    printf("Successfully persisted %d employee records to disk.\n", empCount);
}

void loadEmployeesFromFile() {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Notice: No existing employee file database found. Starting clean.\n");
        return;
    }
    empCount = 0;
    char tempName[MAX_NAME];
    float tempSalary;
    while (fscanf(fp, "%49[^|]|%f\n", tempName, &tempSalary) == 2) {
        strcpy(empNames[empCount], tempName);
        empSalaries[empCount] = tempSalary;
        empCount++;
    }
    fclose(fp);
    printf("Successfully restored %d records from text database.\n", empCount);
}

float getEmployeeTotalPayroll() {
    float total = 0;
    for (int i = 0; i < empCount; i++) total += empSalaries[i];
    return total;
}

int getEmployeeCount() {
    return empCount;
}
