#include <stdio.h>

// KEY 非常重要，不能对公众泄露KEY值
// 发送端和接收端提前秘密约定好KEY值
#define KEY 1313113 // 密钥。更换密钥可以得到不同的加密结果

// 加密算法可以公开
int encrypt(int plainText, int key)
{
    return plainText ^ key;
}

// 解密算法也可以公开
int decrypt(int cipherText, int key)
{
    return cipherText ^ key;
}

int main(void)
{
    int plainText = 20000;

    // 发送端要发送的数据plainText

    printf("plainText is %d\n", plainText);

    // 发送端加密(知道KEY)
    int cipherText = encrypt(plainText, KEY);
    printf("cipherText is %d\n", cipherText);

    /* 请忽略以下注释，感觉很幼稚

	  发送端把cipherText传输到接收端
	  如果cipherText在途中被犯罪分子截取
      即使犯罪分子知道加解密算法，也不能进行
	  因为犯罪分子不知道发送端和接收端私下约定的KEY
    */

    // 接收端解密(知道KEY)
    int result = decrypt(cipherText, KEY);

    // 接收端解密得到的数据result
    printf("result is %d\n", result);

    return 0;
}

/**
       结果为：

        20000
        1329017
        20000
              

        可见，解码端成功得到了20000，即使犯罪分子在传输途中窃取了1329017也没有用，即使犯罪分子知道加解密算法也没有用.
        值得注意的是：最关键的KEY不能泄露. KEY是发送人员和接收人员在一起的时候（比如春节回家，在自己家里）确定的，犯罪分子是不会知道的.

         
        ————————————————
        版权声明：本文为CSDN博主「stpeace」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
        原文链接：https://blog.csdn.net/stpeace/java/article/details/8294980
**/
