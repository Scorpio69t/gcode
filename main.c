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
		printf("��¼ʧ�ܣ������û��������룡\n");
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
	printf("��¼�ɹ�����ӭ����\n");

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
				printf("�����������������룡\n");
				getchar();
#ifdef _WIN32
				system("cls");
#else
				system("clear");
#endif //_WIN32
				sort_select = sort_menu();
			}
			printf("��ʼ����%d\n", sort_select);
			break;
		case 5:
			print_info_header();
			memset((void*)&info, 0, sizeof(info));
			get_student_info_by_line("�����ѧԺ.txt", &info, 1);
			print_info(info);
			memset((void*)&info, 0, sizeof(info));
			get_student_info_by_line("�����ѧԺ.txt", &info, 2);
			print_info(info);
			break;
		default:
			printf("�����������������룡\n");
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

	printf("ллʹ�ã�\n");
	return 0;
}

bool user_login()
{
	char name[20] = { 0 };
	char pass[20] = { 0 };

	printf("��ӭʹ�������ʵ��ѧѧ����У��Ϣϵͳ\n");
	printf("�������û����� __________\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", name);
	fflush(stdin);
	printf("�������û� %s �����룺 _________\b\b\b\b\b\b\b\b\b", name);
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
	printf("** ��ӭʹ�������ʵ��ѧѧ����У��Ϣϵͳ **\n");
	printf("**********      1��¼����Ϣ      **********\n");
	printf("**********      2����Ϣ����      **********\n");
	printf("**********      3��������Ϣ      **********\n");
	printf("**********      4���޸���Ϣ      **********\n");
	printf("**********      5����ʾ��Ϣ      **********\n");
	printf("**********      0���˳�ϵͳ      **********\n");
	printf("********************************************\n");
	printf("��������Ҫ���еĲ�����0-5��: _\b");
	scanf("%d", &select);

	return select;
}

int sort_menu(void)
{
	int select = 0;
	printf("********************************************\n");
	printf("**********      0��ͨ��ѧԺ      **********\n");
	printf("**********      1�������ѧԺ    **********\n");
	printf("**********      2���Զ���ѧԺ    **********\n");
	printf("**********      3���Ƚ�����ѧԺ   **********\n");
	printf("**********      4�����ѧԺ      **********\n");
	printf("**********      5�����ѧԺ      **********\n");
	printf("**********      6����ѧԺ       **********\n");
	printf("**********      7������ѧԺ      **********\n");
	printf("**********      8����ýѧԺ      **********\n");
	printf("**********      9������ѧԺ      **********\n");
	printf("**********      10������ѧԺ     **********\n");
	printf("**********      11������ѧԺ     **********\n");
	printf("��������Ҫ�����ѧԺ��0-11��: _\b");
	scanf("%d", &select);

	return select;
}

bool enter_information(Student_info* info)
{
	bool res = false;

	do
	{
		printf("����������ѧ�ţ��������֣���______\b\b\b\b\b\b");
		scanf("%ld", &info->number);
		fflush(stdin);

		printf("��������������(С��10�ַ�)��______\b\b\b\b\b\b");
		scanf("%s", &info->name);
		fflush(stdin);

		printf("�������������֤����(18λ�ַ�)��__________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->ID);
		fflush(stdin);

		printf("ע��0->��ʿ��; 1->˶ʿ��; 2->������.\n");
		printf("����������ѧ������(0-2)��_\b");
		scanf("%d", &info->s_type);
		fflush(stdin);

		printf("ע��0->ͨ��ѧԺ; 1->�����ѧԺ; 2->�Զ���ѧԺ; 3->�Ƚ�����ѧԺ; 4->���ѧԺ; 5->���ѧԺ;\n");
		printf("   6->��ѧԺ; 7->����ѧԺ; 8->��ýѧԺ; 9->����ѧԺ; 10->����ѧԺ; 11->����ѧԺ.\n");
		printf("����������ѧԺ����(0-11)��_\b");
		scanf("%d", &info->c_type);
		fflush(stdin);

		printf("����������רҵ��Ϣ(С��15�ַ�)��________\b\b\b\b\b\b\b\b");
		scanf("%s", &info->major);
		fflush(stdin);

		printf("���������ķ�У·�ߺͽ�ͨ��Ϣ(С��127�ַ�)��__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->traffic_info);
		fflush(stdin);

		printf("�������������нӴ���Ա��Ϣ(С��127�ַ�)��__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->close_contact);
		fflush(stdin);

		//��У��Ϣ
		printf("��������������(��λС��)��____\b\b\b\b");
		scanf("%f", &info->Admission_info.temperature);
		fflush(stdin);

		printf("���������Ĺ�ȥ14��Ĳ�ʷ(С��217�ַ�)��__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", &info->Admission_info.medical_history);
		fflush(stdin);

		printf("ע��0->��; 1->��.\n");
		printf("���������Ƿ���(0-1)��_\b");
		scanf("%d", &info->Admission_info.have_a_fever);
		fflush(stdin);

		printf("ע��0->��; 1->��.\n");
		printf("���������Ƿ����(0-1)��_\b");
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
	printf(" ���� \t  ѧ��  \t ���֤ \t ѧ������ \t ѧԺ���� \t רҵ��Ϣ \t ��ͨ��Ϣ \t ���нӴ��� \t ���� \t ��ȥ14�첡ʷ \t �Ƿ��� \t �Ƿ���� \t ��Уʱ�� \t\n");
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
