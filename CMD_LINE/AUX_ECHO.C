#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[255]; // Line of text read

    while (fgets(line, sizeof(line), stdin))
    {
        fputs(line, stdout);
        strcat(line, "\r");
        // fputs(line, stdaux);
        fputs(line, stdout);
    }
}

/*
C语言提供了5种标准的流，你的程序在任何时候都可以使用它们，并且不必打开或者关闭它们。（以下列出了这5种标准的流。

名称        描述              例子

stdin     标准输入         键盘
stdout    标准输出          屏幕
stderr    标准错误          屏幕
stdprn    标准打印机       LPT1端口
stdaux    标准串行设备     COM1端口

其中,stdprn和stdaux并不是总是预先定义好的，因为LPT1和COM1端口在某些操作系统中是没有意义的，而stdin,stdout和 stderr 总是预先定义好的。
参见：
https://blog.csdn.net/xiaoran_zhu/article/details/41624367


5.2.5  Standard Devices 
The standard devices are the keyboard, screen, auxiliary device, and printer.  The system provides open file handles to these devices when it starts a program, as shown in the following table. 

Name                           Handle      Device 
Standard input (STDIN)         0           CON 
Standard output (STDOUT)       1           CON 
Standard error (STDERR)        2           CON 
Standard auxiliary (STDAUX)    3           AUX 
Standard printer (STDPRN)      4           PRN 



*/