#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
char str[100000],zhong[5]="END",realzhong[6]="OVER",bb[6]="back";
int f1=0,f2=0,len,ls[100000],name,shelve,cost,st,num,all,inp,allnum;
int shelves[10][10],mem[5][10],pric[30];
int huitui[5][15],ht;
bool f;
void tur();
void fz();
void xz();
void gm();
void gob();
void bog();
void htfuc();
int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    printf("��ӭʹ��\033[31m���пƼ���ѧ\033[0m�Զ��ۻ������������ҵĲ���ָ��(*^��^*)\n");
    printf("�����Խ���1:\033[32m�������\033[0m  2:\033[33mѡ�����\033[0m  3:\033[34m���ﹺ��\033[0m  ���ֲ�����");
    printf("��ע��������ֻ�ɽ���\033[31mһ\033[0m�Σ�������\033[31mȫ��\033[0m������֮ǰ����������\033[31mOVER\033[0mǰ�����������ѡ���빺��\n");
    printf("�ڡ�\033[32m�������\033[0m����\033[33mѡ�����\033[0m����\033[34m���ﹺ��\033[0m���ò�ͬ����֮�䣬����\033[31mEND\033[0m����֪��Ŷ��ע���д��( ? ?��?? )?\n");
    printf("�������˹��ܣ����롰back���������СдŶ������ִ�л��˲��������ǻ����ܴ�����Ȼû�����ƣ��������������������\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\033[32m���ڻ������(������)��\033[0m\n���еĻ����?\033[31m?\033[0m��?дӢ?��?���棨��A,B,C...X,Y,Z��\n��ֻ��\033[31m 5 \033[0m��ͨ��?���ڷŻ��ÿ��ͨ��ֻ�ܷ�\033[31m?\033[0m�ֻ����ÿ��ͨ������?\033[31m 50 \033[0m�����\033[31m��ͬ\033[0m��ͨ�����Է�\033[31m��ͬ\033[0m����Ļ���\nÿ�ֻ���ĵ��۾���\033[31m 10 Ԫ����\033[0m���Ҿ�Ϊ\033[31m����\033[0m\n");
    printf("�������ա�\033[35m�������� ����ͨ�� ���ﵥ�� �ڷŸ���\033[0m����˳����иò�����ÿһ�β����궼Ҫ���У�ע��ո�Ŷ(��'��'��)\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\033[33m����ѡ�����(������)��\033[0m\n����Ҫ֪������\033[31m����ѡ��\033[0m��\033[31m����ͨ��\033[0m��\033[31m��������\033[0m����ȫ��ȫ��Ϊ������Ŷ(?��?��)��\n");
    printf("�������ա�\033[35m�������� ����ͨ�� ѡ�����\033[0m����˳����иò�����ÿһ�β����궼Ҫ���У�ע��ո�Ŷ(��'��'��)\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\033[34m���ڻ��ﹺ��(������)��\033[0m\n������ֻ��ʶ\033[31m 1 Ԫ�� 2 Ԫ�� 5 Ԫ\033[0m��(T^T)\n����������Ͷ�ҵļ۸񣬵���������۸��õ��ģ��һ��Զ�����Ŷ��(>��<*) \n");
    printf("��һ����ֻ��Ҫ����Ͷ�ҽ���Ҿ�����������˼��(��'��'��)\n");
    printf("������ô��ඣ���ӭʹ��\033[31m���пƼ���ѧ\033[0m�Զ��ۻ���\n");
    fz();
    return 0;
}
void tur()
{
    printf("���ٴ��Ķ�����ָ�� лл\n");
    gets(str);
}
void fz()
{
    printf("\n\n����ڷ�\n�밴�գ��������� ����ͨ�� ���ﵥ�� �ڷŸ��� ��˳��ڷ����Ļ���\n");
    gets(str);
    while (strcmp(str,zhong)!=0)// not END
    {
    	if(strcmp(str,bb)==0)
    	{
    		htfuc();
    		bog();
    		gets(str);
    		continue;
		}
        f1=0;f2=0;
        // �жϳ���
        len=strlen(str);
        if (len>=15)
        {
            printf("���Ĳ����ƺ�������Щ����\n");
            tur();continue;
        }
        // �ж�����
        ls[0]=str[0];ls[1]=str[1];//��ȡ
        if (ls[0]>='A'&&ls[0]<='Z'&&ls[1]==' ')
        {
            name=ls[0]+1-'A';//������ȷ ���
        }
        else
        {
            printf("�Ҳ���ʶ�����Ļ�����~\n");
            tur();continue;
        }
        //�жϻ���
        ls[2]=str[2];ls[3]=str[3];
        if (ls[2]>='1'&&ls[2]<='5'&&ls[3]==' ')//����ѡ��ĸ�ʽ��ȷ
        {
            shelve=ls[2]-'0';
            if (shelves[shelve][1]!=0&&shelves[shelve][1]!=name)//��һ��ͨ���ڰ��˲�ͬ�Ļ���
            {
                printf("һ��ͨ��ֻ�ܰڷ�һ�ֻ�����~\n");
                tur();continue;
            }
            // else shelves[shelve][1]=name;
        }
        else
        {
            printf("����û�������Ļ�����~\n");
            tur();continue;
        }
        //�жϵ���
        f=false;
        ls[4]=str[4];ls[5]=str[5];ls[6]=str[6];
        if (ls[4]>='0'&&ls[4]<='9'&&ls[5]==' ')
        {
            cost=ls[4]-'0';st=6;
        }
        else
        {
            printf("����۸��Ҹе��ò�����q(�s^�t)�r\n");
            tur();continue;
        }
        if (pric[name]!=0&&pric[name]!=cost)
        {
            printf("������ﲻ������۸��");
            tur();continue;
        }
        if(pric[name]!=0&&pric[name]==cost)//��������ʱ�����Ǹ���� 
          f=true;
        //�жϰڷ�����
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
            printf("�����ö࣬��װ������~\n");
            tur();continue;
        }
        if (shelves[shelve][2]+num>50)
        {
            printf("�����ö࣬��װ������~\n");
            tur();continue;
        }
        shelves[shelve][2]+=num;
        allnum+=num;
        shelves[shelve][1]=name;
        pric[name]=cost;
        gob();
        huitui[1][1]=6;huitui[1][2]=name;huitui[1][3]=shelve;huitui[1][4]=num;huitui[1][5]=cost;
        if(f) huitui[1][6]=1;
        else huitui[1][6]=0;
        // printf("%d %d %d %d %d\n",name,shelve,cost,num,shelves[shelve][2]);
        gets(str);
    }
    xz();
}
void xz()
{
    printf("\n\n����ѡ��\n�밴�գ��������� ����ͨ�� ѡ����� ѡ������Ҫ�Ļ���\n");
    gets(str);
    
    if(strcmp(str,realzhong)==0) exit(0);
    while (strcmp(str,zhong)!=0)
    {
		if(strcmp(str,bb)==0)
        {
            htfuc();
            bog();
            gets(str);
            continue;
        }
        f1=0;f2=0;
        // �жϳ���
        len=strlen(str);
        if (len>=7)
        {
            printf("���Ĳ����ƺ�������Щ����\n");
            tur();continue;
        }
        // �ж�����
        ls[0]=str[0];ls[1]=str[1];//��ȡ
        if (ls[0]>='A'&&ls[0]<='Z'&&ls[1]==' ')
        {
            name=ls[0]+1-'A';//������ȷ ���
        }
        else
        {
            printf("�Ҳ���ʶ�����Ļ�����~\n");
            tur();continue;
        }
        //�жϻ���
        ls[2]=str[2];ls[3]=str[3];
        if (ls[2]>='1'&&ls[2]<='5'&&ls[3]==' ')//����ѡ��ĸ�ʽ��ȷ
        {
            shelve=ls[2]-'0';
            if (shelves[shelve][1]!=0&&shelves[shelve][1]!=name)//��������ﲻ��Ӧ
            {
                printf("���ͨ��û�д�������Ҫ�Ļ�����~\n");
                tur();continue;
            }
            // else shelves[shelve][1]=name;
        }
        else
        {
            printf("����û�������Ļ�����~\n");
            tur();continue;
        }
        //�ж�����
        if (len==5)
        {
            ls[4]=str[4]-'0';
            // printf("%d\n",shelves[shelve][2]);
            if (shelves[shelve][2]<ls[4])
            {
// printf("%d %d\n",shelve,ls[4]);
                printf("��ֱ�Ǹ,���޷���Ӧ�����㹻�����Ļ���\n��ͨ��ֻ��%d��%c����\n",shelves[shelve][2],shelves[shelve][1]-1+'A');
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
                printf("��ֱ�Ǹ,���޷���Ӧ�����㹻�����Ļ���\n��ͨ��ֻ��%d��������Ҫ�Ļ���\n",shelves[shelve][2],shelves[shelve][1]-1+'A');
                gets(str);continue;
            }
            else
            {
                shelves[shelve][2]-=ls[4];
                all+=pric[name]*ls[4];
                allnum-=ls[4];
            }
        }
        gob();
        huitui[1][1]=5;huitui[1][2]=name;huitui[1][3]=shelve;huitui[1][4]=num;huitui[1][5]=ls[4];
        gets(str);
    }
    gm();
}
void gm()
{
    printf("\n\n���ﹺ��\nֻҪ������Ͷ�ҵ���ֵ�Ϳ��Կ�\n");
    inp=0;
    while (inp<all)
    {
        gets(str);
        if(strcmp(str,bb)==0)
        {
        	htfuc();
            bog();
            continue;
        }
        len=strlen(str);
        if(len>=2)
        {
            printf("Ͷ�Һ���Ͷ������(�s��t)");
            tur();continue;
        }
        else
        {
            ls[0]=str[0]-'0';
            if (ls[0]!=1&&ls[0]!=2&&ls[0]!=5)
            {
                printf("Ͷ�Һ���Ͷ������(�s��t)");
                tur();continue;
            }
            else inp+=ls[0];
        }
        gob();
        huitui[1][1]=2;huitui[1][2]=ls[0];
    }
    printf("%d\n",inp-all);
    all=0;
    if (allnum<=0)
    {
        printf("�������Ѿ�������Ŷ");
        exit(0);
    }
    xz();
}
void gob()
{
	for(int i=2;i>=1;i--)
	{
		for(int j=1;j<=huitui[i][1];j++)
		  huitui[i+1][j]=huitui[i][j];
	}
	for(int i=1;i<=6;i++) huitui[1][i]=0;
}
void bog()
{
	for(int i=2;i<=3;i++)
	{
		for(int j=1;j<=huitui[i][1];j++)
		  huitui[i-1][j]=huitui[i][j];
	}
	for(int i=1;i<=6;i++) huitui[3][i]=0;
}
void htfuc()
{
	if(huitui[1][1]==6)
	{
		shelves[huitui[1][3]][2]-=huitui[1][4];
		allnum-=huitui[1][4];
		if(!huitui[1][6])
		{
			shelves[huitui[1][3]][1]=0;
			pric[huitui[1][2]]=0;
		}
	}
	else if(huitui[1][1]==5)
	{
		shelves[huitui[1][3]][2]+=huitui[1][5];
		all-=pric[huitui[1][2]]*huitui[1][5];
		allnum+=huitui[1][5];
	}
	else
	{
		inp-=huitui[1][2];
	}
}
