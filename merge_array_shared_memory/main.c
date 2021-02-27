#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
#define MAX 100
main()
{
int m=MAX,n=MAX;
  int *a;
  int *b;
  int i,j;
  int shmid_m, shmid_n;

  shmid_m=shmget(IPC_PRIVATE,sizeof(int)*m,S_IRUSR|S_IWUSR);
  shmid_n=shmget(IPC_PRIVATE,sizeof(int)*n,S_IRUSR|S_IWUSR);
  a = (int *)shmat(shmid_m,NULL,0);
  b = (int *)shmat(shmid_n,NULL,0);


  printf("Enter size of the 1st array : ");
  scanf("%d", &m);
  printf("Enter elements in array : ");
  for(i=0; i<m; i++)
  {
     scanf("%d",&a[i]);
  }
  printf("Enter size of the 2nd array : ");
  scanf("%d",&n);

  printf("Enter elements in array : ");
  for(i=0; i<n; i++)
  {
      scanf("%d",&b[i]);
  }




  char strid1[100+1] = {'\0'};
  sprintf( strid1, "%d", shmid_m );
    char strid2[100+1] = {'\0'};
    sprintf( strid2, "%d", shmid_n );
  char str1[100+1] = {'\0'};
  sprintf( str1, "%d", m );
  char str2[100+1] = {'\0'};
  sprintf( str2, "%d", n );
  const char *argv[]={"./merge",strid1,strid2,str1,str2,(char *)NULL};
  execvp("./merge",argv);
  shmdt(a);
  shmdt(b);
  shmctl(shmid_m,IPC_RMID,NULL);
  shmctl(shmid_n,IPC_RMID,NULL);

int *r;
//shmdt((void *) r);

//int shmid = shmget(IPC_PRIVATE, sizeof(int)*(m+n), IPC_EXCL);

//r = shmat(shmid, 0, SHM_RDONLY);



  printf("The merged array is:\n ");
    for(i=0;i<m+n;i++)
    {
        printf("%d\t",r[i]);
    }

  return 0;
}
