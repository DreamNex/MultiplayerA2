#define RAKNET_VERSION "3.704"
#define RAKNET_VERSION_NUMBER 3.704

#define RAKNET_REVISION "$Revision$"

#define RAKNET_DATE "10/22/2009"

// What compatible protocol version RakNet is using. When this value changes, it indicates this version of RakNet cannot connection to an older version.
// ID_INCOMPATIBLE_PROTOCOL_VERSION will be returned on connection attempt in this case
// Version 8 - use UDT algorithm for congestion control
#define RAKNET_PROTOCOL_VERSION 9
