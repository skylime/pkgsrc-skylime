# $NetBSD$

BUILDLINK_TREE+=	libevhtp

.if !defined(LIBEVHTP_BUILDLINK3_MK)
LIBEVHTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevhtp+=	libevhtp>=1.2.0
BUILDLINK_PKGSRCDIR.libevhtp?=		../../skylime/haiwen-libevhtp
.endif	# LIBEVHTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevhtp
