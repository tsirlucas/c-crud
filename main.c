#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "student/student.h"
#include "professor/professor.h"
#include "discipline/discipline.h"

void entities_menu() {
    char option_string[100];
    int option = 6;
    while(option != 5) {
        printf(" 1 - Student\n 2 - Professor\n 3 - Discipline\n 4 - Class\n 5 - Terminate\n");
        fgets (option_string, 100, stdin);
        option_string[strcspn(option_string, "\n")] = 0;
        option = atoi(option_string);

        switch (option) {
            case 1:
                student_menu();
                break;
            case 2:
                professor_menu();
                break;
            case 3:
                discipline_menu();
                break;
            case 4:
                printf("#TODO class menu");
                break;
            case 5:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid option! \n");
        }
    }
}

int main() {
    entities_menu();
    return 0;
}