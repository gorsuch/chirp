#include <stdio.h>
#include <curl/curl.h>
 
int main(int argc, char * argv[])
{
  CURL *curl;
  CURLcode res;
  char *url;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s url\n", argv[0]);
    return 1;
  }
  url = argv[1];
  curl = curl_easy_init();

  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    printf("%d\n", res); 
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  return 0;
}

