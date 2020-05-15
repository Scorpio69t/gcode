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
		file_name = "ͨ��ѧԺ.txt";
		break;
	case COMPUTER:
		file_name = "�����ѧԺ.txt";
		break;
	case AUTOMATION:
		file_name = "�Զ���ѧԺ.txt";
		break;
	case ADVANCED_MANUFACTURING:
		file_name = "�Ƚ�����ѧԺ.txt";
		break;
	case PHOTOELECTRICITY:
		file_name = "���ѧԺ.txt";
		break;
	case SOFTWARE:
		file_name = "���ѧԺ.txt";
		break;
	case SCIENCE:
		file_name = "��ѧԺ.txt";
		break;
	case MANAGEMENT:
		file_name = "����ѧԺ.txt";
		break;
	case MEDIA:
		file_name = "��ýѧԺ.txt";
		break;
	case FOREIGN_LANGUAGES:
		file_name = "����ѧԺ.txt";
		break;
	case INTERNATIONAL:
		file_name = "����ѧԺ.txt";
		break;
	case SAFETY_LAW:
		file_name = "����ѧԺ.txt";
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

	printf("ѧ����Ϣ����ɹ�! �ļ�����%s.\n", file_name);

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
		memcpy(s_type, "��ʿ��", strlen("��ʿ��"));
		break;
	case MASTER:
		memcpy(s_type, "˶ʿ��", strlen("˶ʿ��"));
		break;
	default:
		memcpy(s_type, "������", strlen("������"));
		break;
	}
}

void get_real_c_type(College_type c, char* c_type)
{
	switch (c)
	{
	case SIGNAL_COMMUNICATION:
		memcpy(c_type, "ͨ��ѧԺ", strlen("ͨ��ѧԺ"));
		break;
	case COMPUTER:
		memcpy(c_type, "�����ѧԺ", strlen("�����ѧԺ"));
		break;
	case AUTOMATION:
		memcpy(c_type, "�Զ���ѧԺ", strlen("�Զ���ѧԺ"));
		break;
	case ADVANCED_MANUFACTURING:
		memcpy(c_type, "�Ƚ�����ѧԺ", strlen("�Ƚ�����ѧԺ"));
		break;
	case PHOTOELECTRICITY:
		memcpy(c_type, "���ѧԺ", strlen("���ѧԺ"));
		break;
	case SOFTWARE:
		memcpy(c_type, "���ѧԺ", strlen("���ѧԺ"));
		break;
	case SCIENCE:
		memcpy(c_type, "��ѧԺ", strlen("��ѧԺ"));
		break;
	case MANAGEMENT:
		memcpy(c_type, "����ѧԺ", strlen("����ѧԺ"));
		break;
	case MEDIA:
		memcpy(c_type, "��ýѧԺ", strlen("��ýѧԺ"));
		break;
	case FOREIGN_LANGUAGES:
		memcpy(c_type, "����ѧԺ", strlen("����ѧԺ"));
		break;
	case INTERNATIONAL:
		memcpy(c_type, "����ѧԺ", strlen("����ѧԺ"));
		break;
	default:
		memcpy(c_type, "����ѧԺ", strlen("����ѧԺ"));
		break;
	}
}

void get_true_or_false(int f, char* f_type)
{
	if (f) {
		memcpy(f_type, "��", strlen("��"));
	}
	else {
		memcpy(f_type, "��", strlen("��"));
	}
}

void set_file_line(FILE *fin, int line)
{
	int i = 0;
	for (; i < line; i++) {
		fscanf(fin, "%*[^\n]%*c");
	}
}
