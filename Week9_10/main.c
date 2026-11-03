#include <stdio.h>
#include <stdlib.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"

int main() {
    int choice;

    loadEmployeesFromFile();
    loadBudgetFromFile();

    do {
        printf("\n==================================================\n");
        printf("   MODULAR MUNICIPAL MANAGEMENT RESOURCE INTERFACE \n");
        printf("==================================================\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Employee Records\n");
        printf("3. Query/Search Employee by Name\n");
        printf("4. Configure Revenue & Budget Baselines\n");
        printf("5. Generate Consolidated Financial Report\n");
        printf("6. Force Save Data to Disk Storage\n");
        printf("7. Exit Application\n");
        printf("--------------------------------------------------\n");
        printf("Select Operational Option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection entry.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); // clear buffer

        switch (choice) {
            case 1: addEmployee(); pauseScreen(); break;
            case 2: displayEmployees(); pauseScreen(); break;
            case 3: searchEmployee(); pauseScreen(); break;
            case 4: configureBudgets(); pauseScreen(); break;
            case 5: generateConsolidatedReport(); pauseScreen(); break;
            case 6: 
                saveEmployeesToFile(); 
                saveBudgetToFile(); 
                pauseScreen(); 
                break;
            case 7: 
                saveEmployeesToFile(); 
                saveBudgetToFile(); 
                printf("\nExiting System. All session state logs closed cleanly.\n"); 
                break;
            default: printf("Error: Invalid choice option.\n"); pauseScreen();
        }
    } while (choice != 7);

    return 0;
}
