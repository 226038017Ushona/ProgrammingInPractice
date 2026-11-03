#include <stdio.h>
#include <string.h>
#include "records.h"

#define FILE_NAME "staff.dat"



void swapSalaries(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void updateSalary(Employee *e, double newSalary) {
    if (e != NULL) {
        e->salary = newSalary;
    }
}

Employee *findEmployee(Employee list[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i]; 
        }
    }
    return NULL; 
}

void saveEmployees(const Employee list[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        perror("Error opening file for saving");
        return;
    }
    fwrite(list, sizeof(Employee), count, fp);
    fclose(fp);
    printf("[Disk] Saved %d records to %s\n", count, FILE_NAME);
}

int loadEmployees(Employee list[], int maxRecords) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("[Disk] No existing database file found. Starting fresh.\n");
        return 0;
    }
    size_t loaded = fread(list, sizeof(Employee), maxRecords, fp);
    fclose(fp);
    printf("[Disk] Loaded %zu records from disk.\n", loaded);
    return (int)loaded;
}


int main(void) {
    Employee staff[MAX_RECORDS];
    int currentStaffCount = 0;

    printf("=== STEP 1: LOADING DATA ===\n");
    currentStaffCount = loadEmployees(staff, MAX_RECORDS);

    if (currentStaffCount == 0) {
        printf("Populating 3 sample records...\n");
        
        staff[0].id = 1001;
        strcpy(staff[0].name, "Maria");
        strcpy(staff[0].department, "Finance");
        staff[0].salary = 18500.50;

        staff[1].id = 1002;
        strcpy(staff[1].name, "Simon");
        strcpy(staff[1].department, "Admin");
        staff[1].salary = 17200.00;

        staff[2].id = 1003;
        strcpy(staff[2].name, "Anna");
        strcpy(staff[2].department, "Tech");
        staff[2].salary = 21000.75;

        currentStaffCount = 3;
    }

    printf("\n=== STEP 2: DISPLAY CURRENT STAFF ===\n");
    for (int i = 0; i < currentStaffCount; i++) {
        printf("ID: %d | Name: %-6s | Dept: %-8s | Salary: N$%.2f\n",
               staff[i].id, staff[i].name, staff[i].department, staff[i].salary);
    }

    printf("\n=== STEP 3: POINTER MODIFICATION (WEEK 12) ===\n");
    int targetId = 1002; /* Let's look up Simon */
    printf("Searching for Employee ID %d...\n", targetId);
    Employee *found = findEmployee(staff, currentStaffCount, targetId);

    if (found != NULL) {
        printf("Found %s. Updating salary from N$%.2f to N$19500.00...\n", found->name, found->salary);
        updateSalary(found, 19500.00); /* Uses -> operator inside */
        printf("Verification: %s now earns N$%.2f in the array.\n", found->name, found->salary);
    }

    printf("\n=== STEP 4: TERMINATION & SAVING RESCUE ===\n");
    saveEmployees(staff, currentStaffCount);

    printf("\nProgram finished successfully. Run it again to see changes persist!\n");
    return 0;
}
