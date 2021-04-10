#!/usr/bin/env python3
"""Runs qrng local simulator
"""
__author__ = "Geoffrey Kanteles, Zack Cogswell"

from time import time_ns
from argparse import ArgumentParser

from json import load
import qrng

def parse_args():
    """Parses command line arguments

    Returns:
        Namespace -- arguments and their values
    """
    parser = ArgumentParser()
    parser.add_argument('-t', '--timer', action='store_true', \
            help='Time the first random generation')
    parser.add_argument('-i', '--ibmq', default='', help='IBMQ token')
    parser.add_argument('-b', '--backend', default='', help='IBMQ backend')
    return parser.parse_args()

def init():
    args = parse_args()
    try:
        with open('../conf/ibmq.json', 'r') as configfile:
            config = load(configfile)
            if not args.ibmq:
                args.ibmq = config['ibmq']
            if not args.backend:
                args.backend = config['backend']
    except OSError:
        print('Cannot access ibmq.json')
        args.ibmq = ''
        args.backend = ''

    qrng.set_provider_as_IBMQ(args.ibmq)
    qrng.set_backend(args.backend)

    return args

def main():
    """Uses the qrng library's local simulator to generate random 32b ints.
        The ints are stored in a local file called rand.txt
    """
    
    filename = '../bin/rand.bin'
    args = init()
    print(args)
    
    if args.timer:
        time1 = time_ns()
        num = qrng.get_random_int32()
        num = num.to_bytes(4, 'big')
        with open(filename, 'wb+') as outfile:
            outfile.write(num)
        time2 = time_ns()
        print('{0}\u03BCs'.format((time2 - time1)/1000))
    while True:
        num = qrng.get_random_int32()
        num = num.to_bytes(4, 'big')
        with open(filename, 'wb+') as outfile:
            outfile.write(num)

if __name__ == '__main__':
    main()
