#pragma once
#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <stdio.h>
#include <stdlib.h>
#include "data_type.h"

//根据学院类型获取保存的文件名
void get_file_name_by_college(College_type type, char* file);

//保存学生信息
void save_student_information(Student_info info);

void get_student_info_by_file(char* file_name, Student_info* info);

//按行读取学生信息
void get_student_info_by_line(char* file_name, Student_info* info, int line);

//时间戳转换为标准时间
void get_Admission_time(time_t ti, char* nowtime);

//转换学生类型
void get_real_s_type(Student_type s, char* s_type);

//转换学院类型
void get_real_c_type(College_type c, char* c_type);

//转换是否
void get_true_or_false(int f, char* f_type);

void set_file_line(FILE* fin, int line);

#endif //FILE_OPERATION_H
