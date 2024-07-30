#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define T 27
void IS(int *a,int l,int h){for(int i=l+1;i<=h;i++){int k=a[i],j=i-1;while(j>=l&&a[j]>k)a[j+1]=a[j--];a[j+1]=k;}}
int P(int *a,int l,int h){int p=a[h],i=l-1;for(int j=l;j<h;j++)if(a[j]<p){i++;int t=a[i];a[i]=a[j];a[j]=t;}int t=a[i+1];a[i+1]=a[h];a[h]=t;return i+1;}
void CH(int *a,int l,int h,int i){int L=i,le=2*i+1,ri=2*i+2;if(le<=h&&a[le]>a[L])L=le;if(ri<=h&&a[ri]>a[L])L=ri;if(L!=i){int t=a[i];a[i]=a[L];a[L]=t;CH(a,l,h,L);}}
void BCH(int *a,int l,int h){for(int i=(h-l+1)/2-1;i>=0;i--)CH(a,l,h,i);}
void HS(int *a,int l,int h){BCH(a,l,h);for(int i=h;i>=l;i--){int t=a[l];a[l]=a[i];a[i]=t;CH(a,l,i-1,0);}}
void ISORT(int *a,int l,int h,int d){if(h-l+1<=T)IS(a,l,h);else if(d==0)HS(a,l,h);else{int p=P(a,l,h);ISORT(a,l,p-1,d-1);ISORT(a,p+1,h,d-1);}}
void M(int *a,int l,int m,int r){int n1=m-l+1,n2=r-m,*L=malloc(n1*sizeof(int)),*R=malloc(n2*sizeof(int));for(int i=0;i<n1;i++)L[i]=a[l+i];for(int j=0;j<n2;j++)R[j]=a[m+1+j];int i=0,j=0,k=l;while(i<n1&&j<n2)a[k++]=L[i]<=R[j]?L[i++]:R[j++];while(i<n1)a[k++]=L[i++];while(j<n2)a[k++]=R[j++];free(L);free(R);}
void MS(int *a,int l,int r){if(l<r){int m=l+(r-l)/2;MS(a,l,m);MS(a,m+1,r);M(a,l,m,r);}}
void GRA(int *a,int s){for(int i=0;i<s;i++)a[i]=rand()%10000;}
void BSA(int s,double *r){double IA=0.0,MA=0.0;for(int c=0;c<5;c++){int *a1=malloc(s*sizeof(int)),*a2=malloc(s*sizeof(int));GRA(a1,s);memcpy(a2,a1,s*sizeof(int));clock_t st=clock();ISORT(a1,0,s-1,2*(int)log2(s));IA+=(double)(clock()-st)/CLOCKS_PER_SEC;st=clock();MS(a2,0,s-1);MA+=(double)(clock()-st)/CLOCKS_PER_SEC;free(a1);free(a2);}r[0]=IA/5;r[1]=MA/5;}
int main(){int ER=10;double r[2];for(int c=0;c<=ER;c++){int s=pow(10,c);printf("Testing array size: %d\n",s);BSA(s,r);printf("Introsort took %f seconds\n",r[0]);printf("Mergesort took %f seconds\n",r[1]);}return 0;}
