#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Define getMonthName function
char *getMonthName(int monthNumber);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    // Initial vars
    char *actualMonth; // char var to save actualmonth (to reuse and call getMonthName function only once)
    int month = 0; // to receive month number (starting with zero)
    float reservoirVolumeMax, usedMonth, rainMonth, finalResult, monthReservoirUsed[12], monthRain[12];

    printf("****************************************************** \n");
    printf("**** WELCOME TO RESERVOIR CALCULATOR (RU 2136681) ****\n");
    printf("****************************************************** \n\n");

    // Receive reservoir max volume
    printf("Please, insert the reservoir max volume (mm):\n");
    scanf("%f", &reservoirVolumeMax);

    // Define finalResulr equal max volume
    finalResult = reservoirVolumeMax;

    // While to parse on 12 months (month variable starting with zero)
    while(month < 12) {
        actualMonth = getMonthName(month);
        printf("\n* Seting data to month: %s. Now reservoir max volume is %.2fmm\n", actualMonth, finalResult);

        // Validating finalResult is zero (to show that and cant use reservoir on acutal month)
        if(finalResult == 0) {
            printf("You can't use reservoir, that's empty.\n");
        } else {
            printf("* Reservoir used (mm):\n");
            scanf("%f", &monthReservoirUsed[month]);
        }
    
        printf("* Rain quantity (mm):\n");
        scanf("%f", &monthRain[month]);

        // Printing result on that month
        printf("* Result on %s\n", actualMonth);

        // Saving month reservoir used and rain quantity
        usedMonth = monthReservoirUsed[month];
        rainMonth = monthRain[month];

        // Validating month is zero (Jan) to use reservoirVolumeMax to calculate finalResult. 
        if(month == 0)
            finalResult = reservoirVolumeMax + rainMonth - usedMonth;
        else // If month > 0 finalResult considers finalResult (used on last month)
            finalResult = finalResult + rainMonth - usedMonth;

        printf("* Reservoir used (mm): %.2f\n", usedMonth);
        printf("* Rain quantity (mm): %.2f\n", rainMonth);
        printf("* Final result: %.2f \n", finalResult);

        // Validating reservoir is empty
        if (finalResult == 0) {
            printf("WARNING! On the %s month, reservoir volume is empty! \n", actualMonth);
        } else if(finalResult > reservoirVolumeMax) { // Validating reservoir volume exceeded (leaked water)
            printf("On the %s month, reservoir max volume exceeded with %.2f mm. \n", actualMonth, (finalResult - reservoirVolumeMax));
            finalResult = reservoirVolumeMax; // if leaked water, finalResult is the same reservoirVolumeMax
        } else if(finalResult < reservoirVolumeMax) { // Validating reservoir decrease the volume
            printf("On the %s month, reservoir volume is %.2f mm. \n", actualMonth, finalResult);
        } else { // Validating reservoir is equal max volume
            printf("On the %s month, reservoir volume is equal max volume. \n", actualMonth);
        }

        month++;
        printf("****************************************************** \n");
    }

    // Printing finalResult on dez month
    printf("\n\n****************************************************** \n");
    printf("* RESERVOIR VOLUME ON THE END OF YEAR IS: %.2fmm\n", finalResult);
    printf("****************************************************** \n");

    return 0;
}

// Function to return the month name by month number
char *getMonthName(int monthNumber) {

    // Switch case to identify month number, starting in zero
    switch (monthNumber)
    {
        case 0:
            return "Jan";
            break;
        case 1:
            return "Fev";
            break;
        case 2:
            return "Mar";
            break;
        case 3:
            return "Apr";
            break;
        case 4:
            return "Mai";
            break;
        case 5:
            return "Jun";
            break;
        case 6:
            return "Jul";
            break;
        case 7:
            return "Ago";
            break;
        case 8:
            return "Set";
            break;
        case 9:
            return "Out";
            break;
        case 10:
            return "Nov";
            break;
        case 11:
            return "Dez";
            break;
        default:
            return "";
            break;
    }
}