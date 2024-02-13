# Signal
Nhạy cảm về mặt thời gian thực thi
## System call signal()
    Đăng ký việc xử lý một signal
### sighandler_t signal (int signo, sighandler_t handler);
Các đối số:
    signo: signal number
    handler: signal handler

## Exercise 08

    Viết chương trình in ra thông điệp bất kì khi nhấn tổ hợp phím Ctrl+C. Đăng ký action cho SIGUSR1 và SIGUSR2.
#### Thực chất Ctrl + C chính là gửi signal tên SIGINT

## Exercise 09
    Kiểm tra SIGINT có bị block trong process hay không. Nếu không thực hiện block/ublock thử SIGINT.

### Blocking Signals

#### Signal sets:
    int sigemptyset (sigset_t *set);
    int sigfillset (sigset_t *set);
    int sigaddset (sigset_t *set, int signo);
    int sigdelset (sigset_t *set, int signo);
    int sigismember (const sigset_t *set, int signo); //Checking state

#### int sigprocmask (int how, const sigset_t *newset, sigset_t *oldset); //Modify

    SIG_SETMASK: signal mask của process sẽ bị thay đổi thành newset.
    SIG_BLOCK: newset sẽ được thêm vào signal mask (phép OR).
    SIG_UNBLOCK: newset sẽ bị xóa khỏi signal mask

    Nếu oldset khác NULL, sigprocmask sẽ lấy ra được signal mask hiện tại và lưu vào oldset.

    Nếu newset là NULL, sigprocmask sẽ bỏ qua việc thay đổi giá trị của signal mask, nhưng nó sẽ lấy ra được signal mask hiện tại và lưu vào oldset. Nói cách khác, truyền null vào set như một cách lấy ra signal mask hiện tại.
