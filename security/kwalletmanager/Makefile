# $NetBSD: Makefile,v 1.6 2017/01/01 16:06:35 adam Exp $

DISTNAME=	kwalletmanager-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	security
COMMENT=	KDE wallet manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

USE_TOOLS+=	gmake

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
