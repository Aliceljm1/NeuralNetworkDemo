#include <stdlib.h>   
#include <stdio.h>   
#include <time.h>   
  
  
int M[10];  /** Ȩֵ **/  
int X[10] = {10, 11, 12, 13, 14, 15, 16, 17, 20, 29}; /** ��������  ֻ��Ҫ10����ż������ּ���**/  
int Y[10] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};  /** �����������, 1��ʾż��  0 ��ʾ������ ��������ִ�0��9, �޸����ֵ�ᵼ��ѵ������**/  
int O[10];  /** ����������� **/  
int ST = 5; /** ��ֵ������������ֵ**/  
  
  
  
/** ��ʼ��Ȩֵ **/  
void initM ()  
{  
    int x = 0;  
    srand ((unsigned int)time(0));  
    for (x = 0; x < 10; ++x) {  
        /** ������� 0 - 99 ֮�� **/  
        M[x] = rand () % 100;  
    }  
}  
  
/** ԾǨ�ͼ���� **/  
int active (int m, int x)  
{  
    int o = m * x;  
    if (o > ST) {  
        return 1;  // ż��
    } else {  
        return 0;  
    }      
}  
  
/** ����������� **/  
void calcY ()  
{  
    int x = 0;  
    for (x = 0; x < 10; ++x) {  
        O[x] = active (M[x], X[x]);  
    }  
}  


/** ����ʵ��������������������������Ȩ����,  
    ���� ʵ����������������ƥ�����Ŀ **/  
int adjustM ()  
{  
    int err = 0;  
    int x = 0;  
    for (x = 0; x < 10; ++x) {  
        if (O[x] != Y[x])  
        {  
            err ++;  
            if (0 == O[x]) {  
                M[x] += X[x];// ż����ӣ��������  ����Ȩֵ�����ӽӽ���
            } else {  
                M[x] -= X[x];  
            }  
        }  
    }  
    return err;  
}  
  
  
/** ��ӡȨ���� **/  
void printM ()  
{  
    int x = 0;  
    for (x = 0; x < 10; ++x) {  
        printf ("M[%i] = %i\n", x, M[x]);  
    }  
}  
  
  
void test (int input)  
{  
    printf ("[%i] [%i] ", M[input], X[input]);  
    if (active (M[input], X[input]))  
    {  
        printf ("%d �� ż��\n", input);  
    } else {  
        printf ("%d �� ����\n", input);  
    }  
}  


int  nnFunc(){
	int n = 0;  
	initM ();  

	/** һֱѵ��ֱ���ܹ�100%��ȷΪֹ **/  
	while (1) {  
		n ++;  
		calcY ();  
		int err = adjustM ();  
		if (0  >= err) {  
			/** �ܹ� 100 %��ȷ�ػش������ˣ�����ѵ�� **/  
			break;  
		}  
		printf ("������ %d\n", err);  
	}  

	printM ();  
	printf ("��ֵ %d ѵ������ %d\n", ST, n);  


	while (1) {  
		int a = 0;  
		scanf ("%i", &a);  
		if (0 > a || 9 < a) {  
			break;  
		}  

		test (a);  
	}  
	return 0;  
}

