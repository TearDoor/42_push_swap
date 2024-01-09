ARG=$(<test.txt);
./push_swap $ARG | ./checker_linux $ARG;
./push_swap $ARG > result.txt