# $NetBSD: hacks.mk,v 1.1 2015/07/09 14:13:51 ryoon Exp $

.if !defined(XULRUNNER_HACKS_MK)
XULRUNNER_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-return-type-c-linkage
.endif

.endif	# XULRUNNER_HACKS_MK
