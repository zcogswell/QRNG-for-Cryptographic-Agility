import qrng

qrng.set_provider_as_IBMQ('')
qrng.set_backend('')

while (1):
	num = qrng.get_random_int32()
	f = open("rand.txt", "w")
	f.write(str(num))
	f.close()
