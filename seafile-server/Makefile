# $NetBSD$

CATEGORIES=	net
GITHUB_PROJECT=	seafile-server
VERSION=	9.0.2
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
GITHUB_TAG=	v${VERSION}-server
DISTNAME=	${GITHUB_TAG}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile server
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${GITHUB_PROJECT}-${VERSION}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-server

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config automake aclocal autoheader autoconf gmake gsed

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

CPPFLAGS+=		-I${PREFIX}/include -I${PREFIX}/include/evhtp
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t
LDFLAGS+=		-L${PREFIX}/lib

CONFIGURE_ARGS+=	--disable-fuse

DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	seafile-fileserver-${VERSION}:../../skylime/seafile-fileserver

CONFLICTS=	seafile-client-[0-9]*

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	tools/seafile-admin

SUBST_SED.python=	-e 's,/usr/bin/env python,${PYTHONBIN},'

pre-configure:
	cd ${WRKSRC} && \
		libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf


.include "../../security/openssl/buildlink3.mk"
.include "../../skylime/haiwen-libevhtp/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../skylime/libsearpc/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
