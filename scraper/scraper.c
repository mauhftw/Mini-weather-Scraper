#include "functions.h" 

void scraper(const char* url, const char* filename) {

  CURL* easyhandle = curl_easy_init();						/*Initialize cURL*/
  curl_easy_setopt( easyhandle, CURLOPT_URL, url ) ;        
  FILE* file = fopen( filename, "w");       
  curl_easy_setopt( easyhandle, CURLOPT_WRITEDATA, file) ;  
  curl_easy_perform( easyhandle );				            /*Make call*/
  curl_easy_cleanup( easyhandle );				            /*Close handler's conections*/
  fclose(file);

}