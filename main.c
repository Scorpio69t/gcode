#include "main.h"

int main() {
	bool login = user_login();
	bool enter_info = false;
	Student_info info;
	int select = 0;
	int sort_select = -1;

	while(!login)
	{
		fflush(stdin);
		printf("登录失败！请检查用户名和密码！\n");
		getchar();
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif //_WIN32
		login = user_login();
	}
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif //_WIN32
	printf("登录成功！欢迎您！\n");

	while (login)
	{
		select = menu();
		switch (select)
		{
		case 0:
			login = false;
			break;
		case 1:
			//memset((void*)&info, '\0', sizeof(info));
#ifdef _WIN32
			system("cls");
#else
			system("clear");
#endif //_WIN32
			enter_info = enter_information(&info);
			if (enter_info) {
				save_student_information(info);
			}
			break;
		case 2:
#ifdef _WIN32
			system("cls");
#else
			system("clear");
#endif //_WIN32
			sort_select = sort_menu();
			while(sort_select < 0 || sort_select > 11)
			{
				printf("输入有误，请重新输入！\n");
				getchar();
#ifdef _WIN32
				system("cls");
#else
				system("clear");
#endif //_WIN32
				sort_select = sort_menu();
			}
			printf("开始排序：%d\n", sort_select);
			break;
		case 5:
			print_info_header();
			memset((void*)&info, 0, sizeof(info));
			get_student_info_by_line("计算机学院.txt", &info, 1);
			print_info(info);
			memset((void*)&info, 0, sizeof(info));
			get_student_info_by_line("计算机学院.txt", &info, 2);
			print_info(info);
			break;
		default:
			printf("输入有误，请重新输入！\n");
			getchar();
			fflush(stdin);
#ifdef _WIN32
			system("cls");
#else
			system("clear");
#endif //_WIN32
			break;
		}
	}

	printf("谢谢使用！\n");
	return 0;
}

bool user_login()
{
	char name[20] = { 0 };
	char pass[20] = { 0 };

	printf("欢迎使用重庆邮电大学学生返校信息系统\n");
	printf("请输入用户名： __________\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", name);
	fflush(stdin);
	printf("请输入用户 %s 的密码： _________\b\b\b\b\b\b\b\b\b", name);
	scanf("%s", pass);

	if (strcmp(name, USER) == 0 && strcmp(pass, PASS) == 0) {
		return true;
	}

	return false;
}

int menu(void)
{
	int select = 0;
	printf("********************************************\n");
	printf("** 欢迎使用重庆邮电大学学生返校信息系统 **\n");
	printf("**********      1、录入信息      **********\n");
	printf("**********      2、信息排序      **********\n");
	printf("**********      3、查找信息      **********\n");
	printf("**********      4、修改信息      **********\n");
	printf("**********      5、显示信息      **********\n");
	printf("**********      0、退出系统      **********\n");
	printf("********************************************\n");
	printf("请输入您要进行的操作（0-5）: _\b");
	scanf("%d", &select);

	return select;
}

int sort_menu(void)
{
	int select = 0;
	printf("********************************************\n");
	printf("**********      0、通信学院      **********\n");
	printf("**********      1、计算机学院    **********\n");
	printf("**********      2、自动化学院    **********\n");
	printf("**********      3、先进制造学院   **********\n");
	printf("**********      4、光电学院      **********\n");
	printf("**********      5、软件学院      **********\n");
	printf("**********      6、理学院       **********\n");
	printf("**********      7、经管学院      **********\n");
	printf("**********      8、传媒学院      **********\n");
	printf("**********      9、外语学院      **********\n");
	printf("**********      10、国际学院     **********\n");
	printf("**********      11、安法学院     **********\n");
	printf("请输入您要排序的学院（0-11）: _\b");
	scanf("%d", &select);

	return select;
}

bool enter_information(Student_info* info)
{
	bool res = false;

	do
	{
		printf("请输入您的学号（仅限数字）：______\b\b\b\b\b\b");
		scanf("%ld", &info->number);
		fflush(stdin);

		printf("请输入您的姓名(小于10字符)：______\b\b\b\b\b\b");
		scanf("%s", &info->name);
		fflush(stdin);

		printf("请输入您的身份证号码(18位字符)：__________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->ID);
		fflush(stdin);

		printf("注：0->博士生; 1->硕士生; 2->本科生.\n");
		printf("请输入您的学生类型(0-2)：_\b");
		scanf("%d", &info->s_type);
		fflush(stdin);

		printf("注：0->通信学院; 1->计算机学院; 2->自动化学院; 3->先进制造学院; 4->光电学院; 5->软件学院;\n");
		printf("   6->理学院; 7->经管学院; 8->传媒学院; 9->外语学院; 10->国际学院; 11->安法学院.\n");
		printf("请输入您的学院类型(0-11)：_\b");
		scanf("%d", &info->c_type);
		fflush(stdin);

		printf("请输入您的专业信息(小于15字符)：________\b\b\b\b\b\b\b\b");
		scanf("%s", &info->major);
		fflush(stdin);

		printf("请输入您的返校路线和交通信息(小于127字符)：__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->traffic_info);
		fflush(stdin);

		printf("请输入您的密切接触人员信息(小于127字符)：__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->close_contact);
		fflush(stdin);

		//进校信息
		printf("请输入您的体温(两位小数)：____\b\b\b\b");
		scanf("%f", &info->Admission_info.temperature);
		fflush(stdin);

		printf("请输入您的过去14天的病史(小于217字符)：__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->Admission_info.medical_history);
		fflush(stdin);

		printf("注：0->否; 1->是.\n");
		printf("请输入您是否发烧(0-1)：_\b");
		scanf("%d", &info->Admission_info.have_a_fever);
		fflush(stdin);

		printf("注：0->否; 1->是.\n");
		printf("请输入您是否咳嗽(0-1)：_\b");
		scanf("%d", &info->Admission_info.cough);
		fflush(stdin);

		time_t t = time(NULL);
		info->Admission_info.time = time(&t);

		res = true;
	} while (0);

	return res;
}

void print_info_header(void)
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif //_WIN32
	printf(" 姓名 \t  学号  \t 身份证 \t 学生类型 \t 学院类型 \t 专业信息 \t 交通信息 \t 密切接触者 \t 体温 \t 过去14天病史 \t 是否发烧 \t 是否咳嗽 \t 进校时间 \t\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void print_info(Student_info info)
{
	char a_time[24] = { 0 };
	get_Admission_time(info.Admission_info.time, a_time);

	char s_type[8] = { '\0' };
	get_real_s_type(info.s_type, s_type);

	char c_type[15] = { '\0' };
	get_real_c_type(info.c_type, c_type);

	char f_type[5] = { '\0' };
	get_true_or_false(info.Admission_info.have_a_fever, f_type);

	char fc_type[5] = { '\0' };
	get_true_or_false(info.Admission_info.cough, fc_type);

	printf("\| %s \| %ld \| %s \| %s \| %s \| %s \| %s \| %s \| %.2f \| %s \| %s \| %s \| %s \|\n", info.name, info.number, info.ID, s_type, c_type \
		, info.major, info.traffic_info, info.close_contact, info.Admission_info.temperature, info.Admission_info.medical_history \
		, f_type, fc_type, a_time);
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
