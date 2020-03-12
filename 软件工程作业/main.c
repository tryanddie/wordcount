#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Countcharacter(char File[])                       //字符数计算函数
{
        int count=0;            //字符数计数
        char ch=' ';
        FILE *f_read=fopen(File,"r");
        if(f_read==NULL){
                printf("打开文件出现错误或者没有此文件，请重试\n");
                return ;
        }
        while((ch=fgetc(f_read))!=EOF)
        {
                ++count;
        }
        fclose(f_read);
        printf("文件的字符数为%d\n",count);
        system("pause");
}

void Countword(char File[]){
        int count=0;            //单词数计数
        char ch=' ';
        FILE *f_read=fopen(File,"r");
        if(f_read==NULL){
                printf("打开文件出现错误或者没有此文件，请重试\n");
                return ;
        }
        while((ch=fgetc(f_read))!=EOF)
        {
                while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))       //一连串的字符组成一个单词
                      ch=fgetc(f_read);
                ++count;
        }
        fclose(f_read);
        printf("文件的单词数为%d\n",count);
        system("pause");
}

void Countline(char File[]){
        int count=0;            //行数计数
        char ch[1024];
        FILE *f_read=fopen("File","r");
        if(f_read==NULL){
                printf("打开文件出现错误或者没有此文件，请重试\n");
                return ;
        }
        while(!feof(f_read)){
                fgets(ch,1024,f_read);
                count++;
        }
        fclose(f_read);
        printf("文件的行数为%c\n",count);
        system("pause");
}

int main()
{
    int test=1;
    char control;               //对应的命令
    char File[50];              //对应的文件地址
    while(test)
    {
        printf("请输入用户命令wc.exe-");
        scanf("%c",&control);
        //printf("\n");
        printf("请输入文件的地址");
        scanf("%s",File);
        //printf("\n")
        switch(control){
                case 'c': Countcharacter(File);
                          break;
                case 'w': Countword(File);
                          break;
                case 'l': Countline(File);
                          break;
                default : printf("无此指令，请重新输入\n");
                          break;                                //根据对应的指令进行对应的处理
        }
    }
    return 0;
}
