# Cryptography/2
This is the README for Cryptography/2.

Impersonation using Certificates issued by BAD CA:

Flag:parsec{S1gn0f4Ph0ny_1239938123}
### Procedure

We shall give a CA with a weak key (small) in RSA(for now). We can use it to gain the private key of the CA and use it to sign the fake certificates which are impersonating someone else.

Sending this to a machine which requires authentication and only authorizes certain users and is unaware of the vulnerability, will trust the imposter and can lead to leak of sensitive information.

### File Structure
`create_cert` creates a new certificate, public key and private key. The public key along with other CA's public keys. Victim.py is the server program.
