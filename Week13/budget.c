#include <stdio.h>
#include "budget.h"

static float totalRevenue = 0.0f;
static float totalExpenses = 0.0f;

void configureBudgets() {
    printf("\nEnter structural municipal revenue targets (NAD): ");
    scanf("%f", &totalRevenue);
    printf("Enter baseline physical project operational expenses (NAD): ");
    scanf("%f", &totalExpenses);
    while (getchar() != '\n');
    printf("Budget configurations updated.\n");
}

void saveBudgetToFile() {
    FILE *fp = fopen("budget.txt", "w");
    if (fp == NULL) {
        perror("Error saving ledger configuration");
        return;
    }
    fprintf(fp, "%.2f|%.2f\n", totalRevenue, totalExpenses);
    fclose(fp);
    printf("Budget ledger successfully saved to disk.\n");
}

void loadBudgetFromFile() {
    FILE *fp = fopen("budget.txt", "r");
    if (fp == NULL) {
        printf("Notice: Budget transaction ledger not found. Starting with zero values.\n");
        return;
    }
    if (fscanf(fp, "%f|%f\n", &totalRevenue, &totalExpenses) != 2) {
        totalRevenue = 0.0f;
        totalExpenses = 0.0f;
    }
    fclose(fp);
    printf("Budget allocations synced successfully from file.\n");
}

float getRevenue() { return totalRevenue; }
float getExpenses() { return totalExpenses; }
