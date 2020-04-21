import qrng

qrng.set_provider_as_IBMQ('')
qrng.set_backend('')

for i in range(10):
	num = qrng.get_random_int32()
	print(num)