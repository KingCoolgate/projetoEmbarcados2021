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
~/projetoEmbarcados2021/CANopenDemo/CANopenLinux/cocomm/ cd ../../demo
~/projetoEmbarcados2021/CANopenDemo/demo/ nano Makefile
# E vai adicionar as seguinte linhas no final do arquivos
'install:
	cp $(LINK_TARGET) /usr/bin/$(LINK_TARGET)'
~/projetoEmbarcados2021/CANopenDemo/demo/ make
~/projetoEmbarcados2021/CANopenDemo/demo/ sudo make install
```
Agora pode criar nós da rede can usando demoLinuxDevice, de qualquer pasta via Terminal.

<i>"[...] By default device uses Object Dictionary from `CANopenNode/example`, which contains only communication parameters." ~ projetoEmbarcados2021/CANopenDemo/CANopenLinux/README.md</i>

Então para criar um nó para a rede CAN precisamos ajeitar os Object Dictionary, OD, dessa forma não será preciso mexer os aquivos que o texto acima indica (tentei mexer não consegui, apelei pro demo que funcionou), usando a pasta projetoEmbarcados2021 como referência.

<i>/CANopenDemo/CANopenPIC/demo/OD.c</i>

Altere nesse arquivo os valores dos parâmetros de comunicação PDO (valores 1400(4) e 1800(4)) e os parâmetros de mapeamento PDO (valores 1600(4) e 1A00(4)). Se quiser uma explicação sobre esse valores se encontra no link abaixo.
<b><i>https://github.com/CANopenNode/CANopenDemo/blob/master/demo/demoDevice.md</i></b>

Modificando OD.c permite mais liberdade sobre as capacidades dos nós.

obs2: Caso fizer 'git submodule update --init --recursive' terá que alterar os arquivos OD.c novamente

##################################################################################################################
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
