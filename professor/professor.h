#ifndef CRUD_LANGUAGES_PROFESSOR_H
#define CRUD_LANGUAGES_PROFESSOR_H

struct professor {
    int id;
    char name[1000];
    int age;
};

struct professor * school_professors[1000];

void list_professors();
struct professor * create_professor();
struct professor * edit_professor();
struct professor * remove_professor();

int professor_menu();

#endif //CRUD_LANGUAGES_PROFESSOR_H
