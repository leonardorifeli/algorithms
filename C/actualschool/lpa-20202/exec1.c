#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Create a default struct to product type/properties
struct Product{
    int item;
    char *name;
    int code;
    float price;
};

// Define build function
struct Product build(int item, char name[20], int code, float price);

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Input variables
    float totalBuyedPrice;
    int displayBuyed = 0;
    int menuItem = 0;
    int menuBuyed = 0;
    int buyOption, buyOptionQuantity, canFinish, buyed[100], buyedQuantity[100];
    struct Product products[7];

    // Build the market menu
    products[0] = build(1, "Cachorro-quente", 100, 5.00);
    products[1] = build(2, "X-salada", 101, 8.79);
    products[2] = build(3, "X-bacon", 102, 9.99);
    products[3] = build(4, "Misto", 103, 6.89);
    products[4] = build(5, "Salada", 104, 4.80);
    products[5] = build(6, "Água", 105, 3.49);
    products[6] = build(7, "Refrigerante", 106, 4.99);

    printf("WELCOME TO RIFELI'S MARKET (RU 2136681). Check our menu: \n\n");
    printf("****************************************************** \n");
    printf("# Item | Product         | Code | Unit price \n");

    // Printing market menu (products). Total 7 products
    while(menuItem <= 6) {
        printf("# %-4d | ", products[menuItem].item);

        if(menuItem == 5)
            printf("%-16s | ", products[menuItem].name);
        else
            printf("%-15s | ", products[menuItem].name);
        
        printf("%-4d | %.2f \n", products[menuItem].code, products[menuItem].price);

        menuItem++;
    }

    // Loop to start buy products
    do {
        printf("Insert the product item to buy (0 to finish): \n");
        scanf("%d", &buyOption);
        // Validate product menu item
        struct Product product = products[buyOption-1];

        // Valide exit option
        if(buyOption == 0) {
            // Confirm exit
            printf("Do are you sure you want to finish the buy? (1=YES or 0=NO) \n");
            scanf("%d", &canFinish);

            // Validate confirmed exit
            if(canFinish == 0) {
                buyOption = 10;
                continue;
            }

            break;
        }

        // Validate product exists
        if (!(product.item >= 1 && product.item <= 7)) {
            printf("\n#### Product not found. Please, check the menu and insert again. \n\n");
            printf("****************************************************** \n");
            continue;
        }

        printf("You want buy %s product. What's quantity?\n", product.name);
        scanf("%d", &buyOptionQuantity);

        // Confirm successfully added product
        printf("****************************************************** \n");
        printf("* You added %d of %s product to cart.\n", buyOptionQuantity, product.name);
        printf("****************************************************** \n\n");

        // Save to buyed variables
        buyed[menuBuyed] = (product.item - 1);
        buyedQuantity[menuBuyed] = buyOptionQuantity;

        menuBuyed++;
    } while (buyOption != 0);

    // When finished show the buyed products
    printf("\n\n****************************************************** \n");
    printf("CHECK YOUR LIST: \n");

    // Loop to display buyed products
    for(displayBuyed=0; displayBuyed < menuBuyed; displayBuyed++) {
        int quantity = buyedQuantity[displayBuyed];
        if(quantity != 0) {
            int itemBuyed = buyed[displayBuyed];
            struct Product product = products[itemBuyed];
            float specificPrice = (product.price * quantity);
            totalBuyedPrice += specificPrice;
            printf("* %dx %s UNIT R$ %.2f (TOTAL R$ %.2f)\n", quantity, product.name, product.price, specificPrice);
        }
    }

    // show total value
    printf("TOTAL VALUE: R$ %.2f \n", totalBuyedPrice);
    printf("****************************************************** \n\n");

    return 0;
}

// Função para montar um produto com suas propriedades
struct Product build(int item, char name[20], int code, float price) {
    struct Product product;
    product.item = item;
    product.name = name;
    product.code = code;
    product.price = price;
    return product;
}
