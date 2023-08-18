; display all the permutations of a list
(defun permutations (L &optional (Sofar nil))
   (if (null L) (format t "~A~%" Sofar)
      (dolist (e L)
             (permutations (remove e L :count 1) (append SoFar (list e))))))

(format t "Enter a list:~%")
(defvar orig (read))
(format t "The permutations of list ~A are:~%" orig)
(permutations orig)
