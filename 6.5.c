#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

int main()
{
    FILE *myFile;
    char email[CAPACITY];

    //-----------------------input_computations_results-----------------------
    printf("Please enter an email adress!\n");
    while(1)
    {
        scanf("%s", email);

        int length = strlen(email),
            eta = 0,
            eta_index = 0,
            dot_index = 0;

        for (int i = 0; i < length; ++i)
            if(email[i] == '@')
                ++eta;

        while(email[eta_index] != '@' && eta_index < length)
            ++eta_index;

        while(email[dot_index] != '.' && dot_index < length)
            ++dot_index;

        if(eta == 1 && eta_index != 0 && eta_index < dot_index && eta_index != length && eta_index + 1 != dot_index && dot_index != length - 1 && dot_index != length)
        {
            printf("The email has been entered correctly!\n\nThe email's domain is ");

            for(int i = eta_index + 1; i < length; ++i)
                printf("%c", email[i]);
            printf("!\n");
            myFile = fopen("emails.txt", "a");
            fprintf(myFile, "%s\n", email);
            fclose(myFile);
            break;
        }
        else
            printf("The email has been entered incorrectly!\n\nThe email has to be entered with: ");

        if(eta > 1)
            printf("\nonly one '@' symbol;");
        if(eta_index == length)
            printf("\nan '@' between email's username and server;");
        if(dot_index == length)
            printf("\na '.' between email's server and top-level domain;");
        if(dot_index < eta_index)
            printf("\nan '@' before a '.';");
        if(eta_index == 0)
            printf("\nat least one symbol before '@';");
        if(eta_index + 1 == dot_index)
            printf("\nat least one symbol between '@' and '.';");
        if(dot_index == length - 1)
            printf("\nat least one symbol after '.';");

        printf("\n\nPlease enter another email adress!\n");
    }
    return 0;
}
