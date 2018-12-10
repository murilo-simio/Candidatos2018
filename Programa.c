//Murilo Simionato Arnemann
//Matrícula: 18/0107453
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

//DEFINE TODAS AS VARIAVEIS QUE SERAO UTILIZADAS
    FILE *fp;
    int i,j,k=0,u=0;
    char c;
    int turno1=0, turno2=0, turno;
    int presd=0, vpresd=0, gov=0, vgov=0, senad=0, depf=0, depe=0, depd=0, psupl=0, ssupl=0;
    int partidos[91], part=0;
    char sigla[91][20];
    int ginstr[8], cdinstr, somainstr=0;
    int sexo[5], cdsexo;
    int raca[6], nraca[2], cdraca;
    int idades[100], nidade[2], idade, somaidade=0;
    int medinstr=0, medidade=0;

//VERIFICA SE O USUARIO COLOCOU TODOS OS ARGUMENTOS
    if(argc!=2){
        printf("Argumentos insuficientes!");    
        exit(1);
    }

//ABRE O ARQUIVO
    fp=fopen(argv[1], "r");

//VERIFICA SE O ARQUIVO TEM CONTEUDO
    if(fp==NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(2);
    }

//PREENCHE OS VETORES/MATRIZES DE O
    for(i=0;i<100;i++){
        partidos[i]=0, ginstr[i]=0, sexo[i]=0, raca[i]=0, idades[i]=0;
        for(j=0;j<20;j++){
            sigla[i][j];
        }
    }


//LE O CABEÇALHO
    fscanf(fp, "%c", &c);
    while (c != '\n') {
        fscanf (fp, "%c", &c);
    }
    // Conta a quantidade de ponto e vírgulas
    int contpv = 0;
    fscanf (fp, "%c", &c);

    while (!feof(fp)){
        if (c == ';') contpv++;

//CONTA QUANTOS CANDIDATOS POR TURNO E DEFINE A VAR TURNO
            if(contpv == 5 && c!=';' && c!='\"'){
                if(c == '1')turno1 += 1, turno = 1;
                if(c == '2')turno2 += 1, turno = 2;
            }

    //PEGA SOMENTE OS DADOS DO 1 TURNO
            if(turno == 1){

        //CANDIDATOS POR CARGO
                if(contpv == 13 && c!=';' && c!='\"'){
                    if(c == '1')presd   += 1;
                    if(c == '2')vpresd  += 1;
                    if(c == '3')gov     += 1;
                    if(c == '4')vgov    += 1;
                    if(c == '5')senad   += 1;
                    if(c == '6')depf    += 1;
                    if(c == '7')depe    += 1;
                    if(c == '8')depd    += 1;
                    if(c == '9')psupl   += 1;
                    fscanf(fp, "%c", &c);
                    if(c == '0'){
                        ssupl   += 1;
                        presd   -= 1;
                    }
                }

        //CANDIDATOS POR PARTIDO
                if (contpv == 27 && c!=';'){
                    fscanf(fp,"%i",&part);
                    partidos[part] ++;
                }
                if (contpv == 28 && c!=';'){
                    while(u!=-1){
                        fscanf(fp,"%c",&sigla[part][k]);
                        if (sigla[part][k] == '\"'){
                            u = -1;
                            k = 0;
                        }else {k++;}
                    }
                    u =0;
                }

        //NIVEL DE ESCOLARIDADE
                if(contpv == 43 && c!=';' && c!='\"'){
                    cdinstr = (c - '0');
                    ginstr[cdinstr] += 1;
                }

        //CANDIDATOS POR GENERO
                if(contpv == 41 && c!=';' && c!='\"'){
                    cdsexo = (c - '0');
                    sexo[cdsexo] += 1;
                }

        //CANDIDATOS POR RAÇA
                if(contpv == 47 && c!=';' && c!='\"'){
                    fscanf(fp, "%c", &c);
                    cdraca = (c - '0');
                    raca[cdraca] += 1;
                }

        //CANDIDATOS POR IDADE
                if(contpv == 39 && c!=';' && c!='\"'){
                    nidade[0] = (c - '0');
                    fscanf(fp, "%c", &c);
                    nidade[1] = (c - '0');
                    idade = (nidade[0]*10) + nidade[1];
                    idades[idade] += 1;
                }
            }

        if(c == '\n') {
            contpv = 0;
        }
        fscanf(fp, "%c", &c);

    } 
    fclose(fp);
//FECHA O ARQUIVO E TERMINA TODAS AS AÇÕES NELE

//CALCULA O GRAU MÉDIO DE INTRUÇAO
    for(i=1;i<8;i++){
        somainstr += ginstr[i];
        medinstr += (ginstr[i]*i);
    }

    medinstr = medinstr/somainstr;

//CALCULA A MEDIA DE IDADE
    for(i=0;i<100;i++){
            somaidade += idades[i];
            medidade += (i*idades[i]);
    }
    medidade = medidade/somaidade;

//PRINTA NA TELA OS DADOS PEDIDOS
    printf("Candidatos no 1 Turno: %i\n", turno1);
    printf("Candidatos no 2 Turno: %i\n", turno2);
    printf("\n\n");
    printf("Candidatos a Presidente: %i\n", presd);
    printf("Candidatos a V. Presidente: %i\n", vpresd);
    printf("Candidatos a Governador: %i\n", gov);
    printf("Candidatos a V. Governador: %i\n", vgov);
    printf("Candidatos a Senador: %i\n", senad);
    printf("Candidatos a Dep. Federal: %i\n", depf);
    printf("Candidatos a Dep. Estadual: %i\n", depe);
    printf("Candidatos a Dep. Distrital: %i\n", depd);
    printf("Candidatos a 1 Suplente: %i\n", psupl);
    printf("Candidatos a 2 Suplente: %i\n", ssupl); 
    printf("\n\n");

    for(i=1;i<91;i++){
        if(sigla[i][0]!=0 && partidos[i]!=0){
            printf("O Partido %i", i);
            //for(j=0;j<20;j++){
              //  if(sigla[i][j] != '\"'){
                //    printf("%c", sigla[i][j]);
                //}
            //}
            printf(" tem %i Membros\n",partidos[i]/2);
        }
    }
    printf("\n\n");

    for(i=0;i<7;i++){
        printf("Candidatos com Instrução %i: %i\n", i+1, ginstr[i+2]);
    }
    printf("O grau medio de Instrução eh: %i\n", medinstr);
    printf("\n\n");

    printf("Candidatos do sexo Masculino: %i\n", sexo[2]);
    printf("Candidatos do sexo Feminino: %i\n", sexo[4]);
    printf("\n\n");

    printf("Candidatos da Raca Branca: %i\n", raca[1]);
    printf("Candidatos da Raca Preta: %i\n", raca[2]);
    printf("Candidatos da Raca Parda: %i\n", raca[3]);
    printf("Candidatos da Raca Amarela: %i\n", raca[4]);
    printf("Candidatos da Raca Indigena: %i\n", raca[5]);
    printf("\n\n");

    printf("A idade media dos candidatos eh: %i\n", medidade);
    
    return 0;
}
