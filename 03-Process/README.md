# Exercise 5. 
## Viết một chương trình A tạo ra một tiến trình con B rồi in ra PID và PPID của chúng.

### Nhắc lại đối số
Chuyển đổi đối số từ dạng chuỗi thành số nguyên trước khi tính toán tổng
int num1 = atoi(argv[1]);
int num2 = atoi(argv[2]);
Tính tổng và in ra kết quả
printf("Tong 2 doi so la: %d\n", num1 + num2);

### PID
Nếu PID == 0 thì là process con.
Nếu PID > 0 thì là process cha.
Nếu không thì tiến trình không được tạo thành công.

# Exercise 6. 
Viết một chương trình A tạo ra một tiến trình con B, in ra PID và PPID của chúng.  Sử dụng system waitpid() để lấy được trạng thái kết thúc của tiến con B.

## WIFEXITED(wstatus)
    returns true if the child terminated normally, that is, by
    calling exit(3) or _exit(2), or by returning from main().

## WEXITSTATUS(wstatus)
    returns the exit status of the child.  This consists of
    the least significant 8 bits of the status argument that
    the child specified in a call to exit(3) or _exit(2) or as
    the argument for a return statement in main().  This macro
    should be employed only if WIFEXITED returned true.

## WIFSIGNALED(wstatus)
    returns true if the child process was terminated by a
    signal.

## WTERMSIG(wstatus)
    returns the number of the signal that caused the child
    process to terminate.  This macro should be employed only
    if WIFSIGNALED returned true.

## WIFSTOPPED(wstatus)
    returns true if the child process was stopped by delivery
    of a signal; this is possible only if the call was done
    using WUNTRACED or when the child is being traced (see
    ptrace(2)).

## WSTOPSIG(wstatus)
    returns the number of the signal which caused the child to
    stop.  This macro should be employed only if WIFSTOPPED
    returned true.

WIFCONTINUED(wstatus)
    (since Linux 2.6.10) returns true if the child process was
    resumed by delivery of SIGCONT.

# Exercise 7. 
Từ kiến thức đã học, sử dụng SIGCHLD để ngăn ngừa việc hình thành zombie process.
