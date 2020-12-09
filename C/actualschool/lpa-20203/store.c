#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Create a default struct to store type/properties
struct Store{
    char * name;
    double phone;
    float price;
};

// Define build function
struct Store build(char name[100], double phone, float price);
struct Store createStore();
void sortStores(struct Store stores[14], int totalStores);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    char item;
    int totalStores = 0;
    int i;
    int storeDelete;
    struct Store stores[14];
    struct Store lastStore;

    while(1==1) {
        printf("\nWELCOME TO RIFELI'S STORE (RU 2136681). \n\n");
        printf("***************************** \n");

        if(totalStores <= 14) {
            printf("[ I ] Create a Store (%d created stores) \n", totalStores);
        }

        printf("[ E ] Delete a Store \n");
        printf("[ P ] Best Pricing \n");
        printf("[ S ] Exit \n");
        printf("***************************** \n");

        scanf("%c", &item);

        if(item != 'S' && item != 'I' && item != 'E' && item != 'P') {
            scanf("%c", &item);
        }

        if(item == 'S') {
            printf("Thanks. Bye!");
            break;
        }

        if(item == 'I' && totalStores <= 14) {
            lastStore = createStore();
            stores[totalStores] = lastStore;
            totalStores++;
            printf("## Store %s (%2.f) created with success! \n", lastStore.name, lastStore.phone);
            continue;
        }

        if(item == 'E') {
            printf("\nDELETING A STORE:\n");

            for(i=0;i<totalStores;i++) {
                printf("- [%d] %s (%2.f);\n", i, stores[i].name, stores[i].phone);
            }

            printf("Number of Store to delete? \n");
            scanf("%d", &storeDelete);

            lastStore = stores[storeDelete];

            printf("## Store %s deleted with success! \n", lastStore.name);

            continue;
        }

        if(item == 'P') {
            sortStores(stores, totalStores);

            float avg = 0;
            float sum;

            if(totalStores == 0) {
                printf("\nSTORES NOT FOUND!\n");
                continue;
            }

            printf("\nBEST PRICE:\n");

            for(i=0;i<totalStores;i++) {
                sum += stores[i].price;
            }

            avg = sum / totalStores;

            for(i=0;i<totalStores;i++) {
                printf("- Tablet price on %s store is: $%2.f ", stores[i].name, stores[i].price);
                
                if(stores[i].price < avg) {
                    printf("(is lower avg)");
                }

                printf("\n");
            }

            printf("AVG PRICE IS: %2.f\n", avg);
        }

    }

    return 0;
}

struct Store createStore() {
    char storeName[100];
    double storePhone;
    float storeTablePrice;
    
    printf("\n CREATING A STORE:\n");
    printf("- Name of store: ");
    scanf("%s", storeName);
    printf("- Phone of store: ");
    scanf("%lf", &storePhone);
    printf("- Table pricing: ");
    scanf("%f", &storeTablePrice);

    return build(storeName, storePhone, storeTablePrice); 
}

void sortStores(struct Store stores[14], int totalStores) {
    int i, j;
    struct Store temporaryStore;
    
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


// Função para montar uma store com suas propriedades
struct Store build(char name[100], double phone, float price) {
    struct Store store;
    store.name = name;
    store.phone = phone;
    store.price = price;
    return store;
}
