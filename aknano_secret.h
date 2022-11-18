#ifndef __AKNANO_SECRET_H__
#define __AKNANO_SECRET_H__

#ifdef AKNANO_ENABLE_EXPLICIT_REGISTRATION
/* set API acces token */
#define AKNANO_API_TOKEN "0000000000000000000000000000000000000000"
#endif

#define AKNANO_DEVICE_GATEWAY_PORT 8443
#define AKNANO_FACTORY_UUID "00000000-0000-0000-0000-000000000000"
#define AKNANO_DEVICE_GATEWAY_CERTIFICATE \
"-----BEGIN CERTIFICATE-----\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"0000000000000000000000000000000000000000000000000000000000000000\n" \
"000000000000000000000000000000000000000==\n" \
"-----END CERTIFICATE-----\n"

#endif
