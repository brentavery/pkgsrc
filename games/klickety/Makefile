# $NetBSD: Makefile,v 1.21 2017/01/01 16:06:14 adam Exp $

DISTNAME=	klickety-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	games
COMMENT=	a strategy game for KDE, an adaption of the Clickomania game

REPLACE_PERL+=	klickety-2.0-inherit-ksame-highscore.pl

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
