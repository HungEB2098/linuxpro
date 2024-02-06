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
