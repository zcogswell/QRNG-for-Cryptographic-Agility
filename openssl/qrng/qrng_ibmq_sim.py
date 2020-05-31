import qrng

qrng.set_provider_as_IBMQ('8b6a87f834979265ce5b69af4fffa759f76a592250c8b24f227e7642801b901bc1c9bb7b92bbff9594cced1453193b1ff0f7c107817eb7112b5eaa9c63332b27')
qrng.set_backend('ibmq_qasm_simulator')

for i in range(10):
	num = qrng.get_random_int32()
	print(num)