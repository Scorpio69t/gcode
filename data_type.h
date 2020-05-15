#pragma once
#ifndef DATA_TYPE_H
#define DATA_TYPE_H
#include <time.h>
#include <stdbool.h>

#define USER "gupengcheng"
#define PASS "gpc123456"

#define FILE_PATH "./info/"
#define MH_MAX_LEN 512   //病史最大长度
#define TI_MAX_LEN 215   //返校路线、交通信息最大长度
#define CC_MAX_LEN 215   //密切接触人员信息最大长度


typedef enum _Student_type /* 学生类型 */
{
	DOCTOR = 0,  //0：博士生
	MASTER,     //1：硕士生
	NORMAL,     //2：本科生
}Student_type;

typedef enum _College_type /*学院类型*/
{
	SIGNAL_COMMUNICATION = 0,  //通信学院
	COMPUTER,                  //计算机学院
	AUTOMATION,                //自动化学院
	ADVANCED_MANUFACTURING,    //先进制造学院
	PHOTOELECTRICITY,          //光电学院
	SOFTWARE,                  //软件学院
	SCIENCE,                   //理学院
	MANAGEMENT,               //经管学院
	MEDIA,                    //传媒学院
	FOREIGN_LANGUAGES,        //外语学院
	INTERNATIONAL,            //国际学院
	SAFETY_LAW,               //安法学院
}College_type;

typedef struct _Admission_information /* 进校信息 */
{
	float temperature; //温度
	unsigned char medical_history[MH_MAX_LEN]; //过去14天病史
	int have_a_fever;  //是否发烧
	int cough; //是否咳嗽
	time_t time; //进校时间
}Admission_information;


typedef struct _Student_info /* 学生进校登记信息 */
{
	long number; //学号
	char name[20]; //姓名
	char ID[20]; //身份证号
	Student_type s_type; //学生类型
	College_type c_type; //学院类型
	char major[30]; //专业
	char traffic_info[TI_MAX_LEN]; //返校路线、交通信息
	char close_contact[CC_MAX_LEN]; //密切接触人员信息
	Admission_information Admission_info; //进校信息
	struct _Student_info* next; //下一个学生的指针
} Student_info;


#endif //DATA_TYPE_H
