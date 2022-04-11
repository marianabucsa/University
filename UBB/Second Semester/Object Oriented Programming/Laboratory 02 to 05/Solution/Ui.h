#pragma once

#include "Service.h"

typedef struct {
	Service* srv;
}Ui;

Ui* init_ui(Service*);
// creates the ui
// input: a service
// output: returns an ui

void view_products(Ui*);
// shows the products 
// input: an ui
// output : prints all the products

void view_ordered_products(Ui* ui);
// shows the products ordered by price or amount (ascending or descending)
// input: an ui
// output : prints all the products ordered

void filter_products(Ui* ui);
// shows the products after they are filtered
// input: an ui
// output: prints the products after they are filtered

void add_pro(Ui*);
// reads the data and adds a product
// input: an ui, requaring data from the user
// output : - "Product successfully added!\n" - if the product is successfully added
//          - "Invalid id!\n" - for invalid id , id < 0
//          - "Invalid price!\n" - for invalid price, price < 0
//          - "Invalid amount!\n" - far invalid amount, amount < 0

void modify_pro(Ui*);
// reads the data and modifies a product
// input: an ui, requaring data from the user
// output : - "Product successfully modified!\n" - if the product is successfully modified
//          - "Invalid id!\n" - for invalid id , id < 0
//          - "Invalid price!\n" - for invalid price, price < 0
//          - "Invalid amount!\n" - far invalid amount, amount < 0

void delete_pro(Ui*);
// reads the data and deletes a product
// input: an ui, requaring data from the user
// output : - "Product successfully added!\n" - if the product is successfully added
//          - "Invalid id!\n" - for invalid id , id < 0

void execute_cmd(Ui*, int);
// executes the cmd from the int parameter
// input: an ui 
//        an integer
// output: -

int validate_cmd(int*, int, int);
// validates the command
// input : - an ui 
//         - a reference to commands
//         - the number of commands 
//         - the command
// output: 1 - if the command exists 
//         -1 - if it does not exist


void print_menu();
// prints the menu
// input: a ui
// output: prints the menu

void run(Ui*);
// shows the menu and requests a command 
// input : an ui, requaring data from the user
// output: -

void destroy_ui(Ui*);
//destroys the ui
// input: an ui
// output: destroys the ui