#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char *getMonthName(int monthNumber);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int month = 0;
    float reservoirVolumeMax, monthReservoirUsed[12], monthRain[12];

    printf("****************************************************** \n");
    printf("******** WELCOME TO RESERVOIR CALCULATOR *************\n");
    printf("****************************************************** \n\n");

    printf("Please, insert the reservoir max volume:\n");
    scanf("%f", &reservoirVolumeMax);

    while(month < 12) {
        printf("\nSet data to month: %s\n", getMonthName(month));

        printf("* Reservoir used:\n");
        scanf("%f", &monthReservoirUsed[month]);

        printf("* Rain quantity:\n");
        scanf("%f", &monthRain[month]);

        month++;
        printf("****************************************************** \n");
    }

    printf("FINAL RESULT:");

    return 0;
}

char *getMonthName(int monthNumber) {
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