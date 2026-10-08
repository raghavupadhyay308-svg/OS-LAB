//write a program to create input.txt in a parent processs and write your name university roll  class in it and then read same file in child process and print the contennt

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    FILE *fp;
    char ch;

    pid = fork();

    if (pid > 0)
    {
        fp = fopen("input.txt", "w");

        fprintf(fp, "Name: Raghav Upadhyay\n");
        fprintf(fp, "University Roll No: 89\n");
        fprintf(fp, "Class: B.Tech AIML\n");

        fclose(fp);

        wait(NULL);
    }
    else
    {
        fp = fopen("input.txt", "r");

        printf("Contents of input.txt:\n");

        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }

        fclose(fp);
    }

    return 0;
}