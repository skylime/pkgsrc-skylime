# $NetBSD$

PKGNAME=	libsearpc-3.2.0
CATEGORIES=	devel net

MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/.0/-latest/}
DISTNAME=	${GITHUB_TAG}

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	http://seafile.com/
COMMENT=	Simple RPC framework based on GObject system
LICENSE=	apache-2.0

DIST_SUBDIR=	seafile

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config autoconf automake gsed

DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson

PYTHON_VERSIONS_INCOMPATIBLE=	27

LDFLAGS.SunOS+=	-lsocket -lnsl

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	lib/searpc-codegen.py

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../textproc/jansson/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
