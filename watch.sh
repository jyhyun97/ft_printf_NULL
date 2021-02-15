#!/bin/bash
# usage: watch.sh <your_command> <sleep_duration>

while :; 
  do 
  clear
  git log --graph --oneline
  sleep $2
done
