#!/bin/bash

PIPEX=./pipex
IN=infile.txt
OUT=outfile.txt
HEREDOC_OUT=heredoc_out.txt

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

run_test() {
    desc="$1"
    cmd="$2"

    echo -e "\n🔹 $desc"
    echo "$ cmd: $cmd"

    eval "$cmd"
}

compare() {
    diff bash_out pipex_out > /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}OK${RESET}"
    else
        echo -e "${RED}KO${RESET}"
        diff bash_out pipex_out
    fi
}

compare_stderr() {
    diff bash_err pipex_err > /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}STDERR OK${RESET}"
    else
        echo -e "${RED}STDERR KO${RESET}"
        diff bash_err pipex_err
    fi
}

echo "Hello
Hello world
42" > $IN

# BASIC
run_test "Basic pipe" \
"< $IN grep Hello | wc -l > bash_out"
$PIPEX $IN "grep Hello" "wc -l" pipex_out

compare

# COMMAND NOT FOUND (first)
run_test "Command not found (first)" \
"< $IN notexisting | wc -l > bash_out 2> bash_err"
$PIPEX $IN "notexisting" "wc -l" pipex_out 2> pipex_err

compare
compare_stderr

# COMMAND NOT FOUND (second)
run_test "Command not found (second)" \
"< $IN grep Hello | notexisting > bash_out 2> bash_err"
$PIPEX $IN "grep Hello" "notexisting" pipex_out 2> pipex_err

compare
compare_stderr

# INFILE MISSING
run_test "Infile missing" \
"< nofile grep Hello | wc -l > bash_out 2> bash_err"
$PIPEX nofile "grep Hello" "wc -l" pipex_out 2> pipex_err

compare
compare_stderr

# OUTFILE PERMISSION
touch locked
chmod 000 locked
run_test "Outfile permission denied" \
"< $IN grep Hello | wc -l > locked 2> bash_err"
$PIPEX $IN "grep Hello" "wc -l" locked 2> pipex_err

compare_stderr
chmod 644 locked
rm -f locked

# MULTI PIPE
run_test "Multiple pipes" \
"< $IN grep Hello | cat | wc -l > bash_out"
$PIPEX $IN "grep Hello" "cat" "wc -l" pipex_out

compare

# HEREDOC
run_test "Heredoc" \
"<< EOF cat | wc -l > bash_out
hello
world
EOF"
$PIPEX here_doc EOF "cat" "wc -l" $HEREDOC_OUT << EOF
hello
world
EOF

diff bash_out $HEREDOC_OUT && echo -e "${GREEN}OK${RESET}" || echo -e "${RED}KO${RESET}"

check_exit() {
    eval "$1"
    bash_code=$?

    eval "$2"
    pipex_code=$?

    if [ $bash_code -eq $pipex_code ]; then
        echo -e "${GREEN}EXIT CODE OK ($bash_code)${RESET}"
    else
        echo -e "${RED}EXIT CODE KO bash=$bash_code pipex=$pipex_code${RESET}"
    fi
}

check_exit "< $IN notexisting | wc -l > /dev/null" \
"$PIPEX $IN notexisting wc -l /dev/null"

valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes \
./pipex infile.txt "grep Hello" "wc -l" outfile.txt

valgrind --leak-check=full --show-leak-kinds=all \
./pipex infile.txt "grep Hello" "cat" "wc -l" outfile.txt

valgrind --leak-check=full --show-leak-kinds=all \
./pipex here_doc EOF "cat" "wc -l" outfile.txt

rm -f bash_out pipex_out bash_err pipex_err infile.txt outfile.txt heredoc_out.txt

