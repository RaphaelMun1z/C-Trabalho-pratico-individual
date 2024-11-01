#include <stdio.h>
#include <string.h>

typedef struct
{
    int code;
    char name[50];
    int balance;
    char category;
    char email[50];
    char password[50];
} player;

typedef struct
{
    int code;
    player player;
    char date[11];
} match;

player players[14];
match matches[4];
int authenticated = 0, contPlayers = 0, contMatches = 0;

player *authUser(char email[50], char pass[50])
{
    for (int ii = 0; ii < 14; ii++)
    {
        if (strcmp(players[ii].email, email) == 0)
        {
            if (strcmp(players[ii].password, pass) == 0)
            {
                return &players[ii];
            }
        }
    }

    return NULL;
}

void login()
{
    char l_email[50], l_pass[50];
    printf("========================| LOGIN |========================\n");
    printf("Informe seu e-mail: ");
    scanf("%49s", &l_email);

    printf("Informe sua senha: ");
    scanf("%49s", &l_pass);

    if (authUser(l_email, l_pass) == NULL)
    {
        printf("-- Credenciais inválidas!\n\n");
    }
    else
    {
        player p = *authUser(l_email, l_pass);
        authenticated = 1;
        printf("\n☑ Bem vindo(a) de volta %s.\n\n", p.name);
    }
}

void registerPlayer()
{
    printf("========================| REGISTER |========================\n");
    printf("Informe seu nome: ");
    scanf("%49s", &players[contPlayers].name);

    printf("Informe seu e-mail: ");
    scanf("%49s", &players[contPlayers].email);

    char pass[50], confPass[50];
    do
    {
        printf("Informe sua senha: ");
        scanf("%49s", &pass);

        printf("Confirme sua senha: ");
        scanf("%49s", &confPass);

        if (strcmp(pass, confPass) == 0)
        {
            strcpy(players[contPlayers].password, pass);
        }
        else
        {
            printf("-- Senhas não são iguais!\n\n");
        }
    } while (strcmp(pass, confPass) != 0);

    players[contPlayers].code = contPlayers;
    players[contPlayers].balance = 0;
    players[contPlayers].category = 'A';
    printf("\n☑ Conta registrada com sucesso! Seja bem-vindo(a) %s.\n\n", players[contPlayers].name);
    contPlayers++;
}

void showHomeMenu()
{
    printf("===========================| MENU |===========================\n");
    if(authenticated == 1){
        printf("[1] Play\n");
        printf("[2] Check balance\n");  
    }else{
        printf("[3] Login\n");
        printf("[4] Register\n");
    }
    printf("[5] Exit\n");
    
    printf("______________________________________________________________\n");
}

void showGamesMenu()
{
    printf("========================| GAME MENU |=========================\n");
    printf("[1] Play Game 1\n");
    printf("[2] Play Game 2\n");
    printf("______________________________________________________________\n");
}

void showUserDetails(int code){
    for (int ii = 0; ii < 14; ii++)
    {
        if(players[ii].code == code){
            printf("\n========================| USER DETAILS |=========================\n");
            printf("Nome: %s\n", players[ii].name);
            printf("E-mail: %s\n", players[ii].email);
            printf("Saldo: %d\n", players[ii].balance);
            printf("Categoria: %c\n", players[ii].category);
            printf("______________________________________________________________\n");
        }
    }
    
}

int main()
{
    int opt;

    do
    {
        showHomeMenu();
        printf("Enter the option: ");
        scanf("%d", &opt);
        printf("\n");

        switch (opt)
        {
        case 1:
            showGamesMenu();
            printf("Enter the game: ");
            scanf("%d", &opt);
            printf("\n");
            break;

        case 2:
            showUserDetails();
            break;

        case 3:
            login();
            break;

        case 4:
            registerPlayer();
            break;

        case 5:
            printf("Exiting...");
            break;

        default:
            printf("Invalid option!\n");
            break;
        }

    } while (opt != 5);

    return 0;
}