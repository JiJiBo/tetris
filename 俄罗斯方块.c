#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int PD;
int JS;
int T0;
int T1;
int T2;
int D;
int H;
int score;
int Q;
int a[28][19];
int tzjiance();
int hight(); 
void zhenghe();
void print1();
void print2();
int shengcheng();
void yidong();
void xiangxia();
int qingchu();
int zuigao();
void chushihua();
int main()
{
int i,j,x,y,xy;
Q=0;                         //��ʼ�������0Ϊ����ɾ���
H=0;                         //��ʼ���߶�
srand((int)time(0));
T1=17;                        //��ʼ��T1
T2=rand()%18;                 //��ʼ��T2
PD=1;                        //��ʼ�����ף�����Ϊ1�������ӡT1��T2
chushihua(); //��ʼ������
print1();                
print2();                    //��ӡ����
while(H<21)
{
if(PD)
{
print1();          //���T1
print2();                 //������з��鵽�ף���ӡT1��T2
T0=T1; 
T1=T2;
T2=shengcheng(); 
}          //�����µ�T1,T2
print2();
PD=tzjiance();              //�ж� PD���Ƿ񵽵���
if(PD)
zhenghe();             //������ף���T1��ɹ̶�����
H=hight();
for(i=0;i<4;i++)
{
xy=0;
for(x=0;x<5;x++)
for(y=0;y<11;y++)
{
if(a[x][y]==111)
{
	xy=1;
}  
}
if(xy==0)
for(;kbhit();)
D=getch(); 
                //��ȡ��������
if(PD==0)
yidong(D);
if(D!='s')                    //���ݼ�������D�ƶ�T1
Sleep(100);                   //�ȴ�һ��
D='c';
}
xiangxia();                  //�����ƶ�T1
print2();
PD=tzjiance();              //�ж��Ƿ񵽵���
if(PD)
zhenghe();             //������ף���T1��ɹ̶�����
Q=1;
j=4;                       //��ʾδ����ɾ�
while(Q&&PD&&j>1)                //�����������ɾ�������
{
j--;
Q=qingchu();
print2();
}
}
if(H>=21)
{
system("cls");
puts("������");
}
}          //**************************************************������
void chushihua()
{
int i,j;
for(i=5;i<28;i++)
for(j=0;j<19;j++)
a[i][j]=' ';
for(j=0;j<19;j++)
{
a[27][j]=48;   //27�Ǳ߿���48��ʾ
}
for(i=5;i<28;i++)
{
a[i][0]=48;
a[i][18]=48;
a[i][11]=48;  //0,11,18�Ǳ߿���48��ʾ
}
for(j=11;j<19;j++)
{
a[6][j]=48;
a[8][j]=48;
a[15][j]=48;
}
a[7][13]='n';
a[7][14]='e';
a[7][15]='x';
a[7][16]='t';
}
void print2()
{
int i,j;
system("cls");
printf("�߶�=%d\n",H);
printf("����=%d\n",score);
for(j=0;j<19;j++)
printf("%c ",4);
printf("\n");
for(i=5;i<28;i++)
for(j=0;j<19;j++)
{
	if(a[i][j]==111||a[i][j]==48)
        printf("%c ",4);
	else
		printf("%c ",a[i][j]);
if(j==18)
printf("\n");
}
}
int qingchu()
{
int i,j,t,m,n,p;    
for(i=26;i>4;i--)   //�ӵ�����������
{
	t=1;
	for(j=1;j<11;j++)
		if(a[i][j]==' ')
			t=0;     //�����i�г��ֿո�t=1��˵�����в���Ҫ���
	if(t==1)
	{
		for(p=1;p<11;p++)
			a[i][p]=' ';       //�ѵ�i �����
		score++;
		for(m=i-1;m>4;m--)
			for(n=1;n<11;n++)
			{
				if(a[m][n]==48)      //�̶�������79��ʾ
				{
					a[m+1][n]=48;
					a[m][n]=' ';
				}
			}     //�ѵ�i�аᵽi+1�У�����i�����
	}
}
return 1;
}
void xiangxia()
{
int i,j,t,m,n;    
for(i=25;i>=0;i--)   //�ӵ�����������
{
	t=0;
	for(j=1;j<11;j++)
		if(a[i][j]==111)
			t=1;     //�����i�г���T1��t=1��˵��������Ҫ����
	if(t==1)
	{
		m=i;
			for(n=1;n<11;n++)
			{
				if(a[m][n]==111)      //T1������111��ʾ
				{
					a[m+1][n]=111;
					a[m][n]=' ';
				}
			}     //�ѵ�i-1�аᵽi�У�����i-1�����
	}
}
}
void yidong(char D)
{
int m=0,n,i,j,p,t=0;
switch (D)
{
case 'a':for(i=26;i>4;i--)
			 for(j=1;j<11;j++)
				 if(a[i][j]==111&&(a[i][j-1]==79||a[i][j-1]==48))
					 t=1;
			if(t==0)
			{
				for(i=26;i>4;i--)
				for(j=1;j<11;j++)
				 if(a[i][j]==111)
				 {
					 a[i][j-1]=111;
					 a[i][j]=' ';    //����
				 }
			}
		 
	break;
case 'd':for(i=26;i>4;i--)
			 for(j=1;j<11;j++)
				 if(a[i][j]==111&&(a[i][j+1]==79||a[i][j+1]==48))
				     t=1;
            if(t==0)
			{
				for(i=26;i>4;i--)
				for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 a[i][j+1]=111;
					 a[i][j]=' ';    //����
				 }
			}
	break;
case 'w':switch(T0)
	{	 
case 0: break;
case 1:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+2][n]==79||a[m+2][n]==48)
		break;
	else{
	a[m+1][n-1]=' ';
	a[m+2][n]=111;
	T0=2;
	}
	break;
case 2:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+1][n-1]==79||a[m+1][n-1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m+1][n-1]=111;
	T0=3;
		}
	break;
case 3:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m-1][n-1]==79||a[m-1][n-1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m-1][n-1]=111;
	T0=4;
	}
	break;
case 4:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+1][n+1]==79||a[m+1][n+1]==48)
		break;
	else{
	a[m+2][n]=' ';
	a[m+1][n+1]=111;
	T0=1;
	}
	break;
case 5:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
		if(	a[m][n+1]==79||a[m][n+1]==48||a[m+1][n+1]==79||a[m+1][n+1]==48||a[m+1][n-1]==79||a[m+1][n-1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m+2][n]=' ';
	a[m][n-1]=' ';
	a[m][n+1]=111;
	a[m+1][n+1]=111;
	a[m+1][n-1]=111;
	T0=6;
	}
	break;
case 6:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+2][n]==79||a[m+2][n]==48||a[m+2][n-1]==79||a[m+2][n-1]==48||a[m][n-1]==79||a[m][n-1]==48)
		break;
	else{
	a[m+1][n]=' ';
	a[m+1][n-2]=' ';
	a[m][n]=' ';
	a[m+2][n]=111;
	a[m+2][n-1]=111;
	a[m][n-1]=111;
	T0=7;
	}
	break;
case 7:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+1][n-1]==79||a[m+1][n-1]==48||a[m+1][n+1]==79||a[m+1][n+1]==48||a[m+2][n-1]==79||a[m+2][n-1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m+2][n]=' ';
	a[m+2][n+1]=' ';
	a[m+1][n-1]=111;
	a[m+1][n+1]=111;
	a[m+2][n-1]=111;
	T0=8;
	}
	break;
case 8:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m-1][n-2]==79||a[m-1][n-2]==48||a[m+1][n-1]==79||a[m+1][n-1]==48||a[m-1][n-1]==79||a[m-1][n-1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m][n-2]=' ';
	a[m+1][n-2]=' ';
	a[m-1][n-2]=111;
	a[m+1][n-1]=111;
	a[m-1][n-1]=111;
	T0=5;
	}
	break;
case 9:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+1][n]==79||a[m+1][n]==48||a[m+1][n-2]==79||a[m+1][n-2]==48||a[m+2][n]==79||a[m+2][n]==48)
		break;
	else{
	a[m][n]=' ';
	a[m][n-1]=' ';
	a[m+2][n-1]=' ';
	a[m+1][n]=111;
	a[m+1][n-2]=111;
	a[m+2][n]=111;
	T0=10;
	}
	break;
case 10:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m-1][n-1]==79||a[m-1][n-1]==48||a[m+1][n-1]==79||a[m+1][n-1]==48||a[m+1][n-2]==79||a[m+1][n-2]==48)
		break;
	else{
	a[m][n]=' ';
	a[m][n-2]=' ';
	a[m+1][n]=' ';
	a[m-1][n-1]=111;
	a[m+1][n-1]=111;
	a[m+1][n-2]=111;
	T0=11;
	}
	break;
case 11:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+1][n+2]==79||a[m+1][n+2]==48||a[m+1][n+1]==79||a[m+1][n+1]==48)
		break;
	else{
	a[m+2][n]=' ';
	a[m+2][n-1]=' ';
	a[m+1][n+2]=111;
	a[m+1][n+1]=111;
	T0=12;
	}
	break;
case 12:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m][n+1]==79||a[m][n+1]==48||a[m][n+2]==79||a[m][n+2]==48||a[m+2][n+1]==79||a[m+2][n+1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m+1][n+2]=' ';
	a[m+1][n]=' ';
	a[m][n+1]=111;
	a[m][n+2]=111;
	a[m+2][n+1]=111;
	T0=9;
	}
	break;
case 13:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m+2][n-1]==79||a[m+2][n-1]==48||a[m+2][n+2]==79||a[m+2][n+2]==48||a[m+2][n+1]==79||a[m+2][n+1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m+3][n]=' ';
	a[m+1][n]=' ';
	a[m+2][n-1]=111;
	a[m+2][n+2]=111;
	a[m+2][n+1]=111;
	T0=14;
	}
	break;
case 14:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m-1][n-2]==79||a[m-1][n-2]==48||a[m+1][n-2]==79||a[m+1][n-2]==48||a[m-2][n-2]==79||a[m-2][n-2]==48)
		break;
	else{
	a[m][n]=' ';
	a[m][n-1]=' ';
	a[m][n-3]=' ';
	a[m-1][n-2]=111;
	a[m+1][n-2]=111;
	a[m-2][n-2]=111;
	T0=13;
	}
	break;
case 15:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m][n+1]==79||a[m][n+1]==48||a[m][n+2]==79||a[m][n+2]==48)
		break;
	else{
	a[m][n]=' ';
	a[m+2][n+1]=' ';
	a[m][n+1]=111;
	a[m][n+2]=111;
	T0=16;
	}
	break;
case 16:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m][n-2]==79||a[m][n-2]==48||a[m+2][n-1]==79||a[m+2][n-1]==48)
		break;
	else{
	a[m][n]=' ';
	a[m][n-1]=' ';
	a[m][n-2]=111;
	a[m+2][n-1]=111;
	T0=15;
	}
	break;
case 17:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m][n-1]==79||a[m][n-1]==48||a[m][n-2]==79||a[m][n-2]==48)
		break;
	else{
	a[m][n]=' ';
	a[m+2][n-1]=' ';
	a[m][n-1]=111;
	a[m][n-2]=111;
	T0=18;
	}
	break;
case 18:for(i=26;i>0;i--)
		 {
			 for(j=10;j>0;j--)
				 if(a[i][j]==111)
				 {
					 m=i;n=j;
					 break;
				 }
	   }
	if(	a[m][n+1]==79||a[m][n+1]==48||a[m+2][n]==79||a[m+2][n]==48)
		break;
	else{
	a[m][n]=' ';
	a[m][n-1]=' ';
	a[m][n+1]=111;
	a[m+2][n]=111;
	T0=17;
	}
	break;
default :break;
    }
default :break;
}
}
int tzjiance()
{
int i,j,t=0;
for(i=5;i<27;i++)
for(j=1;j<11;j++)
if(a[i][j]==111)
if(a[i+1][j]==79||a[i+1][j]==48)
{
t=1;
}
return t;
}
int shengcheng()
{
srand((int)time(0));
return rand()%18;
}
void print1()
{
int t=111,i,j;
switch(T1)
{
case 0 : a[4][5]=t;a[4][6]=t;a[3][5]=t;a[3][6]=t;break;
case 1 : a[4][5]=t;a[4][6]=t;a[4][7]=t;a[3][6]=t;break;
case 2 : a[4][5]=t;a[2][5]=t;a[3][5]=t;a[3][6]=t;break;
case 3 : a[4][5]=t;a[3][4]=t;a[3][5]=t;a[3][6]=t;break;
case 4 : a[4][5]=t;a[2][5]=t;a[3][5]=t;a[3][4]=t;break;
case 5 : a[2][5]=t;a[2][6]=t;a[4][6]=t;a[3][6]=t;break;
case 6 : a[4][5]=t;a[4][6]=t;a[4][4]=t;a[3][6]=t;break;
case 7 : a[4][5]=t;a[4][6]=t;a[3][5]=t;a[2][5]=t;break;
case 8 : a[4][5]=t;a[3][7]=t;a[3][5]=t;a[3][6]=t;break;
case 9 : a[4][5]=t;a[2][6]=t;a[3][5]=t;a[2][5]=t;break;
case 10 : a[3][4]=t;a[4][6]=t;a[3][5]=t;a[3][6]=t;break;
case 11 : a[4][5]=t;a[4][6]=t;a[2][6]=t;a[3][6]=t;break;
case 12 : a[4][5]=t;a[4][6]=t;a[3][5]=t;a[4][7]=t;break;
case 13 : a[4][5]=t;a[3][5]=t;a[2][5]=t;a[1][5]=t;break;
case 14 : a[4][5]=t;a[4][6]=t;a[4][4]=t;a[4][7]=t;break;
case 15 : a[2][5]=t;a[4][6]=t;a[3][5]=t;a[3][6]=t;break;
case 16 : a[4][5]=t;a[4][6]=t;a[3][7]=t;a[3][6]=t;break;
case 17 : a[4][5]=t;a[2][6]=t;a[3][5]=t;a[3][6]=t;break;
case 18 : a[4][5]=t;a[4][6]=t;a[3][5]=t;a[3][4]=t;break;
default: break;
}
for(i=9;i<14;i++)
for(j=12;j<17;j++)
a[i][j]=' ';
switch(T2)
{
case 0 : a[11][14]=t;a[11][15]=t;a[12][14]=t;a[12][15]=t;break;
case 1 : a[11][14]=t;a[12][13]=t;a[12][14]=t;a[12][15]=t;break;
case 2 : a[10][14]=t;a[11][14]=t;a[11][15]=t;a[12][14]=t;break;
case 3 : a[11][13]=t;a[11][14]=t;a[11][15]=t;a[12][14]=t;break;
case 4 : a[11][14]=t;a[10][15]=t;a[11][15]=t;a[12][15]=t;break;
case 5 : a[10][14]=t;a[10][15]=t;a[11][15]=t;a[12][15]=t;break;
case 6 : a[11][15]=t;a[12][13]=t;a[12][14]=t;a[12][15]=t;break;
case 7 : a[10][14]=t;a[11][14]=t;a[12][14]=t;a[12][15]=t;break;
case 8 : a[11][13]=t;a[11][14]=t;a[11][15]=t;a[12][13]=t;break;
case 9 : a[10][15]=t;a[10][14]=t;a[11][14]=t;a[12][14]=t;break;
case 10 : a[11][13]=t;a[11][14]=t;a[11][15]=t;a[12][15]=t;break;
case 11 : a[12][14]=t;a[10][15]=t;a[11][15]=t;a[12][15]=t;break;
case 12 : a[11][13]=t;a[12][13]=t;a[12][14]=t;a[12][15]=t;break;
case 13 : a[10][14]=t;a[11][14]=t;a[12][14]=t;a[13][14]=t;break;
case 14 : a[12][13]=t;a[12][14]=t;a[12][15]=t;a[12][16]=t;break;
case 15 : a[10][14]=t;a[11][14]=t;a[11][15]=t;a[12][15]=t;break;
case 16 : a[11][13]=t;a[11][14]=t;a[10][14]=t;a[10][15]=t;break;
case 17 : a[10][15]=t;a[11][15]=t;a[11][14]=t;a[12][14]=t;break;
case 18 : a[10][13]=t;a[10][14]=t;a[11][14]=t;a[11][15]=t;break;
default: break;
}
}
void zhenghe()
{
int i,j;
for(i=0;i<28;i++)
for(j=0;j<19;j++)
if(a[i][j]==111)
a[i][j]=48;
}
int hight()
{
int i,j,h=0;
for(i=4;i<27;i++)
{
for(j=1;j<11;j++)
if(a[i][j]==48)
{
h=27-i;
break;
}
if(h!=0)
break;
}
return h;
}
