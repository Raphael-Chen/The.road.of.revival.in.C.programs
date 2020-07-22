#include "ioput.h"

//蔡勒公式计算星期，只适合于1582年10月15日之后的日期
int calc_week(int year, int month, int day);

//计算闰年
int calc_leap_year(int year);

//日历核心函数
void calc_core(void);