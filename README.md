# Pipex
This Project is about recreating the shell command `< input_file command1 | command2 > output_file` in C.  
Read the [subject.pdf](https://github.com/Tempest989/Pipex/blob/main/en.subject.pdf) for in-depth information about the Project.
# My Score
<img width="1347" alt="Pipex Score" src="https://user-images.githubusercontent.com/55472613/178903398-802a303f-c859-4c6b-9301-f14344ede64c.png">

# Makefile Utility
- `make` and `make pipex` will compile the Mandatory part of the Pipex Project, as the executable `pipex`.
- `make bonus` will compile the Bonus part of the Pipex Project, as the executable `bonus`.
- `make clean` will delete, if possible, the executable `pipex`.
- `make fclean` will run `make clean` and then delete, if possible, the executable `bonus`.
- `make re` will run the commands, `make fclean` then `make` and `make bonus`, to delete (if possible) `pipex` and `bonus`, then compile the executables `pipex` and `bonus`.
# Difference Between Mandatory and Bonus
- Bonus executable can handle a theorectical infinite number of commands, unlike the Mandatory which can only handle 2 commands.
# Code Execution Format
**Mandatory** = `./pipex [input file name] [first command] [second command] [output file name]`.  
**Bonus** = `./bonus [input file name] [first command] ... [last command] [output file name]`.
### A helpful [Tester](https://github.com/gmarcha/pipexMedic) which I used for both Mandatory and Bonus.
