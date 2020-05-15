#include <string.h>
#include "file_operation.h"

void get_file_name_by_college(College_type type, char* file)
{
	char* p = (char*)malloc(sizeof(char*) * 30);
	if (p == NULL) {
		printf("malloc file_name error!\n");
		return NULL;
	}

	char* file_name = p;
	memset(file_name, '\0', 30);
	switch (type)
	{
	case SIGNAL_COMMUNICATION:
		file_name = "通信学院.txt";
		break;
	case COMPUTER:
		file_name = "计算机学院.txt";
		break;
	case AUTOMATION:
		file_name = "自动化学院.txt";
		break;
	case ADVANCED_MANUFACTURING:
		file_name = "先进制造学院.txt";
		break;
	case PHOTOELECTRICITY:
		file_name = "光电学院.txt";
		break;
	case SOFTWARE:
		file_name = "软件学院.txt";
		break;
	case SCIENCE:
		file_name = "理学院.txt";
		break;
	case MANAGEMENT:
		file_name = "经管学院.txt";
		break;
	case MEDIA:
		file_name = "传媒学院.txt";
		break;
	case FOREIGN_LANGUAGES:
		file_name = "外语学院.txt";
		break;
	case INTERNATIONAL:
		file_name = "国际学院.txt";
		break;
	case SAFETY_LAW:
		file_name = "安法学院.txt";
		break;
	default:
		printf("unkonw College_type %d.\n", type);
		file_name = NULL;
		if (p) {
			free(p);
			p = NULL;
		}
		break;
	}
	if (file_name)
	{
		memcpy(file, file_name, strlen(file_name));
		file_name = NULL;
	}


	if (p) {
		free(p);
		p = NULL;
	}

	return;
}

void save_student_information(Student_info info)
{
	char file_name[30] = { '\0' };

	get_file_name_by_college(info.c_type, file_name);
	if (strlen(file_name) <= 0) {
		printf("file_name error!\n");
		return;
	}

	FILE* fp = fopen(file_name, "a");
	if (fp == NULL) {
		printf("open file: %s error!\n", file_name);
		return;
	}

	//fwrite(&info, sizeof(info), 1, fp);
	fprintf(fp, "%s\t%ld\t%s\t%d\t%d\t%s\t%s\t%s\t%.2f\t%s\t%d\t%d\t%I64d\t", info.name, info.number, info.ID, info.s_type, info.c_type \
				, info.major, info.traffic_info, info.close_contact, info.Admission_info.temperature, info.Admission_info.medical_history \
				, info.Admission_info.have_a_fever, info.Admission_info.cough, info.Admission_info.time);
	fputs("\n", fp);

	printf("学生信息保存成功! 文件名：%s.\n", file_name);

	if (fp) {
		fclose(fp);
	}

	return;
}

void get_student_info_by_file(char* file_name, Student_info* info)
{
	FILE* fp = fopen(file_name, "r");

	while(feof(fp) != EOF) {
		fscanf(fp, "%s\t%ld\t%s\t%d\t%d\t%s\t%s\t%s\t%f\t%s\t%d\t%d\t%I64d\t\n", &info->name, &info->number, &info->ID, &info->s_type, &info->c_type \
			, &info->major, &info->traffic_info, &info->close_contact, &info->Admission_info.temperature, &info->Admission_info.medical_history \
			, &info->Admission_info.have_a_fever, &info->Admission_info.cough, &info->Admission_info.time);
	}

	if (fp) {
		fclose(fp);
	}

	return;
}

void get_student_info_by_line(char* file_name, Student_info* info, int line)
{
	int i = 1;
	FILE* fp = fopen(file_name, "r");

	for (; i < line; i++) {
		fscanf(fp, "%*[^\n]%*c");
	}

	fscanf(fp, "%s\t%ld\t%s\t%d\t%d\t%s\t%s\t%s\t%f\t%s\t%d\t%d\t%I64d\t\n", &info->name, &info->number, &info->ID, &info->s_type, &info->c_type \
		, &info->major, &info->traffic_info, &info->close_contact, &info->Admission_info.temperature, &info->Admission_info.medical_history \
		, &info->Admission_info.have_a_fever, &info->Admission_info.cough, &info->Admission_info.time);

	if (fp) {
		fclose(fp);
	}

	return;
}


void get_Admission_time(time_t ti, char* nowtime) {
	struct tm* lt;
	lt = localtime(&ti);
	strftime(nowtime, 24, "%Y-%m-%d %H:%M:%S", lt);

	return nowtime;
}

void get_real_s_type(Student_type s, char* s_type)
{
	switch (s)
	{
	case DOCTOR:
		memcpy(s_type, "博士生", strlen("博士生"));
		break;
	case MASTER:
		memcpy(s_type, "硕士生", strlen("硕士生"));
		break;
	default:
		memcpy(s_type, "本科生", strlen("本科生"));
		break;
	}
}

void get_real_c_type(College_type c, char* c_type)
{
	switch (c)
	{
	case SIGNAL_COMMUNICATION:
		memcpy(c_type, "通信学院", strlen("通信学院"));
		break;
	case COMPUTER:
		memcpy(c_type, "计算机学院", strlen("计算机学院"));
		break;
	case AUTOMATION:
		memcpy(c_type, "自动化学院", strlen("自动化学院"));
		break;
	case ADVANCED_MANUFACTURING:
		memcpy(c_type, "先进制造学院", strlen("先进制造学院"));
		break;
	case PHOTOELECTRICITY:
		memcpy(c_type, "光电学院", strlen("光电学院"));
		break;
	case SOFTWARE:
		memcpy(c_type, "软件学院", strlen("软件学院"));
		break;
	case SCIENCE:
		memcpy(c_type, "理学院", strlen("理学院"));
		break;
	case MANAGEMENT:
		memcpy(c_type, "经管学院", strlen("经管学院"));
		break;
	case MEDIA:
		memcpy(c_type, "传媒学院", strlen("传媒学院"));
		break;
	case FOREIGN_LANGUAGES:
		memcpy(c_type, "外语学院", strlen("外语学院"));
		break;
	case INTERNATIONAL:
		memcpy(c_type, "国际学院", strlen("国际学院"));
		break;
	default:
		memcpy(c_type, "安法学院", strlen("安法学院"));
		break;
	}
}

void get_true_or_false(int f, char* f_type)
{
	if (f) {
		memcpy(f_type, "是", strlen("是"));
	}
	else {
		memcpy(f_type, "否", strlen("否"));
	}
}

void set_file_line(FILE *fin, int line)
{
	int i = 0;
	for (; i < line; i++) {
		fscanf(fin, "%*[^\n]%*c");
	}
}
