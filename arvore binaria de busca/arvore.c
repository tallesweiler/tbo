#include <stdio.h>
#include "arvore.h"


struct arvore {
  int chave;
  Arvore* esquerda;
  Arvore* direita;
};

// Cria uma árvore vazia
Arvore* criaArvoreVazia() {
  return NULL;
}

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arvore* criaArvore(int chave) {
  Arvore* arv = malloc(sizeof(Arvore));
	arv->chave=chave;
	arv->esquerda=criaArvoreVazia();
	arv->direita=criaArvoreVazia();

  return arv;
}

// retorna true se a árvore estiver vazia e false
// caso contrário
int arvoreVazia(Arvore* arv) {
  return (arv==NULL);
}

// libera o espaço de memória ocupado pela árvore a
void liberaArvore(Arvore* arv) {
	if (!arvoreVazia(arv)) {
		liberaArvore(arv->esquerda);
		liberaArvore(arv->direita);
		liberaArvore(arv);
	}
}

// indica a ocorrência (1) ou não (0) do caracter c
int taNaArvore(Arvore* arv, int chave) {
  if (arvoreVazia(arv)) {
    return 0;
  }
  else {
    return (arv->chave == chave || taNaArvore(arv->esquerda, chave) || taNaArvore(arv->direita, chave));
  }
}

// imprime as informações dos nós da árvore
void imprimeArvore(Arvore* arv) {
  if (!arvoreVazia(arv)) {
		imprimeArvore(arv->esquerda);
		printf("(%d)\n", arv->chave);
		imprimeArvore(arv->direita);
  }
}

Arvore* buscaArvore(Arvore* arv, int chave) {
  if (arv->chave==chave) {
		return arv;
	}
  else if (arv->chave>chave) {
    return buscaArvore(arv->esquerda, chave);
	}
  else if (arv->chave<chave) {
    return buscaArvore(arv->direita, chave);
	}
  else {
		return NULL;
	}
}

Arvore* insereArvore(Arvore* arv, int chave) {
  if (arvoreVazia(arv)) {
    arv=criaArvore(chave);
  }
  else if (arv->chave>chave) {
		arv->esquerda=insereArvore(arv->esquerda, chave);
	}
  else {
		arv->direita=insereArvore(arv->direita, chave);
	}
  return arv;
}

Arvore* retiraArvore(Arvore* arv, int chave) {
  if (arvoreVazia(arv)) {
		return NULL;
	}
  else if (arv->chave>chave) {
    arv->esquerda=retiraArvore(arv->esquerda, chave);
	}
  else if (arv->chave<chave) {
    arv->direita=retiraArvore(arv->direita, chave);
	}
  else {
    // sem filhos (folha)
    if (arv->esquerda==NULL && arv->direita==NULL) {
      free(arv);
      arv=NULL;
    }
    // filho somente a esquerda
    else if (arv->direita==NULL) {
      Arvore* temp=arv;
      arv=arv->esquerda;
      free(temp);
    }
    // filho somente a direita
    else if (a->sae == NULL)
    {
      Arv *temp = a;
      a = a->sad;
      free(temp);
    }
    // dois filhos
    else
    {
      // acha o antecessor do nó
      Arv *f = a->sae;
      while (f->sad != NULL)
        f = f->sad;
      // faz a troca das informações
      Aluno *temp = a->aluno;
      a->aluno = f->aluno;
      f->aluno = temp;
      // chama recursivamente para o nó agora em alguma das situações anteriores
      a->sae = arv_retira(a->sae, chave);
    }
  }
  return a;
}

void imprimeCodigo(Arv *arv)
{
  printf("\nstrict graph{\n");
  imprimeArvore(arv);
  printf("}\n");
  return;
}

// retorna a mãe de um dado no
Arv *arv_pai(Arv *a, char *nome)
{
  if (arv_vazia(a))
  {
    return NULL;
  }
  else
  {
    if (a->sae != NULL && (!strcmp(Retorna_nome_aluno(a->sae->aluno), nome)))
    {
      return a;
    }
    else if (a->sad != NULL && (!strcmp(Retorna_nome_aluno(a->sad->aluno), nome)))
    {
      return a;
    }
    else
    {
      Arv *sae = arv_pai(a->sae, nome);
      Arv *sad = arv_pai(a->sad, nome);
      if (sae != NULL)
      {
        return sae;
      }
      else if (sad != NULL)
      {
        return sad;
      }
    }
  }
  return NULL;
}

// retorna a quantidade de folhas de uma arvore binaria
int folhas(Arv *a)
{
  if (a == NULL)
  {
    return 0;
  }
  else if (a->sae == NULL && a->sad == NULL)
  {
    return 1;
  }
  else
  {
    return (folhas(a->sae) + folhas(a->sad));
  }
}


