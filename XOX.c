#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<ctype.h>

void table();
void bot();
int is_winning();
void rebooting();
int beraber();

int game[3][3];

int main()
{
    srand(time(NULL));
    int row,collumn;
    char continous = 'Y';
    printf("(: Welcome to my XOX game :)\nPress ENTER to continue  \n");
    getchar();
    while (continous == 'Y')
    {
        table();
        printf("row: ");
        scanf("%d",&row);
        printf("Collumn: ");
        getchar();
        scanf("%d",&collumn);
        row--;
        collumn--;
        if (game[row][collumn] == 1 || game[row][collumn] == 2 || row > 2 || row < 0 || collumn < 0 || collumn > 2)
            printf("\nYou cant play here!!\nTry again\n\n");
        else
        {
            game[row][collumn] = 1;
            if (is_winning(1) == 3)
            {
                table();
                do
                {
                    printf("Draw!\nWant to try again?(Y/N): ");
                    getchar();
                    scanf("%c",&continous);
                } while (toupper(continous) != 'Y' && toupper(continous) != 'N');
                if (toupper(continous) == 'N')
                    return 0;
                else
                    rebooting();        
            }
            
            else if (is_winning(1) == 1)
            {
                table();
                do
                {
                    printf("Congratulations you won!!\nWant to try again?(Y/N): ");
                    getchar();
                    scanf("%c",&continous);
                } while (toupper(continous) != 'Y' && toupper(continous) != 'N');
                if (toupper(continous) == 'N')
                    return 0;
                else
                    rebooting();        
            }
            else
            {
                bot();
                if(is_winning(2) == 1)
                {
                    table();
                    do
                    {
                        printf("The bot won\nWant to try again?(Y/N): ");
                        getchar();
                        scanf("%c",&continous);
                    } while (toupper(continous) != 'Y' && toupper(continous) != 'N');
                    if (toupper(continous) == 'N')
                        return 0;
                    else
                        rebooting();
                }
            }
        }
        continous = toupper(continous);
    }
}

void table()
{
    for (int i = 0; i < 3; i++)
    {
        printf(" ");
        for (int j = 0; j < 3; j++)
        {
            if (game[i][j] == 1)
                printf("X");
            else if (game[i][j] == 2)
                printf("O");
            else
                printf(" ");
            if (j != 2)
                printf("|");
        }
        if(i != 2)
            printf("\n--------\n");
    }
    printf("\n");
    return;
}

void bot()
{
    int row,collumn;
    do
    {
        row = rand()%3;
        collumn = rand()%3;
    } while (game[row][collumn] != 0);
    game[row][collumn] = 2;
    return;
}

int is_winning(int player)
{
    for (int i = 0; i < 3; i++)     //satir
        if (game[i][0] == player && game[i][1] == player && game[i][2] == player)
            return 1;
    for (int i = 0; i < 3; i++)
        if (game[0][i] == player && game[1][i] == player && game[2][i] == player)
            return 1;
    if ((game[0][0] == player && game[1][1] == player && game[2][2] == player)||(game[2][0] == player && game[1][1] == player && game[0][2] == player))
        return 1;
    if (beraber() == -1)
        return 3;
    return 0;
}

int beraber()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (game[i][j] == 0)
                return 1;
    return -1;
}
void rebooting()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            game[i][j] = 0;
    system("cls");
}