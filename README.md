# Projeto acionamento de Motor e coleta de dados de enconder via barramento CAN e EPOS

O projeto encontra-se na pasta /prjMotorEncoder , para fazer com que os códigos de lá funcionem é necessário a instalação do CANopen, CANopenNode, CANopenDemo e Cocoom. Alterações no Kernel Linux, assim como u-boot, vão depender da máquina.

<hr>

O programa principal do projeto é progfinal.c, nele é incorporados os diversos códigos base que criamos para fazer os testes, assim como o uso de scripts (por serem mais simples) mesmo que mais lentos, para a execução final do programa.

O código se baseia em 4 principais etapas, seno elas:
1- Inicializar os nós, com seus OD, para que possamos fazer a comunicação
2- Inicializar as threads que farão a comunicação, ou seja, preparar as chamadas de funções e limpeza de memória.
3- Manter a comunicação ativa, e fazer o controle do motor.
4- Encerrar os scripts e processos abertos, assim como encerrar os nós criados.

# Projeto ficou inacabado, faltando correção e adição funções

> Adições
<ul>
<li> Código que lerá o log gerado pelo candump ao progfinal.c </li>
<li> Código que converte o que é lido da CAN, para valores em graus/radianos </li>
<li> Envio dos valores em Graus para Cálculo de controle </li>
<li> Conversão dos valores de controle para protocolo CAN </li>
<li> Configuração padrão dos valores a serem usados na funcão prtcl </li>
</ul>

> Correções
<ul>
<li> Código gerado pelo prtclCvt (protocol converter), acaba por dar "stack smashing detected" </li>
<li> Script send.sh precisa chamar outro script para não finalizar o programa pois utilizam o mesmo terminal, podendo ser realizado assim como outros scripts em threads distintas</li>
</ul>

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
