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
  printf("���ْl�����̊J�n(MxN�s��) \n\n");

  msize=8;
  nsize=6;
  msize2 = msize;
  if(msize2 < nsize) msize2 = nsize;

/*�e�z��̃������[�̊m��*/
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

/*�e�ϐ��̏�����*/
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
  
 
  printf ("�W��������O�̓��ْl��������s��=\n");
  for (i=1;i<=msize2;i++){
    	for(j=1;j<=nsize;j++){
     		printf(" %9.6f ",mata[i][j]);
    	}
    printf("\n");
  }
  printf("\n");


//�f�[�^�̕W�����̌v�Z
  for (i=1;i<=nsize;i++){
    	for(j=1;j<=msize2;j++){
      		s[i] += mata[j][i];//�e�p�����[�^�ɂ�����T���v���̍��v�ls
       	}
  }

  printf("\n");
	for (i=1;i<=nsize;i++){
		sber[i]=s[i]/(float)msize2;//�e�p�����[�^�ɂ�����T���v���̕��ϒlsber
	}

	for (i=1;i<=nsize;i++){
    		for(j=1;j<=msize2;j++){
		//�e�p�����[�^�̑S�T���v���ɂ����镪�Uramuda
      			ramuda[i] +=((mata[j][i]-sber[i])*(mata[j][i]-sber[i]))/(float)msize2;
      		}
    		bunsan[i]=sqrt(ramuda[i]);//�W�������ꂽ�f�[�^�T���v��
  	}

  printf("\n");

  printf("���U��\n");
	for (i=1;i<=nsize;i++){
  		printf("%f\n",bunsan[i]);
	}
  printf("\n");

  printf("�e�p�����[�^�̕��ϒl���o�[\n");
  for (i=1;i<=nsize;i++){
	printf("%f\n",sber[i]);
  }

  for (i=1;i<=nsize;i++){
    	for(j=1;j<=msize2;j++){
 		mata[j][i]=(mata[j][i]-sber[i])/bunsan[i];
     	}
  }

  printf ("�W�����������ْl��������s��=\n");
  for (i=1;i<=msize2;i++){
    	for(j=1;j<=nsize;j++){
      		printf(" %9.6f ",mata[i][j]);
    	}
  	printf("\n");
  }
  printf("\n");



  printf ("���ْl�����J�n\n\n");
  svdcmp(mata,msize,nsize,matw,matv);
  printf ("���ْl�����I��\n\n");

  printf ("���ْl�����ɂ�蓾����U=:\n");
  for (i=1;i<=msize2;i++){
    	for(j=1;j<=nsize;j++){
      	printf(" %9.6f ",mata[i][j]);
  	}
  	printf("\n");
  }
  printf("\n");

  printf ("�v�Z�ɂ�� V=:\n");
  for (i=1;i<=nsize;i++){
    	for(j=1;j<=nsize;j++){
      		printf(" %9.6f ",matv[i][j]);
    	}
    	printf("\n");
  }
  printf("\n");

  printf ("�v�Z�ɂ�� W=:\n");
  for (i=1;i<=nsize;i++){
    	printf(" %9.6f \n",matw[i]);
  }
  printf("\n");

//���Z�������Ȃ�  
  printf("���Z���s����");
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
  printf("����͕�������O�̍s��ƈ�v���Ă���\n");


//��^���̌v�Z
  printf ("��^����:\n");
  for (i=1;i<=nsize;i++){
	kiyoritu[i]=(matw[i]*matw[i]/msize2);
    	printf(" %9.6f \n",kiyoritu[i]);
  }

//�ݐϊ�^���̌v�Z
  printf ("�ݐϊ�^����:\n");
  for (i=1;i<=nsize;i++){
	ruisekikiyoritu[i] =kiyoritu[i]+ruisekikiyoritu[i-1];
    	printf(" %9.6f \n",ruisekikiyoritu[i]);
  }

//���q���ח��̌v�Z
  printf ("���q���ח���:\n");
  for (i=1;i<=nsize;i++){
	for(j=1;j<=nsize;j++){		
			insihukaritu[i][j] =sqrt(kiyoritu[j])*matv[i][j];
		   	printf(" %9.6f ",insihukaritu[i][j]);
	}
	printf("\n");
  }

//�听�����_�̌v�Z
  printf ("�听�����_��:\n");
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
