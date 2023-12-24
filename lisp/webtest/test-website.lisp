;; test-website.lisp

(ql:quickload '("hunchentoot" "cl-who"))

(defpackage :test-website
  (:use :cl :hunchentoot :cl-who))

(in-package :test-website)

(defun start-server ()
  (let ((dispatcher (make-instance 'easy-acceptor :port 4242)))
    (start dispatcher)))

(define-easy-handler (index-page :uri "/") ()
  (with-html-output-to-string (s nil :prologue t :indent t)
    (:html
     (:head (:title "Home"))
     (:body
      (:h1 "Welcome to My Website")
      (:p "This is a paragraph on my home page.")))))

(define-easy-handler (about-page :uri "/about") ()
  (with-html-output-to-string (s nil :prologue t :indent t)
    (:html
     (:head
       (:title "About"))
     (:body
       (:h1 "About Us")
       (:p "Welcome to the About page.")
       (:p "What a great website.")
       (:ul
         (:li "Oh yeah.")
         (:li "Oh yeah.")
         (:li "Oh yeah."))
       (:p "Thank you for visiting my website!")
     ))))

(define-easy-handler (contact-page :uri "/contact") ()
  (with-html-output-to-string (s nil :prologue t :indent t)
    (:html
     (:head
       (:title "Contact"))
     (:body
       (:h1 "Contact Me")
       (:p "If you have any questions or comments, please feel free to reach out.")
       (:p "You can contact me via the following methods:")
       (:ul
         (:li "Email: contact@example.com")
         (:li "Phone: 123-456-7890")
         (:li "Address: 123 Lisp Lane, Code City, CS"))
       (:p "I look forward to hearing from you!")
     ))))

(start-server)
