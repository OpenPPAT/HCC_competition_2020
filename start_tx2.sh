#! /bin/bash

ETH0_IP=$(ip addr show eth0 | grep "inet\b" | awk '{print $2}' | cut -d/ -f1)
WLAN0_IP=$(ip addr show wlan0 | grep "inet\b" | awk '{print $2}' | cut -d/ -f1)

source ~/HCC_competition_2020/environment.sh

roslaunch teleop_twist_joy teleop.launch eth0:=$ETH0_IP wlo0:=$WLAN0_IP
