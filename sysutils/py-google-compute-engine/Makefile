# $NetBSD: Makefile,v 1.1 2017/03/04 19:10:32 bsiegert Exp $

GITHUB_PROJECT=	compute-image-packages
GITHUB_TAG=	20170302
DISTNAME=	google-compute-engine-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=GoogleCloudPlatform/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://cloud.google.com/compute/docs/images
COMMENT=	Packages for Google Compute Engine images
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/compute-image-packages-${GITHUB_TAG}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	google_compute_engine/config_manager.py \
			google_compute_engine/accounts/accounts_daemon.py \
			google_compute_engine/accounts/accounts_utils.py \
			google_compute_engine/boto/boto_config.py \
			google_compute_engine/clock_skew/clock_skew_daemon.py \
			google_compute_engine/instance_setup/instance_config.py \
			google_compute_engine/ip_forwarding/ip_forwarding_daemon.py
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_SED.paths=	-e 's,/etc,${PREFIX},g'
SUBST_SED.paths+=	-e 's,/var,${VARBASE},g'



.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
