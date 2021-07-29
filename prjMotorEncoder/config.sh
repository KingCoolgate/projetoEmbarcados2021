#!/bin/sh

#Inicializa CAN BUS
sudo modprobe vcan
sudo ip link add dev can0 type vcan
sudo ip link set up can0

#Cria nós virtuais
gnome-terminal -- /bin/bash /home/joao-ishida/embarcados2021/projeto/prjMotorEncoder/crtNd1.sh

gnome-terminal -- /bin/bash /home/joao-ishida/embarcados2021/projeto/prjMotorEncoder/crtNd2.sh
