#include "stdio.h"
#include "discipline.h"
#include "stdlib.h"
#include "string.h"
#include "../helpers/helpers.h"

int disciplines_index = 0;

void list_disciplines() {
    printf("=====DISCIPLINES=====\n");
    for (int i = 0; i < disciplines_index; i++) {
        printf("id: %i / name: %s\n",
               school_disciplines[i]->id,
               school_disciplines[i]->name
        );
    }
}

struct discipline * create_discipline() {
    struct discipline* discipline = malloc(sizeof(struct discipline));
    discipline->id = disciplines_index;
    printf("Enter a name: \n");
    fgets (discipline->name, 100, stdin);
    discipline->name[strcspn(discipline->name, "\n")] = 0;

    school_disciplines[disciplines_index] = discipline;
    disciplines_index = disciplines_index + 1;

    return discipline;
}

struct discipline * edit_discipline() {
    list_disciplines();
    int id = get_id();
    if(school_disciplines[id] != NULL && id < disciplines_index) {
        struct discipline * discipline = school_disciplines[id];
        printf("Editing %s\n", discipline->name);
        printf("Enter a new name: \n");
        fgets (discipline->name, 1000, stdin);
        discipline->name[strcspn(discipline->name, "\n")] = 0;

        printf("Edited to %s\n", discipline->name);
        return discipline;
    } else {
        printf("Invalid id! \n");
        return NULL;
    }

}

struct discipline * remove_discipline() {
    list_disciplines();
    int id = get_id();
    if(school_disciplines[id] != NULL && id < disciplines_index) {
        struct discipline * discipline = school_disciplines[id];
        printf("Do you really want to remove %s? (y/n)\n", discipline->name);
        char response[100];
        fgets(response, 100, stdin);
        response[strcspn(response, "\n")] = 0;

        if(strcmp(response, "y") == 0) {
            for (int i = id; i < disciplines_index - 1; i++ ) {
                school_disciplines[i] = school_disciplines[i + 1];
                school_disciplines[i]->id = i;
            }
            printf("%s has been removed\n", discipline->name);
            free(discipline);
            disciplines_index = disciplines_index - 1;
            return discipline;
        } else if(strcmp(response, "n") == 0) {
            printf("Remove aborted!");
            return discipline;
        } else {
            printf("Invalid option!\n");
        }
        return discipline;
    } else{
        printf("Invalid id! \n");
        return NULL;
    }
}

int discipline_menu() {
    char option_string[100];
    int option = 6;
    while(option != 5) {
        printf(" 1 - List\n 2 - Add\n 3 - Edit\n 4 - Remove\n 5 - Back\n");
        fgets (option_string, 100, stdin);
        option_string[strcspn(option_string, "\n")] = 0;
        option = atoi(option_string);

        switch (option) {
            case 1:
                list_disciplines();
                break;
            case 2:
                create_discipline();
                break;
            case 3:
                edit_discipline();
                break;
            case 4:
                remove_discipline();
                break;
            case 5:
                printf("Backing to main menu \n");
                break;
            default:
                printf("Invalid option! \n");
        }
    }
    return 1;
}
