#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[2000],zhong[5]="END";
int f1=0,f2=0,len,ls[2000],name,shelve,cost,st,num,all,inp;
int shelves[10][10],mem[5][10],pric[30];
void tur()
{
    printf("请再次阅读操作指南 谢谢\n");
    gets(str);
}
int main()
{
    gets(str);
    while (strcmp(str,zhong)!=0)// not END
    {
        f1=0;f2=0;
        // 判断长度
        len=strlen(str);
        if (len>=15)
        {
            printf("您的操作似乎出现了些问题\n");
            tur();continue;
        }
        // 判断名字
        ls[0]=str[0];ls[1]=str[1];//读取
        if (ls[0]>='A'&&ls[0]<='Z'&&ls[1]==' ')
        {
            name=ls[0]+1-'A';//名字正确 标记
        }
        else
        {
            printf("我不认识这样的货物呢~\n");
            tur();continue;
        }
        //判断货架
        ls[2]=str[2];ls[3]=str[3];
        if (ls[2]>='1'&&ls[2]<='5'&&ls[3]==' ')//货架选择的格式正确
        {
            shelve=ls[2]-'0';
            if (shelves[shelve][1]!=0&&shelves[shelve][1]!=name)//在一个通道内摆了不同的货物
            {
                printf("一个通道只能摆放一种货物呦~\n");
                tur();continue;
            }
            // else shelves[shelve][1]=name;
        }
        else
        {
            printf("好像并没有这样的货架呢~\n");
            tur();continue;
        }
        //判断单价
        ls[4]=str[4];ls[5]=str[5];ls[6]=str[6];
        if (ls[4]>='0'&&ls[4]<='9'&&ls[5]==' ')
        {
            cost=ls[4]-'0';st=6;
        }
        else if (ls[4]=='1'&&ls[5]=='0'&&ls[6]==' ')
        {
            cost=10;st=7;
        }
        else
        {
            printf("这个价格，我感到好不舒服╭(╯^╰)╮\n");
            tur();continue;
        }
        if (pric[name]!=0&&pric[name]!=cost)
        {
            printf("这个货物不是这个价格的");
            tur();continue;
        }
        
        //判断摆放数量
        num=0;
        for (int i = st; i < len; i++)
        {
            num=num*10+str[i]-'0';
            if (num>=100)
            {
                f2=-1;break;
            }
        }
        if (f2==-1)
        {
            printf("东西好多，我装不下了~\n");
            tur();continue;
        }
        if (shelves[shelve][2]+num>50)
        {
            printf("东西好多，我装不下了~\n");
            tur();continue;
        }
        shelves[shelve][2]+=num;
        shelves[shelve][1]=name;
        pric[name]=cost;
        printf("%d %d %d %d %d\n",name,shelve,cost,num,shelves[shelve][2]);
        gets(str);
    }
    // printf("fE\n");
    gets(str);
    while (strcmp(str,zhong)!=0)
    {
        f1=0;f2=0;
        // 判断长度
        len=strlen(str);
        if (len>=7)
        {
            printf("您的操作似乎出现了些问题\n");
            tur();continue;
        }
        // 判断名字
        ls[0]=str[0];ls[1]=str[1];//读取
        if (ls[0]>='A'&&ls[0]<='Z'&&ls[1]==' ')
        {
            name=ls[0]+1-'A';//名字正确 标记
        }
        else
        {
            printf("我不认识这样的货物呢~\n");
            tur();continue;
        }
        //判断货架
        ls[2]=str[2];ls[3]=str[3];
        if (ls[2]>='1'&&ls[2]<='5'&&ls[3]==' ')//货架选择的格式正确
        {
            shelve=ls[2]-'0';
            if (shelves[shelve][1]==0&&shelves[shelve][1]!=name)//货架与货物不对应
            {
                printf("这个通道没有储存你需要的货物诶~\n");
                tur();continue;
            }
            // else shelves[shelve][1]=name;
        }
        else
        {
            printf("好像并没有这样的货架呢~\n");
            tur();continue;
        }
        //判断数量
        if (len==5)
        {
            ls[4]=str[4]-'0';
            printf("%d\n",shelves[shelve][2]);
            if (shelves[shelve][2]<ls[4])
            {
printf("%d %d\n",shelve,ls[4]);
                printf("万分抱歉,我无法供应给您足够数量的货物\n该通道只有%d件您所需要的货物\n",shelves[shelve][2]);
                gets(str);continue;
            }
            else
            {
                shelves[shelve][2]-=ls[4];
                all+=pric[name]*ls[4];
            }
        }
        if (len==6)
        {
            ls[4]=(str[4]-'0')*10+str[5]-'0';
            if (shelves[shelve][2]<ls[4])
            {
                printf("万分抱歉,我无法供应给您足够数量的货物\n该通道只有%d件您所需要的货物\n");
                gets(str);continue;
            }
            else
            {
                shelves[shelve][2]-=ls[4];
                all+=pric[name]*ls[4];
            }
        }
        gets(str);
    }
    inp=0;
    while (inp<all)
    {
        gets(str);
        len=strlen(str);
        if(len>=2)
        {
            printf("投币好像投错了呢(╯︵╰)");
            tur();continue;
        }
        else
        {
            ls[0]=str[0]-'0';
            if (ls[0]!=1&&ls[0]!=2&&ls[0]!=5)
            {
                printf("投币好像投错了呢(╯︵╰)");
                tur();continue;
            }
            else inp+=ls[0];
        }
    }
    printf("%d\n",inp-all);
    return 0;
}