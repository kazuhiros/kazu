#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void){

int n;
double v,kakudo,l,k,i;
printf("*********キム○○○○ナムの野望*********\n");
printf("砲弾を落とし、君は日本を守れるか！？\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("持ち弾は10発です。\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
Sleep(4000);
system("cls");
printf("mmmm太陽mmmmmmm雲mmm雲mmmmmm雲mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|日本の大砲|__________________________|敵敵敵|____\n");

srand((unsigned)time(NULL));
i=rand() % 100 + 1;
printf("敵までの距離は%lfm\n",i);


n=10;
while(1){
printf("初速度と発射角度を入力してください\n");
scanf("%lf%lf",&v,&kakudo);
k=kakudo*3.1415926535/180;
l=(v*cos(k)*2*v*sin(k))/9.8;
system("cls");
if(fabs(l-i)<1){
printf("mmmm太陽mmmmmmm雲mmm雲mmmmmm雲mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("                   命中や！！\n");
printf("                            バコーン\n");
printf("                                煙煙煙\n");
printf("                                 煙煙\n");
printf("__|日本の大砲|_____________________煙___\n");
break;
}

else if(l>i){
printf("mmmm太陽mmmmmmm雲mmm雲mmmmmm雲mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|日本の大砲|__________________________|敵敵敵|____\n");
printf("目標を%lfmオーバー\n",l-i);
}

else{
printf("mmmm太陽mmmmmmm雲mmm雲mmmmmm雲mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|日本の大砲|__________________________|敵敵敵|____\n");
printf("目標に%lfm届かず\n",i-l);
}
if(n<2){
system("cls");
Sleep(300);
printf("弾切れや!!敵をやっつけれず、、、相手がレーザーを撃ってきた！！\n");
printf("mmmm太陽mmmmmmm雲mmm雲mmmmmm雲mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("                               やったぞわはははは\n");
printf("\n");
printf("煙煙煙                         ~|~\n");
printf(" 煙煙\n");
printf("__煙__________________________|敵敵敵|____\n");


return 0;
}
n=n-1;
printf("残り弾数;%d\n",n);
}
return 0;
}
