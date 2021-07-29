# Projeto acionamento de Motor e coleta de dados de enconder via barramento CAN e EPOS

O projeto se encontra na pasta /prjMotorEncoder , para fazer com que os códigos de lá funcionem é necessário a instalação do CANopen, maneira mais fácil é seguir o tutorial do primeiro LINK da região de 'Comandos para fazer teste'.

Se você fez o git clone desse repositório para fazê-lo funcionar deve-se fazer antes os seguintes commandos
```sh
~$ cd projetoEmbarcados2021
~/projetoEmbarcados2021/ git init
~/projetoEmbarcados2021/ git pull
~/projetoEmbarcados2021/ git submodule update --init --recursive
~/projetoEmbarcados2021/ cd CANopenDemo/CANopenLinux/cocomm
~/projetoEmbarcados2021/CANopenDemo/CANopenLinux/cocomm/ make
~/projetoEmbarcados2021/CANopenDemo/CANopenLinux/cocomm/ sudo make install //Para adicionar a função cocomm ao Terminal
~/projetoEmbarcados2021/CANopenDemo/CANopenLinux/cocomm/ cd ..
~/projetoEmbarcados2021/CANopenDemo/CANopenLinux/ make
~/projetoEmbarcados2021/CANopenDemo/CANopenLinux/ sudo make install // Para adicionar a função canopend ao Terminal
```
Agora pode criar nós da rede can usando canopend

<i>"[...] By default device uses Object Dictionary from `CANopenNode/example`, which contains only communication parameters." ~ projetoEmbarcados2021/CANopenDemo/CANopenLinux/README.md</i>

Então para criar um nó para a rede CAN precisamos ajeitar os Object Dictionary, OD, dessa forma iremos mudar alguns arquivos lista deles segue abaixo via endereços, usando a pasta projetoEmbarcados2021 como referência.

<ul>
<li>/CANopenDemo/CANopenLinux/CANopenNode/example/OD.c</li>
<li>/CANopenDemo/CANopenPIC/CANopenNode/example/OD.c</li>
</ul>

Substitua esses 2 arquivos com o
/CANopenDemo/demo/OC.c

<i> Não precisa fazer via substituição, você pode alterar os valores que quiser, para quanto quiser, mas saiba o que está fazendo. Modificando OD.c permite mais liberdade sobre as capacidades dos nós</i>

Depois volte a pasta do CANopenLinux e faça ~$ make ~$ sudo make install
Para que a função canopend possa abrir nós com comunicação aberta.

obs: É possível ao invés de mudar o arquivo OD.c passar os parâmetros desejados como argumentos, porém assim é mais simples para o script que criamos.
obs2: Caso fizer 'git submodule update --init --recursive' terá que alterar os arquivos OD.c novamente

# Comandos para fazer os testes com o CAN

Antes de usar a comunicação com a EPOS precisa instalar algumas ferramentas

Segue esse tutorial para instalar CANopen
https://opensource.lely.com/canopen/docs/installation/

```sh
~$ sudo apt-get update
~$ git clone https://github.com/CANopenNode/CANopenDemo.git
~$ cd CANopenDemo
~/CANopenDemo/$ git submodule update --init --recursive
```
Se precisar atualizar depois
```sh
~$ cd CANopenDemo
~/CANopenDemo/$ git pull
~/CANopenDemo/$ git submodule update --init --recursive
```
Agora é "buildar" e rodar em no mínimo 4 terminais distintos

> Terminal 1
```sh
# Adicionar a função que vai fazer a comunicação
~$ cd CANopenDemo/CANopenLinux/cocomm/
~CANopenDemo/CANopenLinux/cocomm/$ make
~CANopenDemo/CANopenLinux/cocomm/$ sudo make install
~CANopenDemo/CANopenLinux/cocomm/$ cd
# Inicializar o barramento virtual can0 (para teste)
~$ sudo modprobe vcan
~$ sudo ip link add dev can0 type vcan
~$ sudo ip link set up can0
# Ouvir tudo o que é enviado ao barramento
~$ candump can0
```

> Terminal 2
```sh
# Compilar e criar o nó "master"
~$ cd CANopenDemo/CANopenLinux/
~/CANopenDemo/CANopenLinux/$ make
~/CANopenDemo/CANopenLinux/$ rm *.persist
~/CANopenDemo/CANopenLinux/$ ./canopend can0 -i 1 -c "local-/tmp/CO_command_socket"
# Usando o canopend pode se criar diversos nós  "./canopend (Barramento -i id-Nó)"
```

> Terminal 3
```sh
# Compilar e criar o nó "slave"
~$ cd CANopenDemo/demo/
~/CANopenDemo/demo/$ make
~/CANopenDemo/demo/$ rm *.persist
~/CANopenDemo/demo/$ ./demoLinuxDevice can0
```

> Terminal 4
```sh
#aqui é onde você vai passar os commandos via cocomm
~$ cocomm "help"
```

Nos tutoriais explicam certinho e passo a passo, o que é cada função, como usar, quais parametros, o que cada valor significa.

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
