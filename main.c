/**
 *      Developed by RJ Smith in March of 2020
 *      This is a simple C program to calculate the costs of car repairs over one month.
 *
 *      You can reach me on the following platforms:
 *      Twitter @ tupleHunden
 *      Discord @ Alch#6096
 *      GitHub @ tupleHunden
 *
 *      Thanks for checking this out!
 */

#include <stdio.h>

// Defining the max number of months in a year.
#define YEAR 12

// Defining the max number of days in a month.
#define MONTH 31

// Defining the max number of days in a week.
#define WEEK 7

// Prototyping Functions Here
void Welcome();
void FixedCosts();
void VariableCosts();

// Global Variables Here
float monthlyLoan;
float monthlyInsurance;
float yearlyTax;

float monthlyLoan = 0.0;
float monthlyInsurance = 0.0;
float yearlyTax = 0.0;

float monthlyGas[YEAR];
float monthlyParking[YEAR];
float monthlyRepairs[YEAR];
float monthlyMisc[YEAR];


int main()
{
    Welcome();
    FixedCosts();
    VariableCosts();


    return 0;
}

// Simple information function to display some welcome text.
void Welcome ()
{
    printf("\nWelcome to the Yearly Car Cost Estimator! \n");
    printf("This program will calculate the average car costs for the year. \n");
    printf("If you have any questions or comments about this program please reach out! \n");
    printf("I am relatively new to the C Programing Language so any feedback is greatly appreciated. \n \n");
    printf("I can be reached at Twitter @ tupleHunden, Discord @ Alch#6096, or GitHub @ tupleHunden \n \n");
}

// This function will collect the costs of services or goods that won't change month to month.
void FixedCosts() {

    // Prompt the user for the monthly car payment cost.
    printf("How much do you pay each month for your car payment? \n$: ");
    scanf("%f", &monthlyLoan);

    // Verify that the number was positive, if it was negative keep asking the user until a valid entry is made.
    while (monthlyLoan < 0) {
        printf("Please enter a number 0 or higher. \n$: ");
        scanf("%f", &monthlyLoan);
    }

    // Prompt the user for the monthly car insurance costs.
    printf("How much do you pay each month for car insurance? \n$: ");
    scanf("%f", &monthlyInsurance);

    // Verify that the number was positive, if it was negative keep asking the user until a valid entry is made.
    while (monthlyInsurance < 0) {
        printf("Please enter a number 0 or higher. \n$: ");
        scanf("%f", &monthlyInsurance);
    }

    // Prompt the user for the monthly tax cost for the car.
    printf("How much do you pay each month for taxes on your car? \n$: ");
    scanf("%f", &yearlyTax);

    // Verify that the number was positive, if it was negative keep asking the user until a valid entry is made.
    while (yearlyTax < 0) {
        printf("Please enter a number 0 or higher. \n$: ");
        scanf("%f", &yearlyTax);
    }
}

// This function will collect costs of services or goods that can change month to month.
void VariableCosts()
{
    // For loop to collect the monthly costs that can change.
    for (int month = 0; month < YEAR; month++) {

        // Prompt the user for monthly gas costs.
        printf("How much did you spend on gas for month %d? \n$: ", month + 1);
        scanf("%f", &monthlyGas[month]);

        // Verify that the number was positive, if it was negative keep asking the user until a valid entry is made.
        while (monthlyGas[month] < 0) {
            printf("Please enter a number 0 or higher. \n");
            scanf("%f", &monthlyGas[month]);
        }

        // Prompt the user for monthly parking costs.
        printf("How much did you spend on parking for month %d? \n$: ", month + 1);
        scanf("%f", &monthlyParking[month]);

        // Verify that the number was positive, if it was negative keep asking the user until a valid entry is made.
        while (monthlyParking[month] < 0) {
            printf("Please enter a number 0 or higher. \n");
            scanf("%f", &monthlyParking[month]);
        }

        // Prompt the user for monthly repair costs.
        printf("How much did you spend on repairs for month %d? \n$: ", month + 1);
        scanf("%f", &monthlyRepairs[month]);

        // Verify that the number was positive, if it was negative keep asking the user until a valid entry is made.
        while (monthlyRepairs[month] < 0) {
            printf("Please enter a number 0 or higher. \n");
            scanf("%f", &monthlyRepairs[month]);
        }

        // Prompt the user for monthly misc. costs.
        printf("How much did you spend on miscellaneous costs for month %d? \n$: ", month + 1);
        scanf("%f", &monthlyMisc[month]);

        // Verify that the number was positive, if it was negative keep asking the user until a valid entry is made.
        while (monthlyMisc[month] < 0) {
            printf("Please enter a number 0 or higher. \n");
            scanf("%f", &monthlyMisc[month]);
        }
    }
}