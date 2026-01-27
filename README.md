*This project has been created as part of the 42 curriculum by rabdolho.*

## Description
**PIPEX** 
is a small UNIX pipeline runner that reproduces the shell behavior of chaining commands with pipes. It opens an input file, executes commands in sequence with `pipe`, `fork`, `dup2`, and `execve`, and writes the final output to an output file. The bonus version extends the behavior with `here_doc` support (reading from STDIN until a limiter) and multiple commands.

## Instruction

### Usage
#### Compilation
The project includes a `Makefile` that compiles the source files into an executable named `pipex`. To compile, run:
```bash
make
# OR
make bonus
```
#### Execution
```bash
./pipex infile "cmd1 arg1" "cmd2 arg2" outfile
##should behave like : < infile cmd1 arg1 | cmd2 arg2> outfile

# OR for bonus-mulitiple pipes
./pipex infile "cmd1 arg1" "cmd2 arg2" "cmd3 arg3" ... "cmdn argn" outfile
## should behave like : < infile cmd1 arg1 | cmd2 arg2 | cmd3 arg3 | ... cmdn  argn > outfile

# OR for bonus-here_doc
./pipex here_doc LIMITER "cmd1 arg1" "cmd2 arg2" outfile
## should behave like: cmd1  arg1 << LIMITER | cmd2 arg2 >> outfile
```
#### Cleanup
To remove object files, run:
```bash
make fclean
```


## Resources
* MAN page : `pipe(2)`, `fork(2)`, `dup2(2)`, `execve(2)`, `wait(2)`: The core syscalls used to
* <a href="https://42-cursus.gitbook.io/guide/2-rank-02/pipex/understand-pipex" target="_blank">Understand pipex - Guide </a>
* <a href="https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103" target="_blank">Pipex the 42 project “Understanding Pipelines in C”</a>
