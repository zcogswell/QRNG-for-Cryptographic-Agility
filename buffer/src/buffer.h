/**
 * @file buffer.h
 * @author Zack Cogswell
 * @brief Takes numbers and creates a buffer file with them.
 * 
 */


/**
 * @brief Holds metadata about the buffer.
 * 
 */
typedef struct buffer{
    int size;                   //current buffer size in Bytes
    long loc;                   //current reading position
    char *filename;            //filename of buffer
    void (*rng)(int, char *);  //number generator function
}buffer;

/**
 * @brief Uses the buffer's number generator to fille a buffer file.
 * 
 * @param buf the buffer object
 * @param size number of bytes in each random number
 * @param delay number of milliseconds 
 * @param refill 0 if no refills, any other integer for refills
 * @return int 
 */
int fill(buffer *buf, int size, int delay, int refill);

/**
 * @brief Get the next value in the buffer.
 * 
 * @param buf the buffer object
 * @param size number of bytes in each random number
 * @param num pointer to byte array to store abritrary sized number
 */
void getBuff(buffer *buf, int size, char *num);