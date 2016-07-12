#include <stdlib.h>   
#include <stdio.h>   
#include <time.h>   
  
  
int M[10];  /** 权值 **/  
int X[10] = {10, 11, 12, 13, 14, 15, 16, 17, 20, 29}; /** 输入向量  只需要10个奇偶间隔数字即可**/  
int Y[10] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};  /** 理想输出向量, 1表示偶数  0 表示奇数， 输入的数字从0到9, 修改这个值会导致训练错误**/  
int O[10];  /** 保存输出向量 **/  
int ST = 5; /** 阈值，几乎是任意值**/  
  
  
  
/** 初始化权值 **/  
void initM ()  
{  
    int x = 0;  
    srand ((unsigned int)time(0));  
    for (x = 0; x < 10; ++x) {  
        /** 随机数在 0 - 99 之间 **/  
        M[x] = rand () % 100;  
    }  
}  
  
/** 跃迁型激活函数 **/  
int active (int m, int x)  
{  
    int o = m * x;  
    if (o > ST) {  
        return 1;  // 偶数
    } else {  
        return 0;  
    }      
}  
  
/** 计算输出向量 **/  
void calcY ()  
{  
    int x = 0;  
    for (x = 0; x < 10; ++x) {  
        O[x] = active (M[x], X[x]);  
    }  
}  


/** 根据实际输出向量和理想输出向量调整权向量,  
    返回 实际输出和理想输出不匹配的数目 **/  
int adjustM ()  
{  
    int err = 0;  
    int x = 0;  
    for (x = 0; x < 10; ++x) {  
        if (O[x] != Y[x])  
        {  
            err ++;  
            if (0 == O[x]) {  
                M[x] += X[x];// 偶数则加，奇数则减  调整权值，更加接近答案
            } else {  
                M[x] -= X[x];  
            }  
        }  
    }  
    return err;  
}  
  
  
/** 打印权向量 **/  
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
        printf ("%d 是 偶数\n", input);  
    } else {  
        printf ("%d 是 奇数\n", input);  
    }  
}  


int  nnFunc(){
	int n = 0;  
	initM ();  

	/** 一直训练直到能够100%正确为止 **/  
	while (1) {  
		n ++;  
		calcY ();  
		int err = adjustM ();  
		if (0  >= err) {  
			/** 能够 100 %正确地回答问题了，结束训练 **/  
			break;  
		}  
		printf ("错误数 %d\n", err);  
	}  

	printM ();  
	printf ("阈值 %d 训练次数 %d\n", ST, n);  


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

