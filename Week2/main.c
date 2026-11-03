#include <stdio.h>

int main()
{
    double revenue, expenses, balance;
    int departments;
    double payroll, procurement, assets;

    printf("=====================================\n");
    printf("   MUNICIPAL BUDGET CALCULATOR\n");
    printf("=====================================\n\n");

    // Main budget inputs
    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    // Calculate balance
    balance = revenue - expenses;

    // Extension exercise inputs
    printf("\nEnter Number of Departments: ");
    scanf("%d", &departments);

    printf("Enter Total Payroll Amount: ");
    scanf("%lf", &payroll);

    printf("Enter Procurement Amount: ");
    scanf("%lf", &procurement);

    printf("Enter Asset Value: ");
    scanf("%lf", &assets);

    // Display report
    printf("\n=====================================\n");
    printf("     MUNICIPAL FINANCIAL SUMMARY\n");
    printf("=====================================\n");

    printf("Revenue          : %.2lf\n", revenue);
    printf("Expenses         : %.2lf\n", expenses);
    printf("Balance          : %.2lf\n", balance);

    printf("\nDepartments      : %d\n", departments);
    printf("Payroll          : %.2lf\n", payroll);
    printf("Procurement      : %.2lf\n", procurement);
    printf("Assets           : %.2lf\n", assets);

    printf("=====================================\n");

    return 0;
}