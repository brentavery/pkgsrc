# $NetBSD: Makefile,v 1.25 2016/06/08 19:22:16 wiz Exp $

DISTNAME=	Net-AIM-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aryeh.net/netaim.php
COMMENT=	Implementation of the AOL Instant Messenger TOC protocol
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/AIM/.packlist

# Bad symlink in 1.22's distfile
post-extract:
	${RM} ${WRKSRC}/Net

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
