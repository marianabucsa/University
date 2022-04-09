#include "Ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Ui* init_ui(Service* srv) {
	Ui* ui = (Ui*)malloc(sizeof(Ui));
	ui->srv = srv;
	return ui;
}

void add_pro(Ui* ui) {
	int id, amount;
	char type[50], manufacturer[50], model[50], buff[50], * fin;
	float price;
	printf("Enter product id: ");
	scanf("%s", buff);
	id = strtol(buff, &fin, 10);
	if (*fin == '\0') {
		Product* p = init_product(id, "laptop", "lenovo", "i3", 4, 4);
		int i = find_elem(ui->srv->repo->array, p);
		if (i != -1) {
			printf("The product already exists!\n");
			printf("Enter the amount you want to add: ");
			scanf("%s", buff);
			amount = strtol(buff, &fin, 10);
			if (*fin == '\0') {
				int return_code = add_p(ui->srv, id, "laptop", "lenovo", "i3", 10, amount);
				if (return_code == 1)
					printf("Product successfully added!\n");
				else {
					if (return_code % 2 == 0)
						printf("Invalid id!\n");
					if (return_code % 3 == 0)
						printf("Invalid price!\n");
					if (return_code % 5 == 0)
						printf("Invalid amount!\n");
					if (return_code < 0)
						printf("Error adding the product!\n");
				}
			}
			else printf("Invalid amount!\n");
		}
		else {
			printf("Enter product type :");
			scanf("%s", type);
			printf("Enter product manufacturer: ");
			scanf("%s", manufacturer);
			printf("Enter product model: ");
			scanf("%s", model);
			printf("Enter product price: ");
			scanf("%s", buff);
			price = strtof(buff, &fin);
			if (*fin == '\0') {
				printf("Enter product amount: ");
				scanf("%s", buff);
				amount = strtol(buff, &fin, 10);
				if (*fin == '\0') {
					int return_code = add_p(ui->srv, id, type, manufacturer, model, price, amount);
					if (return_code == 1)
						printf("Product successfully added!\n");
					else {
						if (return_code % 2 == 0)
							printf("Invalid id!\n");
						if (return_code % 3 == 0)
							printf("Invalid price!\n");
						if (return_code % 5 == 0)
							printf("Invalid amount!\n");
						if (return_code < 0)
							printf("Error adding the product!\n");
					}
				}
				else {
					printf("Invalid amount!\n");
				}
			}
			else {
				printf("Invalid price!\n");
			}
		}
		destroy_product(p);
	}
	else {
		printf("Invalid id!\n");
	}
}

void modify_pro(Ui* ui) {
	int id, amount, return_code;
	char  buff[50], * fin, mod[50];
	float price;
	printf("Enter what you want to modify(price/amount): ");
	scanf("%s", mod);
	if (strcmp(mod, "price") != 0 && strcmp(mod, "amount") != 0)
		printf("Invalid mode!\n");
	else {

		if (strcmp(mod, "price") == 0)
		{
			printf("Enter product id: ");
			scanf("%s", buff);
			id = strtol(buff, &fin, 10);
			if (*fin == '\0') {
				printf("Enter the new price: ");
				scanf("%s", buff);
				price = strtof(buff, &fin);
				if (*fin == '\0') {
					return_code = modify_p_p(ui->srv, id, "laptop", "lenovo", "i3", price, 4);
					if (return_code == 1)
						printf("Product successfully modified!\n");
					else {
						if (return_code % 2 == 0)
							printf("Invalid id!\n");
						if (return_code % 3 == 0)
							printf("Invalid price!\n");
						if (return_code % 5 == 0)
							printf("Invalid amount!\n");
						if (return_code < 0)
							printf("Error modifying the product!\n");
					}
				}
				else printf("Invalid price!\n");
			}
			else printf("Invalid id!\n");
		}
		if (strcmp(mod, "amount") == 0)
		{
			printf("Enter product id: ");
			scanf("%s", buff);
			id = strtol(buff, &fin, 10);
			if (*fin == '\0') {
				printf("Enter the new amount: ");
				scanf("%s", buff);
				amount = strtol(buff, &fin, 10);
				if (*fin == '\0') {
					return_code = modify_p_a(ui->srv, id, "laptop", "lenovo", "i3", 10, amount);
					if (return_code == 1)
						printf("Product successfully modified!\n");
					else {
						if (return_code % 2 == 0)
							printf("Invalid id!\n");
						if (return_code % 3 == 0)
							printf("Invalid price!\n");
						if (return_code % 5 == 0)
							printf("Invalid amount!\n");
						if (return_code < 0)
							printf("Error modifying the product!\n");
					}
				}
				else printf("Invalid amount!\n");
			}
			else printf("Invalid id!\n");
		}
	}
}

void delete_pro(Ui* ui) {
	int id;
	char buff[50], * fin;
	printf("Enter product id: ");
	scanf("%s", buff);
	id = strtol(buff, &fin, 10);
	if (*fin == '\0')
	{
		int return_code = delete_p(ui->srv, id, "laptop", "lenovo", "i3", 10, 4);
		if (return_code == 1)
			printf("Product successfully deleted!\n");
		else {
			if (return_code % 2 == 0)
				printf("Invalid id!\n");
			if (return_code % 3 == 0)
				printf("Invalid price!\n");
			if (return_code % 5 == 0)
				printf("Invalid amount!\n");
			if (return_code < 0)
				printf("Error deleting the product!\n");
		}
	}
	else
		printf("Invalid id!\n");
}

void view_products(Ui* ui) {
	printf("                            Products    \n");
	printf("\n");
	Array* v = get_products(ui->srv);
	for (int i = 0; i < size_array(v); i++) {
		Product* p = v->elements[i];
		printf("\tID: %d\tType: %s\tManufacturer: %s\tModel: %s\tPrice: %0.1f\t Amount: %d\n", get_id(p), p->type, p->manufacturer, p->model, get_price(p), get_amount(p));
	}
}
void view_ordered_products(Ui* ui) {
	char  sort_field[50], mode[50];
	printf("Enter the 'sort by' field(price/amount):  ");
	scanf("%s", sort_field);
	if (strcmp(sort_field, "price") != 0 && strcmp(sort_field, "amount") != 0)
		printf("Invalid field!\n");
	else {
		printf("Enter the sort mode(asc/desc):  ");
		scanf("%s", mode);
		if (strcmp(mode, "asc") != 0 && strcmp(mode, "desc") != 0)
			printf("Invalid mode!\n");
		else {
			Array* v = ordered_products(ui->srv, sort_field, mode);
			for (int i = 0; i < size_array(v); i++) {
				Product* p = v->elements[i];
				printf("\tID: %d\tType: %s\tManufacturer: %s\tModel: %s\tPrice: %0.1f\t Amount: %d\n", get_id(p), p->type, p->manufacturer, p->model, get_price(p), get_amount(p));
			}
			destroy(v);
		}
	}
}

void filter_products(Ui* ui) {
	char  filter[50], mode[50], data[50], * fin, buff[50];
	printf("Enter the filter(manufacturer/price/amount):  ");
	scanf("%s", filter);
	if (strcmp(filter, "price") != 0 && strcmp(filter, "amount") != 0 && strcmp(filter, "manufacturer") != 0)
		printf("Invalid filter!\n");
	else {
		printf("Enter the %s for the filter: ", filter);
		scanf("%s", buff);
		if (strcmp(filter, "price") == 0 || strcmp(filter, "amount") == 0) {
			int nr = strtol(buff, &fin, 10);
			if (*fin == '\0') {
				nr = 0;
				printf("Enter the filter mode( <= / >= ):  ");
				scanf("%s", mode);
				if (strcmp(mode, "<=") != 0 && strcmp(mode, ">=") != 0) {
					printf("Invalid mode!\n");
					return;
				}
			}
			else {
				printf("Invalid %s!\n", filter);
				return;
			}
		}
		else strcpy(mode, "default");
		strcpy(data, buff);
		Array* v = filter_pro(ui->srv, filter, mode, data);
		if (v->dim == 0)
			printf("No product met the requirements!\n");
		else {
			for (int i = 0; i < size_array(v); i++) {
				Product* p = v->elements[i];
				printf("\tID: %d\tType: %s\tManufacturer: %s\tModel: %s\tPrice: %0.1f\t Amount: %d\n", get_id(p), p->type, p->manufacturer, p->model, get_price(p), get_amount(p));
			}
		}
		destroy(v);
	}
}

void execute_cmd(Ui* ui, int cmd) {
	switch (cmd)
	{
	case 1:
		add_pro(ui);
		break;
	case 2:
		modify_pro(ui);
		break;
	case 3:
		delete_pro(ui);
		break;
	case 4:
		view_products(ui);
		break;
	case 5:
		view_ordered_products(ui);
		break;
	case 6:
		filter_products(ui);
		break;
	}
}

int validate_cmd(int* cmds, int nrcmd, int cmd) {
	for (int i = 0; i < nrcmd; i++)
		if (cmd == cmds[i])
			return 1;
	return 0;
}

void print_menu() {
	printf("\n      ==========Menu==========       \n");
	printf("    ||        0.Quit         ||\n");
	printf("    ||     1.Add product     ||\n");
	printf("    ||    2.Modify product   ||\n");
	printf("    ||    3.Delete product   ||\n");
	printf("    ||  4.View all products  ||\n");
	printf("    ||5.View ordered products||\n");
	printf("    ||   6.Filter products   ||\n");
	printf("      ======================== \n");
}

void run(Ui* ui) {
	int cmd;
	int cmds[] = { 0,1,2,3,4,5,6 };
	int nrcmds = 7;
	int ok, loop=1;
	while (loop==1) {
		print_menu();
		printf("Enter command: ");
		ok = scanf("%d", &cmd);
		if (ok==1){
			if (validate_cmd(cmds, nrcmds, cmd)) {
				if (cmd == 0)
					return;
				execute_cmd(ui, cmd);
			}
			else {
				printf("Invalid command!\n");
			}
		}
		else {
			printf("Invalid command!\n");
			return;
		}
	}
}

void destroy_ui(Ui* ui) {
	destroy_service(ui->srv);
	free(ui);
}