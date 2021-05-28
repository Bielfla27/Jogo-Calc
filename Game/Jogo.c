 #include <stdio.h>
 #include <stdlib.h>

 typedef struct{
     int dificuldade;
     int valor1;
     int valor2;
     int operacao;
     int resultado;
 } Calcular;
 
void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main(){

    //Deve ser chamado apenas 1 vez
    srand(time(NULL));
    jogar();

    return 0;
 }

 void jogar(){
    Calcular calc; 
    int dificuldade;   
    printf("Informe o nível desejado [1 ,2, 3, ou 4]:\n");
    scanf("%d" ,&dificuldade);
    calc.dificuldade = dificuldade;

    //Gera um int randômico entre 0 e 2
    //0 == somar , 1 == diminuir , 2 ==  multiplicar
    calc.operacao =  rand() % 3; // valor final vai ser entre 0 até 3-1

    if(calc.dificuldade == 1){
        //fácil
        calc.valor1 = rand() % 11; //0 a 10
        calc.valor2 = rand() % 11; //0 a 10
    }else if (calc.dificuldade == 2){
        //médio
        calc.valor1 = rand() % 101; //0 a 100
        calc.valor2 = rand() % 101; //0 a 100
    }else if(calc.dificuldade == 3){
        //difícil 
        calc.valor1 = rand() % 1001; //0 a 1000
        calc.valor2 = rand() % 1001; //0 a 1000
    }else if(calc.dificuldade == 4){
        //insano
        calc.valor1 = rand() % 10001; //0 a 10000
        calc.valor2 = rand() % 10001; //0 a 10000
    }else{
        //nível últra pq não obedeceu a regra e digitou coisa errada
        calc.valor1 = rand() % 100001; //0 a 100000
        calc.valor2 = rand() % 100001; //0 a 100000
    }

    int resposta;
    printf("Informe o resultado para a seguinte opração:  \n");

    //somar 
    if(calc.operacao == 0){
        printf("%d + %d\n" , calc.valor1, calc.valor2);
        scanf("%d" ,&resposta);

        if(somar(resposta,calc)){
            pontos += 1;
            printf("Você tem %d ponto(s).\n",pontos);
        }
    }//Diminuir
    else if(calc.operacao == 1){
        printf("%d - %d\n" , calc.valor1, calc.valor2);
        scanf("%d" ,&resposta);

        if(diminuir(resposta,calc)){
            pontos += 1;
            printf("Você tem %d ponto(s).\n",pontos);
        }
    }//multiplicação
    if(calc.operacao == 2){
        printf("%d * %d\n" , calc.valor1, calc.valor2);
        scanf("%d" ,&resposta);

        if(multiplicar(resposta,calc)){
            pontos += 1;
            printf("Você tem %d ponto(s).\n",pontos);
        }
    }//desconhecida
    else{
        printf("A operação %d não é reconhecida\n" ,calc.operacao);
    }

    //Mostrar Info
    //mostrarInfo(calc);

    //Recomeçar o jogor 
    printf("Deseja continura jogando? [1-sim , 0 - não]\n");
    int continuar;  
    scanf("%d" ,&continuar);

    if(continuar){
        jogar();
    }else{
        printf("Você finalizou com %d ponto(s)\n",pontos);
        printf("Até a próxima.");
        exit(0);
    }

 }

 void mostrarInfo(Calcular calc){
      char op[25];
      if(calc.operacao == 0){
            sprintf(op, "Somar");//colocando um valor na varíavel 
      }else if (calc.operacao == 1 ){
            sprintf(op, "Dimunuir");//colocando um valor na varíavel 
      }else if (calc.operacao == 2 ){
            sprintf(op, "Multiplicar");//colocando um valor na varíavel 
      }else{
          sprintf(op, "Operação desconhecida");
      }
      printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d\nOperação: %s", calc.valor1,calc.valor2,calc.dificuldade,op);   
 } 

 int somar (int resposta, Calcular calc){
     int resultado =  calc.valor1 + calc.valor2; 
     calc.resultado = resultado;
     int certo = 0;  //0  ==  errou , 1 == acertou 

     if(resposta == calc.resultado){
         printf("Resposta correta!\n");
         certo = 1;
     }else{
         printf("Resposta errada!\n");
     }
     printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
     return certo;
 }

 int diminuir(int resposta, Calcular calc){
     int resultado =  calc.valor1 - calc.valor2; 
     calc.resultado = resultado;
     int certo = 0;  //0  ==  errou , 1 == acertou 

     if(resposta == calc.resultado){
         printf("Resposta correta!\n");
         certo = 1;
     }else{
         printf("Resposta errada!\n");
     }
     printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
     return certo;
 }

 int multiplicar(int resposta, Calcular calc){
     int resultado =  calc.valor1 * calc.valor2; 
     calc.resultado = resultado;
     int certo = 0;  //0  ==  errou , 1 == acertou 

     if(resposta == calc.resultado){
         printf("Resposta correta!\n");
         certo = 1;
     }else{
         printf("Resposta errada!\n");
     }
     printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
     return certo; 
 }

