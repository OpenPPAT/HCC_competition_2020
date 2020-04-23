#! /bin/bash

ETH0_IP=$(ip addr show eno2 | grep "inet\b" | awk '{print $2}' | cut -d/ -f1)
WLO0_IP=$(ip addr show eno2 | grep "inet\b" | awk '{print $2}' | cut -d/ -f1)

source ~/HCC_competition_2020/environment.sh

roslaunch bridge bridge.launch eth0:=$ETH0_IP wlo0:=$WLO0_IP
