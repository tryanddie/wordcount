#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
                if(isspace(ch)==0)
                ++count;
        }
        fclose(f_read);
        printf("文件的字符数(不包含空格回车)为%d\n",count);
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
                if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                        while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))       //一连串的字符组成一个单词
                        ch=fgetc(f_read);
                        ++count;
                }
        }
        fclose(f_read);
        printf("文件的单词数为%d\n",count);
        system("pause");
}

void Countline(char File[]){
        int count=0;            //行数计数
        char ch[1024];
        int status=0;           //用于规避空文件的行数统计问题
        FILE *f_read=fopen(File,"r");
        if(f_read==NULL){
                printf("打开文件出现错误或者没有此文件，请重试\n");
                return ;
        }
        while(!feof(f_read)){
                fgets(ch,1024,f_read);
                if(status==0&&ch[0]=='\0')    break;  //第一行全无内容，且为空行则行数为0
                else status=1;
                count++;
        }
        fclose(f_read);
        printf("文件的行数为%d\n",count);
        system("pause");
}

void Countother(char File[]){
        int count[3]={0};
        char ch[1024]={0};
        int status=0;
        FILE *f_read=fopen(File,"r");
        if(f_read==NULL){
                printf("打开文件出现错误或者没有此文件，请重试\n");
                return ;
        }
        while(!feof(f_read)){
                fgets(ch,1024,f_read);
                if(status==0){
                        if(strstr(ch,"//")!=NULL||strstr(ch,"/*")!=NULL||strstr(ch,"*/")!=NULL) count[0]++;
                        else {
                                int diff=0;             //字符数
                                int site=0;             //位置
                               while(site<strlen(ch)||diff<1){
                                                if(isspace(ch[site])==0) diff++;
                                                site++;
                                }
                                if(diff>1) count[1]++;          //两个字符以上即为代码行
                                else count[2]++;
                        }
                }
                else count[0]++;
                if(strstr(ch,"/*")!=NULL)       status=1;
                if(strstr(ch,"*/")!=NULL)      status=0;
        }
        fclose(f_read);
        printf("文件的注释行数为%d\n文件的代码行数为%d\n文件的空行数为%d\n",count[0],count[1],count[2]);
        system("pause");
}

int main()
{
    int test=1;
    char control;               //对应的命令
    char File[50];              //对应的文件地址
    while(test)
    {
        printf("请输入用户命令(查询指令表请输入k)wc.exe-");
        scanf(" %c",&control);
        if(control=='k'){
                printf("c  统计字符数；\t w  统计单词数;\tl  统计行数; \na 返回文件基本情况； \t 0 退出");
                          break;
        }
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
                case 'a': Countother(File);
                          break;
                case '0': return 0;                              //输入0，则直接退出
                default : printf("无此指令，请重新输入\n");
                          break;                                //根据对应的指令进行对应的处理
        }
    }
}
