typedef struct buffer{
    int size;                   //current buffer size in Bytes
    long loc;                   //current reading position
    char filename[128];         //filename of buffer
    void (*func)(int, char *);  //number generator function
}buffer;

int fill(buffer *buf, int size, int length, int delay);

void getBuff(buffer *buf, int size, char *num);