#include<stdio.h>
#include "linkedlist.h"

int main(){
    int elments[] = {10,20,30,40,50};
    printf(
        "Creating the linked list from the array elements\n"
    );
    Node *first = create_ll(elments,5);
    display(first);

    
    printf(
        "Inserting the Nodes at given index\n"
    );
    insert(&first,1,1);
    insert(&first,3,3);
    insert(&first,5,5);
    display(first);

    printf(
        "Inserting the element at last\n"
    );
    push(first, 99);
    display(first);


    printf(
        "Removing last Node\n"
    );
    int removed = pop(first);
    printf(
        "Removed data = %d\n", removed
    );
    display(first);


    printf(
        "Finding given element(50) in LL\n"
    );
    Node *found = find(first, 50);
    printf(
        "%s\n", found != NULL ? "FOUND" : "NOT_FOUND"
    );


    printf(
        "Remove given element(50) from the LL\n"
    );
    remove_element(&first,50);
    display(first);
    remove_element(&first,1);
    display(first);
    remove_element(&first,20);
    display(first);
    return 0;
}