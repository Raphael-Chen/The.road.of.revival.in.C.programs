/* ioput.h */
#include <stdio.h>


//读取用户输入的年份
int input_year(void);

//读取用户输入的月份
int input_month(void);

//显示日历
void output_days(int year, int month, int week, int is_leap_year);
