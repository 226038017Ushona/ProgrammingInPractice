#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void generateConsolidatedReport() {
    float payroll = getEmployeeTotalPayroll();
    float operationalCosts = getExpenses() + payroll;
    float revenue = getRevenue();
    float balance = revenue - operationalCosts;

    printf("\n==================================================\n");
    printf("       CONSOLIDATED FINANCIAL SUMMARY REPORT      \n");
    printf("==================================================\n");
    printf("Total Registered Staff Count   : %d\n", getEmployeeCount());
    printf("Gross Payroll Expenditure Obligations: NAD %.2f\n", payroll);
    printf("Municipal Revenue Income Pipeline  : NAD %.2f\n", revenue);
    printf("Total Comprehensive Expenses       : NAD %.2f\n", operationalCosts);
    printf("--------------------------------------------------\n");
    printf("Fiscal Year Ledger Balance         : NAD %.2f\n", balance);
    
    if (balance > 0) printf("Current Financial Status Summary   : FISCAL SURPLUS\n");
    else if (balance < 0) printf("Current Financial Status Summary   : BUDGET DEFICIT\n");
    else printf("Current Financial Status Summary   : BALANCED BOOK MATRIX\n");
    printf("==================================================\n");
}
