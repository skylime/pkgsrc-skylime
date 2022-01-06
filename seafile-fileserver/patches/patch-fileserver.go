$NetBSD$

Use native syscall because Dup3() is not available on all platforms in go.

--- fileserver.go.old
+++ fileserver.go
@@ -437,7 +437,7 @@ func main() {
 		if err != nil {
 			log.Fatalf("Failed to open or create error log file: %v", err)
 		}
-		syscall.Dup3(int(fp.Fd()), int(os.Stderr.Fd()), 0)
+		syscall.Syscall(syscall.SYS_FCNTL, fp.Fd(), syscall.F_DUP2FD, os.Stderr.Fd())
 	}
 
 	repomgr.Init(seafileDB)
