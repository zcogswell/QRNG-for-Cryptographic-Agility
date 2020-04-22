#!/usr/bin/env python
from time import time_ns
from argparse import ArgumentParser

from qrng import get_random_int32, set_backend, set_provider_as_IBMQ


def parse_args():
	parser = ArgumentParser()
	parser.add_argument('-t', '--timer', action='store_true', help='Time the first random generation.')
	return parser.parse_args()

if __name__ == '__main__':
	timer_flag = parse_args().timer
	set_provider_as_IBMQ('')
	set_backend()
	if timer_flag:
		time1 = time_ns()
		num = get_random_int32()
		num = num.to_bytes(4, 'big')
		with open('rand.txt', 'wb+') as f:
			f.write(num)
		time2 = time_ns()
		print('{0}us'.format((time2 - time1)/1000))
	while True:
		num = get_random_int32()
		num = num.to_bytes(4, 'big')
		with open('rand.txt', 'wb+') as f:
			f.write(num)
