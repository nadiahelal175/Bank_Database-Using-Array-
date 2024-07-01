#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

typedef struct customer {
    char name[30];
    double cash;
    char type[7];
    int id;
} customer_t;

void create_new_customer(void);
void edit_customer(int id);
void print_customer_data(int id);
void transfer_money(int source_id, int destination_id, double money);
void delete_customer_data(int id);

#endif

