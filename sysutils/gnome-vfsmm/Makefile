# $NetBSD: Makefile,v 1.55 2017/02/12 06:24:49 ryoon Exp $

DISTNAME=	gnome-vfsmm-2.26.0
PKGREVISION=	30
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-vfsmm/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for gnome-vfs

#BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

USE_LANGUAGES=		c c++
CXXFLAGS+=		-std=c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomevfs/gnome-vfsmm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glibmm/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
