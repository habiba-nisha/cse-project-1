// result system

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void search_student();
void student_record();
void add_student();
void delete_student();
float grade_point(float x);
void clear();

struct student
{
    char name[60];
    char id[10];
    float cse, cse_lab, eee_lab, eee, math, urel, physics, urem, grade;
};

int main()
{
    clear();

    int option;

    while (option != 5)
    {
        printf("\n\tRESULTS OF STUDENTS OF CSE\n\n");

        printf("\t\t1. Add student's data\n");
        printf("\t\t2. Watch student's record\n");
        printf("\t\t3. Search a student's result\n");
        printf("\t\t4. Delete a student's result\n");
        printf("\t\t5. Exit\n\n");

        printf("\t\tEnter option : ");
        scanf("%d", &option);

        clear();
        switch (option)
        {
        case 1:
            add_student();
            break;
        case 2:
            student_record();
            printf("\t\tPress any key to continue . . . ");
            getch();
            clear();
            break;
        case 3:
            search_student();
            printf("\t\tPress any key to continue . . . ");
            getch();
            clear();
            break;
        case 4:
            delete_student();
            printf("\t\tPress any key to continue . . . ");
            getch();
            clear();
            break;
        case 5:
            printf("\n\tThank You For Using Our App. Have a Nice Day!\n");
            exit(0);
        default:
            getch();
            printf("\t\tInvalid input\n");
            printf("\t\tPress any key to continue . . . ");
            getch();
            clear();
            break;
        }
    }
}

void add_student()
{
    char again;
    FILE *pr;
    struct student data;

    do
    {
        printf("\n\tADD STUDENT'S DATA\n\n");

        pr = fopen("student_data.dat", "a");

        printf("\t\tEnter ID\t: ");
        scanf("%s", data.id);
        printf("\t\tEnter Name\t: ");
        fflush(stdin);
        gets(data.name);
        printf("\n\t\tEnter Marks\n");
        printf("\t\t\tCSE\t: ");
        scanf("%f", &data.cse);
        printf("\t\t\tEEE\t: ");
        scanf("%f", &data.eee);
        printf("\t\t\tPHYSICS\t: ");
        scanf("%f", &data.physics);
        printf("\t\t\tENGLISH\t: ");
        scanf("%f", &data.urel);
        printf("\t\t\tMATH\t: ");
        scanf("%f", &data.math);
        printf("\t\t\tUREM\t: ");
        scanf("%f", &data.urem);
        printf("\t\t\tCSE LAB\t: ");
        scanf("%f", &data.cse_lab);
        printf("\t\t\tEEE LAB\t: ");
        scanf("%f", &data.eee_lab);

        data.grade = (((grade_point(data.cse)) * 3) + ((grade_point(data.cse_lab)) * 1.5) + ((grade_point(data.eee)) * 3) + ((grade_point(data.eee_lab)) * 1.5) + ((grade_point(data.math)) * 3) + ((grade_point(data.physics)) * 3) + ((grade_point(data.urel)) * 2) + ((grade_point(data.urem)) * 1)) / 18;

        printf("\n\t\tTotal Grade : %0.2f", data.grade);
        printf("\n\t\t_______________________________________\n\n");

        if (pr == NULL)
            printf("\n\t\tCan't open file\n");
        else
            printf("\t\tRecord stored successfully\n");

        fwrite(&data, sizeof(struct student), 1, pr);
        fclose(pr);

        printf("\t\tAdd another data? [y/n] : ");
        scanf(" %c", &again);

        clear();
    } while (again == 'Y' || again == 'y');
}

void student_record()
{
    FILE *pr;
    struct student data;
    pr = fopen("student_data.dat", "r");

    printf("\n\tCHECK ALL STUDENT'S DATA\n\n");

    if (pr == NULL)
    {
        printf("\n\t\tCan't open file\n");
        return;
    }
    printf("\t\t_______________________________________\n\n");

    while (fread(&data, sizeof(struct student), 1, pr))
    {
        printf("\t\tStudent id\t: %s\n", data.id);
        printf("\t\tStudent name\t: %s\n", data.name);

        printf("\n\t\tMarks\t:\n");
        printf("\t\t\tCSE\t: %0.2f\n", data.cse);
        printf("\t\t\tEEE\t: %0.2f\n", data.cse_lab);
        printf("\t\t\tCSE LAB\t: %0.2f\n", data.eee);
        printf("\t\t\tEEE LAB\t: %0.2f\n", data.eee_lab);
        printf("\t\t\tENGLISH\t: %0.2f\n", data.urel);
        printf("\t\t\tPHYSICS\t: %0.2f\n", data.physics);
        printf("\t\t\tMATH\t: %0.2f\n", data.math);
        printf("\t\t\tUREM\t: %0.2f\n", data.urem);
        printf("\n\t\tTotal Grade\t: %0.2f\n", data.grade);
        printf("\t\t_______________________________________\n\n");
    }

    fclose(pr);
}

void search_student()
{
    FILE *pr;
    struct student data;
    int find = 0;
    char id[10];

    pr = fopen("student_data.dat", "r");

    printf("\n\tSEARCH STUDENT\n\n");
    printf("\t\tEnter id no : ");
    scanf(" %s", &id);

    while (fread(&data, sizeof(struct student), 1, pr))
    {
        if (strcmp(data.id, id) == 0)
        {
            find = 1;
            printf("\t\t_______________________________________\n\n");
            printf("\t\tStudent id\t: %s\n", data.id);
            printf("\t\tStudent name\t: %s\n", data.name);

            printf("\n\t\tMarks\t:\n");
            printf("\t\t\tCSE\t: %0.2f\n", data.cse);
            printf("\t\t\tEEE\t: %0.2f\n", data.cse_lab);
            printf("\t\t\tCSE LAB\t: %0.2f\n", data.eee);
            printf("\t\t\tEEE LAB\t: %0.2f\n", data.eee_lab);
            printf("\t\t\tENGLISH\t: %0.2f\n", data.urel);
            printf("\t\t\tPHYSICS\t: %0.2f\n", data.physics);
            printf("\t\t\tMATH\t: %0.2f\n", data.math);
            printf("\t\t\tUREM\t: %0.2f\n", data.urem);
            printf("\n\t\tTotal Grade\t: %0.2f\n", data.grade);
            printf("\t\t_______________________________________\n\n");
        }
    }
    if (!find)
        printf("\n\t\tRecord not found\n");

    fclose(pr);
}

void delete_student()
{
    FILE *pr, *pr1;
    struct student data;
    int find = 0;
    char id[10];

    printf("\n\tDELETE A STUDENT\n\n");

    pr = fopen("student_data.dat", "r");
    pr1 = fopen("data_2.dat", "w");

    printf("\t\tEnter ID : ");
    scanf("%s", &id);

    if (pr == NULL)
        printf("\n\t\tCan't open file\n");

    while (fread(&data, sizeof(struct student), 1, pr))
    {
        if (strcmp(data.id, id) == 0)
            find = 1;
        else
            fwrite(&data, sizeof(struct student), 1, pr1);
    }

    fclose(pr);
    fclose(pr1);

    if (find)
    {
        remove("student_data.dat");
        rename("data_2.dat", "student_data.dat");
        printf("\n\t\tDeleted successfully\n");
    }
    else
        printf("\n\t\tRecord not found\n");
}

float grade_point(float x)
{
    if (x >= 80 && x <= 100)
        return 4.00;
    else if (x >= 75)
        return 3.75;
    else if (x >= 70)
        return 3.50;
    else if (x >= 65)
        return 3.25;
    else if (x >= 60)
        return 3.00;
    else if (x >= 55)
        return 2.75;
    else if (x >= 50)
        return 2.50;
    else if (x >= 45)
        return 2.25;
    else if (x >= 40)
        return 2.00;
    else
        return 0;
}

void clear()
{
    // printf("\e[1;1H\e[2J"); // Mac OS (partially supported)
    system("cls"); // windows
    // system("clear"); // linux
}
