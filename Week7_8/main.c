#include <stdio.h>
#include <string.h>

void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void removeNewline(char str[]);

char supplierName[100] = "No Supplier Registered";
char email[100] = "N/A";
char phone[30] = "N/A";
char town[50] = "N/A";
int hasSupplier = 0; 
int main() 
{
    int choice;
    float financialAmount, basic, housing, transport, revenue, expenses;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                printf("\nEnter purchase amount for VAT calculation: ");
                scanf("%f", &financialAmount);
                printf("Calculated VAT (15%%): NAD %.2f\n", calculateVAT(financialAmount));
                break;
            case 5:
                printf("\nEnter Basic Salary: ");
                scanf("%f", &basic);
                printf("Enter Housing Allowance: ");
                scanf("%f", &housing);
                printf("Enter Transport Allowance: ");
                scanf("%f", &transport);
                printf("Calculated Gross Salary: NAD %.2f\n", calculateSalary(basic, housing, transport));
                break;
            case 6:
                printf("\nEnter Projected Municipal Revenue: ");
                scanf("%f", &revenue);
                printf("Enter Projected Municipal Expenses: ");
                scanf("%f", &expenses);
                
                float balance = calculateBudget(revenue, expenses);
                printf("Budget Balance: NAD %.2f\n", balance);
                
                if (balance > 0) {
                    printf("Fiscal Status  : SURPLUS\n");
                } else if (balance < 0) {
                    printf("Fiscal Status  : DEFICIT\n");
                } else {
                    printf("Fiscal Status  : BALANCED\n");
                }
                break;
            case 7:
                printf("\nExiting Municipal System. Goodbye.\n");
                break;
            default:
                printf("\nError: Invalid alternative selected. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void displayMenu() 
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("----------------------------------------\n");
    printf("Enter choice: ");
}

void addSupplier() 
{
    printf("\n--- Register New Supplier ---\n");
    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    removeNewline(supplierName);

    printf("Enter email address: ");
    fgets(email, sizeof(email), stdin);
    removeNewline(email);

    printf("Enter phone number: ");
    fgets(phone, sizeof(phone), stdin);
    removeNewline(phone);

    printf("Enter operations town: ");
    fgets(town, sizeof(town), stdin);
    removeNewline(town);

    hasSupplier = 1;
    printf("\nSuccess: Supplier data stored successfully.\n");
}

void displaySupplier() 
{
    printf("\n--- CURRENT SUPPLIER RECORD ---\n");
    if (!hasSupplier) {
        printf("No data recorded yet. Select option 1 to add a record.\n");
        return;
    }
    printf("Name        : %s\n", supplierName);
    printf("Email       : %s\n", email);
    printf("Phone       : %s\n", phone);
    printf("Town        : %s\n", town);
    printf("Name Length : %zu characters\n", strlen(supplierName)); //
}

void searchSupplier() 
{
    char searchName[100];
    printf("\nEnter exact supplier name to query: ");
    fgets(searchName, sizeof(searchName), stdin);
    removeNewline(searchName);

    if (hasSupplier && strcmp(supplierName, searchName) == 0) {
        printf("Result: Supplier '%s' found in active directory.\n", searchName);
    } else {
        printf("Result: Supplier '%s' not found.\n", searchName);
    }
}

float calculateVAT(float amount) 
{
    return amount * 0.15f; 
}

float calculateSalary(float basic, float housing, float transport) 
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) 
{
    return revenue - expenses; 
}

void removeNewline(char str[]) 
{
    str[strcspn(str, "\n")] = '\0';
}
