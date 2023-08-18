
(cons 5 (list 6 7 ))

(cons 5 '(list 6 7))

(cons 'grapes '(of wrath))

(list t '(is not nil))

(symbol-function 'longer-than)
(symbol-name'longer-than)

(cdr '(cons is short for construct))

(defun longer-than (x y) (> (length x) (length y)))

(longer-than '(a 6 h g 3 j 9) '(i 7 4 u i 8))

(apply #'+ '(3 2 4 5))

(eval '(+ 3 2 4 5))

(defun my-eval (x)
  (apply (car x) (cdr x)))

(my-eval '(+ 3 2 4 5))

(defun my-apply (x y)
  (eval (cons x y)))

(my-apply #'+ '(3 2 4 5))

(symbol-function 'apply)
(symbol-function 'my-apply)
(symbol-function 'eval)
(symbol-function 'my-eval)
