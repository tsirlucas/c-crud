#ifndef CRUD_LANGUAGES_DISCIPLINE_H
#define CRUD_LANGUAGES_DISCIPLINE_H

struct discipline {
    int id;
    char name[1000];
};

struct discipline * school_disciplines[1000];

void list_disciplines();
struct discipline * create_discipline();
struct discipline * edit_discipline();
struct discipline * remove_discipline();

int discipline_menu();

#endif //CRUD_LANGUAGES_DISCIPLINE_H
