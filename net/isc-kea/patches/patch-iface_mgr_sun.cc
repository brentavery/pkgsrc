$NetBSD$

--- src/lib/dhcp/iface_mgr_sun.cc.orig	2016-09-25 18:58:05.000000000 +0000
+++ src/lib/dhcp/iface_mgr_sun.cc
@@ -15,6 +15,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/map.h>
 #include <net/if_dl.h>
 #include <net/if.h>
 #include <ifaddrs.h>
@@ -39,7 +40,7 @@ IfaceMgr::detectIfaces() {
         isc_throw(Unexpected, "Network interfaces detection failed.");
     }
 
-    typedef map<string, IfacePtr> IfaceLst;
+    typedef std::map<string, IfacePtr> IfaceLst;
     IfaceLst::iterator iface_iter;
     IfaceLst ifaces;
 
