# $NetBSD: Makefile,v 1.38 2017/02/12 06:25:54 ryoon Exp $
#

DISTNAME=		urlgfe-1.0.1
PKGREVISION=		33
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=urlget/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://urlget.sourceforge.net/
COMMENT=		Download manager for X

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
