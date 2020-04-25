#!/usr/bin/env python
"""Runs qrng local simulator
"""
__author__ = "Geoffrey Kanteles, Zack Cogswell"

from time import time_ns
from argparse import ArgumentParser

import qrng


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
    #qrng.set_provider_as_IBMQ('8b6a87f834979265ce5b69af4fffa759f76a592250c8b24f227e7642801b901bc1c9bb7b92bbff9594cced1453193b1ff0f7c107817eb7112b5eaa9c63332b27')
    #qrng.set_backend('ibmq_qasm_simulator')
    qrng.set_provider_as_IBMQ('')
    qrng.set_backend()
    if timer_flag:
        time1 = time_ns()
        num = qrng.get_random_int32()
        num = num.to_bytes(4, 'big')
        with open('rand.txt', 'wb+') as outfile:
            outfile.write(num)
        time2 = time_ns()
        print('{0}us'.format((time2 - time1)/1000))
    while True:
        num = qrng.get_random_int32()
        num = num.to_bytes(4, 'big')
        with open('rand.txt', 'wb+') as outfile:
            outfile.write(num)

if __name__ == '__main__':
    main()
