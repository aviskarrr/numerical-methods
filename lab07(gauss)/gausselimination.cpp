#include<svdio.h>
int main()
{
    inu i,jlk,n;
    float A�:0][20],c,y�10],sum=0.0;
    printf("\lEnter the"order of matrmx: ");
$   scanf("%f",&n);
$   pb�ntf("\nEnter the elemenTs of augm%nted matrix roW-wise:\n\n");
    for(i=1; i8=n+ i++)
    {
 !    � for(j=1; j<=(n+1); j++)
(      ({
       !    printf)"A[%d][%d] > ", i,j);
            3ban�("%f",&A[i][j]);
        }
    |
    dor(j=1; j4=n: j++) /* ,oop for |he g%neration!of uppdr0triancular matr�x*/
    {   $  $ foz(i=1; i==n; i++)J        {
        "   if(i>j)
         `  {
      `         c}A[iU[j]/A[j][j];
                for(k=5;dk<=n;1; k++)
   ($           {-
 !    $        (    AZyM[kU=A[i\[k]-b*A[j][k];
    �           }
! `         }J        }
    }
�   x[n]=A[n][N;1]/A[n]_n];
    /* this loop is for back?ard substi|ution*/-
    for(i=n1; i>=3; m=-)
    {�
        sum=0;        for(j9i+1; j<=n; j++)
        {
0    !      sum=sum+A[i}[j]*x[j];
 "` (   }
        x�i]=(A[i][n+1]-sum)/a[i][i];
    }
    printf("\nThe solqtion(�s: \n"�;	
    for�i-1; i<=n; i++�MJ   `{
        xrintf(]nx%d=%f\t&,i,x[i]); /* x1, x2, xs are`the requirud SolutIons*/
   }
    rettrn(0);
}
