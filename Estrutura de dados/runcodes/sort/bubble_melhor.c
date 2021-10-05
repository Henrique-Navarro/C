/*Método da Bolha Melhorado: Termina
execução quando nenhuma troca é
realizada após uma passada pelo vetor
*/
#define TRUE 1
#define FALSE 0
void Bolha (Vetor A; Indice n) {
    Indice i, j;
    Item temp;
    char troca;

    troca = TRUE;
    for (i:= n-1; (i >= 1) && (troca == TRUE); i--) {
        troca = FALSE;
        for (j= 0; j < i ;j++) {
            if (A[j].chave < A[j+1].chave) {
                temp = A[j].chave;
                A[j].chave = A[j+1].chave;
                A[j+1].chave = temp;
                troca = TRUE;
            }
        }
    }
}