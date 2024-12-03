#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "uso: solucion1.sh <string a buscar> <fichero>"
    exit 1
fi

grep -o $1 $2 | wc -l
