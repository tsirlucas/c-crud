#ifndef CRUD_LANGUAGES_STUDENT_H
#define CRUD_LANGUAGES_STUDENT_H

struct student {
    int id;
    char name[1000];
    int age;
};

struct student * school_students[1000];

void list_students();
struct student * create_student();
struct student * edit_student();
struct student * remove_student();

int student_menu();

#endif //CRUD_LANGUAGES_STUDENT_H
