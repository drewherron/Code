(in-package :cl-user)

(load (compile-file "my-big-program.lisp"))

(save-lisp-and-die "my-big-program"
                   :toplevel #'my-big-program
                   :executable t)
