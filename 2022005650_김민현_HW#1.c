//융합전자공학부 2022005650 김민현


#include <stdio.h>
#include <time.h>


unsigned long long int fact_recursive(int n) {
	if (n <= 1) {
		return 1; // 재귀중 1에 도달할시 종료
	}
	else {
		return n * fact_recursive(n - 1); // n-1을 적용하여 재귀호출
	}
}

unsigned long long int fact_iter(int n){
	long long int fact_n=1; // n! 변수선언
	for (int i=1;i<=n;i++){
		fact_n=fact_n*i; //for loop를 이용하여 n!계산
	}
	return fact_n; // n! 리턴
}

int main()
{
	clock_t start1, stop1; // fact_recursive() 함수 시간측정을 위한 변수설정
	double duration1, duration2; //clock gap
	int num = 20; // 임의의 수 N
	start1=clock();
	printf("%d 팩토리얼의 값은 %llu 입니다.\n", num, fact_recursive(num)); // fact_recursive() 함수로 팩토리얼 계산
	stop1=clock();
	duration1=(double)(stop1-start1)/CLOCKS_PER_SEC;
	printf("fact_recursive의 수행시간은 %f초입니다.\n", duration1);


	clock_t start2, stop2; // fact_iter() 함수 시간측정을 위한 변수설정
	start2=clock();
	printf("%d 팩토리얼의 값은 %llu 입니다.\n", num, fact_iter(num)); // fact_iter() 함수로 팩토리얼 계산
	stop2=clock();
	duration2=(double)(stop2-start2)/CLOCKS_PER_SEC;


	printf("fact_iter의 수행시간은 %f초입니다.\n", duration2);

	if (duration1 > duration2) {
		printf("fact_recursive() 함수가 fact_iter() 함수보다 더 오래걸렸습니다.");
	}
	else if (duration1 == duration2) {
		printf("두 함수의 실행시간이 동일합니다.");
	}
	else {
		printf("fact_iter() 함수가 fact_recursive() 함수보다 더 오래걸렸습니다.");
	}

}