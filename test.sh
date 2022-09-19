#/bin/bash
ARG=$(seq $1 | sort -R | tr '\n' ' ')
valgrind --quiet ./push_swap $ARG | valgrind --quiet ./checker $ARG
