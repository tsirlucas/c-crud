#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "helpers.h"

int get_id() {
    printf("Enter the entity id: \n");
    char id_string[100];
    fgets (id_string, 100, stdin);
    id_string[strcspn(id_string, "\n")] = 0;
    return atoi(id_string);
}
