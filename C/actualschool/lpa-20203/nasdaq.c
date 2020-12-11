#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

enum StockExchangeActuation {Tech=1, Retail=2};

// Create a default struct to store type/properties
struct StockExchange {
    int code;
    enum StockExchangeActuation actuationArea;
    double date;
    double openValue;
    double closeValue;
    double variationPercent;
};

struct StockExchange createStockExchange();

int main() {
    // Set Portuguese with locale
    setlocale(LC_ALL, "Portuguese");

    int totalStocks = 0, stockToAlloc = 5, item, i;
    struct StockExchange *stockExchanges;

    stockExchanges = (struct StockExchange *) malloc(sizeof(struct StockExchange) * 5);

    if(stockExchanges == NULL) {
        printf("Failed to malloc stockChanges array. \n");
        return 0;
    }

    // Loop to menu options
    while(1==1) {
        printf("\nWELCOME TO RIFELI'S STOCK EXCHANGE (RU 2136681). \n");
        printf("***************************** \n");

        if(totalStocks <= 5)
            printf("[ 1 ] Create an stock exchange (%d created) \n", totalStocks);

        printf("[ 2 ] Show all stock exchange \n");
        printf("[ 3 ] Exit \n");
        printf("***************************** \n");

        scanf("%d", &item);

        // Exit option
        if(item == 3)
            break;

        if(item == 1) {
            stockExchanges[totalStocks] = createStockExchange();
            totalStocks++;
        }

        if(item == 2) {
            for(i=0; i < totalStocks; i++) {
                printf("- [ID %d] Code: %d \n", i, stockExchanges[i].code);

                if(stockExchanges[i].actuationArea == Tech)
                    printf("        Action Area: %d (TECH) \n", stockExchanges[i].actuationArea);

                if(stockExchanges[i].actuationArea == Retail)
                    printf("        Action Area: %d (RETAIL) \n", stockExchanges[i].actuationArea);

                printf("        Date: %2.f \n", stockExchanges[i].date);
                printf("        Open value: %2.f \n", stockExchanges[i].openValue);
                printf("        Close value: %2.f \n", stockExchanges[i].closeValue);
                printf("        Variation Percent: %2.f%%\n", stockExchanges[i].variationPercent);

                if(stockExchanges[i].variationPercent > 0)
                    printf("        Status: (+ increased)\n");
                else if(stockExchanges[i].variationPercent == 0)
                    printf("        Status: (equal)\n");
                else
                    printf("        Status: (- decreased)\n");
            }
        }
    }

    return 1;
}

// StockExchange is function to get stock exchange data and create that
struct StockExchange createStockExchange() {
    struct StockExchange stock;
    double variationPercent = 0.0;

    printf("\nCREATING A STOCK EXCHANGE:\n");

    printf("- Code: ");
    scanf("%d", &stock.code);

    printf("- Action area (Tech=1, Retail=2): ");
    scanf("%d", &stock.actuationArea);

    printf("- Date (ex 20201210): ");
    scanf("%lf", &stock.date);

    printf("- Open value (ex 100): ");
    scanf("%lf", &stock.openValue);

    printf("- Close value (ex 200): ");
    scanf("%lf", &stock.closeValue);

    if(stock.closeValue != 0)
        variationPercent = (stock.closeValue - stock.openValue) / stock.closeValue * 100;

    stock.variationPercent = variationPercent;

    return stock;
}
