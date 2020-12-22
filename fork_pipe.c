#include <sys/types.h>
#include <stdio.h> 
#include <unistd.h>
#include<string.h> 
#include<sys/wait.h> 
int main()
{

pid_t pid;
int fd1[2]; 
int returnstatus;
int fd2[2]; 
int returnstatus2;
returnstatus = pipe(fd1);
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
 }
 returnstatus2 = pipe(fd2);
   if (returnstatus2 == -1) {
      printf("Unable to create pipe\n");
      return 1;
 }
pid = fork();   
char sentence[] = "GDB lets you peek inside a program while the program is executing, something that helps you identify where exactly the problems are.";
char sentence2[] = "The Reversed Sentence is: ";

if (pid<0){
fprintf(stderr, "Fork Failed!");
}

else if (pid == 0){
//printf("Child");

char str[1000];
int l = sizeof(str);
char reversed[l];

read(fd1[0], str, 1000);
//printf("%s\n", reversed);
int len = strlen(str); 
//printf("%d\n", len);
int i;
/*char str2 [] = " ";
int ll = strlen(str2);
printf("%d\n", ll);
for (i=0; i<len;i++){
//str2[0] = ' ';
	str2 [ll++] = str[i];
}
str2[ll] = '\0'; 
*/ 
 int index = 0;
 int start;
 int end = len - 1;
  for(start = len - 1; start>0; start--)

    {
        if(str[start] == ' ')
        {
            for(i= start+1; i<= end; i++)
            {
              reversed[index] = str[i];
              index++;
            }

            reversed[index++] = ' ';

            end = start - 1;
        }

    }

//printf("%d\n", end);
 for(i=0; i<=end; i++)
    {
        reversed[index] = str[i];
        index++;
    }

int k = strlen(sentence2); 
for (i=0; i<index; i++) 
	{   
		sentence2[k++] = reversed[i];
	}	
sentence2[k] = '\0'; 


     close(fd1[0]);   
	 write(fd2[1], sentence2, strlen(sentence2)+1); 
     close(fd2[1]); 
  
}

else{
//printf("Parent");
char read_reversed[1000];
write(fd1[1], sentence, strlen(sentence)+1);
close(fd1[1]); 
wait(NULL);
 read(fd2[0], read_reversed, 1000); 
        printf("%s\n", read_reversed); 
        close(fd2[0]); 

 }
 return 0;
}

