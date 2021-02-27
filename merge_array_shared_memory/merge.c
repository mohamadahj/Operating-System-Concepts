#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>

main(int argc,char *argv[])
{

  int shmid_r, m,n;

m=atoi(argv[3]);
n=atoi(argv[4]);
int sum = m+n;
  int *a;
  int *b;
  int *r;
  shmid_r=shmget(IPC_PRIVATE,sizeof(int)*sum,S_IRUSR|S_IWUSR);
  r = (int *)shmat(shmid_r,NULL,0);

  a=(int *)shmat(atoi(argv[1]),NULL,0);
  b=(int *)shmat(atoi(argv[2]),NULL,0);
  int i,j;
  //for(i=0;i<m;i++)
  //{
  //    printf("%d\t",a[i]);
  //}
  //for(i=0;i<n;i++)
  //{
    //  printf("%d\t",b[i]);
  //}
  //  printf("\n");


int k = 0;
i=0;
j=0;


while (i<m && j <n)
{
    if (a[i] < b[j])
        r[k++] = a[i++];
    else
        r[k++] = b[j++];
}

// Remaining of a
while (i < m)
    r[k++] = a[i++];

// Remaining of b
while (j < n)
    r[k++] = b[j++];


        char strid3[100+1] = {'\0'};
        sprintf( strid3, "%d", shmid_r );


  printf("The merged array is:\n ");
  for(i=0;i<m+n;i++)
  {
      printf("%d\t",r[i]);
  }




  }
