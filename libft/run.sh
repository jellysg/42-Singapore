# run.sh script
#!/bin/bash
echo "==================================="
echo "Test Case: \"$1\""
echo "==================================="
cc -Wall -Wextra -Werror "$1" -o test_case
alias test='./run.sh'  # Removed spaces around the equal sign
if [ $? -eq 0 ]; then
    ./test_case
    rm test_case
fi
