#include <stdio.h>

int main(){

    int stateCode;
    int chargeCode;
    int pricePerKg;
    int porcentTax;
    float totalChargePrice;
    float totalTaxValue;
    float totalPrice;
    float chargeWeightTon;
    float chargeWeightKg;

    printf("Please, insert the state code: ");
    scanf("%d", &stateCode);

    printf("\nPlease, insert the charge wight value (value in ton): ");
    scanf("%f", &chargeWeightTon);

    printf("\nPlease, insert the charge code: ");
    scanf("%d", &chargeCode);

    chargeWeightKg = (chargeWeightTon*1000);

    if((chargeCode >= 10) && (chargeCode <= 20)){
        pricePerKg = 100;
    }else if((chargeCode >= 21) && (chargeCode <= 30)){
        pricePerKg = 250;
    }else  if((chargeCode >= 31) && (chargeCode <= 40)){
        pricePerKg = 340;
    }else{
        return 0;
    }

    switch (stateCode){
        case 1:
            porcentTax = 35;
            break;
        case 2:
            porcentTax = 25;
            break;
        case 3:
            porcentTax = 15;
            break;
        case 4:
            porcentTax = 5;
            break;
        case 5:
            porcentTax = 0;
            break;
    }

    totalChargePrice = (pricePerKg*chargeWeightKg);
    totalTaxValue = ((chargeWeightKg/100)*porcentTax);
    totalPrice = totalChargePrice+totalTaxValue;

    printf("\n ------------------------------- \n");

    printf("The charge wieght in kg is: %.2f \n", chargeWeightKg);

    printf("The charge price is: %.2f \n", totalChargePrice);

    printf("The value tax is: %.2f \n", totalTaxValue);

    printf("The total price of weight is: %.2f", totalPrice);


    printf("\n ------------------------------- \n \n ");

}
