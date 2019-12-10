#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"
#include <math.h>

void svdcmp(float **a, int m, int n, float w[], float **v);

int main(void)
{
  
  int i,j,k,d,msize,msize2,nsize;

  float **mata, *matw, **matv,*s,*sber,*bunsan,*kiyoritu,*ramuda,*ruisekikiyoritu,**insihukaritu,**stokuten;
  float *tempv, *tempv2, **mata2, **mata3;
  FILE *fp;
  printf("特異値分解の開始(MxN行列) \n\n");

  msize=8;
  nsize=6;
  msize2 = msize;
  if(msize2 < nsize) msize2 = nsize;

/*各配列のメモリーの確保*/
  mata   = matrix(1,msize2,1,nsize);
  mata2  = matrix(1,msize2,1,nsize);
  mata3  = matrix(1,msize2,1,nsize);
  matw   = vector(1,nsize);
  tempv  = vector(1,msize);
  tempv2 = vector(1,msize);
  matv   = matrix(1,nsize,1,nsize);
  s      = vector(1,msize2);
  sber   = vector(1,msize2);
  bunsan = vector(1,msize2);
  kiyoritu = vector(1,msize2);
  ramuda = vector(1,msize2); 
  ruisekikiyoritu = vector(1,msize2); 
  insihukaritu =  matrix(1,nsize,1,nsize);
  stokuten   = matrix(1,msize2,1,nsize);

/*各変数の初期化*/
  for(i=0;i<=msize2;i++){
  s[i]=0.0;
  sber[i]=0.0;
  bunsan[i]=0.0;
  kiyoritu[i]=0.0;
  ramuda[i]=0.0;
  ruisekikiyoritu[i]=0.0;
  }

  for(i=1;i<=nsize;i++){
	for(j=1;j<=nsize;j++){
		insihukaritu[i][j]=0.0;
	}
	for(j=1;j<=msize2;j++){
		stokuten[i][j]=0.0;
	}
  } 




  mata[1][1] =  -8.55;
  mata[1][2] =   21040;
  mata[1][3] =   6289000;
  mata[1][4] =   3.24;
  mata[1][5] =   7806;
  mata[1][6] =   5867;

  mata[2][1] =   -14.98;
  mata[2][2] =   117.5;
  mata[2][3] =   100171;
  mata[2][4] =   1.94;
  mata[2][5] =   3745;
  mata[2][6] =   2270;

  mata[3][1] =   -18.98;
  mata[3][2] =   1334;
  mata[3][3] =   127200;
  mata[3][4] =   3.26;
  mata[3][5] =   4694;
  mata[3][6] =   3845;

  mata[4][1] =  -13.16;
  mata[4][2] =   44.97;
  mata[4][3] =   215193;
  mata[4][4] =   1.61;
  mata[4][5] =   3330;
  mata[4][6] =   2184;

  mata[5][1] =  -30.92;
  mata[5][2] =   4317;
  mata[5][3] =   2133000;
  mata[5][4] =   1.66;
  mata[5][5] =   49980;
  mata[5][6] =   34000;

  mata[6][1] =  -9.73;
  mata[6][2] =   1361;
  mata[6][3] =   962036;
  mata[6][4] =   1.66;
  mata[6][5] =   4783;
  mata[6][6] =   3716;

  mata[7][1] =   -29.01;
  mata[7][2] =   840.4;
  mata[7][3] =   176309;
  mata[7][4] =   1.34;
  mata[7][5] =   8470;
  mata[7][6] =   6570;

  mata[8][1] =  -31.59;
  mata[8][2] =   761.9;
  mata[8][3] =   367304;
  mata[8][4] =   1.04;
  mata[8][5] =   6030;
  mata[8][6] =   4125;
  
 
  printf ("標準化する前の特異値分解する行列=\n");
  for (i=1;i<=msize2;i++){
    	for(j=1;j<=nsize;j++){
     		printf(" %9.6f ",mata[i][j]);
    	}
    printf("\n");
  }
  printf("\n");


//データの標準化の計算
  for (i=1;i<=nsize;i++){
    	for(j=1;j<=msize2;j++){
      		s[i] += mata[j][i];//各パラメータにおけるサンプルの合計値s
       	}
  }

  printf("\n");
	for (i=1;i<=nsize;i++){
		sber[i]=s[i]/(float)msize2;//各パラメータにおけるサンプルの平均値sber
	}

	for (i=1;i<=nsize;i++){
    		for(j=1;j<=msize2;j++){
		//各パラメータの全サンプルにおける分散ramuda
      			ramuda[i] +=((mata[j][i]-sber[i])*(mata[j][i]-sber[i]))/(float)msize2;
      		}
    		bunsan[i]=sqrt(ramuda[i]);//標準化されたデータサンプル
  	}

  printf("\n");

  printf("分散σ\n");
	for (i=1;i<=nsize;i++){
  		printf("%f\n",bunsan[i]);
	}
  printf("\n");

  printf("各パラメータの平均値ｘバー\n");
  for (i=1;i<=nsize;i++){
	printf("%f\n",sber[i]);
  }

  for (i=1;i<=nsize;i++){
    	for(j=1;j<=msize2;j++){
 		mata[j][i]=(mata[j][i]-sber[i])/bunsan[i];
     	}
  }

  printf ("標準化した特異値分解する行列=\n");
  for (i=1;i<=msize2;i++){
    	for(j=1;j<=nsize;j++){
      		printf(" %9.6f ",mata[i][j]);
    	}
  	printf("\n");
  }
  printf("\n");



  printf ("特異値分解開始\n\n");
  svdcmp(mata,msize,nsize,matw,matv);
  printf ("特異値分解終了\n\n");

  printf ("特異値分解により得られるU=:\n");
  for (i=1;i<=msize2;i++){
    	for(j=1;j<=nsize;j++){
      	printf(" %9.6f ",mata[i][j]);
  	}
  	printf("\n");
  }
  printf("\n");

  printf ("計算により V=:\n");
  for (i=1;i<=nsize;i++){
    	for(j=1;j<=nsize;j++){
      		printf(" %9.6f ",matv[i][j]);
    	}
    	printf("\n");
  }
  printf("\n");

  printf ("計算により W=:\n");
  for (i=1;i<=nsize;i++){
    	printf(" %9.6f \n",matw[i]);
  }
  printf("\n");

//検算をおこなう  
  printf("検算を行うと");
  for (i=1;i<=msize;i++){
    	for(j=1;j<=nsize;j++){
      	mata2[i][j] = matw[j]*mata[i][j];
    	}
  }

  printf ("UW= \n");
  for (i=1;i<=msize;i++){
    	for(j=1;j<=nsize;j++){
      		printf(" %9.6f ",mata2[i][j]);
    	}
    	printf("\n");
  }
  printf("\n");

  for (i=1;i<=msize;i++){
    	for(j=1;j<=nsize;j++){
      		mata3[i][j]=0.0;
      		for(k=1;k<=nsize;k++){
			mata3[i][j] += mata2[i][k]*matv[j][k];
    		}
  	}
  }
  printf ("UWV^T= \n");
  for (i=1;i<=msize;i++){
    	for(j=1;j<=nsize;j++){
      		printf(" %9.6f ",mata3[i][j]);
    	}
    	printf("\n");
  }
  printf("\n");
  printf("これは分解する前の行列と一致している\n");


//寄与率の計算
  printf ("寄与率は:\n");
  for (i=1;i<=nsize;i++){
	kiyoritu[i]=(matw[i]*matw[i]/msize2);
    	printf(" %9.6f \n",kiyoritu[i]);
  }

//累積寄与率の計算
  printf ("累積寄与率は:\n");
  for (i=1;i<=nsize;i++){
	ruisekikiyoritu[i] =kiyoritu[i]+ruisekikiyoritu[i-1];
    	printf(" %9.6f \n",ruisekikiyoritu[i]);
  }

//因子負荷率の計算
  printf ("因子負荷率は:\n");
  for (i=1;i<=nsize;i++){
	for(j=1;j<=nsize;j++){		
			insihukaritu[i][j] =sqrt(kiyoritu[j])*matv[i][j];
		   	printf(" %9.6f ",insihukaritu[i][j]);
	}
	printf("\n");
  }

//主成分得点の計算
  printf ("主成分得点は:\n");
  for (i=1;i<=nsize;i++){
	for(j=1;j<=msize2;j++){		
			stokuten[j][i] =mata[j][i]*matw[i];
	}
}

 for (i=1;i<=msize2;i++){
	for(j=1;j<=nsize;j++){		   
	 	printf(" %9.6f ",stokuten[i][j]);
	}
	printf("\n");
  }

}
