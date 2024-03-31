//�������ڰ��к� 2022005650 �����


#include <stdio.h>
#include <time.h>


unsigned long long int fact_recursive(int n) {
	if (n <= 1) {
		return 1; // ����� 1�� �����ҽ� ����
	}
	else {
		return n * fact_recursive(n - 1); // n-1�� �����Ͽ� ���ȣ��
	}
}

unsigned long long int fact_iter(int n){
	long long int fact_n=1; // n! ��������
	for (int i=1;i<=n;i++){
		fact_n=fact_n*i; //for loop�� �̿��Ͽ� n!���
	}
	return fact_n; // n! ����
}

int main()
{
	clock_t start1, stop1; // fact_recursive() �Լ� �ð������� ���� ��������
	double duration1, duration2; //clock gap
	int num = 20; // ������ �� N
	start1=clock();
	printf("%d ���丮���� ���� %llu �Դϴ�.\n", num, fact_recursive(num)); // fact_recursive() �Լ��� ���丮�� ���
	stop1=clock();
	duration1=(double)(stop1-start1)/CLOCKS_PER_SEC;
	printf("fact_recursive�� ����ð��� %f���Դϴ�.\n", duration1);


	clock_t start2, stop2; // fact_iter() �Լ� �ð������� ���� ��������
	start2=clock();
	printf("%d ���丮���� ���� %llu �Դϴ�.\n", num, fact_iter(num)); // fact_iter() �Լ��� ���丮�� ���
	stop2=clock();
	duration2=(double)(stop2-start2)/CLOCKS_PER_SEC;


	printf("fact_iter�� ����ð��� %f���Դϴ�.\n", duration2);

	if (duration1 > duration2) {
		printf("fact_recursive() �Լ��� fact_iter() �Լ����� �� �����ɷȽ��ϴ�.");
	}
	else if (duration1 == duration2) {
		printf("�� �Լ��� ����ð��� �����մϴ�.");
	}
	else {
		printf("fact_iter() �Լ��� fact_recursive() �Լ����� �� �����ɷȽ��ϴ�.");
	}

}