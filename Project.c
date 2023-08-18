#include<stdio.h>
#include<string.h>
void addStudent();
void displayListOfStudents();

int main()
{
int ch;
while(1)
{
    printf("1.Add Students\n");
    printf("2.Display List of Students\n");
    printf("3.Exit\n");
    printf("4.Enter your choice : ");
    scanf("%d",&ch);
    if(ch==1) addStudent();
    if(ch==2) displayListOfStudents();
    if(ch==3) break;
}
return 0;
}

void addStudent()
{
    char name[22], rollNumber[14];
    FILE *f;
    int x;
    printf("Enter name of students : ");
    fflush(stdin);
    fgets(name,22,stdin);
    fflush(stdin);
    name[strlen(name)-1]='\0';
    for(x=0; name[x]!='\0'; x++)
    {
        if(name[x]=='!')
        {
            printf("Name cannot contain '!' \n");
            return;
        }
    }
    printf("Enter roll number of student : ");
    fflush(stdin);
    fgets(rollNumber,14,stdin);
    fflush(stdin);
    rollNumber[strlen(rollNumber)-1]='\0';
    for(x=0; rollNumber[x]!='\0'; x++)
    {
        if(rollNumber[x]=='!')
        {
            printf("RollNumber cannot contain '!' \n");
            return;
        }
    }
    f=fopen("Student.txt","a");
    for(x=0; name[x]!='\0'; x++) fputc(name[x],f);
    fputc('!',f);
    for(x=0; rollNumber[x]!='\0'; x++) fputc(rollNumber[x],f);
    fputc('!',f);
    fclose(f);
    printf("Students Added Succesfully\n");
}

void displayListOfStudents()
{
    int sno;
    FILE *k;
    int x; 
    char g;
    char name[22], rollNumber[14];
    k=fopen("Student.txt","r");
    if(k==NULL)
    {
        printf("Student nor added yet\n");
        return;
    }
    sno=1;
    while(1)
    {
        g=fgetc(k);
        if(feof(k)) break;
        name[0]=g;
        x=1;
        while (1)
        {
            g=fgetc(k);
            if(g=='!') break;
            name [x]=g;
            x++;
        }
        name[x]='\0';
        x=0;
        while (1)
        {
            g=fgetc(k);
            if(g=='!') break;
            rollNumber [x]=g;
            x++;
        }
    rollNumber[x]='\0';
    printf("%d) Roll Number is %s\t\tName is %s\n",sno,rollNumber,name);
    sno++;
    }
    fclose(k);
}