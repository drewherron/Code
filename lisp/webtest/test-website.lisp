;; test-website.lisp

(asdf:load-systems '("hunchentoot" "spinneret" "lass"))

(ql:quickload "hunchentoot")
(ql:quickload "spinneret")
(ql:quickload "lass")

(use-package :hunchentoot)
(use-package :spinneret)
(use-package :lass)

(defun start-server ()
  (let ((dispatcher (make-instance 'easy-acceptor :port 4242)))
    (setf (hunchentoot:acceptor-dispatch-table dispatcher)
          (list (create-regex-dispatcher "^/$" 'index-page)
                (create-regex-dispatcher "^/about$" 'about-page)
                (create-regex-dispatcher "^/contact$" 'contact-page)))
    (start dispatcher)))

(defun index-page (request)
  (spinneret:with-html-output-to-string (s)
    (:html
     (:head
       (:title "Home"))
     (:body
       (:h1 "Welcome to My Website")
       (:p "This is a paragraph on my home page.")
       (:ul
         (:li "First item")
         (:li "Second item")
         (:li "Third item"))
       (:p "Here is a link to " (:a :href "/about" "the About page") ".")
     ))))

(defun about-page (request)
  (spinneret:with-html-output-to-string (s)
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

(defun contact-page (request)
  (spinneret:with-html-output-to-string (s)
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
