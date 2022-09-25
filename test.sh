#/bin/bash
ARG=$(seq $1 | sort -R | tr '\n' ' ')
echo "Testing with the following sequence: $ARG"

echo -n "Status: "
valgrind --quiet ./push_swap $ARG | valgrind --quiet ./checker $ARG

echo -n "Operations count: "
./push_swap $ARG | wc -l
