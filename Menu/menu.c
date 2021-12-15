#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int senhaFunc()
{
    int opcao, senha, acesso = 0;

    printf("\nDigite a senha:\n");
    scanf("%d", &senha);

    if (senha == 9999)
    {
        printf("\nAcesso permitido!\n");
        acesso = 1;
        return acesso;
    }
    else
    {
        do
        {
            printf("\nSenha incorreta\n1- Tentar novamente\n0- Encerrar sistema\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 0:
                return acesso;
            case 1:
                if (acesso == 1)
                {
                    return acesso;
                }
                senhaFunc();
                return acesso;
            default:
                printf("Invalido\n");
                break;
            }
        } while (true);
    }
}

void login()
{
    int codigo_usuario;
    int verificar = 1234;

    while (true)
    {
        printf("Digite o usuario:\n");
        scanf("%d", &codigo_usuario);
        if (codigo_usuario != verificar)
        {
            printf("\nUsuario invalido!\n");
            break;
        }
        else
        {
            int acesso = senhaFunc();
            break;
        }
    }
}

int main()
{
    login();

    printf("\nSistema encerrado\n\n");
}