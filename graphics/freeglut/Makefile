# $NetBSD: Makefile,v 1.20 2016/10/01 07:52:57 wiz Exp $

DISTNAME=	freeglut-3.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeglut.sourceforge.net/
COMMENT=	Alternative to the OpenGL Utility Toolkit (GLUT) library
LICENSE=	x11

USE_CMAKE=	yes
CMAKE_ARGS+=	-DFREEGLUT_REPLACE_GLUT:BOOL=OFF

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	freeglut.pc.in

# https://sourceforge.net/p/freeglut/bugs/232/
post-install:
	${RM} ${DESTDIR}${PREFIX}/include/GL/glut.h

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
