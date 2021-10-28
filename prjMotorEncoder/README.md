# Explicando cada um dos arquivos

> Funções ainda não implementadas

<hr>
-> IDE para seleção de inputs (rd/wr,nó,id,subid,valor);
-> Após a leitura do Log fazer a desconversão do protocolo e utilizar para algum controle

> Funções ainda não implementadas no progfinal.c

<hr>
-> Leitura do candumpLog

> Arquivos scripts

<hr>
config.sh -> script que cria o barramento virtual, além de chamar os scripts que criam os nós master e slaves, além de criar candumpLog. Ao chamar os outros scripts são criados terminais para cada um respectivamente.

master.sh -> script que cria o nó principal, junto com um arquivo que permite o uso de algumas funções do CANopenDemo.

nslave.sh -> script para criar um nó cujo ID = n+1, e para o barramento can0.

<del>send.sh -> script que abre um novo terminal, no qual será enviado a mensagem ao barramento.

sendReal.sh -> script que faz o envio da mensagem ao barramento.</del> (foram substituídas pela função system() )

candumpLog.sh -> script que cria um arquivo .log, o qual vai ser lido para ter uma interpretação do retorno do nó.

close.sh -> script que encerra todos os programas, até mesmo suspendo o PC.

> Arquivos .c

<hr>
encoder.c -> Programa inicial onde foi feito o algoritimo inicial, pois a ideia era fazer 2 programas um que enviasse a mensagem de controle para o barramento, outro que recebesse o retorno do nó para ser feito o cálculo de controle. Além de ter adicionado diversos comandos aprendidos no curso, como o uso de threads, semaphore, uso dos pinos para I/O.

motor.c -> Programa inicial onde foi feito o algoritimo inicial pois a ideia era fazer 2 programas um que enviasse a mensagem de controle para o barramento, outro que recebesse o retorno do nó para ser feito o cálculo de controle. Além de ter adicionado diversos comandos aprendidos no curso, como o uso de threads, semaphore, uso dos pinos para I/O.

prtclCvt.c -> Programa teste que foi adicionado ao código final, como uma função que convertia um input em um número de até 8 dígitos em hex.

fileRead.c -> Programa que permite a leitura dos dados do log, que depois seriam desconvertidos para dados reais, que seriam usados para fazer o cálculo de controle. (ainda não implementado no código final)

progfinal.c -> Programa que uniu todos os scripts e códigos em c, com a intenção de fazer a leitura de um encoder e acionamento de um motor, via barramento e protocolo can, em um sistema embarcado, nesse caso era uma toradex Viola VF50 em uma Colibri, usando kernel linux 4 oferecido pela empresa.
