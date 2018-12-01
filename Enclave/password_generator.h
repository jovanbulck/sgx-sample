
#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

/**
\brief Generates a new random password
\param output The output buffer in unprotected memory to write the password to
\param len The length of the buffer
\return 0 on success, else -1
*/
int generate_password( char *output, unsigned int len );


#endif

