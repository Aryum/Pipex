# Pipex
A program that takes an infile, an outfile and multiple commands. It was meant to teach us about forking processes, redirecting file descriptors and all the errors associated with them.

It executes the 1st command with the inputfile as input and sends the output to the next command in the sequence, until it finds the last one where it sends the output to the outfile.

## Main logic
It first checks for the existence and permissions of the input file, if it gives an error then it exits the program. 

If it was successful then it starts executing all the commands redirecting the output to the input of the next command. To be able to redirect them we need to create a pipe that makes two file descriptors one where you can write data one where you read the written data using the function **pipe**.

Then we try to execute the command where we need to use the **execve** function that if successful it will replace the process completely, so we first create a child process so we don’t lose all the piping logic, using the fuction **fork**.

In the child process we redirect the output of the command to the write end of the pipe. Then check for the command binary testing if it exists, to do it we check the env variable _PATH_ (the same place where bash checks for them), if it doesn’t we just move to the next command, always using the read end of the pipe as input and putting the output in the write end, unless it is the last command, where it puts the data into the outfile, if the file doesn't exist it creates it but if it does and it doesn't have permissions to write to it. For these redirections we use the function **dup2**.
