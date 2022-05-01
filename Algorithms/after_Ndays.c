#include <stdio.h>
#include <time.h>
#include <string.h>

// 计算前N天，后N天的日期，详见代码：

// @brief	计算前N天或者后N的日期
// @param[in]	cDateIn : 输入,格式"2019-03-11 12:00:00"
// @param[in]	ndays   : 前N天,输入-N;后N天,则输入N
// @param[out]	cDateOut : 输出,格式"2019-03-11 12:00:00"
// @return
#define TIME_FORMAT "%d-%d-%d %d:%d:%d"

int calc_date(char *cDateIn, int ndays, char *cDateOut)
{
    struct tm tmin;
    struct tm *pTmIn = &tmin;
    struct tm tmout;
    struct tm *pTmOut = &tmout;
    char buf[32];

    //由于windows下没有strptime函数，所以可以使用scanf来格式化
    int year, month, day, hour, minute, second;
    sscanf(cDateIn, TIME_FORMAT, &year, &month, &day, &hour, &minute, &second);
    
    pTmIn->tm_year = year - 1900;
    pTmIn->tm_mon = month - 1;
    pTmIn->tm_mday = day;

    pTmIn->tm_hour = hour;
    pTmIn->tm_min = minute;
    pTmIn->tm_sec = second;
    pTmIn->tm_isdst = -1;

    // 将tm结构数据转换成1970年1月1日开始计算的秒数
    time_t tmp = mktime(pTmIn);

    // 计算需要增加或者减少天数对应的秒数，结果是最终日期对应1970年1月1日开始计算的秒数
    tmp += ndays * 60 * 60 * 24;

    // 将time_t的信息转化真实世界的时间日期表示，结果由结构tm返回
    pTmOut = localtime(&tmp);

    // tm类型的时间转换。将tm按照%Y%m%d格式转化赋值到输出中
    
    memset(buf, 0, sizeof(buf));
    // strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", pTmOut);
    strftime(buf, sizeof(buf), "%Y-%m-%d", pTmOut);
    strcpy(cDateOut, buf);

    return 0;
}
// 整体思路：把输入的日期字符串转为时间（秒），再将天数转为秒，进行相加减，得出结果需要的时间（秒），
// 最后通过strftime函数格式化输出为时间字符串。
// ————————————————
// 版权声明：本文为CSDN博主「hellokandy」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/hellokandy/article/details/88401497


// int main( int argc, char* argv[] )
int main( void )
{
    // int year, month, day;
    // 输入年月日

    // 拼凑时间
    // const char* time = "12:00:00";

    // const char* date_in = "2021-03-11 12:00:00";
    char date_in[32];
    strncpy( date_in, "2021-03-11 16:17:00", 32 );
    char date_out[32];
    calc_date( date_in, 98, date_out );
    printf( "date_in: %s\ndate is: %s\n", date_in, date_out );

    return 0;
}

