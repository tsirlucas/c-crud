cmake_minimum_required(VERSION 3.6)
project(crud_languages)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c student/student.c student/student.h professor/professor.c professor/professor.h discipline/discipline.c discipline/discipline.h class/class.c class/class.h)
add_executable(crud_languages ${SOURCE_FILES})