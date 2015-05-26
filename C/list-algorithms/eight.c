#include <stdio.h>

main (){

    int codeState;
    int codeLoad;
    int pricePerWeight;
    int percentPerCode;
    float weight;
    float priceAmountLoad;
    float priceTax;

    printf("Please, insert the code of state origin \n");
    scanf("%d", &codeState);

    if(codeState == 1){
        percentPerCode = 35;
    } else if(codeState == 2){
        percentPerCode = 25;
    }else if (codeState == 3){
        percentPerCode = 15;
    } else if(codeState == 4){
        percentPerCode = 5;
    } else if(codeState == 5){
        percentPerCode = 0;
    }else {
        printf("Error: The code of state is 1 to 5. \n");
        exit(-2);
    }

    printf("Please, insert the weight \n");
    scanf("%f", &weight);
    weight = (weight)*(1000);

    printf("Please, insert the code of the load (T) \n");
    scanf("%d", &codeLoad);

    if(codeLoad >= 10 && codeLoad <= 20) {
        pricePerWeight = 100;
    } else if(codeLoad >= 21 && codeLoad <= 30) {
        pricePerWeight = 250;
    } else if (codeLoad >= 31 && codeLoad <= 40) {
        pricePerWeight = 340;
    } else {
        printf("Error: The code of load is 10 to 40");
        exit(-2);
    }

    printf("The weight of the load: %f \n", weight);

    priceAmountLoad = (weight)*pricePerWeight;

    printf("The price per kilo is equal: R$ %f. \n", priceAmountLoad);

    if(percentPerCode != 0){
        priceTax = ((priceAmountLoad)/(percentPerCode)*100);
        printf("The price of tax to load is equal %f per cent. \n", priceTax);
    }else{
        printf("Your to isent of the price tax. \n");
    }

    priceAmountLoad = priceAmountLoad+priceTax;
    printf("The price of the tax plus with the price of load: %f. \n", priceAmountLoad);

}
