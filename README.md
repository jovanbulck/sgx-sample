# Compilation
When I try and compile this on the lab's machines, I first set the following variables:
```
source /localhost/packages/linux-sgx/sgxsdk/environment
export SGX_INCLUDE="/localhost/packages/linux-sgx/sgxsdk/include/ /localhost/packages/linux-sgx/sgxsdk/include/tlibc/"
export SGX_LIBS="/localhost/packages/linux-sgx/sgxsdk/lib64/"
```
(where /localhost/packages/linux-sgx/sgxsdk is the path to the SGX SDK)

Then I call `make`

# Complications
This is the corresponding output of my attempts
```
[===] Enclave [===]
[GEN] sgx_edger8r password_generator.edl
[CC]  password_generator_t.c (trusted edge)
[CC]  password_generator.c (core)
[LD]   password_generator.o password_generator_t.o -lsgx_trts password_generator.unsigned.so
password_generator_t.o: In function `sgx_generate_password':
/home/r0702367/sgx_example/passwordGenerator_example/Enclave/password_generator_t.c:70: undefined reference to `memcpy_s'
collect2: error: ld returned 1 exit status
Makefile:41: recipe for target 'password_generator.so' failed
make[1]: *** [password_generator.so] Error 1
Makefile:64: recipe for target 'build-Enclave' failed
make: *** [build-Enclave] Error 2
```

I know that **memcpy_s** is declared in the included header file mbusafecrt.h, but what library is missing to implement this eludes me


