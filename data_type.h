#pragma once
#ifndef DATA_TYPE_H
#define DATA_TYPE_H
#include <time.h>
#include <stdbool.h>

#define USER "gupengcheng"
#define PASS "gpc123456"

#define FILE_PATH "./info/"
#define MH_MAX_LEN 512   //��ʷ��󳤶�
#define TI_MAX_LEN 215   //��У·�ߡ���ͨ��Ϣ��󳤶�
#define CC_MAX_LEN 215   //���нӴ���Ա��Ϣ��󳤶�


typedef enum _Student_type /* ѧ������ */
{
	DOCTOR = 0,  //0����ʿ��
	MASTER,     //1��˶ʿ��
	NORMAL,     //2��������
}Student_type;

typedef enum _College_type /*ѧԺ����*/
{
	SIGNAL_COMMUNICATION = 0,  //ͨ��ѧԺ
	COMPUTER,                  //�����ѧԺ
	AUTOMATION,                //�Զ���ѧԺ
	ADVANCED_MANUFACTURING,    //�Ƚ�����ѧԺ
	PHOTOELECTRICITY,          //���ѧԺ
	SOFTWARE,                  //���ѧԺ
	SCIENCE,                   //��ѧԺ
	MANAGEMENT,               //����ѧԺ
	MEDIA,                    //��ýѧԺ
	FOREIGN_LANGUAGES,        //����ѧԺ
	INTERNATIONAL,            //����ѧԺ
	SAFETY_LAW,               //����ѧԺ
}College_type;

typedef struct _Admission_information /* ��У��Ϣ */
{
	float temperature; //�¶�
	unsigned char medical_history[MH_MAX_LEN]; //��ȥ14�첡ʷ
	int have_a_fever;  //�Ƿ���
	int cough; //�Ƿ����
	time_t time; //��Уʱ��
}Admission_information;


typedef struct _Student_info /* ѧ����У�Ǽ���Ϣ */
{
	long number; //ѧ��
	char name[20]; //����
	char ID[20]; //���֤��
	Student_type s_type; //ѧ������
	College_type c_type; //ѧԺ����
	char major[30]; //רҵ
	char traffic_info[TI_MAX_LEN]; //��У·�ߡ���ͨ��Ϣ
	char close_contact[CC_MAX_LEN]; //���нӴ���Ա��Ϣ
	Admission_information Admission_info; //��У��Ϣ
	struct _Student_info* next; //��һ��ѧ����ָ��
} Student_info;


#endif //DATA_TYPE_H
