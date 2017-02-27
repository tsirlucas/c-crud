#include "stdio.h"
#include "student.h"
#include "stdlib.h"
#include "string.h"
#include "../helpers/helpers.h"

int students_index = 0;

void list_students() {
    printf("=====STUDENTS=====\n");
    for (int i = 0; i < students_index; i++) {
        printf("id: %i / name: %s / age: %i\n",
               school_students[i]->id,
               school_students[i]->name,
               school_students[i]->age
        );
    }
}

struct student * create_student() {
    struct student* student = malloc(sizeof(struct student));
    student->id = students_index;
    printf("Enter a name: \n");
    fgets (student->name, 100, stdin);
    student->name[strcspn(student->name, "\n")] = 0;
    printf("Enter an age: \n");
    char age[100];
    fgets (age, 100, stdin);
    age[strcspn(age, "\n")] = 0;
    student->age = atoi(age);

    school_students[students_index] = student;
    students_index = students_index + 1;

    return student;
}

struct student * edit_student() {
    list_students();
    int id = get_id();
    if(school_students[id] != NULL && id < students_index) {
        struct student * student = school_students[id];
        printf("Editing %s of %i years\n", student->name, student->age);
        printf("Enter a new name: \n");
        fgets (student->name, 1000, stdin);
        student->name[strcspn(student->name, "\n")] = 0;
        printf("Enter a new age: \n");
        char age[1000];
        fgets(age, 1000, stdin);
        student->age = atoi(age);

        printf("Edited to %s of %i years\n", student->name, student->age);
        return student;
    } else {
        printf("Invalid id! \n");
        return NULL;
    }

}

struct student * remove_student() {
    list_students();
    int id = get_id();
    if(school_students[id] != NULL && id < students_index) {
        struct student *student = school_students[id];
        printf("Do you really want to remove %s of %i years? (y/n)\n", student->name, student->age);
        char response[100];
        fgets(response, 100, stdin);
        response[strcspn(response, "\n")] = 0;

        if (strcmp(response, "y") == 0) {
            for (int i = id; i < students_index - 1; i++) {
                school_students[i] = school_students[i + 1];
                school_students[i]->id = i;
            }
            printf("%s of %i has been removed\n", student->name, student->age);
            free(student);
            students_index = students_index - 1;
            return student;
        } else if (strcmp(response, "n") == 0) {
            printf("Remove aborted!");
            return student;
        } else {
            printf("Invalid option!");
        }
        return student;
    } else {
        printf("Invalid id! \n");
        return NULL;
    }
}

int student_menu() {
    char option_string[100];
    int option = 6;
    while(option != 5) {
        printf(" 1 - List\n 2 - Add\n 3 - Edit\n 4 - Remove\n 5 - Back\n");
        fgets (option_string, 100, stdin);
        option_string[strcspn(option_string, "\n")] = 0;
        option = atoi(option_string);

        switch (option) {
            case 1:
                list_students();
                break;
            case 2:
                create_student();
                break;
            case 3:
                edit_student();
                break;
            case 4:
                remove_student();
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
