#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
char str[2000],zhong[5]="END",realzhong[6]="OVER";
int f1=0,f2=0,len,ls[2000],name,shelve,cost,st,num,all,inp,allnum;
int shelves[10][10],mem[5][10],pric[30];
void tur();
void fz();
void xz();
void gm();
void mq();
int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    printf("欢迎使用\033[31m华中科技大学\033[0m自动售货机，下面是我的操作指南(*^▽^*)\n");
    printf("您可以进行1:\033[32m货物放置\033[0m  2:\033[33m选择货物\033[0m  3:\033[34m货物购买\033[0m  三种操作，");
    printf("请注意货物放置只可进行\033[31m一\033[0m次，当货物\033[31m全部\033[0m购买完之前或是您键入\033[31mOVER\033[0m前，请持续进行选择与购买\n");
    printf("在“\033[32m货物放置\033[0m”“\033[33m选择货物\033[0m”“\033[34m货物购买\033[0m”得不同操作之间，请用\033[31mEND\033[0m来告知我哦（注意大写捏）( • ̀ω•́ )✧\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\033[32m关于货物放置(￣▽￣)／\033[0m\n所有的货物均⽤\033[31m⼀\033[0m个⼤写英⽂字⺟代替（如A,B,C...X,Y,Z）\n我只有\033[31m 5 \033[0m个通道⽤来摆放货物，每个通道只能放\033[31m⼀\033[0m种货物，且每个通道最多放⼊\033[31m 50 \033[0m个货物；\033[31m不同\033[0m的通道可以放\033[31m相同\033[0m种类的货物\n每种货物的单价均在\033[31m 10 元以下\033[0m，且均为\033[31m整数\033[0m\n");
    printf("请您按照“\033[35m货物名称 所在通道 货物单价 摆放个数\033[0m”的顺序进行该操作，每一次操作完都要换行，注意空格哦(〃'▽'〃)\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\033[33m关于选择货物(￣▽￣)／\033[0m\n我需要知晓您的\033[31m货物选择\033[0m，\033[31m所在通道\033[0m，\033[31m购买数量\033[0m才能全心全意为您服务哦(๑＞ڡ＜)☆\n");
    printf("请您按照“\033[35m货物名称 所在通道 选择个数\033[0m”的顺序进行该操作，每一次操作完都要换行，注意空格哦(〃'▽'〃)\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\033[34m关于货物购买(￣▽￣)／\033[0m\n我现在只认识\033[31m 1 元， 2 元和 5 元\033[0m呢(T^T)\n请您输入您投币的价格，当超过所需价格不用担心，我会自动找零哦φ(>ω<*) \n");
    printf("这一次您只需要输入投币金额我就明白您的意思啦(〃'▽'〃)\n");
    printf("就是这么多喽，欢迎使用\033[31m华中科技大学\033[0m自动售货机\n");
    fz();
    system("pause");
    return 0;
}
void tur()
{
    printf("请再次阅读操作指南 谢谢\n");
    gets(str);
}
void fz()
{
    printf("\n\n货物摆放\n请按照：货物名称 所在通道 货物单价 摆放个数 的顺序摆放您的货物\n");
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
        for (int i=st;i<len;i++)
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
        allnum+=num;
        shelves[shelve][1]=name;
        pric[name]=cost;
        // printf("%d %d %d %d %d\n",name,shelve,cost,num,shelves[shelve][2]);
        gets(str);
    }
    xz();
}
void xz()
{
    printf("\n\n货物选择\n请按照：货物名称 所在通道 选择个数 选择您需要的货物\n");
    mq();
    gets(str);
    if(strcmp(str,realzhong)==0) exit(0);
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
            // printf("%d\n",shelves[shelve][2]);
            if (shelves[shelve][2]<ls[4])
            {
// printf("%d %d\n",shelve,ls[4]);
                printf("万分抱歉,我无法供应给您足够数量的货物\n该通道只有%d件%c货物\n",shelves[shelve][2],shelves[shelve][1]-1+'A');
                gets(str);continue;
            }
            else
            {
                shelves[shelve][2]-=ls[4];
                all+=pric[name]*ls[4];
                allnum-=ls[4];
            }
        }
        if (len==6)
        {
            ls[4]=(str[4]-'0')*10+str[5]-'0';
            if (shelves[shelve][2]<ls[4])
            {
                printf("万分抱歉,我无法供应给您足够数量的货物\n该通道只有%d件%c货物\n",shelves[shelve][2],shelves[shelve][1]-1+'A');
                gets(str);continue;
            }
            else
            {
                shelves[shelve][2]-=ls[4];
                all+=pric[name]*ls[4];
                allnum-=ls[4];
            }
        }
        mq();
        gets(str);
    }
    gm();
}
void gm()
{
    printf("\n\n货物购买\n只要输入您投币的数值就可以咯,应支付%d元哦\n",all);
    inp=0;
    while (inp<all)
    {
        gets(str);
        len=strlen(str);
        if(len>=2)
        {
            printf("投币好像投错了呢(╯︵╰)\n请再次阅读操作指南，谢谢\n");
            continue;
        }
        else
        {
            ls[0]=str[0]-'0';
            if (ls[0]!=1&&ls[0]!=2&&ls[0]!=5)
            {
                printf("投币好像投错了呢(╯︵╰)\n请再次阅读操作指南，谢谢\n");
                continue;
            }
            else inp+=ls[0];
        }
    }
    printf("%d\n",inp-all);
    all=0;
    if (allnum<=0)
    {
        printf("东西都已经卖完了哦");
        exit(0);
    }
    xz();
}
void mq()
{
    printf("目前");
    for (int i=1;i<=5;i++)
    {
        if(shelves[i][2]==0)
        {
            printf("货道%d没有货物  ",i);
            continue;
        }
        printf("货道%d有%d件%c货物  ",i,shelves[i][2],shelves[i][1]-1+'A');
    }
    printf("\n");
}