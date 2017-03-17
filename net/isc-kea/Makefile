# $NetBSD$

DISTNAME=	kea-1.1.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.isc.org/isc/kea/1.1.0/

MAINTAINER=	brent.avery0@gmail.com
HOMEPAGE=	http://kea.isc.org/
COMMENT=	Kea is an open source DHCPv4/DHCPv6 server being developed by Internet Systems Consortium. Kea is a high-performance, extensible DHCP server engine that is designed to be easily modified and extended with hooks libraries.
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	dns++.pc.in

CONFIGURE_ARGS+=	--with-openssl=${PREFIX}
CONFIGURE_ARGS+=	--with-dhcp-mysql=${PREFIX}/bin/mysql_config
CONFIGURE_ARGS+=	--with-dhcp-pgsql=${PREFIX}/bin/pg_config

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/log4cplus/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../databases/postgresql96-client/buildlink3.mk"
.include "../../databases/mysql57-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
