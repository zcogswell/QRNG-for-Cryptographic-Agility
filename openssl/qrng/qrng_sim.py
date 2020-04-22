#!/usr/bin/env python
"""Runs qrng local simulator
"""
__author__ = "Goeffrey Kanteles, Zack Cogswell"

from time import time_ns
from argparse import ArgumentParser

from qrng import get_random_int32, set_backend, set_provider_as_IBMQ


def parse_args():
    """Parses command line arguments

    Returns:
        Namespace -- arguments and their values
    """
    parser = ArgumentParser()
    parser.add_argument('-t', '--timer', action='store_true', \
            help='Time the first random generation.')
    return parser.parse_args()

def main():
    """Uses the qrng library's local simulator to generate random 32b ints.
        The ints are stored in a local file called rand.txt
    """
    timer_flag = parse_args().timer
    set_provider_as_IBMQ('')
    set_backend()
    if timer_flag:
        time1 = time_ns()
        num = get_random_int32()
        num = num.to_bytes(4, 'big')
        with open('rand.txt', 'wb+') as outfile:
            outfile.write(num)
        time2 = time_ns()
        print('{0}us'.format((time2 - time1)/1000))
    while True:
        num = get_random_int32()
        num = num.to_bytes(4, 'big')
        with open('rand.txt', 'wb+') as outfile:
            outfile.write(num)

if __name__ == '__main__':
    main()
