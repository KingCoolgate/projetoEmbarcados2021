#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

void prtcl(char net[4],int ndId, char rw[5], char index[4], char subindex[2], int valor) {

  char  call[50]="0";
  char  nd[3];
  char  indx1[2];
  char  indx2[2];
  char  sindx[2];
  char  valc[8];
  char  valc1[2];
  char  valc2[2];
  char  valc3[2];
  char  valc4[2];
  int   id=600+ndId;
  int   val1;
  int   i=0;
  int   j=0;

  //formato da string no final deve ser
  // "./write.sh can0 ndId#rw.index1.index2.subindex.valor1.valor2.valor3.valor4"

  //Define o Script a ser chamado
  strcat(call, "./send.sh ");

  // Define a Rede que se encontra os nós
  strcat(call, net);
  strcat(call, " ");

  // Define o nó para qual será enviado
  sprintf(nd, "%d", id);
  strcat(call, nd);
  strcat(call, "#");

  //Define se vai ser Read ou Write no barramento
  if (!(strcmp(rw,"write"))){
    strcat(call,"2F.");
  }
  else {
    strcat(call,"40.");
  }

  //Define o Index do nó chamado
  indx1[0] = index[2];
  indx1[1] = index[3];
  strcat(call, indx1);
  strcat(call, ".");
  indx2[0] = index[0];
  indx2[1] = index[1];
  strcat(call, indx2);
  strcat(call, ".");

  //Define o SubIndex do nó chamado
  strcat(call, subindex);
  strcat(call, ".");

  //Valor a ser passado de até 8 digitos em HEX
  sprintf(valc, "%X", valor);
  val1 = strlen(valc);

  while (i<8){
    while (j<val1){
      valc[8-val1+j]= valc[j];
      j++;
      i++;
    }
    while(8-i > 0){
      valc[7-i] = 48;
      i++;
    }
  }

  i=0;
  j=0;

  valc1[0] = valc[6];
  valc1[1] = valc[7];
  strcat(call, valc1);
  strcat(call, ".");

  valc2[0] = valc[4];
  valc2[1] = valc[5];
  strcat(call, valc2);
  strcat(call, ".");

  valc3[0] = valc[2];
  valc3[1] = valc[3];
  strcat(call, valc3);
  strcat(call, ".");

  valc4[0] = valc[0];
  valc4[1] = valc[1];
  strcat(call, valc4);

  system(call);

}


//prtcl(char net[4],int ndId, char rw[5], char index[4], char subindex[2], int valor)
void main() {
  prtcl("can0", 2, "write", "1017", "00", 1000);
}
