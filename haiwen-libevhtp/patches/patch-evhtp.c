$NetBSD$

--- evhtp.c.orig	2012-12-27 07:16:17.000000000 +0000
+++ evhtp.c
@@ -2722,7 +2722,7 @@ evhtp_bind_socket(evhtp_t * htp, const c
     struct sockaddr_in6 sin6;
 
 #ifndef NO_SYS_UN
-    struct sockaddr_un sun;
+    struct sockaddr_un sockun;
 #endif
     struct sockaddr  * sa;
     size_t             sin_len;
@@ -2743,18 +2743,18 @@ evhtp_bind_socket(evhtp_t * htp, const c
 #ifndef NO_SYS_UN
         baddr += 5;
 
-        if (strlen(baddr) >= sizeof(sun.sun_path)) {
+        if (strlen(baddr) >= sizeof(sockun.sun_path)) {
             return -1;
         }
 
-        memset(&sun, 0, sizeof(sun));
+        memset(&sockun, 0, sizeof(sockun));
 
         sin_len        = sizeof(struct sockaddr_un);
-        sun.sun_family = AF_UNIX;
+        sockun.sun_family = AF_UNIX;
 
-        strncpy(sun.sun_path, baddr, strlen(baddr));
+        strncpy(sockun.sun_path, baddr, strlen(baddr));
 
-        sa = (struct sockaddr *)&sun;
+        sa = (struct sockaddr *)&sockun;
 #else
         fprintf(stderr, "System does not support AF_UNIX sockets\n");
         return -1;
