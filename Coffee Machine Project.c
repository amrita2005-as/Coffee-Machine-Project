#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>

// Espresso
#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_MILK 0
#define ESPRESSO_SYRUP 0
float ESPRESSO_COST = 3.5;

// Cappuccino
#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_SYRUP 0
float CAPPUCCINO_COST = 4.5;

// Mocha
#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_SYRUP 30
float MOCHA_COST = 5.5;

// Other Constants
#define ADMIN_PASSCODE "VAV"
float SALES_TOTAL = 0;

// Ingredient Levels (Available Amounts)
float COFFEE_LEVEL = 300;
float WATER_LEVEL = 300;
float MILK_LEVEL = 300;
float SYRUP_LEVEL = 300;

// Function Prototypes
int placeOrder();
int processPayment(float total_due);
int enterAdminMode();
int restockIngredients();
int updatePrices();
void checkStockAndSales();

// Main Function
int main() {
    int user_choice;
    while (1) {
        printf("\n\n*MENU*\n");
        printf("1. Order Coffee\n");
        printf("2. Enter Admin Mode\n");
        printf("3. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                placeOrder();
                break;
            case 2:
                enterAdminMode();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}

// Place Coffee Order
int placeOrder() {
    int coffee_selection;

    printf("\n\n*COFFEE MENU*\n");
    printf("1. Espresso\t\t%.2f\n", ESPRESSO_COST);
    printf("2. Cappuccino\t\t%.2f\n", CAPPUCCINO_COST);
    printf("3. Mocha\t\t%.2f\n", MOCHA_COST);
    printf("0. Cancel Order\n");
    printf("Choose your coffee: ");
    scanf("%d", &coffee_selection);

    switch (coffee_selection) {
        case 1:
            printf("You've chosen Espresso.\n");
            if (ESPRESSO_BEANS <= COFFEE_LEVEL && ESPRESSO_WATER <= WATER_LEVEL) {
                printf("Brewing coffee...\n");
                printf("Your Espresso is ready!\n");
                processPayment(ESPRESSO_COST);

                // Update ingredient levels
                COFFEE_LEVEL -= ESPRESSO_BEANS;
                WATER_LEVEL -= ESPRESSO_WATER;
            } else {
                printf("Sorry, we don't have enough ingredients at the moment.\n");
            }
            break;
        case 2:
            printf("You've chosen Cappuccino.\n");
            if (CAPPUCCINO_BEANS <= COFFEE_LEVEL && CAPPUCCINO_WATER <= WATER_LEVEL && CAPPUCCINO_MILK <= MILK_LEVEL) {
                printf("Brewing coffee...\n");
                printf("Your Cappuccino is ready!\n");
                processPayment(CAPPUCCINO_COST);

                // Update ingredient levels
                COFFEE_LEVEL -= CAPPUCCINO_BEANS;
                WATER_LEVEL -= CAPPUCCINO_WATER;
                MILK_LEVEL -= CAPPUCCINO_MILK;
            } else {
                printf("Sorry, we don't have enough ingredients at the moment.\n");
            }
            break;
        case 3:
            printf("You've chosen Mocha.\n");
            if (MOCHA_BEANS <= COFFEE_LEVEL && MOCHA_WATER <= WATER_LEVEL && MOCHA_MILK <= MILK_LEVEL && MOCHA_SYRUP <= SYRUP_LEVEL) {
                printf("Brewing coffee...\n");
                printf("Your Mocha is ready!\n");
                processPayment(MOCHA_COST);

                // Update ingredient levels
                COFFEE_LEVEL -= MOCHA_BEANS;
                WATER_LEVEL -= MOCHA_WATER;
                MILK_LEVEL -= MOCHA_MILK;
                SYRUP_LEVEL -= MOCHA_SYRUP;
            } else {
                printf("Sorry, we don't have enough ingredients at the moment.\n");
            }
            break;
        case 0:
            printf("Order canceled.\n");
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0; 
}

// Admin Mode Function
int enterAdminMode() {
    char entered_pass[50];
    int admin_option;

    printf("Enter admin password: ");
    scanf("%s", entered_pass);

    if (strcmp(entered_pass, ADMIN_PASSCODE) == 0) {
        printf("Access granted.\n");

        printf("ADMIN MENU:\n");
        printf("1. Check Stock and Sales\n");
        printf("2. Restock Ingredients\n");
        printf("3. Update Coffee Prices\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &admin_option);

        switch (admin_option) {
            case 1:
                checkStockAndSales();
                break;
            case 2:
                restockIngredients();
                break;
            case 3:
                updatePrices();
                break;
            case 4:
                printf("Exiting admin mode...\n");
                break;
            default:
                printf("Invalid selection.\n");
        }
    } else {
        printf("Incorrect password.\n");
    }

    return 0;
}

// Function to Check Stock and Sales
void checkStockAndSales() {
    printf("Current stock levels and sales:\n\n");
    printf("Coffee beans: %.2f g\n", COFFEE_LEVEL);
    printf("Water: %.2f ml\n", WATER_LEVEL);
    printf("Milk: %.2f ml\n", MILK_LEVEL);
    printf("Chocolate syrup: %.2f ml\n", SYRUP_LEVEL);
    printf("Total sales: %.2f dhs\n", SALES_TOTAL);
}

// Restocking Ingredients
int restockIngredients() {
    int restock_choice;
    int new_quantity;
    srand(time(NULL));

    printf("Restock Ingredients:\n\n");
    printf("1. Coffee Beans\n");
    printf("2. Water\n");
    printf("3. Milk\n");
    printf("4. Chocolate Syrup\n");
    printf("0. Exit\n");
    printf("Select item to restock: ");
    scanf("%d", &restock_choice);

    new_quantity = 100 + rand() % 400;

    switch (restock_choice) {
        case 1:
            printf("Adding %d grams of coffee beans!\n", new_quantity);
            COFFEE_LEVEL += new_quantity;
            printf("New coffee beans level: %.2f g\n", COFFEE_LEVEL);
            break;
        case 2:
            printf("Adding %d grams of water!\n", new_quantity);
            WATER_LEVEL += new_quantity;
            printf("New water level: %.2f ml\n", WATER_LEVEL);
            break;
        case 3:
            printf("Adding %d grams of milk!\n", new_quantity);
            MILK_LEVEL += new_quantity;
            printf("New milk level: %.2f ml\n", MILK_LEVEL);
            break;
        case 4:
            printf("Adding %d grams of syrup!\n", new_quantity);
            SYRUP_LEVEL += new_quantity;
            printf("New syrup level: %.2f ml\n", SYRUP_LEVEL);
            break;
        case 0:
            printf("Exiting restock mode.\n");
            break;
        default:
            printf("Invalid selection.\n");
    }

    return 0;
}

// Update Coffee Prices
int updatePrices() {
    int coffee_type;
    float new_price;

    printf("Update Coffee Prices:\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Mocha\n");
    printf("Select coffee type: ");
    scanf("%d", &coffee_type);

    switch (coffee_type) {
        case 1:
            printf("Current price of Espresso: %.2f\n", ESPRESSO_COST);
            printf("Enter new price: ");
            scanf("%f", &new_price);
            ESPRESSO_COST = new_price;
            printf("New Espresso price: %.2f\n", ESPRESSO_COST);
            break;
        case 2:
            printf("Current price of Cappuccino: %.2f\n", CAPPUCCINO_COST);
            printf("Enter new price: ");
            scanf("%f", &new_price);
            CAPPUCCINO_COST = new_price;
            printf("New Cappuccino price: %.2f\n", CAPPUCCINO_COST);
            break;
        case 3:
            printf("Current price of Mocha: %.2f\n", MOCHA_COST);
            printf("Enter new price: ");
            scanf("%f", &new_price);
            MOCHA_COST = new_price;
            printf("New Mocha price: %.2f\n", MOCHA_COST);
            break;
        default:
            printf("Invalid selection.\n");
    }

    return 0;
}

// Payment Processing Function
int processPayment(float total_due) {
    float inserted_amount = 0;
    float amount;

    while (inserted_amount < total_due) {
        printf("Insert 1 dh or 0.5 dh: ");
        scanf("%f", &amount);

        if (amount == 1) {
            inserted_amount += 1;
        } else if (amount == 0.5) {
            inserted_amount += 0.5;
        } else {
            printf("Invalid coin.\n");
        }
    }

    if (inserted_amount > total_due) {
        float change = inserted_amount - total_due;
        printf("Your change is %.1f dhs.\n", change);
    }

    SALES_TOTAL += total_due;
    printf("Thank you! Enjoy your coffee!\n\n");

    return 0;
}


