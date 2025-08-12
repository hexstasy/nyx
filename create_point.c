#include <sodium.h>
#include "create_point.h"

static inline int encrypt_key(unsigned long long * cipher_msg_len,
    const unsigned char * key, const unsigned char * msg, unsigned long long msg_len,
    unsigned char * cipher_msg, const unsigned char * nonce);

enum nyx_err_t create_point(const char * port, const char * sid) {
    unsigned long long key_len = crypto_aead_xchacha20poly1305_ietf_KEYBYTES;
    unsigned char key_buf[key_len];
    randombytes_buf(key_buf, key_len);

    unsigned long long nonce_len = crypto_aead_xchacha20poly1305_ietf_NPUBBYTES;
    unsigned char nonce[nonce_len];
    randombytes_buf(nonce, nonce_len);

    unsigned long long cipher_key_len = 0;
    unsigned char cipher_buf[key_len + crypto_aead_xchacha20poly1305_ietf_ABYTES];

    int ret = encrypt_key(&cipher_key_len, (const unsigned char *)sid, key_buf, key_len, cipher_buf, nonce);
    if (ret != 0)
        return NYX_ERR_CIPHER;

    puts(cipher_buf);
    return NYX_ERR_OK;
}

static inline int encrypt_key(unsigned long long * cipher_msg_len,
    const unsigned char * key, const unsigned char * msg, unsigned long long msg_len,
    unsigned char * cipher_msg, const unsigned char * nonce) 
{
    return crypto_aead_xchacha20poly1305_ietf_encrypt(
        cipher_msg, cipher_msg_len,
        msg, msg_len,
        NULL, 0,
        NULL, nonce, key
    );
}