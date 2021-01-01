#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <time.h>

long long int speed=0;              //���Ƶ��˵��ٶ�
int position_x, position_y;         //���������λ��
int upbullet_x, upbullet_y;         //��ǰ��i�����ӵ���λ��
int leftbullet_x, leftbullet_y;     //��ǰ��j�����ӵ���λ��
int rightbullet_x, rightbullet_y;   //��ǰ�ң�L�����ӵ���λ��
int downbullet_x, downbullet_y;     //��ǰ�£�k�����ӵ���λ��
int enemy_x, enemy_y,flag,flag2=0;  //С͵��λ��
char c[4]={"ZYX"};
char d[4];
int map[190][190]={
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1},
    {0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0},
    {0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0},
    {0,1,0,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,0},
    {0,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,0,1,0},
    {0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0},
    {0,1,1,1,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0},
    {0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,1,1,1,0},
    {0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
    {0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0},
    {0,1,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,1,0},
    {0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0},
    {1,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
};
// ��ͼ��17��17�У����� 0 �����ſյأ�
// 1 ������ǽ��0�����"    ",1�����"��"����������ɷֱ���"��""��"��ʾ��

void startup(){//����λ�ó�ʼ����С͵λ�ó�ʼ�����ӵ�λ�ó�ʼ��������������ӵ���
int x,i;                //
time_t t=time(NULL);    //    ��ϵͳʱ����Ϊ��ǩ�����������
srand(t);               //
position_x=16;          //����λ�ó�ʼ��
position_y=9;
upbullet_x=19;          //�ӵ�λ�ó�ʼ��
upbullet_y=19;
leftbullet_x=0;
leftbullet_y=0;
rightbullet_x=0;
rightbullet_x=19;
downbullet_x=0;
downbullet_y=1;
enemy_x=2;              //С͵λ�ó�ʼ��
enemy_y=7;
flag=0;
flag2=0;
do{enemy_y=rand()%18;}
while ((enemy_y==0)||(enemy_y==1)||(enemy_y==7)||(enemy_y==9)||(enemy_y==16)||(enemy_y==17)||(enemy_y==18));
}

void StartMap(){        //�Ը�����λ���и�ֵ������2��С͵3���ӵ�4567
    map[position_x][position_y]=2;
    map[enemy_x][enemy_y]=3;
    map[upbullet_x][upbullet_y]=4;
    map[leftbullet_x][leftbullet_y]=5;
    map[rightbullet_x][rightbullet_y]=6;
    map[downbullet_x][downbullet_y]=7;
}

void HideCursor()
{//���ع��
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x, int y)
{//����һ������Ļ
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void show(){            //չʾ������
    gotoxy(0,0);
    int i, j;
    for (i=1; i<=17; i++)
    {
        for (j=1; j<=17; j++)
        {
            if (map[i][j] == 0)
                printf("  ");   //�ո���0 �յ�
            if (map[i][j] == 1)
                printf("��");    //����1 ǽ
            if (map[i][j] == 2)
                printf("��");    //����2 ����
            if (map[i][j] == 3)
                printf("��");    //����3 С͵
            if (map[i][j] == 4)
                printf("��");    //����4 �ӵ�
            if (map[i][j] == 5)
                printf("��");    //����5 �ӵ�
            if (map[i][j] == 6)
                printf("��");    //����6 �ӵ�
            if (map[i][j] == 7)
                printf("��");    //����7 �ӵ�
        }
        printf("\n");
    }
    //printf("\n��ĵ÷�:%d\n\n", score);
    printf("\n����һ�����ٵ����񾯲�(��)������һ��С͵(��)�����㸺���Ͻ������������\n��ٿ���Ľ�ɫ(��)������С͵(��)��Ϊ�������\n\n");
    printf("**  ����˵��: WASD�ֱ���� �������� �ĸ�������ƶ�  **\n");
    printf("**            IJKL�ֱ��� �������� �ĸ�������ӵ�  **\n\n");
    printf("##  ��ʾ:�벻Ҫ��ͼ��С͵������,��Ҫʱʹ�����ǹ  ##\n\n");
    printf("%%%  ����:������� DQ262  %%%% ����֧��:dsgwds Acid  %%%\n");
    printf("@@ �ο�����:�� https://blog.csdn.net/zhaojin0718/article/details/81416546 @@\n");
    printf("@@ �ο�����:�� https://blog.csdn.net/zhao5502169/article/details/61620774 @@\n");
}

void updateWithInput()//�������йصĸ���
{
    char input;
    if (kbhit())//��VC6.0++�£�Ϊ_kbhit()
    {
        input = getch();//��VC6.0++��Ϊ_getch();

        //�����Ǿ����ƶ�
        if (input == 'a')                               //�����ƶ�
            if(map[position_x][position_y-1]==0)
                {map[position_x][position_y]=0;position_y--;}
        if (input == 's')                               //�����ƶ�
            if(map[position_x+1][position_y]==0)
                {map[position_x][position_y]=0;position_x++;}
        if (input == 'd')                               //�����ƶ�
            if(map[position_x][position_y+1]==0)
                {map[position_x][position_y]=0;position_y++;}
        if (input == 'w')                               //�����ƶ�
            if(map[position_x-1][position_y]==0)
                {map[position_x][position_y]=0;position_x--;}

        //�����Ƿ����ӵ�
        if (input == 'i')                               //�������
            if(map[position_x-1][position_y]!=1)
                {upbullet_x = position_x - 1;upbullet_y = position_y;}
        if (input == 'j')                               //�������
            if(map[position_x][position_y-1]!=1)
                {leftbullet_x = position_x;leftbullet_y = position_y - 1;}
        if (input == 'k')                               //�������
            if(map[position_x+1][position_y]!=1)
                {downbullet_x = position_x + 1;downbullet_y = position_y;}
        if (input == 'l')                               //�������
            if(map[position_x][position_y+1]!=1)
                {rightbullet_x = position_x;rightbullet_y = position_y + 1;}

        if (input == 'Z'){ZYX();}
}
}
void updateWithoutInput()//�������޹صĸ���
{
    if (upbullet_y < 18 && upbullet_x > 0)           //�ӵ�up�Զ�����
        {
            if(map[upbullet_x-1][upbullet_y]!=1)
                {map[upbullet_x][upbullet_y]=0;upbullet_x--;}
            else {map[upbullet_x][upbullet_y]=0;upbullet_x=19;upbullet_y=19;}
        }
    if (leftbullet_y < 18 && leftbullet_x > 0)       //�ӵ�left�Զ�����
        {
            if(map[leftbullet_x][leftbullet_y - 1]!=1)
                {map[leftbullet_x][leftbullet_y]=0;leftbullet_y--;}
            else {map[leftbullet_x][leftbullet_y]=0;leftbullet_x=0;leftbullet_y=0;}
        }
    if (rightbullet_y < 18 && rightbullet_x > 0)     //�ӵ�right�Զ�����
        {
            if(map[rightbullet_x][rightbullet_y + 1]!=1)
                {map[rightbullet_x][rightbullet_y]=0;rightbullet_y++;}
            else {map[rightbullet_x][rightbullet_y]=0;rightbullet_x=0;rightbullet_y=19;}
        }
    if (downbullet_y < 18 && downbullet_x > 0)       //�ӵ�down�Զ�����
        {
            if(map[downbullet_x + 1][downbullet_y]!=1)
                {map[downbullet_x][downbullet_y]=0;downbullet_x++;}
            else {map[downbullet_x][downbullet_y]=0;downbullet_x=0;downbullet_y=1;}
        }

    if (((upbullet_x == enemy_x) && (upbullet_y == enemy_y))||((leftbullet_x == enemy_x) && (leftbullet_y == enemy_y))||((rightbullet_x == enemy_x) && (rightbullet_y == enemy_y))||((downbullet_x == enemy_x) && (downbullet_y == enemy_y)))
        //�����˵ķɻ�������ʱ
        {
            flag2=1;// printf("��ɹ�������С͵��\n");
        }
    speed = 0;
    if (speed == 0)
    {
        int x,i;                //
        time_t t=time(NULL);    //    ��ϵͳʱ����Ϊ��ǩ�����������
        srand(t);               //
        int p;
        flag=0;
        Sleep(100);
        while(flag==0)
        {
            p=rand()%4;
            switch(p)
            {
                case 0:if(map[enemy_x-1][enemy_y]==0||map[enemy_x-1][enemy_y]==2){map[enemy_x][enemy_y]=0;enemy_x--;flag=1;}break;//С͵���������������
                case 1:if(map[enemy_x][enemy_y-1]==0||map[enemy_x][enemy_y-1]==2){map[enemy_x][enemy_y]=0;enemy_y--;flag=1;}break;//�Ŀյ��ƶ�Ŷ
                case 2:if(map[enemy_x+1][enemy_y]==0||map[enemy_x+1][enemy_y]==2){map[enemy_x][enemy_y]=0;enemy_x++;flag=1;}break;//
                case 3:if(map[enemy_x][enemy_y+1]==0||map[enemy_x][enemy_y+1]==2){map[enemy_x][enemy_y]=0;enemy_y++;flag=1;}break;//
            }
        }
        speed = 1;
    }
    if(enemy_x == position_x && enemy_y == position_y){flag2=2;}
}

void ZYX(){         //������
//if(kbhit())
{int i;
gets(d);
i=strcmp(c,d);
if(i==0)
    flag2=3;}
}

int main()
{
    //int i;

        loop:startup();
        while (flag2==0)
        {
            HideCursor();
            StartMap();
            show();
            updateWithoutInput();
            updateWithInput();
            //Sleep(100);
        }
        switch(flag2)
        {
            case 1: {for(int i=1;i<100;i++)printf("!!!!!  ��ɹ�������С͵��������  !!!!!\n\n");printf("��r�����¿�ʼ��Ϸ...");}break;
            case 2: {for(int i=1;i<100;i++)printf("!!!!!  �㱻С͵�����ˣ����  !!!!!\n\n");printf("��r�����¿�ʼ��Ϸ...");}break;
            case 3: {for(int i=1;i<100;i++)printf("!!!!!  ZYX I LOVE U  !!!!!\n\n");printf("��r�����¿�ʼ��Ϸ...");}break;
        }
        Sleep(2000);
        char input;
        while(1)
            if (kbhit())//��VC6.0++�£�Ϊ_kbhit()
            {
                input = getch();//��VC6.0++��Ϊ_getch();
                if (input == 'r') //��r���¿�ʼ��Ϸ
                {
                    system("cls");
                    map[position_x][position_y]=0;
                    goto loop;
                }
            }
        system("pause");
    return 0;
}
