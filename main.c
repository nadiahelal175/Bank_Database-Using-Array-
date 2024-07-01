#include <stdio.h>
#include <stdlib.h>
#include "Bank Database.h"

int counter = 0;
customer_t arr[4];

void print_menu() {
    printf("Please select one of the following options:\n");
    printf("1 - Create a new customer\n");
    printf("2 - Edit customer\n");
    printf("3 - Delete customer\n");
    printf("4 - Print customer data\n");
    printf("5 - Cash transfer from customer to another\n");
    printf("6 - Exit\n");
    printf("Enter your choice: ");
}

void handle_choice(char choice) {
    int id_check, id_from, id_to;
    double money_transfer;

    switch (choice) {
        case '1':
            if (counter >= 4) {
                printf("The maximum number of customers is 4, you can't add more.\n");
            } else {
                create_new_customer();
            }
            break;
        case '2':
            printf("Enter the ID of the customer to edit: ");
            scanf("%d", &id_check);
            edit_customer(id_check);
            break;
        case '3':
            printf("Enter the ID of the customer to delete: ");
            scanf("%d", &id_check);
            delete_customer_data(id_check);
            break;
        case '4':
            printf("Enter the ID of the customer to print: ");
            scanf("%d", &id_check);
            print_customer_data(id_check);
            break;
        case '5':
            printf("Enter the ID of the customer to transfer from: ");
            scanf("%d", &id_from);
            printf("Enter the ID of the customer to transfer to: ");
            scanf("%d", &id_to);
            printf("Enter the amount to transfer: ");
            scanf("%lf", &money_transfer);
            while (money_transfer <= 0) {
                printf("Amount should be greater than zero. Enter again: ");
                scanf("%lf", &money_transfer);
            }
            transfer_money(id_from, id_to, money_transfer);
            break;
        case '6':
            exit(0);
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    char choice;
    while (1) {
        print_menu();
        scanf(" %c", &choice);
        handle_choice(choice);
    }
    return 0;
}
