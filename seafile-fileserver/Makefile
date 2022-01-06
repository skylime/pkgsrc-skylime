# $NetBSD$

CATEGORIES=	net
GITHUB_PROJECT=	seafile-server
VERSION=	9.0.2
PKGNAME=	seafile-fileserver-${VERSION}

GITHUB_TAG=	v${VERSION}-server
DISTNAME=	${GITHUB_TAG}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile server
LICENSE=	gnu-gpl-v2

GO_BUILD_PATTERN=	.

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-server/fileserver

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
