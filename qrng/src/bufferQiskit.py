#!/usr/bin/env python3
"""Runs qrng local simulator
"""
__author__ = "Geoffrey Kanteles, Zack Cogswell"

from time import time_ns
from argparse import ArgumentParser
from json import load
import qrng

from qrng_sim import init

def main(sub_size):
    filename = '../../buffer/bin/buffer.bin'
    args = init()
    print(args)
    i = 0
    with open(filename, 'wb+') as outfile:
        outfile.close()
    while i < sub_size:
        subBuf = []
        for j in range(sub_size // 8):
            subBuf.append(qrng.get_random_int64().to_bytes(8, 'big'))
            print('\r' + str(j),end='')
        with open(filename, 'ab') as outfile:
            outfile.write(subBuf)
        i += sub_size


if __name__ == '__main__':
    main(1024*1024)