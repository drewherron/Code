package main

import (
    "encoding/json"
    "net/http"
)

func main() {
    http.HandleFunc("/ping", func(w http.ResponseWriter, r *http.Request) {
        response := map[string]string{"message": "pong"}
        json.NewEncoder(w).Encode(response)
        w.Header().Set("Content-Type", "application/json")
    })
    
    http.ListenAndServe(":8080", nil)
}