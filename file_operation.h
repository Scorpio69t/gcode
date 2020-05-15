#pragma once
#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <stdio.h>
#include <stdlib.h>
#include "data_type.h"

//����ѧԺ���ͻ�ȡ������ļ���
void get_file_name_by_college(College_type type, char* file);

//����ѧ����Ϣ
void save_student_information(Student_info info);

void get_student_info_by_file(char* file_name, Student_info* info);

//���ж�ȡѧ����Ϣ
void get_student_info_by_line(char* file_name, Student_info* info, int line);

//ʱ���ת��Ϊ��׼ʱ��
void get_Admission_time(time_t ti, char* nowtime);

//ת��ѧ������
void get_real_s_type(Student_type s, char* s_type);

//ת��ѧԺ����
void get_real_c_type(College_type c, char* c_type);

//ת���Ƿ�
void get_true_or_false(int f, char* f_type);

void set_file_line(FILE* fin, int line);

#endif //FILE_OPERATION_H
