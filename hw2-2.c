// �������ڰ��к� 2022005650 �����


#include <stdio.h>
#include <time.h>

struct student { //�л� ����ü ����
	char name[20];
	int id;
	int dataS;
	int linearA;
	int circuitT;
};
int sum(struct student s) { //���� ���� �հ�
	return s.dataS + s.linearA + s.circuitT;
}
int avg(struct student s) { //���� ���
	return sum(s) / 3;
}
void print(struct student s) { //�л� ���� ���
	printf("%7s ", s.name);
	printf("%7d ", s.id);
	printf("%7d ", s.dataS);
	printf("%11d ", s.linearA);
	printf("%11d ", s.circuitT);
	printf("%11d ", sum(s));
	printf("%9d", avg(s));
	printf("%7c\n", gpa(s));
}
int gpa(struct student s) { //���� ���
	if (avg(s) >= 90) {
		return 'A';
	}
	else if (avg(s) >= 80) {
		return 'B';
	}
	else if (avg(s) >= 70) {
		return 'C';
	}
	else{
		return 'D';
	}
}
int main() {
	struct student s[9]={
		{"���ν�", 20240001, 90, 99, 78},
		{"��ö��", 20210020	, 75, 88, 95},
		{"ȫ�浿", 20230100	, 86, 77, 86},
		{"������", 20221001, 57, 66, 46},
		{"������", 20231200	, 90, 89, 87},
		{"�谳��", 20230201	, 99, 78, 91},
		{"����", 20240002, 78, 94, 85},
		{"����", 20201111, 69, 96, 79},
		{"����", 20193000, 88, 92, 89}
	}; //�л� ���� �ʱ�ȭ

	printf("%7s %7s %11s %11s %11s %11s %7s %7s\n", "�̸�", "�й�","�ڷᱸ��","�������","ȸ���̷�","�����հ�","���","����");


	for (int i = 0; i < 9; i++) { //�л� ���� ���
		print(s[i]);
	}
}