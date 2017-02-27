#include "stdio.h"
#include "professor.h"
#include "stdlib.h"
#include "string.h"
#include "../helpers/helpers.h"

int professors_index = 0;

void list_professors() {
    printf("=====PROFESSORS=====\n");
    for (int i = 0; i < professors_index; i++) {
        printf("id: %i / name: %s / age: %i\n",
               school_professors[i]->id,
               school_professors[i]->name,
               school_professors[i]->age
        );
    }
}

struct professor * create_professor() {
    struct professor* professor = malloc(sizeof(struct professor));
    professor->id = professors_index;
    printf("Enter a name: \n");
    fgets (professor->name, 100, stdin);
    professor->name[strcspn(professor->name, "\n")] = 0;
    printf("Enter an age: \n");
    char age[100];
    fgets (age, 100, stdin);
    age[strcspn(age, "\n")] = 0;
    professor->age = atoi(age);

    school_professors[professors_index] = professor;
    professors_index = professors_index + 1;

    return professor;
}

struct professor * edit_professor() {
    list_professors();
    int id = get_id();
    if(school_professors[id] != NULL && id < professors_index) {
        struct professor * professor = school_professors[id];
        printf("Editing %s of %i years\n", professor->name, professor->age);
        printf("Enter a new name: \n");
        fgets (professor->name, 1000, stdin);
        professor->name[strcspn(professor->name, "\n")] = 0;
        printf("Enter a new age: \n");
        char age[1000];
        fgets(age, 1000, stdin);
        professor->age = atoi(age);

        printf("Edited to %s of %i years\n", professor->name, professor->age);
        return professor;
    } else {
        printf("Invalid id! \n");
        return NULL;
    }

}

struct professor * remove_professor() {
    list_professors();
    int id = get_id();
    if(school_professors[id] != NULL && id < professors_index) {
        struct professor *professor = school_professors[id];
        printf("Do you really want to remove %s of %i years? (y/n)\n", professor->name, professor->age);
        char response[100];
        fgets(response, 100, stdin);
        response[strcspn(response, "\n")] = 0;

        if (strcmp(response, "y") == 0) {
            for (int i = id; i < professors_index - 1; i++) {
                school_professors[i] = school_professors[i + 1];
                school_professors[i]->id = i;
            }
            printf("%s of %i has been removed\n", professor->name, professor->age);
            free(professor);
            professors_index = professors_index - 1;
            return professor;
        } else if (strcmp(response, "n") == 0) {
            printf("Remove aborted!");
            return professor;
        } else {
            printf("Invalid option!");
        }
        return professor;
    } else{
        printf("Invalid id! \n");
        return NULL;
    }
}

int professor_menu() {
    char option_string[100];
    int option = 6;
    while(option != 5) {
        printf(" 1 - List\n 2 - Add\n 3 - Edit\n 4 - Remove\n 5 - Back\n");
        fgets (option_string, 100, stdin);
        option_string[strcspn(option_string, "\n")] = 0;
        option = atoi(option_string);

        switch (option) {
            case 1:
                list_professors();
                break;
            case 2:
                create_professor();
                break;
            case 3:
                edit_professor();
                break;
            case 4:
                remove_professor();
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
