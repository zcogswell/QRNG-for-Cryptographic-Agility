/**
 * @file qRand.h
 * @author Zack Cogswell
 * @brief Gathers random numbers from IBMQ
 * @version 0.1
 */

 /**
 * @brief Quantum random functino
 * 
 * @param buf buffer to place random bytes into
 * @param num number of random bytes to generate
 * @return int status code, 1 = success, 0 = failure
 */
int q_rand(unsigned char* buf, int num);