#/bin/bash
ARG=$(jot $1 | sort -R | tr '\n' ' ')
echo "Testing with the following sequence: $ARG"

echo "Status: $(./push_swap $ARG | ./checker $ARG)"

echo "Operations count: $(./push_swap $ARG | wc -l)"
