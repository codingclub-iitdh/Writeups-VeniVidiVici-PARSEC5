from cryptography import x509
from cryptography.x509.oid import NameOID
from cryptography.hazmat.primitives import serialization, hashes
import datetime

# Load the private key
with open("private_key.pem", "rb") as key_file:
    private_key = serialization.load_pem_private_key(
        key_file.read(),
        password=None  
    )

# Define certificate any subject and issuer
subject = x509.Name([
    x509.NameAttribute(NameOID.COUNTRY_NAME, u"India"),
    x509.NameAttribute(NameOID.STATE_OR_PROVINCE_NAME, u"Dharwad"),
    x509.NameAttribute(NameOID.LOCALITY_NAME, u"Dharwad"),
    x509.NameAttribute(NameOID.ORGANIZATION_NAME, u"IITDH"),
    x509.NameAttribute(NameOID.COMMON_NAME, u"iitdh.ac.in"),
])


issuer = x509.Name([
    x509.NameAttribute(NameOID.COUNTRY_NAME, u"India"),
    x509.NameAttribute(NameOID.STATE_OR_PROVINCE_NAME, u"Dharwad"),
    x509.NameAttribute(NameOID.LOCALITY_NAME, u"Dharwad"),
    x509.NameAttribute(NameOID.ORGANIZATION_NAME, u"CA_org"),
    x509.NameAttribute(NameOID.COMMON_NAME, u"CA_org.org"),
])


# Build the certificate
cert = (
    x509.CertificateBuilder()
    .subject_name(subject)
    .issuer_name(issuer)
    .public_key(private_key.public_key())
    .serial_number(x509.random_serial_number())
    .not_valid_before(datetime.datetime.utcnow())
    .not_valid_after(datetime.datetime.utcnow() + datetime.timedelta(days=365))
    .sign(private_key, hashes.SHA256())
)

# Save the signed certificate
with open("signed_cert.pem", "wb") as f:
    f.write(cert.public_bytes(serialization.Encoding.PEM))

print("Certificate signed successfully.")
