# Debugged run.sh script
#!/bin/bash
echo "=============================================================="
echo "Compiling: cc -Wall -Wextra -Werror \"$1\" -o test_case"
cc -Wall -Wextra -Werror "$1" -o test_case
alias test ="./run.sh"
if [ $? -eq 0 ]; then
    echo "Running: ./test_case"
    echo "=============================================================="
    ./test_case
    rm test_case
else
    echo "Compilation failed."
    echo "=============================================================="
fi
