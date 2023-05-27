library(base)

hashfunction <- function(s){
  return (strtoi(charToRaw(s),16L))
}

