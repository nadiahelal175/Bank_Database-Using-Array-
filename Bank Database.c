#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bank Database.h"

extern int counter;
extern customer_t arr[4];

void create_new_customer(void) {
    customer_t new_customer;

    printf("Enter the name of customer %d: ", counter + 1);
    fflush(stdin);
    gets(new_customer.name);

    printf("Enter the cash for customer %d: ", counter + 1);
    scanf("%lf", &new_customer.cash);
    while (new_customer.cash < 0) {
        printf("Cash should be non-negative. Enter again: ");
        scanf("%lf", &new_customer.cash);
    }

    printf("Enter the type (debit or credit) for customer %d: ", counter + 1);
    fflush(stdin);
    gets(new_customer.type);

    printf("Enter the ID for customer %d: ", counter + 1);
    scanf("%d", &new_customer.id);

    arr[counter] = new_customer;
    counter++;
}

void edit_customer(int id) {
    for (int i = 0; i < counter; i++) {
        if (id == arr[i].id) {
            printf("Enter new name: ");
            fflush(stdin);
            gets(arr[i].name);

            printf("Enter new cash: ");
            scanf("%lf", &arr[i].cash);

            printf("Enter new type (debit or credit): ");
            fflush(stdin);
            gets(arr[i].type);

            printf("Enter new ID: ");
            scanf("%d", &arr[i].id);

            return;
        }
    }
    printf("Customer ID not found.\n");
}

void print_customer_data(int id) {
    for (int i = 0; i < counter; i++) {
        if (id == arr[i].id) {
            printf("Customer %d:\n", i + 1);
            printf("Name: %s\n", arr[i].name);
            printf("Cash: %.2lf\n", arr[i].cash);
            printf("Type: %s\n", arr[i].type);
            printf("ID: %d\n", arr[i].id);
            return;
        }
    }
    printf("Customer ID not found.\n");
}

void transfer_money(int source_id, int destination_id, double money) {
    int index_from = -1, index_to = -1;
    for (int i = 0; i < counter; i++) {
        if (arr[i].id == source_id) {
            index_from = i;
        } else if (arr[i].id == destination_id) {
            index_to = i;
        }
        if (index_from != -1 && index_to != -1) {
            break;
        }
    }
    if (index_from == -1 || index_to == -1) {
        printf("Invalid customer ID(s).\n");
        return;
    }
    if (money > arr[index_from].cash) {
        printf("Insufficient funds for transfer.\n");
        return;
    }
    arr[index_from].cash -= money;
    arr[index_to].cash += money;
    printf("Transfer successful.\n");
}

void delete_customer_data(int id) {
    int index = -1;
    for (int i = 0; i < counter; i++) {
        if (arr[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Customer ID not found.\n");
        return;
    }
    for (int i = index; i < counter - 1; i++) {
        arr[i] = arr[i + 1];
    }
    counter--;
    printf("Customer deleted successfully.\n");
}

