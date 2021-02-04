# Platform dependence

ISO C 范例程序的整理，已经接近尾声。但遗憾的是，大多数当下流行的功能，比如网络通信、进程间通信、并发计算（多进程与多线程）、定时执行、系统级别的文件操作以及权限处理等功能等，ISO标准已经无能为力，需要借助具体操作系统平台所提供的函数接口来完成。除了Windows平台的接口，它们中大多数也都包含在BSD、POSIX、IEEE等系列标准中。接下来我们将依次介绍这些接口，分为类Unix（包含Linux, mac）、Windows两个目录分门别类地整理。

类Unix部分将直接搬运APUE[^1]的范例代码，理论上来说，这些代码也可以在mac系统中编译与运行。它们将充分地展示系统化的C语言工程编译方式，以及大量的系统接口的具体使用方法。您也可将适用的代码应用于未来的项目之中。

.  
├── advio  
├── daemons  
├── datafiles  
├── db  
├── environ  
├── exercises  
├── figlinks  
├── filedir  
├── fileio  
├── **include**     // 项目头文件aupe.h存放目录，定义了本项目中所有的宏和范例中调用的函数  
├── intro  
├── ipc1  
├── ipc2  
├── **lib**            //  实现include目录头文件的所有调用接口函数  
├── printer  
├── proc         // 进程控制  
├── pty  
├── relation  
├── signals  
├── sockets  
├── standards   // 系统环境变量和各类资源限制， make后生成源文件和可执行文件 
├── stdio  
├── termios  
├── threadctl  
└── threads   



[^1]:《UNIX环境高级编程》 Advanced Programming in the UNIX® Environment