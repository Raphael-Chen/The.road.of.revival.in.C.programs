#include <stdio.h>
#include <assert.h>

//usage: ./program input_file_name output_file_name

int main(int argc, char const *argv[])
{
    // assert(argc < 3);
    if ( argc < 3 )
    {
        printf("Input Error: Lake of arguments.\n");
        return -1;
    }

    int len = 1;
    char buff[2048];
    FILE *in, *out;
    char const *src_path = argv[1];       // 要被拷贝的文件路径
    char const *des_path = argv[2];       // 拷贝的文件放在哪里（路径）
    
    in  = fopen(src_path, "r+");
    out = fopen(des_path, "w+");

    // 判断文件是否打开成功
    if ( NULL == in || NULL == out )
    {
        // 打开失败则输出错误原因
        perror("fopen error");

        // Closes the underlying file descriptor.
        fclose( in );
        fclose( out );
        return -2;
    }

    // while ( (len = fread(buff, 1, sizeof(buff), in) ) > 0 )
    // while ( ( len  ) > 0 )
    do
    {
        len = fread(buff, 1, sizeof(buff), in);     
        fwrite(buff, 1, len, out);
    } while ( len > 0 );

    // Closes the underlying file descriptor.
    fclose( in );
    fclose( out );

    return 0;
}

