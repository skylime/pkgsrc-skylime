# $NetBSD$

DISTNAME=	libevhtp-${VERSION}
VERSION=	1.2.0

CATEGORIES=	www

MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://github.com/haiwen/libevhtp
COMMENT=	Flexible replacement for libevent's httpd API
LICENSE=	modified-bsd

DIST_SUBDIR=	libevhtp

USE_CMAKE=	yes
LDFLAGS.SunOS+= -lsocket -lnsl

# the only current consumer (seafile-server/seafile-client) requires
# these options.
CMAKE_ARGS+=	-DEVHTP_DISABLE_SSL=ON -DEVHTP_BUILD_SHARED=OFF

USE_LANGUAGES+=	c99 c++

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
