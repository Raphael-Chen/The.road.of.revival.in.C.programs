Figure 4.26. Summary of file access permission bits

fwide 如何使用？


ISO C requires the following buffering characteristics.
- Standard input and standard output are fully buffered, if and only if they do not refer to an interactive device.
- Standard error is never fully buffered.

1. Fully buffered.  
   In this case, actual I/O takes place when the standard I/O buffer is filled. Files residing on disk are normally fully buffered by the standard I/O library. The buffer used is usually obtained by one of the standard I/O functions calling malloc (Section 7.8) the first time I/O is performed on a stream.

2. Line buffered.  In this case, the standard I/O library performs I/O when a newline character is encountered on input or output.
   This allows us to output a single character at a time (with the standard I/O fputc function), knowing that actual I/O will take place only when we finish writing each line. Line buffering is typically used on a stream when it refers to a terminal: standard input and standard output, for example.


Figure 5.6. Timing results using standard I/O routines

Figure 5.10. The conversion type component of a conversion specification

a,A,e,E,f,F,g,G floating-point number



Note that we do not close the standard I/O streams explicitly in Figure 5.4 or Figure 5.5. Instead, we know that the exit function will flush any unwritten data and then close all open streams. (We'll discuss this in Section 8.5.) It is interesting to compare the timing of these three programs with the timing data from Figure 3.5. We show this data when operating on the same file (98.5 MB with 3  million lines) in Figure 5.6.

## Figure 5.6. Timing results using standard I/O routines

| Function                  | User CPU (seconds) | System CPU (seconds) | Clock time (seconds) | Bytes of program Text |
| ------------------------- | ------------------ | -------------------- | -------------------- | --------------------- |
| best time from Figure 3.5 | 0.01               | 0.18                 | 6.67                 |                       |
| fgets , fputs             | 2.59               | 0.19                 | 7.15                 | 139                   |
| getc , putc               | 10.84              | 0.27                 | 12.07                | 120                   |
| fgetc , fputc             | 10.44              | 0.27                 | 11.42                | 120                   |
