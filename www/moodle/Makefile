# $NetBSD: Makefile,v 1.53 2017/01/19 02:31:57 wen Exp $

DISTNAME=	moodle-3.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moodle/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://www.moodle.org/
COMMENT=	Course management system based on social constructionism
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.4:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.4.4:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.4.4:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.4.4:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-xmlrpc>=5.4.4:../../net/php-xmlrpc
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.4.4:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.4.4:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.4.4:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=5.4.4:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.4:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.4.4:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=5.4.4:../../devel/php-opcache

EGDIR=			share/examples/moodle
MOODLEDIR=		${PREFIX}/share/moodle
MOODLEDATADIR=		${PREFIX}/moodledata

PKG_DESTDIR_SUPPORT=	destdir
INSTALLATION_DIRS=	${EGDIR} share/moodle

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PKG_GROUPS_VARS=	APACHE_GROUP
PKG_USERS_VARS=		APACHE_USER
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

PKG_SYSCONFSUBDIR=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/moodle.conf \
			${PKG_SYSCONFDIR}/moodle.conf
OWN_DIRS_PERMS+=	${MOODLEDATADIR} ${APACHE_USER} ${APACHE_GROUP} 0750

USE_TOOLS+=		pax
NO_CONFIGURE=		yes
NO_BUILD=		yes

PLIST_SRC+=		${PKGDIR}/PLIST ${WRKDIR}/PLIST.AUTO

.include "../../mk/apache.mk"

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing pathnames in configuration file.
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	../moodle.conf
SUBST_SED.conf=		-e "s,@MOODLEDIR@,${MOODLEDIR},g"
SUBST_SED.conf+=	-e "s,@MOODLEDATADIR@,${MOODLEDATADIR},g"
.if ${PKG_APACHE} == "apache24"
SUBST_SED.conf+=	-e "/Order allow,deny/d"
SUBST_SED.conf+=	-e "s,Allow from all,Require all granted,g"
.endif

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing the path of php.
SUBST_STAGE.php=	post-patch
SUBST_FILES.php=	admin/cli/mysql_engine.php admin/cli/maintenance.php admin/cli/cron.php
SUBST_FILES.php+=	admin/cli/reset_password.php admin/cli/automated_backups.php
SUBST_FILES.php+=	admin/cli/install.php admin/cli/install_database.php admin/cli/upgrade.php
SUBST_FILES.php+=	admin/mailout-debugger.php admin/process_email.php
SUBST_FILES.php+=	auth/db/cli/sync_users.php
SUBST_FILES.php+=	enrol/ldap/cli/sync.php enrol/database/cli/sync.php enrol/category/cli/sync.php
SUBST_SED.php=		-e "s,/usr/bin/php,${PREFIX}/bin/php,g"

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing the path of perl.
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	filter/algebra/algebra2tex.pl
SUBST_SED.perl=		-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

WRKSRC=			${WRKDIR}/moodle

post-extract:
	${CP} ${FILESDIR}/moodle.conf ${WRKDIR}/moodle.conf

post-patch:
	cd ${WRKDIR} && ${FIND} moodle -type f -print \
		| ${SED} -e 's,^,share/,' > ${WRKDIR}/PLIST.AUTO

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${MOODLEDIR}/
	${INSTALL_DATA} ${WRKDIR}/moodle.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/moodle.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MOODLEDATADIR}
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MOODLEDATADIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
