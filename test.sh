ARG=$(<test.txt);
./push_swap $ARG | ./checker_MAC $ARG;
./push_swap $ARG > result.txt