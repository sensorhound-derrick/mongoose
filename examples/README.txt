The bug is in simplest_web_server.  The mongoose server doesn't close a file descriptor that it opens, and will only present itself after it serves a file 1024 times (otherwise known as ulimit).
