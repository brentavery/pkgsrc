# $NetBSD: Makefile,v 1.1 2017/02/18 05:48:51 riastradh Exp $

GITHUB_PROJECT=	ledger
VERSION=	3.1.1
PKGREVISION=	1
DISTNAME=	ledger-${VERSION}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=ledger/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	http://ledger-cli.org/
COMMENT=	Double-entry accounting system for command-line
LICENSE=	modified-bsd

USE_CMAKE=	YES
USE_LANGUAGES=	c++ c
GCC_REQD+=	4.8

.include "options.mk"

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python+=	contrib/getquote-uk.py acprep python/demo.py
REPLACE_FILES.python+=	test/DocTests.py test/LedgerHarness.py
REPLACE_FILES.python+=	test/convert.py test/RegressTests.py test/convert.py
REPLACE_FILES.python+=	tools/genuuid

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
