#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Create a default struct to store type/properties
struct Store {
    char name[100];
    double phone;
    float price;
};

// Define createStore function
struct Store createStore();

// Define sortStores function
void sortStores(struct Store stores[14], int totalStores);

// Define showPricing function
void showPricing(struct Store stores[14], int totalStores);

// Define exportToCSV function
void exportToCSV(struct Store stores[14], int totalStores);

int main() {
    // Set Portuguese with locale
    setlocale(LC_ALL, "Portuguese");
    
    // Define default vars
    char item;
    int totalStores = 0, insertedStores = 0, lastDeleted = -1, storeDelete = -1, i;
    struct Store stores[14];
    struct Store emptyStore = {0};

    // Loop to menu options
    while(1==1) {
        printf("\nWELCOME TO RIFELI'S STORE (RU 2136681). \n");
        printf("***************************** \n");

        // Validate totalStores is <= 14 (0-14) to can create a new store
        if(totalStores <= 14) {
            printf("[ I ] Create a Store (%d created stores) \n", totalStores);
        }

        printf("[ E ] Delete a Store \n");
        printf("[ P ] Best Pricing \n");
        printf("[ C ] Save CSV file \n");
        printf("[ S ] Exit \n");
        printf("***************************** \n");

        scanf("%c", &item);

        // Validate menu is diff of options to rescan and (to not show menu again)
        if(item != 'S' && item != 'I' && item != 'E' && item != 'P' && item != 'C') {
            scanf("%c", &item);
        }

        // Exit option
        if(item == 'S')
            break;

        if(item == 'P')
            showPricing(stores, insertedStores);

        if(item == 'C')
            exportToCSV(stores, insertedStores);

        // CreateStore option
        if(item == 'I' && totalStores <= 14) {
            // Save created store
            if(lastDeleted == -1) {
                stores[insertedStores] = createStore();
                insertedStores++;
            } else {
                stores[lastDeleted] = createStore();
                lastDeleted = -1;
            }

            totalStores++;

            printf("## Store created with success! \n");
        }

        // Delete store option (by "id")
        if(item == 'E') {
            printf("\nDELETING A STORE:\n");

            for(i=0;i < insertedStores; i++) {
                if(stores[i].price != 0) {
                    printf("- [ID %d] name: %s\n", i, stores[i].name);
                    printf("         phone: %2.f\n", stores[i].phone);
                    printf("         price: %2.f\n", stores[i].price);
                }
            }

            // Get store "id" to delete
            printf("Number of Store to delete? (-1 TO CANCEL)\n");
            scanf("%d", &storeDelete);

            // Validate is cancel option
            if(storeDelete == -1)
                continue;

            // Delete store option equal emptyStore 
            stores[storeDelete] = emptyStore;

            // Save lastDeleted with 0
            lastDeleted = 0;

            // Decrement totalStores
            totalStores--;

            printf("## Store deleted with success! \n");
        }
    }

    return 0;
}

// Function to export to a CSV file
void exportToCSV(struct Store stores[14], int insertedStores) {
    // Validate has sotres
    if(insertedStores == 0) {
        printf("\nSTORES NOT FOUND!\n");
        return;
    }

    // Sort stores by pricing ASC
    sortStores(stores, insertedStores);

    int i,j;
    FILE *file;
    file = fopen("precos.csv", "w+");
    fprintf(file, "Name;Phone;Price\n");

    for (i = 0; i < insertedStores; i++) {
        if(stores[i].price != 0)
            fprintf(file,"%s;%2.f;%2.f\n", stores[i].name, stores[i].phone, stores[i].price);
    }

    fclose(file);

    printf("GENERATE CSV FILE");
}

// Function to show pricing only
void showPricing(struct Store stores[14], int insertedStores) {
    // Sort stores by pricing ASC
    sortStores(stores, insertedStores);

    int i;
    float avg = 0;
    float sum;

    // Validate has sotres
    if(insertedStores == 0) {
        printf("\nSTORES NOT FOUND!\n");
        return;
    }

    printf("\nBEST PRICE:\n");

    // Sum all prices to calculate avg
    for (i = 0; i < insertedStores; i++) {
        if(stores[i].price != 0) {
            sum += stores[i].price;
        }
    }

    // calculate store avg
    avg = sum / insertedStores;

    // Show all created stores and show avg warning
    for (i = 0; i < insertedStores; i++) {
        if(stores[i].price != 0) {
            printf("- [ID %d] name: %s\n", i, stores[i].name);
            printf("         phone: %2.f\n", stores[i].phone);
            printf("         price: %2.f", stores[i].price);

            if(stores[i].price < avg)
                printf("\n         **WARNING** is lower avg");

            printf("\n");
        }
    }

    printf("AVG PRICE IS: %2.f\n", avg);
}

// CreateStore is function to get store data and create that
struct Store createStore() {
    struct Store store;

    printf("\nCREATING A STORE:\n");
    printf("- Name of store: ");
    scanf("%s", store.name);

    printf("- Phone of store: ");
    scanf("%lf", &store.phone);

    printf("- Table pricing: ");
    scanf("%f", &store.price);

    return store;
}

// Sort stores by tablet price
void sortStores(struct Store stores[14], int totalStores) {
    // Data to use on for
    int i, j;

    // Create temporaryStore
    struct Store temporaryStore;

    // Parse stores and order price ASC
    for (i = 0; i < totalStores - 1; i++) {
        for (j = 0; j < (totalStores - 1-i); j++) {
            if (stores[j].price > stores[j + 1].price) {
                temporaryStore = stores[j];
                stores[j] = stores[j + 1];
                stores[j + 1] = temporaryStore;
            }
        }
    }
}
