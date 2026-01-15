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
Ans this is a test
42" > $IN

#PACO_LOGS
run_test "Paco logs" \
"< $IN cat | wc > bash_out 2> bash_err"
$PIPEX $IN "cat" "wc" pipex_out 2> pipex_err
compare
compare_stderr

run_test "Substitution command" \
"< $IN sed 's/And/But/' | grep But > bash_out 2> bash_err"
$PIPEX $IN  'sed "s/And/But/"' 'grep But' pipex_out 2> pipex_err
compare
compare_stderr

run_test "AWK" \
"< $IN sed 's/And/But/' | awk '{count++} END {print count}' > bash_out 2> bash_err"
$PIPEX $IN 'sed "s/And/But/"' 'awk '"'"'{count++} END {print count}'"'"'' pipex_out 2> pipex_err
compare
compare_stderr

run_test "AWK_2" \
"< $IN sed 's/And/But/' | awk '{count++} END {print count}' > bash_out 2> bash_err"
$PIPEX $IN 'sed "s/And/But/"' 'awk "{count++} END {print count}"' pipex_out 2> pipex_err
compare
compare_stderr

run_test "AWK_3" \
'< $IN sed "s/And/But/" | awk "{count++} END {printf \"count: %i\" , count}" > bash_out 2> bash_err'
$PIPEX $IN 'sed "s/And/But/"' 'awk "{count++} END {printf \"count: %i\" , count}"' pipex_out 2> pipex_err
compare
compare_stderr

run_test "AWK_4" \
"< $IN sed 's/And/But/' | awk '{count++} END {printf \"count: %i\", count}' > bash_out 2> bash_err"
$PIPEX $IN 'sed "s/And/But/"' 'awk '"'"'{count++} END {printf "count: %i", count}'"'"'' pipex_out 2> pipex_err
compare
compare_stderr

run_test "script" \
"< $IN ./script.sh | wc > bash_out 2> bash_err"
$PIPEX $IN "./script.sh" "wc" pipex_out 2> pipex_err
compare
compare_stderr

run_test "script_2" \
"< $IN './script space.sh' | wc > bash_out 2> bash_err"
$PIPEX $IN "./script space.sh" "wc" pipex_out 2> pipex_err
compare
compare_stderr

# BASIC
run_test "Basic pipe" \
"< $IN grep Hello | wc -l > bash_out"
$PIPEX $IN "grep Hello" "wc -l" pipex_out

compare

# COMMAND NOT FOUND (first)
run_test "Command not found (first)" \
"< $IN bash -c notexisting | wc -l > bash_out"
$PIPEX $IN "notexisting" "wc -l" pipex_out

compare

# COMMAND NOT FOUND (second)
run_test "Command not found (second)" \
"< $IN grep Hello | notexisting > bash_out"
$PIPEX $IN "grep Hello" "notexisting" pipex_out

compare

# INFILE MISSING
run_test "Infile missing" \
"< nofile grep Hello | wc -l > bash_out"
$PIPEX nofile "grep Hello" "wc -l" pipex_out

compare

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
"rm -f bash_out pipex_out; << EOF cat | wc -l > bash_out
hello
world
EOF"
rm -f $HEREDOC_OUT
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
run_test "check_exit" \
check_exit "< $IN notexisting | wc -l > /dev/null" \
"$PIPEX $IN notexisting wc -l /dev/null"

echo -e "\n------------------------------------------------------------\n"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42 --trace-children=yes \
./pipex infile.txt "grep Hello" "wc -l" outfile.txt
if [ $? -eq 42 ]; then
    echo -e "${RED}ACTUAL LEAKS DETECTED!${RESET}"
else
    echo -e "${GREEN}NO LEAK(program exited normally or with non-leak error) ${RESET}"
fi

echo -e "\n------------------------------------------------------------\n"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42 --trace-children=yes \
./pipex infile.txt "cmd_worng" "wc -l" outfile.txt
if [ $? -eq 42 ]; then
    echo -e "${RED}ACTUAL LEAKS DETECTED!${RESET}"
else
    echo -e "${GREEN}NO LEAK(program exited normally or with non-leak error) ${RESET}"
fi

echo -e "\n------------------------------------------------------------\n"
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --error-exitcode=42 --trace-children=yes \
./pipex infile.txt "grep Hello" "cat" "wc -l" outfile.txt
if [ $? -eq 42 ]; then
    echo -e "${RED}ACTUAL LEAKS DETECTED!${RESET}"
else
    echo -e "${GREEN}NO LEAK(program exited normally or with non-leak error) ${RESET}"
fi

echo -e "\n------------------------------------------------------------\n"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42 --trace-children=yes \
./pipex here_doc EOF "cat" "wc -l" outfile.txt
if [ $? -eq 42 ]; then
    echo -e "${RED}ACTUAL LEAKS DETECTED!${RESET}"
else
    echo -e "${GREEN}NO LEAK(program exited normally or with non-leak error) ${RESET}"
fi

