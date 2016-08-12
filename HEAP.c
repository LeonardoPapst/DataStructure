#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;
    int max;
    int quantidade;
}heap;

/**Inicializa o Heap com tamanho n
 */
void inicializaHeap(heap* h, int n) {
    h->v = malloc(sizeof (int) * n);
    h->max = n;
    h->quantidade = 0;
    if (!h->v) {
        printf("problema na alocacao\n");
        system("PAUSE");
    }
}

int ultimoPai(heap *h){
	return (h->quantidade/2)-1;
}

int filhoEsquerdo(heap *h, int indicador){
	return  2 * indicador +1;
}

int filhoDireito(heap *h, int indicador){
	return  2 * indicador +2;
}

int pai(heap *h, int indicador){
	return (indicador - 1)/2;
}

void trocaPos(heap *h, int a, int b){
	int aux;
	aux = h->v[a];
	h->v[a] = h->v[b];
	h->v[b] = aux;
}

/**peneira a partir do ?ndice pai
*/
void peneirar(heap* h, int pai) {

	int fEsq = filhoEsquerdo(h, pai);
	int fDir = filhoDireito(h, pai);
	int indiceMaior = pai;

	if(fEsq < h->quantidade && h->v[fEsq] > h->v[indiceMaior])
	    indiceMaior = fEsq;
	if(fDir < h->quantidade && h->v[fDir] > h->v[indiceMaior])
	    indiceMaior = fDir;
	if (indiceMaior != pai){
		trocaPos(h,indiceMaior,pai);
		peneirar(h,indiceMaior);
	}

}

/**reordena o vetor h->v para que se torne um heap
*/

void construirHeap(heap* h) {
	int i=0;
	for(i = ultimoPai(h); i >= 0 ; i-- ){
		peneirar(h, i);
	}
}

void destroiHeap(heap* h) {
    if (h->v)
        free(h->v);
}

/**Insere o elemento x no heap h
 */
void insereMaxHeap(heap* h, int x) {
	if(h->quantidade == h->max)
	    return;
	h->v[h->quantidade]=x;
	h->quantidade++;
	if(h->quantidade != 1)
			construirHeap(h);
}

/**Retorna o maior elemento do heap h e remove-o da ?rvore.
 */
int removerMaxHeap(heap* h) {
	int aux = h->v[0];
	h->v[0] = h->v[h->quantidade-1];
	h->quantidade--;
	construirHeap(h);
	return aux;
}

int main(int argc, char *argv[]) {

    heap h;
    inicializaHeap(&h, 10);
    insereMaxHeap(&h, 5);
    insereMaxHeap(&h, 6);
    insereMaxHeap(&h, 2);
    insereMaxHeap(&h, 3);
    insereMaxHeap(&h, 50);
    insereMaxHeap(&h, 1);
    insereMaxHeap(&h, 0);
    insereMaxHeap(&h, 13);
    insereMaxHeap(&h, 44);


    printf("%d\n", removerMaxHeap(&h));
    printf("%d\n", removerMaxHeap(&h));
    printf("%d\n", removerMaxHeap(&h));
    printf("%d\n", removerMaxHeap(&h));
    printf("%d\n", removerMaxHeap(&h));
    printf("%d\n", removerMaxHeap(&h));

    system("pause");
    return 0;
}
