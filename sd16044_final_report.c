#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void){

int n;
double v,kakudo,l,k,i;
printf("*********�L�����������i���̖�]*********\n");
printf("�C�e�𗎂Ƃ��A�N�͓��{�����邩�I�H\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("�����e��10���ł��B\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
Sleep(4000);
system("cls");
printf("mmmm���zmmmmmmm�_mmm�_mmmmmm�_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|���{�̑�C|__________________________|�G�G�G|____\n");

srand((unsigned)time(NULL));
i=rand() % 100 + 1;
printf("�G�܂ł̋�����%lfm\n",i);


n=10;
while(1){
printf("�����x�Ɣ��ˊp�x����͂��Ă�������\n");
scanf("%lf%lf",&v,&kakudo);
k=kakudo*3.1415926535/180;
l=(v*cos(k)*2*v*sin(k))/9.8;
system("cls");
if(fabs(l-i)<1){
printf("mmmm���zmmmmmmm�_mmm�_mmmmmm�_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("                   ������I�I\n");
printf("                            �o�R�[��\n");
printf("                                ������\n");
printf("                                 ����\n");
printf("__|���{�̑�C|_____________________��___\n");
break;
}

else if(l>i){
printf("mmmm���zmmmmmmm�_mmm�_mmmmmm�_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|���{�̑�C|__________________________|�G�G�G|____\n");
printf("�ڕW��%lfm�I�[�o�[\n",l-i);
}

else{
printf("mmmm���zmmmmmmm�_mmm�_mmmmmm�_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|���{�̑�C|__________________________|�G�G�G|____\n");
printf("�ڕW��%lfm�͂���\n",i-l);
}
if(n<2){
system("cls");
Sleep(300);
printf("�e�؂��!!�G��������ꂸ�A�A�A���肪���[�U�[�������Ă����I�I\n");
printf("mmmm���zmmmmmmm�_mmm�_mmmmmm�_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("                               ���������͂͂͂�\n");
printf("\n");
printf("������                         ~|~\n");
printf(" ����\n");
printf("__��__________________________|�G�G�G|____\n");


return 0;
}
n=n-1;
printf("�c��e��;%d\n",n);
}
return 0;
}
