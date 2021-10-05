#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tp_dados
{
    char numero[9], nome1[30], nome2[30];
    int status;
    char numaux[9];
};
struct tp_contato
{
    struct tp_dados dados;
} contatos[20];

int main()
{
    int n, i, vezes;
    int compara = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %s %s %s", &contatos[i].dados.status,
              contatos[i].dados.numero,
              contatos[i].dados.nome1,
              contatos[i].dados.nome2);
    }

    scanf("%d", &vezes);
    char *op;
    op = (char *)malloc(sizeof(char) * vezes);

    for (i = 0; i < vezes; i++)
    {
        scanf(" %c %s", &op[i], contatos[i].dados.numaux);
    }
    for (i = 0; i < vezes; i++)
    {
        switch (op[i])
        {
        case 'E':
            for (int j = 0; j < n; j++)
            {
                if (strcmp(contatos[i].dados.numero, contatos[j].dados.numaux) == 0)
                {
                    compara = 1;
                    break;
                }
            }

            if (compara == 1)
            {

                if (contatos[i].dados.status == 0)
                {
                    printf("APAGADO\n");
                }
                else if (contatos[i].dados.status != 0)
                {
                    contatos[i].dados.status = 0;
                    printf("%d %s\n", contatos[i].dados.status, contatos[i].dados.numero);
                }
            }
            else
            {
                printf("INVALIDO\n");
            }

            break;

        case 'P':
            if (strcmp(contatos[i].dados.numero, contatos[i].dados.numaux) != 0)
            {
                printf("PPP INVALIDO\n");
            }
            else
            {
                if (contatos[i].dados.status == 0)
                {
                    printf("APAGADO\n");
                }
                else
                {
                    printf("%s %s %s\n", contatos[i].dados.numero,
                           contatos[i].dados.nome1,
                           contatos[i].dados.nome2);
                }
            }
        default:
            break;
        }
    }
}