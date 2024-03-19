#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX       2147483647
#include <windows.h>
#include <stdio.h>
#include <iostream>  
#include <string.h>
#include <psapi.h>
#include <tlhelp32.h>

#pragma comment(lib, "psapi.lib")
#include <unordered_map>

using namespace std;


#define _DFDF "lzl16@chinatele.com.cn"

std::unordered_map<int, string> getAdminapp()
{
    // 获取进程句柄
    std::unordered_map<int, string> ret;
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);

    return std::move(ret);
}


//lzl3316@chinatele.com.cn;
char _chinatele_com_cn[] = "@chinatele";
char weijun_chinatelecoma[] = "sadfdb";
char chinatele_com_cn[] = "chinatele";
char mailChar[] = "lzl16@chinatele.com.cn";
char mailmailChar1[] = "lzl2216@chinatele.com.cn";
bool  _chinatele_com_cnbool = true;
int _chinatele_com_cn_int = 0;
//复杂类型变量名称检测
unordered_map<string, int> _chinatele_com_cn_map;
string lzl_chinatelecoma = "";


class MyClass
{
public:
    MyClass();
    ~MyClass();
    void testMail();
private:
    string lzl = "@chinatelecom";
    unordered_map<string, int> _chinatele_com_cn_map;

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}



/// @brief lzl3316@chinatele.com.cn
void MyClass::testMail()
{
    string mail = "lzl2216@chinatele.com.cn";
    char mailChar[] = "lzl16@chinatele.com.cn";
    char mailChar1[] = "lzl2216@chinatele.com.cn";
    char test[] = _DFDF;
}


int main()
{
    cout << mailmailChar1 << endl;
    //复杂类型变量名称检测
    unordered_map<string, int> _chinatele_com_cn_map1;
    string lzl_chinatelecoma1 = "";

    // 1. 缓冲区溢出  
    // 使用strcpy而不检查目标缓冲区大小，可能导致溢出  
    char buffer1[10];
    strcpy(buffer1, "This is a very long string that will cause a buffer overflow!"); // 不安全：缓冲区溢出  

    // 2. 未初始化的变量  
    // 变量x未初始化，其值是不确定的  
    // vs编译器不让编译
    //int x;  
    //if (x == 0) {  
    //    cout << "x is zero" << endl; // 不安全：未初始化的变量  
    //}  

    // 3. 空指针引用  
    // 解引用空指针，导致程序崩溃  
    int* ptr1 = nullptr;
    int value1 = *ptr1; // 不安全：空指针引用  

    // 4. 资源泄露  
    // 动态分配的内存没有被释放  
    int* leaked_memory = new int[100]; // 不安全：资源泄露  

    // 5. 不安全的函数使用  
    // 使用gets函数，它不检查缓冲区大小，容易导致溢出  
    // vs2015之后用不了了
    //char password[10];  
    //gets(password); // 不安全：使用gets函数  

    // 6. 整数溢出  
    // 增加INT_MAX会导致整数溢出  
    int a = INT_MAX;
    a += 1; // 不安全：整数溢出  

    // 7. 未检查的数组边界  
    // 访问数组时超出了其边界  
    int array[10];
    for (int i = 0; i <= 10; ++i) {
        array[i] = i; // 不安全：访问数组越界  
    }

    // 8. 不安全的类型转换  
    // 类型转换可能导致精度损失或未定义行为  
    double d = 3.14;
    int i = static_cast<int>(d); // 不安全：不安全的类型转换  

    // 9. 不安全的文件操作  
    // 打开文件时没有错误检查，读取时也没有检查fgets的返回值  
    FILE* file = fopen("file.txt", "r");
    if (file) {
        char buffer[128];
        fgets(buffer, sizeof(buffer), file); // 不安全：文件操作未检查错误  
        fclose(file);
    }

    // 10. 不安全的字符串操作  
    // 目标字符串未初始化，使用strcat可能导致未定义行为  
    char dest[50]; // 未初始化  
    char src[] = "This is a source string";
    strcat(dest, src); // 不安全：目标字符串未初始化  

    return 0;
}