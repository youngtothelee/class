/*
 * EE312 Simple CRM Project
 *
 * YOUR INFO HERE!
 */

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

String bottles;
String rattles;
String diapers;


/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


/* clear the inventory and reset the customer database to empty */

void reset(void) {
    for (int i = 0; i < num_customers; i++) {
        customers[i].bottles=0;
        customers[i].diapers=0;
        customers[i].rattles=0;
        StringDestroy(&(customers[i].name));
    }

    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
    num_customers = 0;
}

    void processSummarize() {
    int max_bottles = 0;
    int max_diapers = 0;
    int max_rattles = 0;
    String max_customer_b;
    String max_customer_d;
    String max_customer_r;

    printf("There are %d Bottles, %d Diapers and %d Rattles in inventory\n", num_bottles, num_diapers, num_rattles);
    printf("we have had a total of %d different customers\n", num_customers);

    //find max_bottles
    for(int i=0; i<=num_customers; i++){
        if(customers[i].bottles>max_bottles){
            max_bottles=customers[i].bottles;
            max_customer_b=customers[i].name;
        }
    }
    //find max_diapers
    for(int i=0; i<=num_customers; i++){
        if(customers[i].diapers>max_diapers){
            max_diapers=customers[i].diapers;
            max_customer_d=customers[i].name;
        }
    }

    for(int i=0; i<=num_customers; i++){
        if(customers[i].rattles>max_rattles){
            max_rattles=customers[i].rattles;
            max_customer_r=customers[i].name;
        }
    }



    if (max_bottles == 0) {
        printf("no one has purchased any Bottles\n");
    }
    else {
        printf("%s has purchased the most Bottles (%d)\n", max_customer_b.ptr, max_bottles);
    }

    if (max_diapers == 0) {
        printf("no one has purchased any Diapers\n");
    }
    else {
        printf("%s has purchased the most Diapers (%d)\n", max_customer_d.ptr, max_diapers);
    }

    if (max_rattles == 0) {
        printf("no one has purchased any Rattles\n");
    }
    else {
        printf("%s has purchased the most Rattles (%d)\n", max_customer_r.ptr, max_rattles);
    }
}

void processPurchase() {

    bottles = StringCreate("Bottles");
    rattles = StringCreate("Rattles");
    diapers = StringCreate("Diapers");
    int quantity;
    int i;
    String current_name;
    String ordered_item;
    bool new_customer=true;
    bool enough=true;
    Customer* current_customer;

    readString(&current_name);
    readString(&ordered_item);
    readNum(&quantity);


    for (int i = 0; i < num_customers; i++) {
        Customer* c = &(customers[i]);
        if (StringIsEqualTo(&current_name, &(customers[i].name))) {
            new_customer = false;
            current_customer=c;
        }
    }


    if (StringIsEqualTo(&ordered_item, &bottles)) {
        if (quantity > num_bottles) {
            enough = false;
        }
    }
    else if (StringIsEqualTo(&ordered_item, &diapers)) {
        if (quantity > num_diapers) {
            enough = false;
        }
    }
    else if (StringIsEqualTo(&ordered_item, &rattles)) {
        if (quantity > num_rattles) {
            enough = false;
        }
    }


    if (enough==false){
        if (StringIsEqualTo(&ordered_item, &bottles)){
            printf("Sorry %s, we only have %d Bottles\n", current_name.ptr, num_bottles);
        }
        if (StringIsEqualTo(&ordered_item, &diapers)){
            printf("Sorry %s, we only have %d Diapers\n", current_name.ptr, num_diapers);
        }
        if (StringIsEqualTo(&ordered_item, &rattles)){
            printf("Sorry %s, we only have %d Rattles\n", current_name.ptr, num_rattles);
        }
    }

    if(new_customer && enough){
        Customer new_c;
        new_c.name = StringDup(&current_name);
        new_c.bottles = 0;
        new_c.diapers = 0;
        new_c.rattles = 0;
        customers[num_customers] = new_c;
        current_customer = &(customers[num_customers]);
        num_customers++;
    }



    if ((StringIsEqualTo(&ordered_item, &bottles)) && enough) {
        (*current_customer).bottles += quantity;
        num_bottles -= quantity;
    } else if ((StringIsEqualTo(&ordered_item, &rattles)) && enough) {
        (*current_customer).rattles += quantity;
        num_rattles -= quantity;
    } else if ((StringIsEqualTo(&ordered_item, &diapers)) && enough) {
        (*current_customer).diapers += quantity;
        num_diapers -= quantity;
    }


    StringDestroy(&ordered_item);
    StringDestroy(&current_name);
    StringDestroy(&bottles);
    StringDestroy(&rattles);
    StringDestroy(&diapers);
}

void processInventory() {
    bottles=StringCreate("Bottles");
    rattles=StringCreate("Rattles");
    diapers=StringCreate("Diapers");

    int quantity;
    String ordered_item;

    readString(&ordered_item);
    readNum(&quantity);

    if (StringIsEqualTo(&bottles, &ordered_item)) { // bottles
        num_bottles += quantity;
    } else if (StringIsEqualTo(&rattles, &ordered_item)) { // rattles
        num_rattles += quantity;
    } else if (StringIsEqualTo(&diapers, &ordered_item)) { // diapers
        num_diapers += quantity;
    } else { // invalid item
        printf("ERROR: item doesnt exist.\n");
    }

    StringDestroy(&ordered_item);
    StringDestroy(&bottles);
    StringDestroy(&rattles);
    StringDestroy(&diapers);

}
