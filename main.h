#pragma once
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data_type.h"
#include "file_operation.h"

bool user_login();

int menu(void);

int sort_menu(void);

bool enter_information(Student_info* info);

void print_info_header(void);

void print_info(Student_info info);

#endif //MAIN_H
