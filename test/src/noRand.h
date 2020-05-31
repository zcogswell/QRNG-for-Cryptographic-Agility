/**
 * @file noRand.h
 * @author Zack Cogswell
 * @brief Example testing program for writing random generators and implementing into OpenSSL
 * @version 0.1
 */

 /**
 * @brief New random function
 * 
 * @param buf buffer to place random bytes into
 * @param num number of random bytes to generate
 * @return int status code, 1 = success, 0 = failure
 */
int fake_rand(unsigned char* buf, int num);