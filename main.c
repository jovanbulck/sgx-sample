#include <stdio.h>
#include <sgx_urts.h>
#include "Enclave/password_generator_u.h"

#define DEBUG_ENCLAVE		1
#define PASSWD_LEN		100
#define ENCLAVE_FILE		"Enclave/password_generator.so"

int main( int argc, char **argv )
{

  static sgx_enclave_id_t enclaveId = 0;
  static sgx_launch_token_t launch_token = { 0 };
  static int updated= 0;
  static sgx_status_t sgx_status= SGX_SUCCESS;
  int output;
  char* pw;

  sgx_status = sgx_create_enclave(ENCLAVE_FILE, DEBUG_ENCLAVE, &launch_token, &updated, &enclaveId, NULL);
  if(sgx_status != SGX_SUCCESS) return -1;

  sgx_status = generate_password(enclaveId,&output,pw,PASSWD_LEN);
  if(sgx_status != SGX_SUCCESS) printf( "Error calling enclave\n (error 0x%x)\n", sgx_status );
	else printf("Enclave called successfully (%i)\n",output);

  sgx_status = sgx_destroy_enclave(enclaveId);
	if(sgx_status != SGX_SUCCESS){
    printf( "Error destroying enclave (error 0x%x)\n", sgx_status );
    return -3;
	}


  return 0;
}

