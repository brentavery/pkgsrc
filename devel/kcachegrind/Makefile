# $NetBSD: Makefile,v 1.17 2017/01/19 08:51:56 markd Exp $

DISTNAME=	kcachegrind-16.12.0
CATEGORIES=	devel
COMMENT=	Visualization of Performance Profiling Data
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

REPLACE_PERL+= \
	converters/dprof2calltree \
	converters/memprof2calltree \
	converters/op2calltree

# REPLACE_PHP+= converters/pprof2calltree
SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	converters/pprof2calltree
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

REPLACE_PYTHON+= \
	converters/hotshot2calltree.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
