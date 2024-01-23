/////////////////////////////////////////////////////////////////////////////
/** NOTE
  w (width) = UNum-1
  h (height) = VNum-1
  p : UDegree = UOrder - 1
  q : VDegree = VOrder - 1
  P : array of control point SIZE = 3 or 4
 */
/////////////////////////////////////////////////////////////////////////////
 
#include <stdlib.h>
#include <stdio.h>
 
#define AY_OK          0 /* everything all right */
#define AY_EOMEM       5 /* out of memory */
 
int ay_nb_FindSpan(int n, int p, double u, double *U)
{
  int low, mid, high;
  if(u >= U[n]) return n;
 
  /* never return a span 0-p, because this would make BasisFuns() crash badly */
  if(u <= U[p])  return p;
 
  /* was:  if(u == U[n+1]) return(n);*/
  low = 0; /* was: low = p; */
  high = n+1;
  mid = (low+high)/2;
 
  while(u < U[mid] || u >= U[mid+1])
    {
      if(u < U[mid])  high = mid;
      else                  low = mid;
      mid = (low+high)/2;
    } /* while */
 
 return(mid);
} /* ay_nb_FindSpan */
 
 
void ay_nb_BasisFuns(int span, double u, int p, double *U, double *N) //p >= 1
{
 double *left = NULL, *right = NULL, saved, temp;
 int j, r;
 
  if(!(left = (double*)calloc(p+1, sizeof(double))))   return;
  if(!(right = (double*)calloc(p+1, sizeof(double))))  {free(left); return;}
 
  N[0] = 1.0;
 
//printf("  + ay_nb_BasisFuns(span = %d, u = %0.2f, p = %d)\n", span, u, p);
  for(j=1; j<=p; j++)
  {
      left[j] = u - U[span+1-j];
      right[j] = U[span+j] - u; 
      saved = 0.0f;
 
      for(r=0; r<j; r++)
      {
          temp = N[r] / (right[r+1] + left[j-r]);
          N[r] = saved + right[r+1] * temp;
          saved = left[j-r] * temp;
      }
   
      N[j] = saved;
  //  printf("  + ay_nb_BasisFuns(N[%d,%d] = %0.3f)\n", j, p, N[j]); 
  }
 
  free(left);
  free(right);
  return;
 
} /* ay_nb_BasisFuns */
 
//m: UKnotCount - 1; i,p: Nip
void ay_nb_OneBasisFun(int p, int m, double *U, int i, double u, double *Nip)
{ 
    /*  Compute  the  basis  function  Nip  *f/
    /*  Input:  p,m,U,i,u  */
    /*  Output:  Nip  */
   
    if  ((i  ==  0  &&  u  ==  U[0])  || (i  ==  m-p-1  &&  u  ==  U[m]))
    /*  Special  cases  */
    {  *Nip  =  1.0;  return; }
    if  (u  < U[i]  ||  u  >=  U[i+p+1])  /*  Local  property  */
    {  *Nip  =  0.0;  return; }
   
    double *N=NULL;
    N = (double*)calloc(p+1, sizeof(double));
   
    int j, k;
    double Uleft, Uright, saved, temp;
   
    for  (j=0;  j<=p;  j++)  /*  Initialize  zeroth-degree  functs  */
    if  (u  >=  U[i+j]  &&  u < U[i+j+1])  N[j]  =  1.0;
    else  N[j]  =  0.0;
   
    for  (k=1;  k<=p;  k++)  /*  Compute  triangular  table  */
    {
          if  (N[0]  ==  0.0)  saved  =  0.0;
          else  saved=  ((u-U[i])*N[0])/(U[i+k]-U[i]);
          for  (j=0;  j<p-k+1;  j++)
          {
                Uleft  = U[i+j+1];
                Uright  = U[i+j+k+1];
                if  (N[j+1]  ==  0.0) { N[j]  =  saved;  saved  =  0.0; }
                else
                {
                      temp  =  N[j+1]/(Uright-Uleft);
                      N[j]  =  saved+(Uright-u)*temp;
                      saved =  (u-Uleft)*temp;
                }
          }
    }
    *Nip=  N[0];
    delete []N;
}
 
int ay_nb_CurvePoint3D(int n, int p, double *U, double *P, double u, double *C)
{
  int span, j, k;
  double *N = NULL;
 
  if(!(N = (double*)calloc(p+1, sizeof(double)))) return AY_EOMEM;
  span = ay_nb_FindSpan(n, p, u, U);
  ay_nb_BasisFuns(span, u, p, U, N);
 
  C[0] = 0.0;
  C[1] = 0.0;
  C[2] = 0.0;
 
  double c0, c1, c2;  
  
  for(j = 0; j <= p; j++)
  {
      k = (span-p+j)*3;
      c0 = C[0]; c1 = C[1]; c2 = C[2]; //ntk
     
      C[0] = C[0] + N[j]*P[k];
      C[1] = C[1] + N[j]*P[k+1];
      C[2] = C[2] + N[j]*P[k+2];
     
      printf("  + C[0] = C[0] + N[%d]*P[%d] = %0.3f + %0.3f*%0.3f = %0.3f\n", j, k, c0, N[j], P[k], C[0]);
      printf("  + C[1] = C[1] + N[%d]*P[%d] = %0.3f + %0.3f*%0.3f = %0.3f\n", j, k+1, c1, N[j], P[k+1], C[1]);
      printf("  + C[2] = C[2] + N[%d]*P[%d] = %0.3f + %0.3f*%0.3f = %0.3f\n\n", j, k+2, c2, N[j], P[k+2], C[2]);
  }//for
  
  free(N);
  return AY_OK;
} /* ay_nb_CurvePoint3D */
 
void libAyamBasicFunction(int UNum, int UDegree, double u, double *UKnot)
// UNum = n + 1  Tong so dinh Pi
// UKnotCount = UNum - 1+ UDegree + 2
{
  int span, i, k;
  double *N = NULL;
 
  printf("* C(u = %.2f): UNum = %d, bac p = %d, UKnot = {", u, UNum, UDegree);
  for (i = 0; i < (UNum - 1+ UDegree + 2); i++) printf("u[%d]=%0.2f, ", i, UKnot[i]); printf("\b\b}\n");
 
  int flag = 1;
  double Nip;
     
  for(k = 0; k <= UDegree; k++)
  {
      if (N!=NULL) { delete []N; N = NULL; }
      N = (double*)calloc(UNum-1+UDegree-k, sizeof(double));
         
      span = ay_nb_FindSpan(UNum, k, u, UKnot);
      ay_nb_BasisFuns(span, u, k, UKnot, N);
     
      if (flag > 0) { printf("\n span = %d\n", span); flag = 0; };
      printf("* k = %d, i = 0,..,%d\n", k, (UNum-1 + UDegree-k));
      for(i = 0; i <= (UNum-1 + UDegree-k); i++)
      {
          ay_nb_OneBasisFun(k, UNum+UDegree, UKnot, i, u, &Nip);
        if (k == 0) printf(" N[%d,%d](%0.2f) = %.3f (Nip = %.3f)   [u[%d], u[%d])=[%0.2f, %0.2f) \n", i, k, u, N[i-span+k], Nip, i, i+1, UKnot[i], UKnot[i+1]); //i, k, u, N[i]);         
        else          printf(" N[%d,%d](%0.2f) = %.3f (Nip = %.3f)\n", i, k, u, N[i-span+k], Nip); //i, k, u, N[i]);       
      }
      printf("\n");
  }//for
  free(N);
}//libAyamBasicFunction
 
void libAyamCurvePoint3D(int UNum, int UDegree, double *UKnot, double *m_cv3, double u)
{
    double *C=NULL;        
    C = (double*)calloc(3, sizeof(double));
    int ay_status = ay_nb_CurvePoint3D(UNum-1, UDegree, UKnot, m_cv3, u, C);
    printf("* C(%.2f)(x, y, z) = (%.2f, %.2f, %.2f)\n", u, C[0], C[1], C[2]);
    delete []C;
}
 
int main(int argc, char* argv[])
{
	//printf("-----------------------------------------------------------------\n");
    printf("           PARAMETERIZATION METHOD ON B-SPLINE CURVE\n");
 	printf("-----------------------------------------------------------------\n");
    int i, p;
    int UNum;         // So dinh dieu khien cua B-spline Curve
    int UDegree;      // Bac cua B-spline Curve
    int UKnotCount;
 
    double *m_cv3 = NULL; // Dinh dieu khien 3D
    double *UKnot = NULL; // Vector nut co UKnotCount phan tu
    double u;
   
    UNum = 4; UDegree = 2;
    UKnotCount = UNum + UDegree + 1;
    UKnot = (double*)calloc(UKnotCount, sizeof(double));
    UKnot[0] = 0.0f; UKnot[1] = 0.0f; UKnot[2] = 0.0f; UKnot[3] = 0.5f; UKnot[4] = 1.0f; UKnot[5] = 1.0f; UKnot[6] = 1.0f;
         
    // Ma tran dinh dieu khien P 3D
    if (m_cv3 != NULL) { delete m_cv3; m_cv3 = NULL;}
    m_cv3 = (double*)calloc(UNum*3, sizeof(double));
    p = 0;     m_cv3[p+0]=  0.0f; m_cv3[p+1]= 10.0f; m_cv3[p+2]= 0.0f; //P0
    p = p + 3; m_cv3[p+0]= 10.0f; m_cv3[p+1]= 40.0f; m_cv3[p+2]= 0.0f; //P1
    p = p + 3; m_cv3[p+0]= 40.0f; m_cv3[p+1]= 40.0f; m_cv3[p+2]= 0.0f; //P2
    p = p + 3; m_cv3[p+0]= 50.0f; m_cv3[p+1]=  0.0f; m_cv3[p+2]= 0.0f;  //P3
 
////////////////////////////////////////////////////////////////////////////////////////////////
   
    printf(">> Tinh gia trinh ham Ni,k(u)) tai tham so u\n");    
    u = 0.45f;
    libAyamBasicFunction(UNum, UDegree, u, UKnot);
 
////////////////////////////////////////////////////////////////////////////////////////////////
   
    printf("\n>> Xac dinh toa do cua mot diem 3D (x, y, z) tren B-spline Curve tai tham so u\n\n");
    u = 0.45f;
    libAyamCurvePoint3D(UNum, UDegree, UKnot, m_cv3, u);        
 	printf("\n\n\n");
////////////////////////////////////////////////////////////////////////////////////////////////
   
    delete []UKnot;
    delete []m_cv3;  
    return 0;
}//main

