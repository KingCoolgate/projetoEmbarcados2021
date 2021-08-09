# Projeto acionamento de Motor e coleta de dados de enconder via barramento CAN e EPOS

O projeto encontra-se na pasta /prjMotorEncoder , para fazer com que os códigos de lá funcionem é necessário a instalação do CANopen, CANopenNode, CANopenDemo e Cocoom. Alterações no Kernel Linux, assim como u-boot, vão depender da máquina.

<hr>

A execução do Script config.sh vai criar o CAN Bus virtual e inicilizar 3 nós. De forma a permitir o uso do comando 'cocomm'

Falta integrar o script aos códigos em C, que faram uso de threads para se comunicar entre os nós, por facilidade essas threads vão chamar scripts que usaram cocomm para enviar as mensagens e ler elas também.

Somada a essas alterações que falta, faremos alteração no device-tree como explicado em vídeo pelo Henrique @griloHBG. Além de tentar implementar mudar o CANtx CANrx para o CAN-High CAN-low

# Em caso de dúvidas entre em contato

@joaopedroburle no twitter

# Manual para executar as partes

Leia o tutorial.md

# Links Possivelmente úteis

> Git com programas e documentação para entender o básico do CANopen aplicado for dummies<br>
Interno a esse repositório existe diversos outros que são base, como o CANopenLinux, por ser mais completo, é o que recomendo.
https://github.com/CANopenNode/CANopenDemo

> README.md bem simplificado de tutorial para ver se a instalação tá ok <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/README.md

> Após brincar um pouco faça o teste global das ferramentas <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/test/README.md

> Configurar os nós e dar nome a eles com LSS <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/LSS.md

> Finalizar a configuração dos nós via comandos SDO <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/SDO.md

> Teste de comunicação entre nós e master PDO <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/PDO.md

> Habilitando CAN na toradex Colibri VFxx <br>
https://developer.toradex.com/knowledge-base/can-linux#Kernel_Support_Colibri_VFxx

> Fazendo Build do kernel e pegando os arquivos do git toradex <br>
https://developer.toradex.com/knowledge-base/build-u-boot-and-linux-kernel-from-source-code
