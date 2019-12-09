#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void){

int n;
double v,kakudo,l,k,i;
printf("*********ƒLƒ€››››ƒiƒ€‚Ì–ì–]*********\n");
printf("–C’e‚ğ—‚Æ‚µAŒN‚Í“ú–{‚ğç‚ê‚é‚©IH\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("‚¿’e‚Í10”­‚Å‚·B\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
Sleep(4000);
system("cls");
printf("mmmm‘¾—zmmmmmmm‰_mmm‰_mmmmmm‰_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|“ú–{‚Ì‘å–C|__________________________|“G“G“G|____\n");

srand((unsigned)time(NULL));
i=rand() % 100 + 1;
printf("“G‚Ü‚Å‚Ì‹——£‚Í%lfm\n",i);


n=10;
while(1){
printf("‰‘¬“x‚Æ”­ËŠp“x‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
scanf("%lf%lf",&v,&kakudo);
k=kakudo*3.1415926535/180;
l=(v*cos(k)*2*v*sin(k))/9.8;
system("cls");
if(fabs(l-i)<1){
printf("mmmm‘¾—zmmmmmmm‰_mmm‰_mmmmmm‰_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("                   –½’†‚âII\n");
printf("                            ƒoƒR[ƒ“\n");
printf("                                ‰Œ‰Œ‰Œ\n");
printf("                                 ‰Œ‰Œ\n");
printf("__|“ú–{‚Ì‘å–C|_____________________‰Œ___\n");
break;
}

else if(l>i){
printf("mmmm‘¾—zmmmmmmm‰_mmm‰_mmmmmm‰_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|“ú–{‚Ì‘å–C|__________________________|“G“G“G|____\n");
printf("–Ú•W‚ğ%lfmƒI[ƒo[\n",l-i);
}

else{
printf("mmmm‘¾—zmmmmmmm‰_mmm‰_mmmmmm‰_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("__|“ú–{‚Ì‘å–C|__________________________|“G“G“G|____\n");
printf("–Ú•W‚É%lfm“Í‚©‚¸\n",i-l);
}
if(n<2){
system("cls");
Sleep(300);
printf("’eØ‚ê‚â!!“G‚ğ‚â‚Á‚Â‚¯‚ê‚¸AAA‘Šè‚ªƒŒ[ƒU[‚ğŒ‚‚Á‚Ä‚«‚½II\n");
printf("mmmm‘¾—zmmmmmmm‰_mmm‰_mmmmmm‰_mmmmmmmmmmmmmmmm\n");
printf("\n");
printf("\n");
printf("                               ‚â‚Á‚½‚¼‚í‚Í‚Í‚Í‚Í\n");
printf("\n");
printf("‰Œ‰Œ‰Œ                         ~|~\n");
printf(" ‰Œ‰Œ\n");
printf("__‰Œ__________________________|“G“G“G|____\n");


return 0;
}
n=n-1;
printf("c‚è’e”;%d\n",n);
}
return 0;
}
