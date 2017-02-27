#include "stdio.h"
#include "student/student.h"

int main() {
    create_student("lucas", 20);
    create_student("marcelo", 20);
    create_student("carlos", 20);
    remove_student(1);
    edit_student(1);
    list_students();
    create_student("marcelo", 20);
    list_students();
    edit_student(1);
    list_students();
    return 0;
}