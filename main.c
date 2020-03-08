/**
 *      Developed by RJ Smith in March of 2020
 *      This is a simple program to calculate the costs of car ownership over one year, written in C.
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

// Prototyping Functions Here
void Welcome();
void FixedCosts();
void VariableCosts();
void Calculate();
void Display();

// Global Variables Here
float monthlyLoan;
float monthlyInsurance;
float yearlyTax;
float gSum;
float rSum;
float pSum;
float mSum;
float lSum;
float iSum;
float total;
float average;

float monthlyLoan = 0.0;
float monthlyInsurance = 0.0;
float yearlyTax = 0.0;

float monthlyGas[YEAR];
float monthlyParking[YEAR];
float monthlyRepairs[YEAR];
float monthlyMisc[YEAR];

int main()
{
    // Functions in proper order.
    Welcome();
    FixedCosts();
    VariableCosts();
    Calculate();
    Display();

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

// This function will do all of the calculations required based on the data entered above.
void Calculate() {

    // This section will calculate the yearly cost for fixed costs.
    // Tax calculations aren't needed since the total yearly amount was already asked above.
    lSum = monthlyLoan * YEAR;
    iSum = monthlyInsurance * YEAR;

    // This for loop will calculate the totals for each variable cost array.
    for (int month = 0; month < YEAR; month++) {
        gSum += monthlyGas[month];
        pSum += monthlyParking[month];
        rSum += monthlyRepairs[month];
        mSum += monthlyMisc[month];
    }

    // This will calculate the overall total.
    total = yearlyTax + lSum + iSum + gSum + pSum + rSum + mSum;
    
    // This will calculate the average cost per month over the year.
    average = total / YEAR;
}

// This function will display the final data to the user.
void Display() {

    // Fixed Cost Totals
    printf("\nYou spent a total of $%.02f on your auto loan. \n", lSum);
    printf("\nYou spent a total of $%.02f on auto insurance. \n", iSum);
    printf("\nYou spent a total of $%.02f on tax. \n", yearlyTax);

    // Variable Cost Totals
    printf("\nYou spent a total of $%.02f on gas. \n", gSum);
    printf("\nYou spent a total of $%.02f on parking. \n", pSum);
    printf("\nYou spent a total of $%.02f on repairs. \n", rSum);
    printf("\nYou spent a total of $%.02f on misc. \n", mSum);

    // Yearly overall total
    printf("\n\nYour yearly total for car ownership was: $%.02f\n", total);
    printf("Your average cost per month was: $%.02f\n", average);
}
