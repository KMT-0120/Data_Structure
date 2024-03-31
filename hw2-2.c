// 융합전자공학부 2022005650 김민현


#include <stdio.h>
#include <time.h>

struct student { //학생 구조체 선언
	char name[20];
	int id;
	int dataS;
	int linearA;
	int circuitT;
};
int sum(struct student s) { //과목별 점수 합계
	return s.dataS + s.linearA + s.circuitT;
}
int avg(struct student s) { //과목별 평균
	return sum(s) / 3;
}
void print(struct student s) { //학생 정보 출력
	printf("%7s ", s.name);
	printf("%7d ", s.id);
	printf("%7d ", s.dataS);
	printf("%11d ", s.linearA);
	printf("%11d ", s.circuitT);
	printf("%11d ", sum(s));
	printf("%9d", avg(s));
	printf("%7c\n", gpa(s));
}
int gpa(struct student s) { //학점 계산
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
		{"김인식", 20240001, 90, 99, 78},
		{"박철수", 20210020	, 75, 88, 95},
		{"홍길동", 20230100	, 86, 77, 86},
		{"강동구", 20221001, 57, 66, 46},
		{"성동구", 20231200	, 90, 89, 87},
		{"김개동", 20230201	, 99, 78, 91},
		{"마속", 20240002, 78, 94, 85},
		{"여포", 20201111, 69, 96, 79},
		{"유비", 20193000, 88, 92, 89}
	}; //학생 정보 초기화

	printf("%7s %7s %11s %11s %11s %11s %7s %7s\n", "이름", "학번","자료구조","선형대수","회로이론","점수합계","평균","학점");


	for (int i = 0; i < 9; i++) { //학생 정보 출력
		print(s[i]);
	}
}