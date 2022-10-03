#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


//Estrutura responsável por definir as variáveis ligadas ao relógio
typedef struct _TEMPO {
    clock_t tempoInicial, tempoFinal, tempoTotal;
}TEMPO;


//Posição Global do personagem
short posicao = 0;

//Bônus do personagem
short bonus = 0;

//Ferramentas a serem procuradas no jogos. Estas começam com o valor 0 pois o personagem adquire todos essas ao decorrer do jogo.
short espada = 0;
short corda = 0;
short picador = 0;
short marreta = 0;
short lamparina = 0;

//Postura do capitão e do personagem no momento da batalha
int acaocap = 2;
int postura = 1;

//Quantidade de vida dos persoangens
int personagem = 100;
int capitao = 100;

//Variáveis ligadas a aleatoriedade da luta entre capitão e personagem
int x;
int y;

//Checa se o personagem já entrou na sala do Capitão
int salaCap=0;

//Grava o Nome do Jogador e seu tempo
void gravaApelidoTempo(char apelido[], int tempoTotal){

    FILE *gravaNomeTempo;

    gravaNomeTempo = fopen("Tabela_de_Resultados.txt", "a");    

    if(gravaNomeTempo == NULL){
        puts("O arquivo não pôde ser aberto");
        exit(2);
    }

    fprintf(gravaNomeTempo, "Apelido: ");
    fprintf(gravaNomeTempo ,"%s", apelido);
    fprintf(gravaNomeTempo, " Tempo: ");
    fprintf(gravaNomeTempo ,"%d", tempoTotal);
    fprintf(gravaNomeTempo, "u.t \n");

    fclose(gravaNomeTempo);

}

//Protótipo da função gets
char *gets(char *str);

//Variável responsável por orientar a resposta da fuga do personagem;
char respostaFuga[50];

//Função que gera números aleatórios na Luta Final entre personagem e capitão
int dado(){
srand(time(NULL));
int dadoFace = ( rand()%20)+1;
return dadoFace;
}

//Função que gera números aleatorios para a postura do capitão
int randomico(){
srand(time(NULL));
int randomVar = (rand()%4)+1;
return randomVar;
}

//As funções a seguir mostram as imagens dos objetos no jogo

int imagemEspada(){
FILE *es;
char p[50];
es= fopen("espada.txt" , "r");
if(es==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,es)!=NULL) {
printf("%s", p);
}
fclose(es);
return 0;
}

int imagemBandeira (){
FILE *ba;
char p[1000];
ba= fopen("bandeira.txt" , "r");
if(ba==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,ba)!=NULL) {
printf("%s", p);
}

fclose(ba);
return 0;
}

int imagemTitulo (){
FILE *ti;
char p[100];
ti= fopen("titulo.txt" , "r");
if(ti==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,100,ti)!=NULL) {
printf("%s", p);
}

fclose(ti);
return 0;
}

int imagemMarreta (){
FILE *ma;
char p[50];
ma= fopen("marreta.txt" , "r");
if(ma==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,ma)!=NULL) {
printf("%s", p);
}

fclose(ma);
return 0;
}

int imagemLamparina (){
FILE *la;
char p[50];
la= fopen("lamparina.txt" , "r");
if(la==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,la)!=NULL) {
printf("%s", p);
}
fclose(la);
return 0;
}

int imagemCorda (){
FILE *co;
char p[50];
co= fopen("corda.txt" , "r");
if(co==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,co)!=NULL) {
printf("%s", p);
}
fclose(co);
return 0;
}

int imagemPicador () {
FILE *pi;
char p[50];
pi= fopen("picador.txt" , "r");
if(pi==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,pi)!=NULL) {
printf("%s", p);
}
fclose(pi);
return 0;
}

int imagemPorta (){
FILE *po;
char p[50];
po= fopen("porta.txt" , "r");
if(po==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,po)!=NULL) {
printf("%s", p);
}
fclose(po);
return 0;
}

int imagemPorta2 (){
FILE *po2;
char p2[50];
po2= fopen("porta2.txt" , "r");
if(po2==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p2,50,po2)!=NULL) {
printf("%s", p2);
}
fclose(po2);
return 0;
}

int imagemMapa (){
FILE *ma;
char p[50];
ma= fopen("mapa.txt" , "r");
if(ma==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,ma)!=NULL) {
printf("%s", p);
}
fclose(ma);
return 0;
}

int imagemTesouro (){
FILE *te;
char p[50];
te= fopen("tesouro.txt" , "r");
if(te==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,te)!= NULL) {
printf("%s", p);
}
fclose(te);
return 0;
}

int imagemEnigma(){
FILE *en;
char p[50];
en= fopen("enigma.txt" , "r");
if(en==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,en)!=NULL) {
printf("%s", p);
}
fclose(en);
return 0;
}

int imagemGameOver(){
FILE *ga;
char p[50];
ga= fopen("gameover.txt" , "r");
if(ga==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,ga)!=NULL) {
printf("%s", p);
}
fclose(ga);
return 0;
}

int imagemFight(){
FILE *fi;
char p[50];
fi= fopen("fight.txt" , "r");
if(fi==NULL){
  printf("impossivel ler o arquivo.\n");
  return 1;
}
while (fgets(p,50,fi)!=NULL) {
printf("%s", p);
}
fclose(fi);
return 0;
}

//Função responsável por direcionar uma possível fuga para o personagem
void fuga() {

printf("    Você acaba de iniciar a fuga!!! (música épica rolando de fundo)\n");
if (corda == 1) {
  printf("    Você tem o item corda e por isso pode fugir pelo [mastro frontal].\n");
  while(gets(respostaFuga) && (strcmp(respostaFuga, "mastro frontal")!= 0)) {
    printf("    Digite a palavra corretamente: ");
  }
  if ((strcmp (respostaFuga, "mastro frontal") == 0) && (posicao == 0))  {
    if (bonus ==1) {
      printf("    Você consegue fugir com o seu baú e com o Mapa do Capitão, o jogo termina aqui. Você concluiu o jogo com maestria! \n");
      imagemGameOver();
      //exit(0);
    }
    if (bonus == 0) {
      printf("    Você conseguiu fugir com o Mapa do Capitão, mas acabou deixando itens para trás. Jogue novamente e tente buscar outros finais!");
      imagemGameOver();
      //exit(0);
    }
  }

}
else if(corda == 0){
  printf("    Você pode fugir pela proa\n");
  while(gets(respostaFuga) && (strcmp(respostaFuga, "proa")!= 0)) {
          printf("    Digite a palavra corretamente: ");
  }
  if ((strcmp (respostaFuga, "proa") == 0) && (posicao == 0))  {
    if (bonus ==1) {
      printf("    Você consegue fugir sem o seu baú e com o mapa, o jogo termina aqui!\n");
      imagemGameOver();
      exit(0);
    }
    if (bonus == 0) {
      printf("    Você conseguiu fugir com o Mapa do Capitão, mas acabou deixando itens para trás! Jogue novamente e tente buscar outros finais\n");
      imagemGameOver();
      exit(0);

    }

  }
}
}

//Função responsável em realizar a luta entre personagem e capitão
void lutando(){

fflush(stdin);
printf("    Digite agora a sua ação:\n");
while(gets(respostaFuga) && (strcmp(respostaFuga, "bater")!= 0) && (strcmp(respostaFuga, "esquivar")!= 0)&& (strcmp(respostaFuga, "defender")!= 0)) {
        printf("     Digite uma palavra válida: \n");

}

if ((strcmp (respostaFuga, "bater") == 0) && (posicao == 0))  {
  postura = 1;
  x = dado();
  printf("Você conseguiu tirar %d no dado\n",x );
  if (x < 5) {
    printf("    Você não conseguiu bater no capitão\n");sleep(1);
    if (capitao > 0){
    printf("    Agora o capitão executará a sua ação:\n");sleep(1);
    acaocap = randomico();
        if ((acaocap ==1) || (acaocap == 4)) {
          printf("    O capitão te atacará\n");
          if (postura == 1) {
              printf("    -->Você está em um postura de ataque\n");sleep(1);
            printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
            printf("    Ele conseguiu tirar %d no dado\n", y);
              if (y < 5) {
                printf("    O capitão não conseguiu te atacar! \n");
              }
              if ((y>4) && (y<16)) {
                printf("    O capitão conseguiu te dar um golpe de 20!\n");
                personagem = personagem - 20;
                if (personagem>=0){
                   printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                 }
                 else{
                    printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                 }
              }
              if ((y>15) && (y<21)) {
                printf("    O capitão conseguiu fazer um golpe com maestria, você recebe 20 + 8 no dano\n");
                personagem = personagem - 28;
                if (personagem>=0){
                   printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                 }
                 else{
                    printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                 }
              }
          }


          if (postura == 2) {
              printf("    -->Você está em um postura de defesa\n");
            printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
            printf("    Ele conseguiu tirar %d no dado\n", y);
              if (y < 5) {
                printf("    O capitão não conseguiu te atacar! \n");sleep(1);
              }
              if ((y>4) && (y<16)) {
                printf("    O capitão conseguiu te dar um golpe, mas você está em posicao de defesa, e só levou metade do dano!\n");sleep(1);
                personagem = personagem -10;
                if (personagem>=0){
                   printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                 }
                 else{
                    printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                 }

              }
              if ((y>15) && (y<21)) {
                printf("    O capitão conseguiu fazer um golpe boladão , você recebe 20 + 8 no dano, mas como está em posicão de defesa você só leva metade do dano!\n");sleep(1);
                personagem = personagem -14;
                if (personagem>=0){
                   printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                 }
                 else{
                    printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                 }
              }
          }


          if (postura == 3) {
            printf("    -->Você está em um postura de esquiva\n");
            printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
            printf("    você conseguiu tirar %d no dado\n", y);
              if (y < 5) {
                printf("    Você não conseguiu esquivar-se do ataque do capitão, levou 20 de dano!\n");
                personagem = personagem - 20;
                if (personagem>=0){
                   printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                 }
                 else{
                    printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                 }

              }
              if ((y>4) && (y<16)) {
                printf("    Você conseguiu esquivar-se do golpe!\n");
                personagem = personagem;
                if (personagem>=0){
                   printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                 }
                 else{
                    printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                 }

              }
              if ((y>15) && (y<21)) {
                printf("    Você conseguiu esquivar-se do golpe com maestria e ainda aplicou um contra ataque de 8 de dano no capitão\n");
                capitao = capitao -8;
                if (capitao>=0){
                   printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
                 }
                 else{
                    printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
                 }
              }
          }


        }
      if (acaocap == 2) {
        printf("    -->O capitao assume postura de defesa\n");sleep(1);
      }
      if (acaocap == 3) {
        printf("    -->O capitão assume postura de esquiva\n");sleep(1);
      }
    }
  }
  if ((x >4) && (x < 21)  ) {

    printf("   Você executou a ação de bater no capitão\n" );
    if ((acaocap == 1) || (acaocap == 4)) {
      printf("    -->O capitão está em um postura de ataque\n");sleep(1);

        if ((x>4) && (x<16)) {
          printf("    O capitão levou um golpe normal de 20\n");
          capitao = capitao -20;
          if (capitao>=0){
             printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
           }
           else{
              printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
           }
        }
        if ((x>15) && (x<21)) {
          printf("    Você conseguiu executar um golpe boladão , capitão levará 20 + 8 de dano\n");sleep(1);
          capitao = capitao - 28;
          if (capitao>=0){
             printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
           }
           else{
              printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
           }

        }
    }
      if (acaocap == 2) {
        printf("    -->O capitão está em um postura de defesa\n");
        printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
        printf("    Ele conseguiu tirar %d no dado\n", y);
          if (y < 5) {
            printf("    O capitão não conseguiu defender o seu ataque, ele levou 20 de dano \n");
            capitao = capitao -20;
            if (capitao>=0){
               printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
             }
             else{
                printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
             }
          }
          if ((y>4) && (y<16)) {
            printf("    O capitão conseguiu defender o seu golpe, ele levou metade do dano do dano, que equivale a 10\n");sleep(1);
            capitao = capitao -10;
            if (capitao>=0){
               printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
             }
             else{
                printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
             }
          }
          if ((y>15) && (y<21)) {
            printf("    O capitão conseguiu defender o seu golpe com maestria, defendeu 75 porcento do dano\n");sleep(1);
            capitao = capitao -5;
            if (capitao>=0){
               printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
             }
             else{
                printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
             }
          }
      }
      if (acaocap == 3) {
        printf("    -->O capitão está em um postura de esquiva\n");
        printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
        printf("    Ele conseguiu tirar %d no dado\n", y);
          if (y < 5) {
            printf("    O capitão não conseguiu esquivar-se do seu ataque, ele levou 20 de dano \n");sleep(1);
            capitao = capitao - 20;
            if (capitao>=0){
               printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
             }
             else{
                printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
             }
          }
          if ((y>4) && (y<16)) {
            printf("    O capitão conseguiu esquivar-se do seu golpe\n");sleep(1);
            capitao = capitao;
            if (capitao>=0){
               printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
             }
             else{
                printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
             }
          }
          if ((y>15) && (y<21)) {
            printf("    O capitão conseguiu esquivar-se do seu golpe com maestria, ele ainda te aplicou um contra ataque de 20 + 8 de dano\n");sleep(1);
            personagem = personagem -8;
            if (personagem>=0){
               printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
             }
             else{
                printf("    A sua vida atual é [ 0 ]\n");sleep(1);
             }
          }
      }
      if (capitao>0){
      printf("    Agora o capitão executará a sua ação\n");
      acaocap = randomico();
          if ((acaocap==1) || (acaocap == 4)) {
            printf("    -->Você está em uma postura de ataque\n");
            printf("    O capitão te atacará\n");sleep(1);
            if (postura == 1) {
              printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
              printf("    Ele conseguiu tirar %d no dado\n", y);
                if (y < 5) {
                  printf("    O capitão ta azarado e não conseguiu te atacar! \n");sleep(1);
                }
                if ((y>4) && (y<16)) {
                  printf("    O capitão conseguiu te dar um golpe de 20 de dano\n");sleep(1);
                  personagem = personagem - 20;
                  if (personagem>=0){
                     printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                   }
                   else{
                      printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                   }
                }
                if ((y>15) && (y<21)) {
                  printf("    O capitão conseguiu fazer um golpe bolado, você recebe 20+8 de dano bonus\n");sleep(1);
                  personagem = personagem -28;
                  if (personagem>=0){
                     printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                   }
                   else{
                      printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                   }
                }
            }


            if (postura == 2) {
              printf("    -->Você está em um postura de defesa\n");
              printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
              printf("    Ele conseguiu tirar %d no dado\n", y);
                if (y < 5) {
                  printf("    O capitão não conseguiu te atacar \n");sleep(1);
                }
                if ((y>4) && (y<16)) {
                  printf("    O capitão conseguiu te dar um golpe, mas você está em posicao de defesa, só levou metade do dano, que equivale a 6\n");sleep(1);
                  personagem = personagem - 10 ;
                  if (personagem>=0){
                     printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                   }
                   else{
                      printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                   }
                }
                if ((y>15) && (y<21)) {
                  printf("    O capitão conseguiu fazer um golpe com maestria, você recebe 20 + 8 de dano bonus, mas como está em posicão de defesa você só leva metade do dano\n");sleep(1);
                  personagem = personagem - 14;
                  if (personagem>=0){
                     printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                   }
                   else{
                      printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                   }
                }
            }


            if (postura == 3) {
              printf("    -->Você está em um postura de esquiva\n");
              printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
              printf("    você conseguiu tirar %d no dado\n", y);
                if (y < 5) {
                  printf("    você não conseguiu esquivar-se do ataque do capitão, levou 20 de dano\n");sleep(1);
                  personagem = personagem -20;
                  if (personagem>=0){
                     printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                   }
                   else{
                      printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                   }
                }
                if ((y>4) && (y<16)) {
                  printf("    Você conseguiu esquivar-se do golpe\n");sleep(1);
                  personagem = personagem;
                  if (personagem>=0){
                     printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
                   }
                   else{
                      printf("    A sua vida atual é [ 0 ]\n");sleep(1);
                   }
                }
                if ((y>15) && (y<21)) {
                  printf("    Você conseguiu esquivar-se do golpe com maestria e ainda aplicou um contra ataque de 8 de dano no capitão\n");sleep(1);
                  capitao = capitao -8;
                  if (capitao>=0){
                     printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
                   }
                   else{
                      printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
                   }

                }
            }


          }
        if (acaocap == 2) {
          printf("    --> O Capitão assume postura de defesa\n");sleep(1);
        }
        if (acaocap == 3) {
          printf("    -->O Capitão assume postura de esquiva\n");sleep(1);
        }
      }
  }
}


if ((strcmp (respostaFuga, "esquivar") == 0) && (posicao == 0)){
  printf("    -->Você assume posicão de esquiva\n");
  postura = 3;
  if (capitao>0){
  printf("    Agora o capitão executará a sua ação\n");sleep(1);
  acaocap = randomico();
      if ((acaocap==1)||(acaocap == 4)) {
        printf("    -->O capitão te atacará\n");sleep(1);
        if (postura == 1) {
          printf("    -->Você está em um postura de ataque\n");sleep(1);
          printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
          printf("    Ele conseguiu tirar %d no dado\n", y);sleep(1);
            if (y < 5) {
              printf("    O capitão não conseguiu te atacar \n");sleep(1);
            }
            if ((y>4) && (y<16)) {
              printf("    O capitão conseguiu te dar um golpe de 20 de dano\n");sleep(1);
              personagem = personagem - 20;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>15) && (y<21)) {
              printf("    O capitão conseguiu fazer um golpe com maestria, você recebe 20 +8 no dano\n");sleep(1);
              personagem = personagem -28;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
        }


        if (postura == 2) {
          printf("    -->Você está em um postura de defesa\n");sleep(1);
          printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
          printf("    Ele conseguiu tirar %d no dado\n", y);
            if (y < 5) {
              printf("    O capitão não conseguiu te atacar \n");sleep(1);
            }
            if ((y>4) && (y<16)) {
              printf("    O capitão conseguiu te dar um golpe, mas você está em posicao de defesa, só levou metade do dano\n");sleep(1);
              personagem = personagem -10;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>15) && (y<21)) {
              printf("    O capitão conseguiu fazer um golpe com maestria, você recebe 20 + 8 no dano, mas como está em posicão de defesa você só leva metade do dano\n");sleep(1);
              personagem = personagem -14;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }

            }
        }


        if (postura == 3) {
          printf("    -->Você está em um postura de esquiva\n");sleep(1);
          printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
          printf("    você conseguiu tirar %d no dado\n", y);
            if (y < 5) {
              printf("    você não conseguiu esquivar-se do ataque do capitão e levou 20 de dano\n");sleep(1);
              personagem = personagem - 20;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>4) && (y<16)) {
              printf("    Você conseguiu esquivar-se do golpe\n");sleep(1);
              personagem = personagem;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>15) && (y<21)) {
              printf("    Você conseguiu esquivar-se do golpe com maestria e ainda aplicou um contra ataque de 8 de dano no capitão\n");sleep(1);
              capitao = capitao -8;
              if (capitao>=0){
                 printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
               }
               else{
                  printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
               }

            }
        }


      }
    if (acaocap == 2) {
      printf("    -->O capitão assume postura de defesa\n");sleep(1);
    }
    if (acaocap == 3) {
      printf("    -->O capitão assume postura de esquiva\n");sleep(1);
    }
  }

}
if ((strcmp (respostaFuga, "defender") == 0) && (posicao == 0)){
  printf("    -->Você assume posicão de defesa\n");sleep(1);
  postura = 2;
  if (capitao>0){
  printf("    Agora o capitão executará a sua ação\n");sleep(1);
  acaocap = randomico();
      if ((acaocap==1) || (acaocap == 4)) {
        printf("    O capitão te atacará\n");sleep(1);
        if (postura == 1) {
            printf("    -->Você está em um postura de ataque\n");sleep(1);
          printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
          printf("    Ele conseguiu tirar %d no dado\n", y);
            if (y < 5) {
              printf("    O capitão não conseguiu te atacar \n");sleep(1);
            }
            if ((y>4) && (y<16)) {
              printf("    O capitão conseguiu te dar um golpe\n");sleep(1);
              personagem = personagem - 20;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>15) && (y<21)) {
              printf("    O capitão conseguiu fazer um golpe com maestria, você recebe +8 no dano\n");sleep(1);
              personagem = personagem -28;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }

            }
        }


        if (postura == 2) {
          printf("    -->Você está em um postura de defesa\n");
          printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
          printf("    Ele conseguiu tirar %d no dado\n", y);
            if (y < 5) {
              printf("    O capitão não conseguiu te atacar \n");sleep(1);
            }
            if ((y>4) && (y<16)) {
              printf("    O capitão conseguiu te dar um golpe, mas você está em posicao de defesa, só levou metade do dano\n");sleep(1);
              personagem = personagem -10;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>15) && (y<21)) {
              printf("    O capitão conseguiu fazer um golpe com maestria, você recebe +8 no dano, mas como está em posicão de defesa você só leva metade do dano\n");sleep(1);
              personagem = personagem -14;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }

            }
        }


        if (postura == 3) {
          printf("    -->Você está em um postura de esquiva\n");
          printf("...\n");sleep(1); printf("...\n");sleep(1); y = dado();
          printf("    você conseguiu tirar %d no dado\n", y);
            if (y < 5) {
              printf("    você não conseguiu esquivar-se do ataque do capitão, levou 20 de dano\n");sleep(1);
              personagem = personagem - 20;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>4) && (y<16)) {
              printf("    Você conseguiu esquivar-se do golpe\n");sleep(1);
              personagem = personagem;
              if (personagem>=0){
                 printf("    A sua vida atual é [ %d ]\n",personagem);sleep(1);
               }
               else{
                  printf("    A sua vida atual é [ 0 ]\n");sleep(1);
               }
            }
            if ((y>15) && (y<21)) {
              printf("    Você conseguiu esquivar-se do golpe com maestria e ainda aplicou um contra ataque de 8 de dano no capitão\n");sleep(1);
              capitao = capitao - 8;
              if (capitao>=0){
                 printf("    A vida atual do Capitão é [ %d ]\n",capitao);sleep(1);
               }
               else{
                  printf("    A vida atual do Capitão é [ 0 ]\n");sleep(1);
               }

            }
        }


      }
    if (acaocap == 2) {
      printf("    -->O capitao assume postura de defesa\n");sleep(1);
    }
    if (acaocap == 3) {
      printf("    -->O capitão assume postura de esquiva\n");sleep(1);
    }
  }
}
if ((personagem > 0) && (capitao > 0)) {
  lutando();
}
if (capitao <=0) {
  fuga();
}

if (personagem <= 0) {
printf("    Infelizmente você não conseguiu completar a missão e morreu, tente novamente! \n");
imagemGameOver();
exit(0);
}

}/* final da função lutando*/

//Essa função ajuda o usuario se orientar no jogo
void help (){
printf("_____________________________________________________________________________________________________________________________________________________\n");
printf("    INFORMAÇÕES SOBRE O JOGO: Como foi dito, sua missão é coletar um mapa na sala do capitão Barba Rala. Porém, para isso você precisará de alguns itens e resoluções de problemas\n"); sleep(1);
printf("    Seu primeiro objetivo é entrar na sala do Capitão, mas para isso você precisará coletar alguns itens e informações\n" );sleep(2);

printf("    A primeira parte do jogo é o [convés] do navio. Este é o centro do navio\n");sleep(1);
printf("    OBS: Tente [checar] quando lhe for sugerido que algo pode ser importante!\n    Sempre que você quiser sair, digite [sair] para retornar ao seu local de origem e poder ir a outros lugares\n" );sleep(1);
printf("    palavras entre [] são as que você precisa digitar para desencadear a ação\n" );sleep(1);
}

//Orienta o jogador em meio a luta
void lutaHelp() {
 printf("\n");sleep(2);
 printf("    Explicação da batalha: você tem 100 de vida, você pode usar [bater], [esquivar] ou [defender]\n");sleep(2);
 printf("    Ambos começam com 100 de vida \n    Quando você bate, você dá dano no capitão(obviamente KK) e existe a possibilidade de errar o golpe se sua sorte estiver zoada\n");sleep(1);
 printf("    Esquivar dá a chance de não levar todo o dano do capitão, porém também depende da sua maré de sorte\n");sleep(2);
 printf("    Defender faz você conseguir tankar metade do dano do capitão, talvez até mais...\n");sleep(1);
 printf("    Sempre que você digitar a ação um dado de vinte lados ira rodar, se você tirar abaixo de 8\n    tua sorte não está muito boa, se você tirar de 8 até 15, você executa a ação namoral\n    E se tirar de 16 até 20 você tem bônus e é deus demais. \n");sleep(2);
 printf("\n");sleep(2);
 imagemFight();
 printf("\n");
 printf("    --> O capitão já começou se defendendo\n");
 printf("\n");

 lutando();
}

//Função resposável por fazer o personagem caminhar pelo navio
void recursao(char *resposta) {

  if (posicao == 0)  {
    fflush(stdin);
    printf("_____________________________________________________________________________________________________________________________________________________\n");
    printf("                                                 _________CONVÉS_________\n");sleep(2);
    printf("    VOCÊ ACABOU DE ENTRAR NO CONVÉS\n" );sleep(2);
    printf("    -Digite [Help] se tiver alguma dificuldade-\n");
    printf("    Aqui você tem acesso a todos os lugares do navio, considere aqui como o centro. Você pode entrar no [porão], [mastro frontal], [enfermaria], [canhões] e [sala do capitão]\n"); sleep(2);
        while(gets(resposta) && (strcmp(resposta, "mastro frontal")!= 0) && (strcmp(resposta, "canhões")!= 0)&& (strcmp(resposta, "sala do capitão")!= 0)&& (strcmp(resposta, "porão")!= 0)&& (strcmp(resposta, "enfermaria")!= 0)&& (strcmp(resposta, "help")!= 0)) {
                printf("     Digite uma palavra válida: ");

        }

        if ((strcmp (resposta, "help") == 0) && (posicao == 0))  {
            help();
            recursao(resposta);
        }
        if ((strcmp (resposta, "mastro frontal") == 0) && (posicao == 0))  {
          printf("                                             _________MASTRO FRONTAL_________\n");sleep(2);
          printf("    VOCÊ ACABOU DE ENTRAR NO MASTRO FRONTAL\n" );sleep(2);

          if (lamparina == 0) {
              printf("    Na proa você vê uma lamparina, talvez seja uma boa ideia [pegar]. Porém a luz do luar já ilumina o navio. Parece também que alguém deixou uma caixa de ferramentas por aqui...  \n");
              while(gets(resposta) && (strcmp(resposta, "sair")!= 0) && (strcmp(resposta, "pegar")!= 0)) {
                printf("Digite uma palavra válida: ");
              }
                      if ((strcmp (resposta, "sair") == 0) && (posicao == 0))  {
                        printf("    -VOCÊ SAIU DO MASTRO FRONTAL-\n" );sleep(2);
                        printf("    &\n");sleep(1);
                        recursao(resposta);
                      }
                      if ((strcmp (resposta, "pegar") == 0) && (posicao == 0))  {
                        printf("    Você acaba de pegar a lamparina\n" );sleep(2);
                        printf("    O item lamparina foi adicionado ao seu inventário\n");sleep(2);
                        lamparina = lamparina + 1;
                        imagemLamparina();
                        printf("    Com a lamparina fica mais fácil de olhar o que tem na [caixa]\n");sleep(2);
                        printf("    Digite a sua ação: \n");
                        while(gets(resposta) && (strcmp(resposta, "sair")!= 0) && (strcmp(resposta, "caixa")!= 0)&& (strcmp(resposta, "caixa")!= 0)) {
                                printf("    Digite uma resposta válida: ");sleep(2);
                        }
                        if (((strcmp (resposta, "caixa") == 0) && (posicao == 0)) || (strcmp (resposta, "caixa") == 0))  {
                              printf("    Você checou a caixa e achou uma marreta\n");sleep(2);
                              printf("    O item marreta foi adicionado ao seu inventário\n");
                              marreta = marreta + 1;
                              imagemMarreta();
                                printf("    Não tem mais nada para fazer na área do mastro , digite [sair] para d1rigir-se ao convés\n");sleep(2);
                              while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                                      printf("    Digite uma resposta correta: ");sleep(2);
                              }
                              if ((strcmp (resposta, "sair") == 0) && (posicao == 0))  {
                                printf("    -VOCÊ SAIU DO MASTRO FRONTAL-\n" );sleep(2);
                                printf("    &\n");sleep(1);
                                recursao(resposta);
                              }
                        }
                        if ((strcmp (resposta, "sair") == 0) && (posicao == 0))  {
                          printf("    -VOCÊ SAIU DO MASTRO FRONTAL-\n" );sleep(2);
                          printf("    &\n");sleep(1);
                          recursao(resposta);
                        }
                      }

          }
          else if((marreta != 0) && (lamparina != 0)){
            printf("    Não tem mais nada para fazer na área do mastro , digite [sair] para d1rigir-se ao convés\n");
            while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                    printf("    digite uma resposta certa: ");sleep(2);
            }
            if ((strcmp (resposta, "sair") == 0) && (posicao == 0))  {
              printf("    -VOCÊ SAIU DO MASTRO FRONTAL-\n" );sleep(2);
              printf("    &\n");sleep(1);
              recursao(resposta);
            }
          }

        }

        if ((strcmp (resposta, "canhões") == 0) && (posicao == 0))  {
          if (espada == 0) {
            /* code */

              printf("                                                _________CANHÕES_________\n");sleep(2);
              printf("    VOCÊ ACABOU DE ENTRAR NA SALA DOS CANHOES\n" );sleep(1);
              printf("    Na sala dos canhões tem algo peculiar nos fenos, você pode [checar]\n");sleep(2);
              while(gets(resposta) && (strcmp(resposta, "sair")!= 0) && (strcmp(resposta, "checar")!= 0)) {
                      printf("    Digite a palavra corretamente: ");
              }
              if ((strcmp (resposta, "checar") == 0) && (posicao == 0))  {
                printf("    Você vasculhou o feno e achou uma espada\n");sleep(2);
                printf("    A espada foi adicionada ao seu inventário e você esta cheio de feno na roupa\n");sleep(2);
                imagemEspada();
                    espada = espada + 1;
                    printf("   Humm, parece que não tem mais nada para fazer na sala dos canhões, digite [sair] para voltar ao convés\n");sleep(1);
                    while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                            printf("    Digite a palavra corretamente: ");
                    }
                    printf("    -VOCÊ SAIU DA SALA DOS CANHÕES-\n" );sleep(2);
                    printf("    &\n");sleep(1);
                    recursao(resposta);
              }
              if ((strcmp (resposta, "sair") == 0) && (posicao == 0))  {
                printf("    -VOCÊ SAIU DA SALA DOS CANHÕES-\n" );sleep(1);
                printf("    &\n");sleep(1);
                recursao(resposta);

              }
          }
          else if (espada != 0) {
            printf("                                                _________CANHÕES_________\n");sleep(2);
            printf("    VOCÊ ACABOU DE ENTRAR NA SALA DOS CANHOES\n" );sleep(1);
            printf("    Humm, parece que não tem mais nada para fazer na sala dos canhões, digite [sair] para voltar ao convés \n");sleep(1);
            while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                    printf("    Digite a palavra corretamente: ");
            }
            printf("    -VOCÊ SAIU DA SALA DOS CANHÕES-\n" );sleep(2); /*o que ta rolando aqui?*/
            printf("    &\n");sleep(1);
            recursao(resposta);
          }

        }
        if ((strcmp (resposta, "porão") == 0) && (posicao == 0))  {
          printf("                                                 _________PORÃO_________\n");sleep(2);
          printf("    VOCÊ ACABOU DE ENTRAR NO PORÃO\n" );sleep(1);
          if (corda == 0) {
            /* code */

                  if (espada == 0) {
                      printf("    Tem um carretel gigante na sua frente mas você não consegue cortar um pedaço de corda só com os dentes\n");sleep(2);
                      printf("     Não tem mais nada para fazer no porão, digite [sair] para voltar ao conv3s\n");sleep(2);
                      while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                              printf("    Digite a palavra corretamente: ");
                      }
                      printf("    -VOCÊ SAIU DA SALA DO PORÃO-\n" );sleep(1);
                      printf("    &\n");sleep(1);
                      recursao(resposta);

                  }
                  else  if(espada == 1) {
                            printf("      Tem um carretel gigante na sua frente mas você não consegue [cortar] um pedaço de corda só com os dentes, uma espada parece ser útil para isso\n");sleep(1);
                          while(gets(resposta) && (strcmp(resposta, "sair")!= 0) && (strcmp(resposta, "cortar")!= 0)) {
                                  printf("    Digite a palavra corretamente: ");
                          }
                          if ((strcmp (resposta, "cortar") == 0) && (posicao == 0))  {
                              printf("    Você cortou a corda\n");sleep(2);
                              printf("    O item corda foi adicionado ao seu inventário\n");sleep(2);
                              corda = corda + 1;
                              imagemCorda();
                              printf("   Não tem mais nada para fazer no porão, digite [sair] para voltar ao conv3s\n");sleep(1);
                              while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                                      printf("    Digite a palavra corretamente: ");
                              }
                              printf("    -VOCÊ SAIU DA SALA DO PORÃO-\n" );sleep(1);
                              printf("    &\n");sleep(1);/*ele printa que você está de volta ao convés aqui?*/
                              recursao(resposta);

                          }



                }
         }
         else if (corda!=0) {
           printf("   Não tem mais nada para fazer no porão, digite [sair] para voltar ao conv3s \n");sleep(1);
           while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                   printf("    Digite a palavra corretamente: ");
           }
           printf("    -VOCÊ SAIU DA SALA DO PORÃO-\n" );sleep(1);
           printf("    &\n");sleep(1);/*ele printa que você está de volta ao convés aqui?*/
           recursao(resposta);
         }

      }
      if ((strcmp (resposta, "enfermaria") == 0) && (posicao == 0))  {

              printf("                                                 _________ENFERMARIA_________\n");sleep(2);
              printf("    VOCÊ ACABOU DE ENTRAR NA ENFERMARIA\n" );sleep(1);

              if (picador == 0) {
                printf("      A sala está bem suja de sangue e fede a podre. \n      Tem uma [gaveta] de instrumentos médicos aberta no fundo da sala.\n");sleep(2);
                while(gets(resposta) && (strcmp(resposta, "sair")!= 0) && (strcmp(resposta, "gaveta")!= 0)) {
                        printf("    Digite a palavra corretamente: ");
                }
                if ((strcmp (resposta, "gaveta") == 0) && (posicao == 0))  {
                      printf("    Você checou a gaveta e achou um picador de gelo, não é algo que um médico usaria, parece desgastado e marcado de sangue, ainda pode ser útil para forçar algo, tipo gelo.\n");sleep(2);
                      printf("    O picador de gelo foi adicionada ao seu inventário\n");sleep(2);
                      picador = picador + 1;
                      imagemPicador();
                      printf("    Não tem mais nada para fazer na enfermaria, digite [sair] para vaz4r\n");sleep(2);
                      while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                              printf("    Digite a palavra corretamente: ");
                      }
                      printf("     -VOCÊ SAIU DA SALA DA ENFERMARIA-\n" );sleep(1);  /*?????*/
                      printf("    &\n");sleep(1);
                      recursao(resposta);
                }
                if ((strcmp (resposta, "sair") == 0) && (posicao == 0))  {
                  printf("    -VOCÊ SAIU DA ENFERMARIA-\n" );
                  printf("    &\n");
                  recursao(resposta);

                }
              }
              else if (picador != 0) {
                printf("    Não tem mais nada para fazer na enfermaria, digite [sair] para vaz4r\n");sleep(2);
                while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                        printf("    Digite a palavra corretamente: ");
                }
                printf("     -VOCÊ SAIU DA ENFERMARIA-\n" );sleep(1);  /*?????*/
                printf("    &\n");sleep(1);
                recursao(resposta);
              }



      }
      if ((strcmp (resposta, "sala do capitão") == 0) && (posicao == 0))  {
          if ((marreta + picador) != 2) {
            printf("                                               _________SALA DO CAPITÃO_________\n");sleep(2);
            printf("    A sala está trancada, você precisa de algo pra dar aquela forçada master na porta\n");sleep(2);
            imagemPorta();
            printf("    Digite [sair] para voltar ao convés\n");
            while(gets(resposta) && (strcmp(resposta, "sair")!= 0)) {
                    printf("    Digite a palavra corretamente: ");
            }
            printf("     -VOCÊ SAIU DA SALA DO CAPITÃO-\n" );sleep(1);  /*?????*/
            printf("    &\n");sleep(1);
            recursao(resposta);

          }
          else if ((marreta + picador)==2) {
            printf("                                               _________SALA DO CAPITÃO_________\n");sleep(2);
            imagemPorta2();
            if (salaCap==0){
            printf("    Boa meu consagrado \n");sleep(1);
            printf("    Você forçou a porta com a marreta e o picador de gelo!");sleep(1);
            printf("    Você acaba de entrar na sala do capitão\n");sleep(2);
            printf("    Você chega na sala e se depara com algumas cartas em cima da mesa\n");sleep(1);
            salaCap=salaCap+1;
            }

            printf("\n");
            imagemEnigma();
            printf("      Com ajuda da lamparina consegue ler o que o envelope com selo do Barba Rala guardava : \n      [Carta para mim mesmo: Lembre-se da ordem , pense !!! (P-E-M-C)....\n       Para o segundo já sabe, o selo é seguro pelo mais óbvio guardar o mais valioso\n");sleep(2);
            printf("\n      Logo você se depara com um [armario] no fundo da sala, é isso!\n      Parece que finalmente chegou a hora de pegar o mapa e completar a missão!!!\n");sleep(2);
            printf("      Ou você pode [sair] por algum motivo\n");
            while(gets(resposta) && (strcmp(resposta, "sair")!= 0) && (strcmp(resposta, "armario")!= 0)) {
                    printf("    Digite a palavra corretamente: ");
            }
            if ((strcmp (resposta, "armario") == 0) && (posicao == 0))  {
                printf("    O armario do capitão está trancado, você precisa de uma senha para desbloquear a tranca\n");
                printf("    Digite a senha se você souber ela\n");
                printf("    Ou você pode [sair] da sala do Capitão\n");

                while(gets(resposta) && (strcmp(resposta, "sair")!= 0) && (strcmp(resposta, "3411")!= 0)) {
                        printf("    Essa não é a senha KKKK\n");
                }
                if ((strcmp (resposta, "3411") == 0) && (posicao == 0)){
                  printf("    Você advinhou a senha e conseguiu abrir o armário UUUHHHHH\n");sleep(1);
                  printf("    Dentro do armario você encontrou uma garrafa com o mapa!!!\n");sleep(1);
                  imagemMapa();
                  printf("    O item mapa foi adicionado ao seu inventário\n");sleep(1);
                  printf("    Você pode [fugir] do barco agora ou tentar continuar a [checar] a sala do capitão\n");sleep(1);
                  while(gets(resposta) && (strcmp(resposta, "fugir")!= 0)&& (strcmp(resposta, "checar")!= 0)) {
                          printf("    Digite a palavra corretamente: ");
                  }
                  if ((strcmp (resposta, "fugir") == 0) && (posicao == 0))  {
                    fuga();
                  }
                  if ((strcmp (resposta, "checar") == 0) && (posicao == 0))  {
                    printf("    Após algum tempo checando o armário um fundo falso que escondia um baú se revela !!!\n     Porém esse está preso à uma corrente com cadeado que precisa de senha....HUUUMMMMM\n");sleep(1);
                    printf("    Digte a senha se souber, ou digite [fugir] para meter o pé do navio\n");sleep(2);
                    while(gets(resposta) && (strcmp(resposta, "fugir")!= 0)&& (strcmp(resposta, "10")!= 0)) {
                            printf("    ERROOU! Digite a palavra corretamente: ");
                    }
                    if ((strcmp (resposta, "10") == 0) && (posicao == 0))  {
                    printf("    Você conseguiu desvendar a senha e soltar o baú XEROQ  \n");sleep(2);
                    printf("    O item baú foi adicionado ao seu inventário\n");sleep(1);
                    printf("'Barulho da porta se abrindo'\n");sleep(1);
                    printf("...\n");sleep(2);
                    printf("    Meu DEUS, você demorou muito tempo checando a sala, o capitão apareceu\n");sleep(1);
                    printf("\n");

                    lutaHelp();
                    }
                    if ((strcmp (resposta, "fugir") == 0) && (posicao == 0))  {
                      fuga();
                    }

                  }
                }
            }
            if ((strcmp (resposta, "sair") == 0) && (posicao == 0)){

              printf("     -VOCÊ SAIU DA SALA DO CAPITÃO-\n" );sleep(1);
              printf("    &\n");sleep(1);
              recursao(resposta);
            }

          }
      }
  }
}


int main() {

//Parâmentro da função recursão. Está é responsável pela movimentação do jogador pelo navio;
char resposta[10];

TEMPO tempo;

//Declaração da variavel next, para que não haja a apresentação de um "warning"
char next = 'a';
next++;

imagemBandeira();

//Início do relógio
tempo.tempoInicial = clock();

next = getchar();
printf("_____________________________________________________________________________________________________________________________________________________\n");
printf("    Você entra numa taberna portuária nas Antilhas, vai se encontrar com uma pessoa que te contratou para um serviço.\n");sleep(1);
printf("    Um sujeito com roupas caras porém desgastadas, parecidas com a da marinha espanhola,lhe acena.\n    Você entende o gesto e senta na cadeira à sua frente, enquanto o mesmo pede mais rum e guarda um baralho.\n"); sleep(2);
printf("    PRESS  [ENTER]");
fflush(stdin);
next = getchar();
printf("\n");
printf("    Contratante:\n");sleep(1);
printf("    Finalmente chegou o grande dia! Vamos revisar o plano? Tudo foi de acordo,\n    hoje o navio do Barba Rala vai atracar neste porto e eles devem dormir nas acomodações dessa taberna,\n    Todos vão descansar antes de continuar a rota de contrabando.\n");sleep(1);
printf("    Um informante disse que o mapa da próxima rota deles está na sala do capitão , mas não será tão simples chegar lá.\n");sleep(1);
printf("    Temos que esperar até a madrugada, vamos beber um pouco por enquanto!\n");sleep(2);
fflush(stdin);
printf("    PRESS  [ENTER]");
next = getchar();
printf("\n");
printf("    Enfim chega a madrugada, você sai da taberna, porém percebe que muitos marujos ainda estão acordados (apesar da maioria não estar em plenas condições). \n    Não há mais tempo, logo você sai, adentra o navio e chega ao convés. \n");
printf("    Você acaba de subir escondido no barco e tem 6 lugares para procurar.\n" );

//Chamada da função recursao(resposável em caminhar entre o navio)
recursao(resposta);

//Guarda o apelido do Jogador
char apelidoJogador[20];
puts("Digite seu Apelido para salvar seus dados: ");
scanf("%s", apelidoJogador);

/*Realiza a conta para saber a quantidade de tempo do usuário no jogo e finaliza o programa salvando o apelido do
jogador em um arquivo .txt*/

tempo.tempoFinal = clock();

tempo.tempoTotal = (double)(tempo.tempoFinal - tempo.tempoInicial);

gravaApelidoTempo(apelidoJogador, tempo.tempoTotal);

return 0;
}
