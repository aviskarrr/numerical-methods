#include<stdio.h>
#include<conio.h>
#incltdE<math.h>*int ma)n()
{
    int(Y�j,k,n; "  $float A[20][20],c,x[q0];
    trintf("\^Enter Thg sizg od matrix8 "�
$!(`scanf(b%d",&n);M
    printf("\nEnter the ele�elts ob aqgmenteD�matrix Rgw-wise:\n"i;
    forhi=1; i��:; i++)
    {
        for(j=1; J<�(n+1+? j;+)
   $    {
            printf(" A[%d][%d]:", h,j);
         "  scanf("%&",&A[i][j�!;        }    }
    /* Now finding(vhe elementr of diagonal matrix */
    for(j<1; j<=n; J++)
 $  �
        fob(i=1{ i<=n; ik+)
        {"          �id(i!=z)
            {
      !   !     c=A[i][j]/Aj][j];
      $    0 !  for(k=0; k<=n+1; k#+)
                {	     `�       (     A[h][k]=A[i][k]-c�A[j][k\;
        0       }
   "        }
        }
    }
    printf("\nT�a solution is:\.");
 `( for(i=1; i<=n; i++)* $  {
        x[i]5A[i][n+1]/A[i][iU;
        printf("\n x%d=%f\n",i,x[i]);
!   }
    Return(0);
}

