#include <flight_reservation.h>

void ta_det()
{
    FILE *fp;
    struct book b;
    printf("Enter ticket code :  ");
    scanf("%s", b.code);
    printf("Enter  passenger name :  ");
    scanf("%s", b.name);
    printf("Enter  Date:  ");
    scanf("%s", b.date);
    printf("Enter Ticket Price:  ");
    scanf("%d", &b.cost);
    fp = fopen("data.txt", "a");

    if (fp == NULL)
    {
        printf("FIle not Found");
    }
    else
    {
        fprintf(fp, "%s %s %s %d\n", b.code, b.name, b.date, b.cost);
        printf("Congratulations,Booking successfull");
    }
    printf("\n");
    fclose(fp);
}

void search()
{
    struct book b;
    FILE *fp;

    char ch[5];
    printf("Enter ticket code :");
    scanf("%s", ch);

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    {
        while (getc(fp) != EOF)
        {
            fscanf(fp, "%s %s %s %d", b.code, b.name, b.date, &b.cost);
            if (strcmp(b.code, ch) == 0)
            {
                printf("%s  %s  %s %d\n", b.code, b.name, b.date, b.cost);
                printf("\n Record Found\n");
                printf("\n\t\tTicket Code : %s", b.code);
                printf("\n\t\tPassenger name : %s", b.name);
                printf("\n\t\tDate : %s", b.date);
                printf("\n\t\tPrice : %d", b.cost);
                break;
            }
        }
    }

    fclose(fp);
}

void viewall()
{
    char ch;
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Not found !");
        exit(1);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }
    fclose(fp);
}

// void book_tic()
// {
//     struct book b;
//     FILE *fp;
//     FILE *ufp;
//     int total_seat, phone;
//     char name[20];
//     char ch;
//     char ticket_code[20];
//     fp = fopen("data.txt", "r");
//     if (fp == NULL)
//     {
//         printf("Not found !");
//         exit(1);
//     }
//     else
//     {
//         while ((ch = fgetc(fp)) != EOF)
//             printf("%c", ch);
//     }
//     fclose(fp);
//     printf("\n Enter ticket code :");
//     scanf("%s", ticket_code);
//     fp = fopen("data.txt", "r");
//     if (fp == NULL)
//     {
//         printf("File not found !");
//         exit(1);
//     }
//     else
//     {
//         while (getc(fp) != EOF)
//         {
//             fscanf(fp, "%s %s %s ", b.code, b.name, b.date);
//             if (strcmp(b.code, ticket_code) == 0)
//             {
//                 printf("\n Record Found\n");
//                 printf("\n\t\tCode :%s", b.code);
//                 printf("\n\t\tPassenger name :%s", b.name);
//             }
//         }
//     }
//     printf("\n===========================");
//     printf("\n");
//     printf("\t Passenger Details ");
//     printf("\n");
//     printf("\n===========================");
//     printf("\n Passenger name :");
//     scanf("%s", name);
//     printf("\n Phone number :");
//     scanf("%d", &phone);
//     printf("\n Total seat :");
//     scanf("%d", &total_seat);
//     printf("\n===========================");
//     printf("\n");
//     printf("\t Happy Journey ");
//     printf("\n");
//     printf("\n===========================");
//     printf("\n\t\tname : %s", name);
//     printf("\n\t\tphone Number : %d", phone);
//     printf("\n\t\tTotal seats : %d", total_seat);
//     ufp = fopen("record.txt", "a");
//     if (ufp == NULL)
//     {
//         printf("FIle not Found");
//     }
//     else
//     {
//         fprintf(ufp, "%d %d %s \n", phone, total_seat, b.name);
//         printf("\n Re-enter in record");
//     }
//     printf("\n");
//     fclose(ufp);
//     fclose(fp);
// }

void old_rec()
{
    char ch;
    FILE *fp;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("Not found !");
        exit(1);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }
    fclose(fp);
}
